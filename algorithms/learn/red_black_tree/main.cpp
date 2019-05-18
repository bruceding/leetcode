// red black tree code
#include <iostream>
enum tree_color {RED, BLACK};
struct TreeNode {
      int data;
      TreeNode *left;
      TreeNode *right;
      tree_color color;
      TreeNode(int x):data(x),left(NULL), right(NULL), color(RED){}
};
class RedBlackBST {
private:
        TreeNode *root;
        TreeNode* put(TreeNode* h, int data) {
            if (h == nullptr) {
                // default red color
                return new TreeNode(data);
            }

            if (h->data > data) {
                h->left = put(h->left, data);
            } else if (h->data < data) {
                h->right = put(h->right, data);
            } else {
                h->data = data;
            }
            
            // rotate left node 
            if (Red(h->right) && !Red(h->left)) {
                h = RotateLeft(h);
            }

            // rotate right 
            if (Red(h->left) && Red(h->left->left)) {
                h = RotateRight(h);
            }

            if (Red(h->left) && Red(h->right)) {
                FlipeColors(h);
            }

            return h;
        }

        bool Red(TreeNode *node) {
            if (node == nullptr) {
                return false;
            }
            return node->color == RED;
        }
        TreeNode *RotateLeft( TreeNode *h) {
            TreeNode *x = h->right;
            h->right = x->left;
            x->left = h;
            x->color = h->color;
            h->color = RED;
            return x;
        }
        TreeNode *RotateRight(TreeNode *h) {
            TreeNode *x = h->left;
            h->left = x->right;
            x->right = h;
            x->color = h->color;
            h->color = RED;
            return x;
        }
        void FlipeColors(TreeNode *h) {
            h->color = RED;
            h->left->color = BLACK;
            h->right->color = BLACK;
            return;
        }
public:
    RedBlackBST():root(nullptr) {}
    TreeNode* get_root() {
        return root;
    }
    // insert data
    void insert(int data) {
        root = put(root, data);
        root->color = BLACK;
    }



    void inOrder(TreeNode* root) {
      if (root == nullptr) return;
      inOrder(root->left);
      std::cout << root->data << "\t" <<  root->color << std::endl;    
      inOrder(root->right);
    }
    int Min() {
        TreeNode *p = Min(root);
        return p->data;
    }

    TreeNode *Min(TreeNode * node) {
        if (node->left == nullptr) return node;
        return Min(node->left);
    }

    // destruct func
    ~RedBlackBST() {

    }
};

int main() {

    RedBlackBST tree;
    tree.insert(7);
    tree.insert(3);
    tree.insert(1);
    tree.insert(2);
    tree.insert(15);
    tree.insert(9);
    tree.insert(20);

    tree.inOrder(tree.get_root());

    std::cout << tree.Min() << std::endl;
    return 0;
}

