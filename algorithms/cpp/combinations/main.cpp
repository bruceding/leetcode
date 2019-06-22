#include<iostream>
#include<vector>
#include <map>

using namespace std;

class Solution {
public:
    vector<vector<int>> combine(int n, int k) {
         vector<vector<int>> aResult;
        vector<int> aData(k, 0);

        int i = 0;

        // 还是比较巧妙
        while (aData[0] <= (n - k + 1)) {

            aData[i]++;
            // 这个 -1 操作 很重要
            if (aData[i] > n) {
                i -= 1;
            } else if (i == (k - 1)) {
                aResult.push_back(aData);
            } else {
                i += 1;
                aData[i] = aData[i - 1];
            }
        }

        return aResult;
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
    auto ret = sol.combine(4, 2);
    printVector(ret);

    ret = sol.combine(4, 3);
    printVector(ret);

    ret = sol.combine(5, 2);
    printVector(ret);

    ret = sol.combine(1, 1);
    printVector(ret);

    ret = sol.combine(4, 1);
    printVector(ret);
    return 0;
}
