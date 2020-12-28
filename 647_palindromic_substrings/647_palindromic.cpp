#include <iostream>
#include <string>
using namespace std;

int count_palindromic_sub(string s){
    int count = 0;
    for (int len = 1;len <= s.length(); len++){
        for(int start = 0; start < s.length()+1-len; start++){
            string sub (s,start,len);
            //length of substring if even
            bool flag = true;
            for(int i = 0; i < len/2; i++){
                if(sub[i]!=sub[len - 1 -i]){
                    flag = false;
                    break;
                }
            }
            if(flag == true) {
                cout << sub << " is palindromic\n";
                count ++;
            }
        }
    }
    return count;
}


int main(){
    string s = "aaa";
    cout << "The string is: " << s << endl;
    int count = count_palindromic_sub(s);
    cout << "in total "<< count << " substring\n";
    return 0;
}