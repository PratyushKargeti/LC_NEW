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
    int count=0;

    void dfs(TreeNode* root,int maxi)
    {
        if(root==NULL)return;
        maxi=max(maxi,root->val);
        if(maxi==root->val)
            count++;
        dfs(root->left,maxi);

        dfs(root->right,maxi);
    }
    int goodNodes(TreeNode* root) {
        dfs(root,INT_MIN);
        return count;
    }
};