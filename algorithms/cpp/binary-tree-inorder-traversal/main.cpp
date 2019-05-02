#include <iostream>
#include <stack>
#include <vector>
using std::stack;
using std::vector;
//  Definition for a binary tree node.
  struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode(int x) : val(x), left(NULL), right(NULL) {}
  };
class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> ret;        
        stack<TreeNode*> stack;

        TreeNode *curr = root;
        while ( curr || !stack.empty()) {
            while (curr) {
                stack.push(curr);
                curr = curr->left;
            }

            curr = stack.top();
            stack.pop();
            ret.push_back(curr->val);

            curr = curr->right;
        }
        return ret;
    }
};
int main() {

    Solution sol;
    TreeNode h1(1);
    TreeNode h2(2);
    TreeNode h3(3);

    h1.right = &h2;
    h2.left = &h3;
    vector<int> ret;
    ret = sol.inorderTraversal(&h1);
    for (auto v : ret) {
        std::cout << v << "\t";
    }
    std::cout<< std::endl;
    return 0;
}
