#include<string>
#include<iostream>
#include<vector>
#include<list>
using std::string;
using namespace std;
class Solution {
public:
    int findJudge(int N, vector<vector<int>>& trust) {
        vector< list<int>* > maps(N+1, 0);

        for (int i = 1; i < N+1; i++) {
            maps[i] = new list<int>();
        }
        for (auto vec : trust) {
           maps[vec[1]]->push_back(vec[0]); 
        }

        int judge = 0;
        int num = 0;

        for (int i = 1 ; i < N+1; i++) {
            // rule 2 Everybody (except for the town judge) trusts the town judge.
           if (maps[i]->size() == N-1) {
               bool hasTrust = false; 
               // rule 1  The town judge trusts nobody.
               for (auto vec : trust) {
                  if (vec[0] == i) {
                    hasTrust = true;
                    break;
                  } 
               }
               if (!hasTrust) {
                    num++;
                    judge = i;
               }
           } 
        }

        if (num == 1) {
            return judge;
        }
        return -1;
    }
};
int main() {
    Solution sol;
    vector<vector<int> > test;
    test.push_back(vector<int>{1,3});
    test.push_back(vector<int>{2,3});

    int ret;
    ret = sol.findJudge(3, test); 
    std::cout << ret << std::endl;

    test.clear();
    test.push_back(vector<int>{1,2});
    ret = sol.findJudge(2, test); 
    std::cout << ret << std::endl;

    test.clear();
    test.push_back(vector<int>{1,3});
    test.push_back(vector<int>{2,3});
    test.push_back(vector<int>{3,1});
    ret = sol.findJudge(3, test); 
    std::cout << ret << std::endl;

    test.clear();
    test.push_back(vector<int>{1,2});
    test.push_back(vector<int>{2,3});
    ret = sol.findJudge(3, test); 
    std::cout << ret << std::endl;

    test.clear();
    test.push_back(vector<int>{1,3});
    test.push_back(vector<int>{1,4});
    test.push_back(vector<int>{2,3});
    test.push_back(vector<int>{2,4});
    test.push_back(vector<int>{4,3});
    ret = sol.findJudge(4, test); 
    std::cout << ret << std::endl;
    return 0;
}
