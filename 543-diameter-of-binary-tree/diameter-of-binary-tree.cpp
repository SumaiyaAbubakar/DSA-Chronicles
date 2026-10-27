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

        int leftheight=Height(root->left);
        int rightheight=Height(root->right);

        if(leftheight>rightheight)
        {
            return leftheight+1;
        }

        return rightheight+1;
    }
    int diameterOfBinaryTree(TreeNode* root) {
        if(root==nullptr)
        {
            return 0;
        }

        int LEFT=Height(root->left);
        int RIGHT=Height(root->right);

        int curr= LEFT+RIGHT+2;

        int left=diameterOfBinaryTree(root->left);
        int right=diameterOfBinaryTree(root->right);

        if(curr>left && curr>right)
        {
            return curr;
        }
        else if(left>right)
        {
            return left;
        }

        return right;

    }
};