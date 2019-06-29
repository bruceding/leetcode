#include<iostream>
#include<vector>

using namespace std;
class Solution {
public:
    int uniquePaths(int m, int n) {
        int x = 0; 
        int y = 0;
        int total = 0;
        right(x, y, m, n, &total);
        
        return total;
    }
    
    void right(int x, int y, int m, int n, int *total) {
        if (x >= n || y >= m) {
            return;
        }
        if (x == n-1 && y == m-1) {
            *total +=1;
            return;
        }
        
        if (y == m -1) {
            if (x < n -1) {
                down(x+1, y, m, n, total);
            }
            return;
        }
        
        right(x, y+1, m, n, total);
        down(x+1, y, m, n, total);
    }
    
    void down(int x, int y, int m, int n, int *total) {
        if (x >= n || y >= m) {
            return;
        }
        if (x == n-1 && y == m-1) {
            *total +=1;
            return;
        }
        
        if (x == n-1) {
            if (y < m -1) {
                right(x, y+1, m, n, total);
            }
            return;
        }
        down(x+1, y, m, n, total);
        right(x, y+1, m, n, total);
    }
    
    
};
int main() {
    Solution sol;
    int ret;
    ret = sol.uniquePaths(3, 2);
    std::cout << ret << std::endl;
    ret = sol.uniquePaths(7, 3);
    std::cout << ret << std::endl;
    ret = sol.uniquePaths(7, 1);
    std::cout << ret << std::endl;
    ret = sol.uniquePaths(3, 1);
    std::cout << ret << std::endl;
    ret = sol.uniquePaths(23, 12);
    std::cout << ret << std::endl;
    return 0;
}
