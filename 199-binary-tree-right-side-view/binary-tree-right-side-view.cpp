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
    void rightSideHelper(TreeNode* curr,vector<int> &result,int depth){
        if(curr==NULL)
            return;
        if(depth==result.size())
            result.push_back(curr->val);
        
        rightSideHelper(curr->right,result,depth+1);
        rightSideHelper(curr->left,result,depth+1);
    }
public:
    vector<int> rightSideView(TreeNode* root) {
        vector<int> result;
        rightSideHelper(root,result,0);
        return result;
    }
};