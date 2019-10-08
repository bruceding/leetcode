#include <vector>
#include <iostream>
using namespace  std;

void printVector(const vector<int> &vec) {
    for (auto v : vec) {
        std::cout << v << "\t";
    }
    std::cout << std::endl; 
}
class Solution {
public:
    vector<int> addToArrayForm(vector<int>& A, int K) {
        vector<int> b;

        int i = K;
        while(true) {
            if (i /10 == 0) {
                b.insert(b.begin(), i);
                break;
            }

            b.insert(b.begin(), i%10);
            i = i /10;
        }

        vector<int> ret;

        int min = A.size() > b.size() ? b.size() : A.size();

        int d = 0;
        for (i = 0; i <min ; i++) {
            int j = A[A.size()-i -1];
            int k = b[b.size()-i -1];
            ret.insert(ret.begin(), (j+k+d)%10);
            d = (j + k + d) / 10;
        }

        if (A.size() > min) {
            for (i = A.size() - min - 1; i >= 0; i--) {
                int j = A[i];
                ret.insert(ret.begin(), (j+d)%10);
                d = (j + d) / 10;
            }

        } else if (b.size() > min) {
            for (i = b.size() - min -1; i >=0; i--) {
                int j = b[i];
                ret.insert(ret.begin(), (j+d)%10);
                d = (j + d) / 10;
            }

        }
        if (d > 0) {
            ret.insert(ret.begin(), d);
            d = 0;
        }
        return ret; 
    }

};

int main() {
    Solution sol;
    vector<int> A = {1,2,0,0};
    auto ret = sol.addToArrayForm(A,  34);
    printVector(ret);
    A = {2,7,4};
    ret = sol.addToArrayForm(A,  181);
    printVector(ret);
    A = {2,1,5};
    ret = sol.addToArrayForm(A,  806);
    printVector(ret);
    A = {9,9,9,9,9,9,9,9,9,9};
    ret = sol.addToArrayForm(A,  1);
    printVector(ret);
    return 0;
}
