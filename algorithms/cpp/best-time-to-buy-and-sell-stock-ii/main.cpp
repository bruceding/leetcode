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
   int maxProfit(vector<int>& prices) {
       int profit = 0;
        
       for (int i = 0; i < prices.size(); i++) {

            int buy = prices[i];

            int sell = 0;
            int index = findSellDay(prices, i, buy, &sell);
            if (index == -1) {
                continue;
            }

            i = index;

            profit += sell - buy;
       }
       return profit;
    }

   int findSellDay(vector<int>& prices, int i, int buy, int *sell) {
       int j = i + 1;
       *sell = buy;
       int ret = -1;
       for (; j < prices.size(); j++) {
           if ( prices[j] < *sell) {
                break;
           }
          if (prices[j] > *sell) {
             ret = j; 
             *sell = prices[j];
             continue;
          } 

          // if (ret != -1 && prices[j] < *sell) {
            // break;
          // }
       }

       return ret;
   } 
};

int main() {
    Solution sol;
    vector<int> prices = {7,6,4,3,1};
    auto ret = sol.maxProfit(prices);
    std::cout << ret << std::endl;

    prices = {7,1,5,3,6,4};
    ret = sol.maxProfit(prices);
    std::cout << ret << std::endl;

    prices = {1,2,3,4,5};
    ret = sol.maxProfit(prices);
    std::cout << ret << std::endl;

    prices = {6,1,3,2,4,7};
    ret = sol.maxProfit(prices);
    std::cout << ret << std::endl;
    return 0;
}
