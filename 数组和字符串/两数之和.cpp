#include <vector>

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int i = 0;
        vector<int> ans(2);
        while (i < nums.size())
        {
            for(int j = i + 1; j < nums.size(); j++) {
                if(nums[i] + nums[j] == target) {
                    ans[0] = i;
                    ans[1] = j;
                    return ans;
                }
            }
            i++;
        }
        return NULL;
    }
};