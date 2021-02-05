#include <iostream>
#include <vector>
#include <math.h>
using namespace std;
class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        int n = nums.size();
        //resulting vector
        vector<vector<int>> v;
        //convert to binary, deciding whether to include an element
        for(int j = 0; j < pow(2,n); j++){
            vector<int> vi = {};
            //convert to binary
            int count = 0;
            int i = j;
            while(i > 0){
                if( i%2 == 1) vi.push_back(nums[count]);
                count ++;
                i = i/2;
            }
            v.push_back(vi);
        }
        return v;
    }
};

int main(){
    vector<int> input = {1, 2, 3};
    Solution s;
    auto result = s.subsets(input);
    cout << "all subsets of [1, 2, 3]: \n";
    for(auto v : result){
        cout << "[";
        for(auto num : v){
            cout << num << " ";
        }
        cout << "]\n";
    }
}