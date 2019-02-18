#include<vector>
#include<iostream>
using std::vector;
class Solution {
public:
    vector<int> sumEvenAfterQueries(vector<int>& A, vector<vector<int>>& queries) {
        vector<int> result;
        for (auto &vec : queries) {
            int index = vec[1];
            if (index <= A.size() -1) {
                A[index] += vec[0];
                result.push_back(calcEvenNumbers(A));
            }
        }
        return result;
    }

    int calcEvenNumbers(const vector<int>& vec) {
        int total = 0;
        for (auto val : vec) {
            if (isEven(val)) {
                total += val;
            } 
        }
        return total;
    }
    bool isEven(int num) {
        return num % 2 == 0;
    }
};

int main() {
    vector<int> A{1,2,3,4};
    vector<vector<int>> queries{{1,0}, {-3,1}, {-4,0}, {2,3}};
    Solution sol;
    auto result = sol.sumEvenAfterQueries(A, queries);
    for (auto v : result) {
    std::cout << v << std::endl;
    }
    return 0;
}
