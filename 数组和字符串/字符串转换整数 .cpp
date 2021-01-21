class Solution {
public:
    int myAtoi(string s) {
        int i = 0;
        int sign_flag = 0;
        int ans = 0;
        while (s[i] == ' ') {
            i++;
        }
        if (s[i] == '-') {
            sign_flag = 1;
            i++;
        } else if (s[i] == '+') {
            i++;
        }
        if (s[i] > '9' || s[i] < '0') {
            return 0;
        } else {
            double ans_d = 0;
            while (i < s.length() && s[i] >= '0' && s[i] <= '9') {
                ans_d = ans_d * 10 +s[i] - '0';
                if (sign_flag) {
                    if (-ans_d < INT_MIN)
                        return INT_MIN;
                } else {
                    if (ans_d > INT_MAX) {
                        return INT_MAX;
                    }
                }
                ans = sign_flag ? (int)(-ans_d) : (int)(ans_d);
                i++;
            }
        }
        return ans;
    }
};