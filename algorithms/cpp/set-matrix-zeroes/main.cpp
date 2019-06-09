#include<iostream>
#include<vector>
#include <map>

using namespace std;

class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        vector<map<int, int>> ret;

        for (int i = 0; i < m ; i++) {
            for (int j = 0; j < n; j++) {

                if (matrix[i][j] == 0) {
                    map<int, int> mapping;
                    mapping[i] = j;
                    ret.push_back(mapping);
                }
            }
        }

        for (auto mMap : ret) {
            for(auto iter = mMap.begin(); iter != mMap.end(); iter++) {
                std::cout << iter->first << "\t" << iter->second << std::endl;
                for (int i = 0; i < n; i++) {
                    matrix[iter->first][i] = 0;
                }
                  for (int i = 0; i < m; i++) {
                    matrix[i][iter->second] = 0;
                }
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
    vector<vector<int>> matrix;
    vector<int> v1{0,1,2,0};
    vector<int> v2{3,4,5,2};
    vector<int> v3{1,3,1,5};
    matrix.push_back(v1);
    matrix.push_back(v2);
    matrix.push_back(v3);

    sol.setZeroes(matrix);
    printVector(matrix);
    return 0;
}
