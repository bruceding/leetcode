#include<iostream>

//  Definition for a binary tree node.
  struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode(int x) : val(x), left(NULL), right(NULL) {}
  };
class Solution {
public:
    bool isValidBST(TreeNode* root) {
        if (!root) {
            return true;
        }

        TreeNode *left = root->left;
        
        while(left) {
            if (left->val >= root->val) {
                return false;
            }
            if (left->left) {
                if (left->left->val >= left->val) {
                    return false;
                }
            }
            if (left->right) {
                if (left->right->val <= left->val) {
                    return false;
                }
                if (left->right->val >= root->val) {
                    return false;
                }
            }
            left = left->right;
        }

        TreeNode *right = root->right;
        while (right) {
            if (right->val <= root->val) {
                return false;
            }
            if (right->left) {
                if (right->left->val >= right->val) {
                    return false;
                }
                if (right->left->val <= root->val) {
                    return false;
                }
            }
            if (right->right) {
                if (right->right->val <= right->val) {
                    return false;
                }
            }
            right = right->left;
        }

       bool flag;
       flag = isValidBST(root->left);
       if (!flag){
           return false;
       }
       flag = isValidBST(root->right);
       return flag;
    }
};

int main() {
    Solution sol;

    TreeNode h1(10);
    TreeNode h2(5);
    TreeNode h3(15);
    TreeNode h4(6);
    TreeNode h5(20);
    h1.left = &h2;
    h1.right = &h3;
    h3.left = &h4;
    h3.right = &h5;

    bool ret;

    ret = sol.isValidBST(&h1);
    std::cout << ret << std::endl;

    return 0;
}
