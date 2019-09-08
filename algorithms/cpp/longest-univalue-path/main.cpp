#include<string>
#include<iostream>
using std::string;
 // Definition for a binary tree node.
struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
class Solution {
private: 
    int ans;
public:
    int longestUnivaluePath(TreeNode* root) {
        if (!root) return 0;
        ans = 0;
        searchNode(root);
        return ans;
    }

    int searchNode(TreeNode* node ) {
        if (!node) {
            return 0;
        }
        
        int left = searchNode(node->left);
        int right = searchNode(node->right);

        int ansLeft = 0;  
        int ansRight = 0;

        if (node->left && node->left->val == node->val) {
            ansLeft += left + 1;
        }
        if (node->right && node->right->val == node->val) {
            ansRight += right + 1;
        }

        ans = ans > (ansLeft + ansRight) ? ans : (ansLeft + ansRight);

        return ansLeft > ansRight ? ansLeft : ansRight;
    }
};
int main() {
    Solution sol;
    TreeNode t1(4);
    TreeNode t2(4);
    TreeNode t3(4);
    TreeNode t4(4);
    TreeNode t5(4);
    TreeNode t6(5);
    t1.left = &t2;
    t1.right = &t3;
    t2.left = &t4;
    t2.right = &t5;
    t3.right = &t6;

    int ret;
    ret = sol.longestUnivaluePath(&t1);
    std::cout << ret << std::endl;
    return 0;
}
