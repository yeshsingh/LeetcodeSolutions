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
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> preorder;
        if(root==NULL)
        {
            return preorder;
        }
        stack<TreeNode*> ans;
        ans.push(root);
        while(ans.size()!=0)
        {
            root=ans.top();
            ans.pop();
            preorder.push_back(root->val);
            if(root->right!=NULL)
            {
                ans.push(root->right);
            }
            if(root->left!=NULL)
            {
                ans.push(root->left);
            }
        }
        return preorder;
    }
};