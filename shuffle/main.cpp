#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> shuffle(vector<int>& nums, int n) {
        vector<int> ans(2*n);
        for (int i=0;i<=n-1;i++){
            ans[i*2]=nums[i];
            ans[i*2+1]=nums[i+n];
        }
        return ans;
    }
};

int main(){
    vector<int> input;
    input.push_back(2);
    input.push_back(5);
    input.push_back(1);
    input.push_back(3);
    input.push_back(4);
    input.push_back(7);
    int n=input.size()/2;
    Solution sol;
    vector<int> output;
    //output.reserve(2*n);
    output=sol.shuffle(input,n);
    for (int j=0;j<2*n;j++) cout<<output[j];
    cout<<endl;
    return  0;
}