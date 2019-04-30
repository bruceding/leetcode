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
        if (!p->left) {
            child = p->left;
        } else if (!p->right) {
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

    // destruct func
    ~BinarySearchTree() {

    }
};

int main() {

    return 0;
}

