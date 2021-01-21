class Solution {
public:
    string longestPalindrome(string s) {
        string ans;
        int ans_len = 0;
        int i = 0;
        // 字符串为奇数长度时
        while (i < s.length()) {
            int distance = 1;
            while (i - distance >= 0 && i + distance < s.length()) {
                if (s[i-distance] == s[i+distance]) {
                    distance++;
                } else {
                    break;
                }
            }
            if (2*distance-1 > ans_len) {
                ans_len = 2*distance - 1;
                string str(s, i - distance + 1, ans_len);
                ans = str;
            }
            i++;
        }
        // 字符串为偶数长度时
        i = 0;
        while (i < s.length()) {
            if(i + 1 < s.length() && s[i] == s[i+1]) {
                int distance = 1;
                while (i - distance >= 0 && i + distance + 1 < s.length()) {
                    if (s[i-distance] == s[i+distance+1]) {
                        distance++;
                    } else {
                        break;
                    }
                }
                if (2 * distance > ans_len) {
                    ans_len = 2 * distance;
                    string str(s, i - distance + 1, ans_len);
                    ans = str;
                }
            }
            i++;
        }
        return ans;
    }
};