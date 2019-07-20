#include<string>
#include<iostream>
#include<vector>
#include<list>
#include<unordered_map>
using std::string;
using namespace std;
class Solution {
public:
    vector<int> gardenNoAdj(int N, vector<vector<int>>& paths) {
        vector<int> ret;
        vector<int> flowers{-1, -1, -1, -1};
        vector<list<int>*> maps(N+1, 0);
        // garden index of flower
        int relation[N+1];
        for (int i = 1; i <=N; i++) {
            maps[i] = new list<int>();
            relation[i] = -1;
        }

        for (auto &vec : paths) {
            maps[vec[0]]->push_back(vec[1]);
            maps[vec[1]]->push_back(vec[0]);
        }
        vector<int> tmp;
        for (int i = 1; i <=N; i++) {
            tmp = flowers;
            for (auto g : *(maps[i])) {
               if (relation[g] != -1) {
                   tmp[relation[g] -1] = 1;
               } 
            }

            for (int j = 0; j < 4; j++) {
                if (tmp[j] == -1) {
                    relation[i] = j + 1;
                    ret.push_back(j+1);
                    break;
                }
            }
        }
        return ret;
    }
};
void print(vector<int>& vec) {
    for (auto v : vec) {
        std::cout << v << "\t" ;
    }
    std::cout << std::endl;
}
int main() {
    Solution sol;
    vector<vector<int> > test;
    test.push_back(vector<int>{1,2});
    test.push_back(vector<int>{2,3});
    test.push_back(vector<int>{3,1});

    vector<int> ret;
    ret = sol.gardenNoAdj(3, test); 
    print(ret);

    test.clear();
    test.push_back(vector<int>{1,2});
    test.push_back(vector<int>{3,4});
    ret = sol.gardenNoAdj(4, test); 
    print(ret);

    test.clear();
    test.push_back(vector<int>{1,2});
    test.push_back(vector<int>{2,3});
    test.push_back(vector<int>{3,4});
    test.push_back(vector<int>{4,1});
    test.push_back(vector<int>{1,3});
    test.push_back(vector<int>{2,4});
    ret = sol.gardenNoAdj(4, test); 
    print(ret);

    return 0;
}
