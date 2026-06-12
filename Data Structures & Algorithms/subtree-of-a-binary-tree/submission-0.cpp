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

class Solution {
    bool func2(TreeNode* root, TreeNode* subroot) {
        if (root == NULL && subroot == NULL) return true;
        if (root == NULL || subroot == NULL) return false;
        if(root->val != subroot->val)return false;
        return func2(root->left,subroot->left) &&  func2(root->right, subroot->right);
    }
    bool func1(TreeNode* root, TreeNode* subroot) {
        if (root == NULL && subroot == NULL) return true;
        if (root == NULL || subroot == NULL) return false;
        if (func2(root, subroot)) {
            return true;
        }
        return func1(root->left, subroot) || func1(root->right, subroot);
    }

   public:
    bool isSubtree(TreeNode* root, TreeNode* subroot) { return func1(root, subroot); }
};
