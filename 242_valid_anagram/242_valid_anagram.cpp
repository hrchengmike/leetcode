#include <iostream>
using namespace std;

//return true if two strings are anagrams, assuming only lower case characters 
class Solution {
public:
    bool isAnagram(string s, string t) {
        int count ['z'-'a'+1] = {0};
        for (int i = 0; i <  s.length(); i++) count[s[i]-'a']++;
        for (int i = 0; i <  t.length(); i++) count[t[i]-'a']--;
        for (int i = 0; i < 'z'-'a'; i++) if(count[i]!=0) return false;
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