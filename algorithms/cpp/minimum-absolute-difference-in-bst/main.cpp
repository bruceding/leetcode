#include<iostream>

//  Definition for a binary tree node.
  struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode(int x) : val(x), left(NULL), right(NULL) {}
  };
#define MIN(x, y) ((x)<(y)? (x):(y))
class Solution {
public:
    int getMinimumDifference(TreeNode* root) {
         int md = -1;
        if (!root) {
            return md;
        }

        int rVal = -1;
        TreeNode *r = root->right;

        if (r) {
            rVal = r->val;
            while (r->left) {
                rVal = r->left->val;
                r = r->left;
            }
        }

        int lVal = -1;
        TreeNode *l = root->left;

        if (l) {
            lVal = l->val;
            while(l->right) {
                lVal = l->right->val;
                l = l->right;
            }
        }

        if (lVal == -1 && rVal == -1) {
            md = -1;
        } else if (lVal == -1 && rVal != -1) {
            md = rVal - root->val;
        } else if (lVal != -1 && rVal == -1) {
            md = root->val - lVal;
        } else  {
            md = MIN(rVal-root->val, root->val - lVal);
        }

        int lmd;
        lmd = getMinimumDifference(root->left);
        if (lmd != -1) {
            md = MIN(md, lmd);
        }
        int rmd;
        rmd = getMinimumDifference(root->right);
        if (rmd != -1) {
             md = MIN(md, rmd);
        }
        return md;
    }
};

int main() {
    return 0;
}
