#include <iostream>
using namespace std;
#include <vector>
#include <string>

int find_element(vector<int>& nums, int target, int l, int h, string option){
    if (h-l==0 ){
        if (nums[l] == target) {
            return l;
        }
        else {
            return -1;
        }
    } 

    if (h-l==1){
        if (nums[l]==nums[h]){
            if (nums[l] == target) {
                 if(option == "upper") {
                     return h;
                 } else {
                     return l;
                 }
            }
            else {
                return -1;
            }   
        }
        if(option == "upper" && nums[l]==target) return l;
        if(option == "lower" && nums[h]==target) return h;
        return -1;
    } 
    int m = (l+h)/2;
    if(nums[m] < target) return find_element(nums, target,m, h, option);
    else if (nums[m] > target) return find_element(nums, target,l, m, option); 
    else {
        if(option == "upper") return find_element(nums, target,m, h, option);
        else return find_element(nums, target,l, m, option); 
    }
}
vector<int> searchRange(vector<int>& nums, int target) {
    vector<int> range;
    if(nums.size()==0) {
        range = {-1,-1};
        return range;
    }
    range = {find_element(nums, target, 0, nums.size()-1, "lower"), find_element(nums, target, 0, nums.size()-1, "upper")};
    return range;
}
int main(){
    cout << "Input a string of numbers: \n";
    vector<int> nums;
    /*
    int input;
    while(cin >> input) nums.push_back(input);
    for (auto i = nums.begin(); i!=nums.end(); i++) {
        cout << *i;
    }
    */
    nums = {1,2,3,4,4,4,5,6,7};
    cout << "Input an element to search:\n";
    int target;
    //while(cin >> target);
    target = 4;
    vector<int> range = searchRange(nums, target);
    cout << "Range is: " << range[0] << ", "<< range[1] << endl;
    return 0;
}
