class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int> L_num(n);
        vector<int> R_num(n);
        L_num[0] = 1;
        for(int i = 1; i < n; i++) {
            L_num[i] = L_num[i - 1] * nums[i - 1];
        }
        R_num[n - 1] = 1;
        for(int i = n - 2; i >= 0; i--) {
            R_num[i] = R_num[i + 1] * nums[i + 1];
        }
        for(int i = n - 1; i >= 0; i--) {
            L_num[i] = L_num[i] * R_num[i];
        }
        return L_num;
    }
};