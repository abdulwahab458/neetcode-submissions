/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode() {}
 *     TreeNode(int val) { this.val = val; }
 *     TreeNode(int val, TreeNode left, TreeNode right) {
 *         this.val = val;
 *         this.left = left;
 *         this.right = right;
 *     }
 * }
 */

class Solution {
    public TreeNode findIt(TreeNode root, TreeNode p,TreeNode q){
        if(root.val>q.val && root.val>p.val){
            return findIt(root.left,p,q);
        }
        
        if(root.val<q.val && root.val<p.val){
            return findIt(root.right,p,q);
        }
        return root;
    }
    public TreeNode lowestCommonAncestor(TreeNode root, TreeNode p, TreeNode q) {
        return findIt(root,p,q);
    }
}
