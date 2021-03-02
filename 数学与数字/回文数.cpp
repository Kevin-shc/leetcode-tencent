class Solution {
public:
    bool isPalindrome(int x) {
        int reverseNum = 0;
        if(x < 0 || (x % 10 == 0 && x != 0)) {
            return false;
        }
        while(x > reverseNum) {
            int a = x % 10;
            reverseNum = reverseNum * 10 + a;
            x = x / 10;
        }
        return x == reverseNum || x == reverseNum / 10;
    }
};