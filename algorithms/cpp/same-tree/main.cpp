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
    bool isSameTree(TreeNode* p, TreeNode* q) {
        // 先判断节点
        if (!sameTreeNode(p, q)) {
           return false; 
        }

        if (!p && !q) {
            return true;
        }

        if (!isSameTree(p->left, q->left)) {
            return false;
        }
        if (!isSameTree(p->right, q->right)) {
            return false;
        }

        return true;
    }
    bool sameTreeNode(TreeNode* p, TreeNode* q) {
        if (p && !q) {
            return false;
        }
        if (!p && q) {
            return false;
        }
        if (!p && !q) {
            return true;
        }

        if (p->val == q->val) {
            return true;
        }
        return false;
    }
};

int main() {
    TreeNode *p = nullptr, *q = nullptr;
    Solution sol;
    auto ret = sol.isSameTree(p, q);
    std::cout << ret << std::endl;

    TreeNode h1(1);
    TreeNode h2(2);
    TreeNode h3(3);
//    h1.left = &h2;
    h1.right = &h3;

    TreeNode t1(1);
    TreeNode t2(2);
    TreeNode t3(3);
//    t1.left = &t2;
    t1.right = &t3;

    p = &h1;
    q = &t1;
    ret = sol.isSameTree(p, q);
    std::cout << ret << std::endl;
    return 0;
}
