class Solution {
public:
    int longestPalindrome(string s) {
        vector<int> hash('z'-'A'+1, 0);
        for(char c:s) hash[c - 'A']++;
        bool single = false;
        int ans = 0;
        for(auto count:hash){
            if(count % 2 != 0) single = true;
            //maximum even number smaller or equal to count
            ans += (count/2)*2;
        }
        return ans + single;
    }
};