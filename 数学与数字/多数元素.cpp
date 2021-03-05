class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int ans = nums[0];
        int time = 0;
        for (auto num : nums) {
            if(num == ans) {
                time++;
            } else {
                time--;
                if(time == 0) {
                    ans = num;
                    time = 1;
                }
            }
        }
        return ans;
    }
};