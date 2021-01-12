#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int maxProfit_multi_transaction(vector<int>& prices) {
        int max_profit = 0;
        for(int i = 0; i < prices.size() -1 ; i++){
            int new_profit = prices[i+1] - prices[i];
            if(new_profit > 0) max_profit+=new_profit;
        }
        return max_profit;
    }

    int maxProfit_single_transaction(vector<int>& prices) {
        int min_val = INT16_MAX;
        int max_profit = 0;
        for(int i = 0; i < prices.size(); i++){
            if(prices[i] < min_val){
                min_val = prices[i];
            } else if (prices[i] - min_val > max_profit){
                max_profit = prices[i] - min_val;
            }
        }
        return max_profit;
    } 
};

int main(){
    vector<int> prices = {7, 1, 5, 3, 6, 4};
    Solution s;
    cout << "maxProfit_single_transaction: "<< s.maxProfit_single_transaction(prices) << endl;
    cout << "maxProfit_multi_transaction: "<< s.maxProfit_multi_transaction(prices) << endl;
}