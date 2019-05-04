/*
 * Given n, how many structurally unique BST's (binary search trees) that store values 1 ... n?
 */

class Solution {
public:
    int numTrees(int n) {
         if (n == 0) return 1;
        if (n == 1) return 1;
        if (n == 2) return 2;

        // when root = 1  or  root = n  
        int total = 2 * numTrees(n-1);
        for (int i = 2; i <=n-1 ;i++) {
            // when root = i, cal left node, right node , then  multiply
            total += numTrees(i-1) * numTrees(n -i);
        }

        return total;
    }
};


