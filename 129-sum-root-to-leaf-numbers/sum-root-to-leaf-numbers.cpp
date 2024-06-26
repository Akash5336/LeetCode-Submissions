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
private:
    void sumNumbersHelper(TreeNode* node,int sum){
        if(node==nullptr)
            return;
        if(node->left ==nullptr && node->right==nullptr)
            ans+=sum*10+node->val;
        sum = sum*10+node->val;
        sumNumbersHelper(node->left,sum);
        sumNumbersHelper(node->right,sum);
    }
public:
    int ans=0;
    int sumNumbers(TreeNode* root) {
        sumNumbersHelper(root,0);
        return ans;
    }
};