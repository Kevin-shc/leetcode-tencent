class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if(nums.size() <= 0) {
            return 0;
        }
        int last_num = nums[0];
        int ans = 1;
        for(int i = 1; i < nums.size(); i++) {
            if(nums[i] == last_num) {
                continue;
            }
            last_num = nums[i];
            nums[ans] = last_num;
            ans++;
        }
        return ans;
    }
};