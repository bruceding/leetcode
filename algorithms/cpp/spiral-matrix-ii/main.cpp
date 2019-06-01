#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
     vector<vector<int>> generateMatrix(int n) {
        int x_s = 0;
        int y_s = 0;
        int x = n;
        int y = n;
        int total = x * y;

        vector<vector<int>> ret;

        for (int i = 0; i < n ; i++) {
            vector<int> v(n);
            ret.push_back(v);
        }
        int i = 1;
        while (i <= total) {
            for (int j = y_s; j < y; j++) {
                ret[x_s][j] = i++;
            }
            x_s++;

            for (int j = x_s; j < x; j++) {
                ret[j][y-1] = i++;
            }
            y--;

            for (int j= y-1; j >= y_s ; j--) {
                ret[x-1][j] = i++;
            }
            x--;
            for (int j= x-1; j >= x_s ; j--) {
                ret[j][y_s] = i++;
            }
            y_s++;
        }
        return ret;
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
    vector<vector<int>> ret;
    ret = sol.generateMatrix(3);
    printVector(ret);

    ret = sol.generateMatrix(1);
    printVector(ret);

    ret = sol.generateMatrix(2);
    printVector(ret);

    ret = sol.generateMatrix(4);
    printVector(ret);
    return 0;
}
