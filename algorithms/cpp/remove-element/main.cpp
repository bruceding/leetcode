/*
 * =====================================================================================
 *
 *       Filename:  main.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  2019/02/18 08时46分02秒
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  YOUR NAME (), 
 *   Organization:  
 *
 * =====================================================================================
 */
#include<vector>
#include<iostream>
using std::vector;
class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        for (auto iter = nums.begin(); iter != nums.end();) {
            if(*iter == val) {
                iter = nums.erase(iter);
            } else {
                iter++;
            } 
        } 
        return nums.size();
    }
};
int main() {
    vector<int> num{3,2,2,3};
    Solution sol;

    int len;
    len = sol.removeElement(num, 3);
    for(int i =0; i < len; i++) {
        std::cout << num[i] << "\t"; 
    }
    std::cout << len << std::endl;

    vector<int> num1{0,1,2,2,3,0,4,2};
    len = sol.removeElement(num1, 2);
    for(int i =0; i < len; i++) {
        std::cout << num1[i] << "\t"; 
    }
    std::cout << len << std::endl;
    return 0;
}
