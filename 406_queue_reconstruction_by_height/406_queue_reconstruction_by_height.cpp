#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<vector<int>> reconstructQueue(vector<vector<int>>& people) {
        // Larger h and smaller k has higher priority, won't affect later people once fixed 
        sort(people.begin(), people.end(), [](vector<int>& a, vector<int>& b){
            if(a[0] != b[0]){
                return a[0] > b[0];
            } else {
                return a[1] < b[1];
            }
        });
        for(int i = 0; i < people.size(); i++){
            //Similar to insertion sort, insert the people to right position
            int count = people[i][1];
            for(int j = i; j > count; j--){
                swap(people[j], people[j-1]);
            }
        }
        return people;
    }
};

int main(){
    vector<vector<int>> input = {{7,0}, {4,4}, {7,1}, {5,0}, {6,1}, {5,2}};
    Solution s;
    vector<vector<int>> output = s.reconstructQueue(input);
    cout << "output: \n";
    for(auto person:output){
        for(auto e:person){
            cout << e << " ";
        }
        cout << endl;
    }
}