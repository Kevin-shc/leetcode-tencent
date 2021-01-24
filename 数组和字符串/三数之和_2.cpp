class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> ans;
        int n = nums.size();
        if (n < 3) {
            return ans;
        }

        sort(nums.begin(), nums.end());

        for (int i = 0; i < n - 2; i++) {
            int k = n - 1;
            if(i > 0 && nums[i] == nums[i - 1]) {
                continue;
            }
            for (int j = i + 1; j < n - 1; j++) {
                if(j > i + 1 && nums[j] == nums[j - 1]) {
                    continue;
                }
                while (j < k && nums[j] + nums[k] > -nums[i]) {
                    k--;
                }
                if (k == j) {
                    continue;
                }
                if (nums[j] + nums[k] == -nums[i]) {
                    ans.push_back({nums[i], nums[j], nums[k]});
                }
            }
        }
        return ans;
    }
};