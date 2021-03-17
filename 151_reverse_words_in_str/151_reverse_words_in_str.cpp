class Solution {
public:
    string reverseWords(string s) {
        stack<string> words_stack;
        int i = 0;
        while( i < s.length()){
            while(i < s.length() && s[i] == ' '){
                i++;
            }
            if(!(i < s.length())){
                break;
            }
            string word;
            while(i < s.length() && s[i] != ' '){
                word.push_back(s[i]);
                i++;
            }
            cout << word << "\n";
            words_stack.push(word);
        }
        string output;
        while(!words_stack.empty()){
            output.append(words_stack.top());
            words_stack.pop();
            if(!words_stack.empty()){
                output.push_back(' ');
            }
        }
        return output;
    }
};