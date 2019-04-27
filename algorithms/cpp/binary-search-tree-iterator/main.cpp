#include <iostream>
#include <stack>
using std::stack;
/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */
//  Definition for a binary tree node.
  struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode(int x) : val(x), left(NULL), right(NULL) {}
  };
class BSTIterator {
public:
    BSTIterator(TreeNode* root) {
       pushNode(root); 
       std::cout << "stack size : " << stack_.size() << std::endl;
    }

    /** @return the next smallest number */
    int next() {
        TreeNode *node = stack_.top();
        stack_.pop();
        return node->val;
    }

    /** @return whether we have a next smallest number */
    bool hasNext() {
        return !stack_.empty();
    }

 private:
    stack<TreeNode*> stack_;
    void pushNode(TreeNode *node) {
        if (!node) {
            return;
        }

        if (node->right) {
            pushNode(node->right);
        }

        stack_.push(node);
        
        if (node->left) {
            pushNode(node->left);
        }
    }
};

int main() {

    BSTIterator *bst = new BSTIterator(NULL);
    std::cout << bst->hasNext()<< std::endl;
    TreeNode h1(2);
    TreeNode h2(1);
    TreeNode h3(3);
    h1.left = &h2;
    h1.right = &h3;
    bst = new BSTIterator(&h1);
    std::cout << bst->hasNext()<< std::endl;
    std::cout << bst->next()<< std::endl;
    std::cout << bst->next()<< std::endl;
    std::cout << bst->next()<< std::endl;
    TreeNode t1(7);
    TreeNode t2(3);
    TreeNode t4(15);
    TreeNode t5(9);
    TreeNode t6(20);
    t1.left = &t2;
    t1.right = &t4;
    t4.left = &t5;
    t4.right = &t6;
    bst = new BSTIterator(&t1);
    std::cout << bst->hasNext()<< std::endl;
    std::cout << bst->next()<< std::endl;
    std::cout << bst->next()<< std::endl;
    std::cout << bst->next()<< std::endl;
    std::cout << bst->next()<< std::endl;
    std::cout << bst->next()<< std::endl;
    std::cout << bst->hasNext()<< std::endl;

    return 0;
}
