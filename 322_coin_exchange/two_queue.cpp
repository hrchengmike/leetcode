#include <iostream>
#include <vector>
#include <deque>
#include <algorithm>
#include <map>
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

    int coinChange2(vector<int>& coins, int amount){
        int dict [amount+1] = {};
        return coinChange2_dict(coins, amount, dict);
    }
    int coinChange2_dict(vector<int>& coins, int amount, int dict []) {
        if(amount == 0) return 0;
        if(amount < 0) return -1;
        if(dict[amount]!=0) return dict[amount];

        int min_num = -1;
        for (int i = 0; i < coins.size(); i++){
            int rest = amount - coins[i];
            int num = coinChange2_dict(coins, rest, dict);
            if (num >= 0 && (min_num == -1 || num < min_num)){
                min_num = num;
            } 
        }
        if(min_num!=-1) {
            cout << "memoize amount: "<< amount << " num: "<< min_num+1 << endl;
            dict[amount] = min_num+1;
            return min_num+1;
        } else {
            return -1;
        }
    }
};

int main(){
    Solution s;
    //vector<int> coins = {1, 2, 5, 10, 20, 50};
    //vector<int> coins = {186,419,83,408};
    //test 6249
    vector<int> coins = {83, 186, 408, 419};
    int amount;
    cout << "please input amount:\n";
    cin >> amount;
    cout << "#of coins: "<<s.coinChange2(coins, amount) << endl;
    return 0;
}