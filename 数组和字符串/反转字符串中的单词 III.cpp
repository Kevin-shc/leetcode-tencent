class Solution {
public:
    string reverseWords(string s) {
        string ans;
        int i = 0;
        while(i < s.length()) {
            if(i > 0) 
                ans += ' ';
            string temp_s;
            while(i < s.length() && s[i] != ' ') {
                temp_s.push_back(s[i]);
                i++;
            }
            ans = ans + reverseString(temp_s);
            i++;
        }
        return ans;
    }

    string reverseString(string s) {
        char c;
        int i = 0, j = s.length() - 1;
        while(i < j) {
            c = s[i];
            s[i] = s[j];
            s[j] = c;
            i++;
            j--;
        }
        return s;
    }
};