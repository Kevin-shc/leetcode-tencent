class Solution {
public:
    string multiply(string num1, string num2) {
        string ans("0");
        if(num1[0] == '0' || num2[0] == '0') {
            return ans;
        }
        // 开始计算
        // 从num2的低位开始
        for (int i = num2.length() - 1; i >= 0; i--) {
            // 将值为0的位跳过
            if(num2[i] == '0') {
                continue;
            }
            // 循环加num2[i]-1次
            string num(num1);
            for (int j = 1; j < num2[i] - '0'; j++) {
                num = string_plus(num, num1);
            }
            // 在值的末尾加若干个0
            for (int k = num2.length() - i - 1; k > 0; k--) {
                num.push_back('0');
            }
            ans = string_plus(ans, num);
        }
        return ans;
    }

    string string_plus(string num1, string num2) {
        string ans;
        string temp_num;
        if(num1.size() > 0 && num1[0] == '0') {
            return num2;
        }
        if (num2.size() > 0 && num2[0] == '0') {
            return num1;
        }
        if (num1.size() > num2.size()) {
            int i = num1.size() - 1, j = num2.size() - 1;
            int carry_flag = 0;
            while(j >= 0) {
                temp_num = ans;
                if(carry_flag) {
                    carry_flag = (num1[i] - '0' + num2[j] - '0' + 1) / 10;
                    ans = (num1[i] - '0' + num2[j] - '0' + 1) % 10 + '0';
                } else {
                    carry_flag = (num1[i] - '0' + num2[j] - '0') / 10;
                    ans = (num1[i] - '0' + num2[j] - '0') % 10 + '0';
                }
                // ans.push_back(temp_num);
                ans = ans + temp_num;
                j--;
                i--;
            }
            while(i >= 0) {
                temp_num = ans;
                if(carry_flag) {
                    carry_flag = (num1[i] - '0' + 1) / 10;
                    ans = (num1[i] - '0' + 1) % 10 + '0';
                } else {
                    carry_flag = (num1[i] - '0') / 10;
                    ans = (num1[i] - '0') % 10 + '0';
                }
                // ans.push_back(temp_num);
                ans = ans + temp_num;
                i--;
            }
            if(carry_flag) {
                temp_num = ans;
                ans = '1';
                // ans.push_back(temp_num);
                ans = ans + temp_num;
            }
        } else {
            int i = num1.size() - 1, j = num2.size() - 1;
            int carry_flag = 0;
            while(i >= 0) {
                temp_num = ans;
                if(carry_flag) {
                    carry_flag = (num1[i] - '0' + num2[j] - '0' + 1) / 10;
                    ans = (num1[i] - '0' + num2[j] - '0' + 1) % 10 + '0';
                } else {
                    carry_flag = (num1[i] - '0' + num2[j] - '0') / 10;
                    ans = (num1[i] - '0' + num2[j] - '0') % 10 + '0';
                }
                // ans.push_back(temp_num);
                ans = ans + temp_num;
                j--;
                i--;
            }
            while(j >= 0) {
                temp_num = ans;
                if(carry_flag) {
                    carry_flag = (num2[j] - '0' + 1) / 10;
                    ans = (num2[j] - '0' + 1) % 10 + '0';
                } else {
                    carry_flag = (num2[j] - '0') / 10;
                    ans = (num2[j] - '0') % 10 + '0';
                }
                // ans.push_back(temp_num);
                ans = ans + temp_num;
                j--;
            }
            if(carry_flag) {
                temp_num = ans;
                ans = '1';
                // ans.push_back(temp_num);
                ans = ans + temp_num;
            }
        }
        return ans;
    }
};