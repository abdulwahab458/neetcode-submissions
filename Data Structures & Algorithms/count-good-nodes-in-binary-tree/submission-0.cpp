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
public:
    void findmax(int maxi,int& count,TreeNode* root){
        if(root == NULL) return;
        if(root->val>=maxi){
            count++;
        }
        maxi = max(maxi,root->val);
        findmax(maxi,count,root->left);
        findmax(maxi,count,root->right);
    }
    int goodNodes(TreeNode* root) {
        int maxi = INT_MIN;
        int count = 0 ; 
        findmax(maxi,count,root);
        return count;
    }
};
