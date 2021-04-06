#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    vector<int> partitionLabels(string S) {
        vector<int> hash(26, -1);
        //Hash table to store the last index of each letter
        for(int i = 0; i < S.length(); i++){
            hash[S[i]-'a'] = i;
        }
        int cur = -1;
        vector<int> result;
        
        while(true){
            int start = cur + 1;
            //reaches end of array
            if(start == S.length()) break;
            int end = hash[S[start]-'a'];       
            int cur_l = 0;
            while(cur < end){
                cur++;
                cur_l++;
                if(hash[S[cur]-'a'] > end){
                    end = hash[S[cur]-'a'];
                }
            }
            result.push_back(cur_l);
        }
        return result;   
    }
};

int main(){
    Solution s;
    vector<int> result;
    result = s.partitionLabels("ababcbacadefegdehijhklij");
    for(auto len:result){
        cout << len << " ";
    }
    cout << endl;
}