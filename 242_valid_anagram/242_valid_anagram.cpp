#include <iostream>
using namespace std;

class Solution {
public:
    bool isAnagram(string s, string t) {
        int count [128] = {0};
        for (int i = 0; i <  s.length(); i++) count[s[i]]++;
        for (int i = 0; i <  t.length(); i++) count[t[i]]--;
        for (int i = 'a'; i <= 'z'; i++) if(count[i]!=0) return false;
        return true;
    }
};

int main(){
    Solution s;
    string a = "anagram";
    string b = "nagaram";
    int result = s.isAnagram(a,b);
    cout << "result: "<< result << endl;
    return 0;
}