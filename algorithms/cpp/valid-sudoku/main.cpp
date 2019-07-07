#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        int row = board.size();
        int col = board[0].size();
        
        for (int i = 0; i < row; i++) {
            vector<int> tmp(10, 0) ;
            for (int j = 0; j < col; j++) {
                if (board[i][j] != '.') {
                    auto index = board[i][j] - '0';
                    if (tmp[index] >0) {
                        return false;
                    } else {
                        tmp[index] = index;
                    }
                }
            }
        }
        
        for ( int j=0; j < col; j++) {
            vector<int> tmp(10, 0) ;
            for (int i = 0; i < row; i++) {
                if (board[i][j] != '.') {
                    auto index = board[i][j] - '0';
                    if (tmp[index] >0) {
                        return false;
                    } else {
                        tmp[index] = index;
                    }
                }
            }
        }
        
        for (int i = 0; i < row; i += row/3) {
            for (int j = 0; j < col; j+= col/3) {
                vector<int> tmp(10, 0) ;
                for (int x = i; x < i+3; x++) {
                    for (int y = j; y < j + 3; y++) {
                        if (board[x][y] != '.') {
                            auto index = board[x][y] - '0';
                            if (tmp[index] >0) {
                                return false;
                            } else {
                                tmp[index] = index;
                            }
                        }

                    }
                }
                
            }
        }
        return true;
    }
};
void printVector(const vector<int> &vec) {
    for (auto v : vec) {
        std::cout << v << "\t";
    }
    std::cout << std::endl; 
}
int main() {
    vector<char> v1{'5','3','.','.','7','.','.','.','.'};
    vector<char> v2{'6','.','.','1','9','5','.','.','.'};
    vector<vector<char>> board;
    board.push_back(v1);
    board.push_back(v2);
    Solution sol;
    auto ret = sol.isValidSudoku(board);
    std::cout << ret << std::endl;
    return 0;
}
