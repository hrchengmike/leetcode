#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;
class Solution {
public: 
    //brute force solution O(n^2)
    vector<int> twoSum_brute_force(vector<int>& nums, int target) {
        for(int i = 0; i < nums.size() - 1; i++){
            for(int j = i + 1; j < nums.size(); j++){
                if(target == nums[i] + nums[j]){ 
                    return vector<int> {i, j};
                }
            }
        }
        return vector<int> {-1, -1};
    }
    //hash table implementation O(n) time complexity
    vector<int> twoSum_hash(vector<int>& nums, int target) {
        unordered_map<int, int> map;
        for(int i = 0; i < nums.size(); i++){
            map[nums[i]] = i;
        }
        for(int i = 0; i < nums.size() ; i++){
            auto id = map.find(target - nums[i]);
            if( id != map.end() && id -> second!= i){
                return vector<int>  {i, id -> second};
            }
        }        
        return vector<int> {-1, -1};
    } 

    vector<int> twoSum_hash_faster(vector<int>& nums, int target) {
        unordered_map<int, int> map;
        for(int i = 0; i < nums.size(); i++){
            int complement = target - nums[i];
            if(map.count(complement)){
                return vector<int> {i, map[complement]};
            }
            map[nums[i]] = i;
        }   
        return vector<int> {-1, -1};
    } 
};

int main(){
    vector<int> input = {2, 7, 11, 15};
    int target = 17;
    Solution s;
    vector<int> s1 = s.twoSum_brute_force(input, target);
    vector<int> s2 = s.twoSum_hash(input, target);
    vector<int> s3 = s.twoSum_hash_faster(input, target);
    cout << "index by brute force: " << s1[0] << " , " << s1[1] << endl;
    cout << "index by hash table: " << s2[0] << " , " << s2[1] << endl;
    cout << "index by hash table(faster): " << s3[0] << " , " << s3[1] << endl;
}