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
    int ans=0;
    private void helper(TreeNode node,int sum){
        if(node==null)
            return;
        if(node.left==null && node.right==null)
            ans+=sum*10+node.val;
        sum = sum*10+node.val;
        helper(node.left,sum);
        helper(node.right,sum);
    }
    public int sumNumbers(TreeNode root) {
        helper(root,0);
        return ans;
    }
}