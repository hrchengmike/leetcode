#include <iostream>
using namespace std;
#include <vector>
#include <string>

class Solution {
public:
    int binary_search_l(vector<int>& nums, int target, int l, int h){
        if(l == h) return l;
        int mid = (l+h)/2;
        if(nums[mid] < target){
            return binary_search_l(nums, target, mid+1, h);
        } else { // nums[mid] >= target
            return binary_search_l(nums, target, l, mid);
        }
    }
    int binary_search_h(vector<int>& nums, int target, int l, int h){
        if(l == h) return l-1;
        // when l == 0 l-1 = -1, cannot nums[l-1]
        //if(l == h && nums[l-1] != target) return -1;
        //if(l == h && nums[l-1] == target) return l-1; //l-1 is the highest index
        int mid = (l+h)/2;
        if(nums[mid] <= target){
            return binary_search_h(nums, target, mid+1, h);
        } else { 
            return binary_search_h(nums, target, l, mid);
        }
    }
    vector<int> searchRange(vector<int>& nums, int target) {
        if(nums.size() == 0) return vector<int>{-1, -1};
        int low = binary_search_l(nums, target, 0, nums.size());
        int high = binary_search_h(nums, target, 0, nums.size());
        if(low == nums.size() || nums[low] != target) return vector<int>{-1, -1};
        return vector<int> {low, high};
    }
};

int main(){
    Solution s;
    //cout << "Input a string of numbers: \n";
    vector<int> nums;
    /*
    int input;
    while(cin >> input) nums.push_back(input);
    for (auto i = nums.begin(); i!=nums.end(); i++) {
        cout << *i;
    }
    */
    nums = {1,2,4,4,4,6,7};
    //nums = {1};
    cout << "Input an element to search:\n";
    int target;
    cin >> target;
    //target = 3;

    vector<int> range = s.searchRange(nums, target);
    cout << "Range is: " << range[0] << ", "<< range[1] << endl;
    //cout << "index is: " << s.binary_search(nums, target, 0, nums.size()) << endl;
    return 0;
}