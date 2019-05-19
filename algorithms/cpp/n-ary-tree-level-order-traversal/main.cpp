/*
 * =====================================================================================
 *
 *       Filename:  main.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  2019/05/19 09时44分04秒
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  YOUR NAME (), 
 *   Organization:  
 *
 * =====================================================================================
 */

#include <vector>
using std::vector;
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};


class Solution {
public:
    vector<vector<int>> levelOrder(Node* root) {
         vector<vector<int>> ret;
        if (!root) {
            return ret;
        }
       
        ret.push_back({root->val});
        vector<Node*> childs = root->children;
        while ( childs.size() > 0) {
            vector<int> temp;
            vector<Node*> childsTemp;
            for (auto child: childs) {
                temp.push_back(child->val);
                childsTemp.insert(childsTemp.end(), child->children.begin(), child->children.end());
            }
            ret.push_back(temp);
            childs = childsTemp;
            
        }
        return ret;
    }
};
int main() {
    return 0;
}
