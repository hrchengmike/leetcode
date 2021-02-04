#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;
class Solution {
public:
    int fourSumCount(vector<int>& A, vector<int>& B, vector<int>& C, vector<int>& D){
        unordered_map<int, int> map;
        int n = A.size();
        int count = 0;
        for(int i = 0; i < n ; i++){
            for(int j = 0; j < n; j++){
                if(map.count(A[i] + B[j])){
                    map[A[i] + B[j]] += 1;
                } else{
                    map[A[i] + B[j]] = 1;
                }        
            }
        }
        for(int i = 0; i < n ; i++){
            for(int j = 0; j < n; j++){
                if(map.count(-C[i] - D[j])){
                    count += map[-C[i] - D[j]];
                }
            }
        }
        return count;
    }
    int fourSumCount2(vector<int>& A, vector<int>& B, vector<int>& C, vector<int>& D){
        unordered_map<int, int> map;
        for(auto a : A){
            for(auto b : B){
                map[a+b]++;
            }
        }
        int count = 0;
        for(auto c : C){
            for(auto d : D){
                auto it = map.find(0-c-d);
                if(it != map.end()){
                    count += it->second;   
                }
            }
        }
        return count;
    }
};

int main(){
    Solution s;
    vector<vector<int>> v = {{-1,-1},{-1,1},{-1,1},{1,-1}};
    cout << "count: " << s.fourSumCount(v[0], v[1], v[2], v[3] ) << endl;
    cout << "count: " << s.fourSumCount2(v[0], v[1], v[2], v[3] ) << endl;
    return 0;
}