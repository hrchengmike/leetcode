#include <iostream>
#include <set>
#include <vector>
using namespace std;

class Solution {
public:
    //using c++ set to implememt, complexity n log n
    int singleNumber(vector<int>& nums) {
        std::set<int> s;
        for(int i = 0; i < nums.size(); i++){
            auto it = s.find(nums[i]);
            if( it != s.end()){
                s.erase(it);
            }else{
                s.insert(nums[i]);
            }
        }
        return *s.begin();
    }

    //xor all elements, xor is associative and commutative
    int singleNumber_bitwise(vector<int>& nums) {
        int a = 0;
        for(int i = 0; i < nums.size(); i++){
            a ^= nums[i]; 
        }
        return a;
    }
};

int main(){
    Solution s;
    vector<int> a = {4, 5, 1, 3, 5, 3, 4, 1, 2};
    cout << "single number: " << s.singleNumber(a) << endl;
    cout << "single number_bitwise : " << s.singleNumber_bitwise(a) << endl;
    return 0;
}