/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
#include <cstdlib>
class Solution {
public:
    bool isBalanced(TreeNode* root) {
        if (root == nullptr) {
            return true;
        }

        int left = height(root->left);
        int right = height(root->right);

        if (abs(left - right) > 1) {
            return false;
        }

        int flag = isBalanced(root->left);
        if (!flag) {
            return false;
        }

        return isBalanced(root->right);
    }

    int height(TreeNode *node) {
        int h = 0;
        if (node == nullptr) {
            return h;
        }

        int l = height(node->left) + 1;
        int r = height(node->right) + 1;


        return (l>r)? l : r;
    }
};


