/*
 * =====================================================================================
 *
 *       Filename:  main.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  2019/04/14 07时20分50秒
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  YOUR NAME (), 
 *   Organization:  
 *
 * =====================================================================================
 */
#include <iostream>
struct TreeNode {
      int data;
      TreeNode *left;
      TreeNode *right;
      TreeNode(int x):data(x),left(NULL), right(NULL){}
};
class BinarySearchTree {
private:
        TreeNode *tree;

public:
    BinarySearchTree():tree(nullptr) {}
    TreeNode* get_root() {
        return tree;
    }
    // search data 
    TreeNode* find(int data) {
        TreeNode *p = tree;
        while (p) {
          if (data < p->data) p = p->left;
          else if (data > p->data) p = p->right;
          else return p;
        }
        return nullptr;
    }
    // insert data
    void insert(int data) {
        if (!tree) {
            tree = new TreeNode(data);
            return;
        }

        TreeNode *p = tree;

        while (p) {
            if (data > p->data) {
                if(!p->right) {
                    p->right = new TreeNode(data);
                    return;
                }
                p = p->right;
            } else {
                if(!p->left) {
                    p->left = new TreeNode(data);
                    return;
                }

                p = p->left;
            }
        }
    }

    // consider three situation
    // leaf node, set parent node left or right link, child set nullptr
    // node has a left node or right node , set child = left node or  right node, then  parent node set link
    // node has left node and right node, find the min node from right, then  exchang data, set the right delete node
    void deleteNode(int data) {
        TreeNode *p = tree;
        TreeNode *pp;
        while (p && p->data != data) {
           pp = p; 
           if (data > p->data) {
                p = p->right;
           } else {
                p = p->left;
           }
        }

        // not find node
        if (!p) {
            return ;
        }

        if (p->left && p->right) {
            TreeNode *minP = p->right;
            TreeNode *minPP = p;
            while (minP->left) {
                minPP = minP;
                minP = minP->right;
            }

            // copy minP data
            p->data = minP->data;
            // p point to delete node
            p = minP;
            pp = minPP;
        }

        TreeNode *child = nullptr;
        if (p->left) {
            child = p->left;
        } else if (p->right) {
            child = p->right;
        } 
        
        if (!pp) {
            // delete root node
            tree = child;
            delete p;
        } else if (pp->left == p) {
            pp->left = child;
            delete p;
        } else {
            pp->right = child;
            delete p;
        }

    }


    void inOrder(TreeNode* root) {
      if (root == nullptr) return;
      inOrder(root->left);
      std::cout << root->data << std::endl;    
      inOrder(root->right);
    }

    int Min() {
        TreeNode *p = tree;
        while(p && p->left) {
            p = p -> left;
        }

        return p->data;
    }
    void DeleteMin() {
        if (!tree) {
            return;
        }
        TreeNode *p = tree;    
        TreeNode *pp = nullptr;
        while(p && p->left) {
            pp = p;
            p = p->left;
        } 

        TreeNode *child = nullptr;
        if (p->right) {
            child = p->right;
        }
        if (!pp) {
            tree = child;
        } else {
            pp->left = child;
        }

        delete p;

    }
    // destruct func
    ~BinarySearchTree() {

    }
};

int main() {

    BinarySearchTree tree;
    tree.insert(7);
    tree.insert(3);
    tree.insert(1);
    tree.insert(2);
    tree.insert(15);
    tree.insert(9);
    tree.insert(20);

    tree.DeleteMin();
    tree.inOrder(tree.get_root());

    return 0;
}

