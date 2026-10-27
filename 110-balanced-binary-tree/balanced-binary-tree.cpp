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
    int Height(TreeNode* root)
    {
        if(root==nullptr)
        {
            return -1;
        }
        int leftHeight=Height(root->left);
        int rightHeight=Height(root->right);

        if(leftHeight>rightHeight)
        {
            return leftHeight+1;
        }

        return rightHeight+1;
    }
    bool isBalanced(TreeNode* root) {
        if(root==nullptr)
        {
            return true;
        }
        
        int LEFT=Height(root->left);
        int RIGHT=Height(root->right);

        if(abs(LEFT-RIGHT)>1)
        {
            return false;;
        }

        if(isBalanced(root->left) && isBalanced(root->right))
        {
            return true;
        }

        return false;
    }
};