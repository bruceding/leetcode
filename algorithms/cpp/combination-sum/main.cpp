#include<iostream>
#include<vector>
#include <map>

using namespace std;

void printVector(const vector<vector<int>> &vec);
class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> ret;
        vector<int> data;
        combination(candidates, ret, data, 0, target, 0);
        return ret;

    }
    // 递归思想
    void combination(vector<int>& candidates, vector<vector<int>>&ret, vector<int> &data, int start, int target, int bak) {
        if (target == 0) {
            ret.push_back(data);
            std::cout << "=0" << std::endl;
            printVector(ret);
            return;
        }
        if (target < 0) {
            return;
        }
        if (start >= candidates.size()) {
            return;
        }
        
        int value = candidates[start];
        int size = target / value ; 
        for (int i =size; i>=0; i--) {
            if (target < i * value) {
                continue;
            }
            for (int j = i; j >0; j--) {
                data.push_back(value);
            }
            combination(candidates, ret, data, start+1, target - i * value, i);
            // 清理数据
            // 递归，前置，后置，条件都比较重要
            for (int k = 0; k < i; k++) {
                data.pop_back();
            }
        }
    }
};
void printVector(const vector<vector<int>> &vec) {
    for (auto v : vec) {
        for (auto i : v) {
            std::cout << i << "\t";
        }
        std::cout << std::endl; 
    }
    std::cout << std::endl; 
}
int main() {
    Solution sol;
    vector<int> r1{2,3,5};
    vector<vector<int>> ret;
    ret = sol.combinationSum(r1, 8);
    printVector(ret);

    vector<int> r2{2,3,6,7};
    ret = sol.combinationSum(r2, 7);
    printVector(ret);

    vector<int> r3{2,3,6,7};
    ret = sol.combinationSum(r3, 1);
    printVector(ret);
    return 0;
}
