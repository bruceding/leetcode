#include<iostream>
#include<vector>
#include <map>
#include <cmath>

using namespace std;

void printVector(const vector<vector<int>> &vec);
class Solution {
public:
    vector<int> grayCode(int n) {
        
        if (n == 0) {
            return {0};
        }
        auto vects = create(n);
        vector<int> ret;
        for (auto v : vects) {
            ret.push_back(cal(v));
        }
        return ret;
    }
    
    // 递归，找逻辑关系
    vector<vector<int>> create(int n) {
        if (n == 1) {
            return {{0}, {1}};
        }
        
        vector<vector<int>> pre = create(n-1);
        
        int size = pre.size();
        vector<vector<int>> ret;
        
        for (int i = 0; i < size; i++) {
            auto tmp = pre[i];
            tmp.insert(tmp.begin(), 0);
            ret.push_back(tmp);
        }
        for (int i = size-1; i >=0; i--) {
            auto tmp = pre[i];
            tmp.insert(tmp.begin(), 1);
            ret.push_back(tmp);
        }
        
        return ret;
    }
    
    int cal(vector<int>& vec) {
        int total = 0;
        int j = 0;
        for (int i = vec.size()-1; i>=0; i--, j++) {
            total +=  vec[i] * pow(2, j);
        }
        
        return total;
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
    sol.grayCode(2);
    sol.grayCode(3);
    return 0;
}
