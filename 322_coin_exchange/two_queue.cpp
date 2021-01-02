#include <iostream>
#include <vector>
#include <deque>
#include <algorithm>
using namespace std;

class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        if(amount==0) return 0;
        if(find(coins.begin(), coins.end(), amount)!=coins.end()){
            return 1;
        } 
        //use q to store all nodes of the tree
        //level to store the respective level of the node
        deque<int> q;
        deque<int> level;
        q.push_back(amount);
        level.push_back(1);
        while(!q.empty()){
            int cur_amount = q.front();
            q.pop_front();
            int cur_level = level.front();
            level.pop_front();
            //cout << "cur_amount: "<<cur_amount<<" cur_level: "<<cur_level<<endl;
            for (int i = 0; i< coins.size(); i++){
                int next_amount = cur_amount-coins[i];
                //cout << "next_amount: "<<next_amount<<endl;
                if(next_amount<0) continue;
                if(find(coins.begin(), coins.end(), next_amount)!=coins.end()){
                    return cur_level+1;
                } 
                q.push_back(next_amount);
                level.push_back(cur_level+1);
            }
        }
        return -1;
    }
};

int main(){
    Solution s;
    vector<int> coins = {1, 2, 5};
    int amount;
    cout << "please input amount:\n";
    cin >> amount;
    cout << "#of coins: "<<s.coinChange(coins, amount) << endl;
    return 0;
}