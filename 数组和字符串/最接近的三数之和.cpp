class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        int n = nums.size();
        int ans = 0, diff = INT_MAX;
        sort(nums.begin(), nums.end());
        for (int i = 0; i < n -2; i++) {
            if(i > 0 && nums[i] == nums[i - 1]) {
                continue;
            }
            for (int j = i + 1; j < n - 1; j++) {            
                if(j > i + 1 && nums[j] == nums[j-1]) {
                    continue;
                }
                int k = n - 1;
                int a = INT_MAX;
                while (j < k) {
                    if(abs(nums[i] + nums[j] + nums[k] - target) > a) {
                        break;
                    }
                    a = abs(nums[i] + nums[j] + nums[k] - target);
                    if(a < diff) {
                        diff = a;
                        ans = nums[i] + nums[j] + nums[k];
                    }
                    k--;
                }
            }
        }
        return ans;
    }
};