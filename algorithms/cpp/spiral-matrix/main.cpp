#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> ret;
        int m = matrix.size();
        if (m < 1) {
            return ret;
        }
        int n = matrix[0].size();
        int total = m * n;

        int s_m = 0;
        int s_n = 0;

        int i = 0;
        while (i < total ) {
            for (int j = s_n; j < n ; j++) {
                ret.push_back(matrix[s_m][j]);
                ++i;
            }
            s_m++;
            for (int j =s_m; j< m; j++) {
                ret.push_back(matrix[j][n-1]);
                ++i;
            }
            n--;
            // m= 1, shoud check
            if (i >= total) {
                break;
            }
            for (int j = n-1; j >=s_n;j--) {
                 ret.push_back(matrix[m-1][j]);
                ++i;
            }
            m--;
              for (int j = m-1; j >=s_m;j--) {
                 ret.push_back(matrix[j][s_n]);
                ++i;
            }
            s_n++;
        }

        return ret;
    }
};
void printVector(const vector<int> &vec) {
    for (auto i : vec) {
        std::cout << i << "\t";
    }
    std::cout << std::endl; 
}
int main() {
    Solution sol;
    vector<int> ret;
    vector<vector<int>> matrix;
    vector<int> v1{1,2,3,4};
    matrix.push_back(v1);

    ret = sol.spiralOrder(matrix);
    printVector(ret);
    return 0;
}
