#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int search_pivot(vector<int> arr, int low, int high){
        if(high - low < 2) return -1;// no pivots or input array size is 1
        int mid = (high + low)/2;
        // pivot is in the open set (low, high)
        if(arr[mid - 1] > arr[mid]) return mid;
        else if( arr[mid] > arr[low]) return search_pivot(arr, mid, high);
        else return search_pivot(arr, low, mid+1);
    }
    
    int binary_search(vector<int> & nums, int target, int low, int high){
        if(low >= high) return -1;
        int mid = (low + high)/2;
        if(nums[mid] == target) return mid;
        else if(nums[mid] < target) return binary_search(nums, target, mid + 1, high);
        else return binary_search(nums, target, low, mid);
    }
    int search(vector<int>& nums, int target) {
        int pivot = search_pivot(nums, 0, nums.size());
        //not rotated
        if(pivot == -1) return binary_search(nums, target, 0, nums.size());
        //rotated 
        int id1 = binary_search(nums, target, 0, pivot);
        int id2 = binary_search(nums,  target, pivot, nums.size());
        if(id1 != -1) return id1;
        if(id2 != -1) return id2;
        return -1;
    }
};

int main(){
    Solution s;
    vector<int> input = {4, 5, 6, 7, 1, 2, 3};
    cout << s.search(input, 2) << endl;
}