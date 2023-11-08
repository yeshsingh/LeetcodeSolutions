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
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> inorder;
        TreeNode* node=root;
        stack<TreeNode*> ans;
        
        while(true)
        {
            if(node!=NULL)
            {
                ans.push(node);
                node=node->left;
            }
            else 
            {
                if(ans.empty()==true) return inorder;
                node=ans.top();
                ans.pop();
                inorder.push_back(node->val);
                node=node->right;
            }
        }
        return inorder;
    }
};