#include<iostream>
#include<vector>

using namespace std;
class Solution {
public:
    // 实际也是递归的思想
    int uniquePaths(int m, int n) {
        if(m==1&&n==1) return 1;

        int table[n][m]; //Table of number of paths at each point
        memset(table,0,sizeof(table)); //Initialise everything to 0 ways
        for(int x=1; x<n; x++) table[x][0]=1;
        for(int y=1; y<m; y++) table[0][y]=1; //Set wall paths to 1 path only

        for(int x=1; x<n; ++x)
        for(int y=1; y<m; ++y){
          table[x][y]+=table[x-1][y]+table[x][y-1]; //Add up and left and place in array
        }

        return table[n-1][m-1]; //Return destination paths
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
