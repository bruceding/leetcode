#include<string>
#include<iostream>
#include<vector>
#include<map>
using std::string;
using namespace std;
class Solution {
public:
    vector<int> countSmaller(vector<int>& nums) {
        vector<int> ret;
        map<int, int> mapping;

        // vector<int> tmp(nums) ;
        // for (int i = 0; i < tmp.size() -1; i++) {
            // for (int j = 0; j < tmp.size() -1 - i; j++) {
               // if (tmp[j] > tmp[j+1]) {
                    // if (mapping.find(tmp[j]) == mapping.end()) {
                        // mapping[tmp[j]] = 1;
                    // } else {
                        // ++mapping[tmp[j]];
                    // }
                    // swap(tmp, j , j+1);
               // }
            // }
        // }
//
        // for (auto n : nums) {
            // std::cout << n << "\t" << mapping[n] << std::endl;
            // if (mapping.find(n) == mapping.end()) {
                // ret.push_back(0);
            // } else {
                // ret.push_back(mapping[n]);
            // }
        // }
        //
        
        for (int i = 0; i < nums.size(); i++) {
            int total = count(nums, nums[i], i+1);
            ret.push_back(total);
        }
        return ret;
    }
    // void swap(vector<int>& nums, int i, int j) {
        // int tmp = nums[i];
        // nums[i] = nums[j];
        // nums[j] = tmp;
    // }

    int count(vector<int>& nums, int val, int i) {
        int total = 0;
        for (int j = i; j < nums.size(); j++) {
            if (nums[j] < val) {
                ++total;
            }
        }
        return total;

    }
};
void printVec(const vector<int>& vec) {
    for (auto v : vec) {
        std::cout << v << " ";
    }
    std::cout << std::endl;
}
int main() {
    Solution sol;
    vector<int> ret;
    vector<int> nums = {5,2,1,6};
    ret = sol.countSmaller(nums);
    printVec(ret);

    nums = {5,2,6, 6, 1};
    ret = sol.countSmaller(nums);
    printVec(ret);
    return 0;
}
