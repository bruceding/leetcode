#include <iostream>
#include <vector>
#include <stdexcept>
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
    vector< vector<int> > levelOrder(TreeNode* root) {
        vector< vector<int> > ret;
        levelOrderHelper(root, 0, ret);

        return ret;
    }
    void levelOrderHelper(TreeNode *node, int level, vector<vector<int> > &ret) {
       if (!node) {
           return ;
       } 

       try {
           auto &vec = ret.at(level);
           vec.push_back(node->val);
       } catch (const std::out_of_range& e) {
           // not find
           vector<int> vec;
           vec.push_back(node->val);
           ret.resize(level+1);
           ret[level] = vec;
       }

       levelOrderHelper(node->left, level+1, ret);
       levelOrderHelper(node->right, level+1, ret);
    }
};
int main() {

    Solution sol;
    TreeNode h1(3);
    TreeNode h2(9);
    TreeNode h3(20);
    TreeNode h4(15);
    TreeNode h5(7);

    h1.right = &h3;
    h1.left = &h2;
    h3.right = &h5;
    h3.left = &h4;
    vector< vector<int> >  ret;
    ret = sol.levelOrder(&h1);
    std::cout << "ret size=" << ret.size() << std::endl;
    for (auto vec : ret) {
        for (auto v : vec) {
            std::cout <<  v << "\t";
        }
            std::cout << std::endl;
    }
    std::cout<< std::endl;
    return 0;
}
