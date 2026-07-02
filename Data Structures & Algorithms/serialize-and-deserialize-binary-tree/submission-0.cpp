/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

class Codec {
   public:
    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        string s = "";
        getStringArray(root, s);
        return s;
    }

    void getStringArray(TreeNode* root, string& s) {
        if (root == nullptr) {
            s += "N,";
            return;
        }
        s += to_string(root->val) + ",";
        getStringArray(root->left, s);
        getStringArray(root->right, s);
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        vector<string> tokens;
        string temp = "";

        for (char c : data) {
            if (c == ',') {
                tokens.push_back(temp);
                temp = "";
            } else {
                temp += c;
            }
        }
        int idx = 0;
        return buildit(tokens, idx);
    }
    TreeNode* buildit(vector<string> data, int& idx) {
        if (data[idx] == "N") {
            idx++;
            return nullptr;
        }
        TreeNode* root = new TreeNode(stoi(data[idx]));
        idx++;
        root->left = buildit(data, idx);
        root->right = buildit(data, idx);
        return root;
    }
};
