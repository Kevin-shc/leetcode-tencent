class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> ans;
        if (nums.size() < 3) {
            return ans;
        }

        // 带注释部分为优化后的代码部分，之前的代码运行大数组时会超时
        // 对数组进行排序，为以后减少循环次数做准备工作
        sort(nums.begin(), nums.end());

        int i = 0, j = 1, k =2, n = nums.size();
        // int repeat_flag = 0;
        // 由于内部已有返回条件，因此不再需要while处进行判断
        // while(k < nums.size()) {
        while(1) {
            // 由于跳过了重复的部分，因此不再需要比较重复
            // int m = 0;
            // while(m < ans.size()) {
            //     // 由于数组是有序的，因此获得的答案也是有序的，比较时不需要再考虑乱序情况
            //     if( (ans[m][0] == nums[i] && ans[m][1] == nums[j]) // || 
            //      /* (ans[m][0] == nums[i] && ans[m][2] == nums[j]) ||
            //         (ans[m][1] == nums[i] && ans[m][2] == nums[j]) ||
            //         (ans[m][1] == nums[i] && ans[m][0] == nums[j]) || 
            //         (ans[m][2] == nums[i] && ans[m][0] == nums[j]) ||
            //         (ans[m][2] == nums[i] && ans[m][1] == nums[j]) */) {
            //         repeat_flag = 1;
            //         break;
            //     }
            //     m++;
            // }
            // if(repeat_flag) {
            //     repeat_flag = 0;
            // } else {
                // while(nums[i] + nums[j] +nums[k] != 0) {
                // 由于是有序数组，因此循环到第三个数大于0时即可停止
            // 合并到一起减少一次条件判断
            while(nums[j] +nums[k] <= -nums[i]) {
                if(nums[j] +nums[k] == -nums[i]) {
                    ans.push_back({nums[i], nums[j], nums[k]});
                    break;
                } else if (k >= n - 1) {
                    break;
                }
                k++;
            }
            // 将三数相加变为两数相加
            // if(k < n &&  nums[j] +nums[k] == -nums[i]) {
            //     // 修改ans添加的方式
            //     // vector<int> one_ans(3);
            //     // one_ans[0] = nums[i];
            //     // one_ans[1] = nums[j];
            //     // one_ans[2] = nums[k];
            //     ans.push_back({nums[i], nums[j], nums[k]});
            // }
            // }
            // 旧的循环函数，现在增加跳过相同数字的功能
            // if(++j < nums.size() - 1) {
            //     k = j + 1;
            // } else {
            //     i++;
            //     j = i + 1;
            //     k = i + 2;
            // }
            if(i == n - 3)
                return ans;
            int a = nums[j];
            // while(++j < nums.size() - 1 && a == nums[j]) ;
            while(j < n) {
                if(a != nums[j])
                    break;
                j++;
            }
            if(j < n - 1) {
                k = j + 1;
            } else {
                a = nums[i];
                // while(++i < nums.size() - 2 && a == nums[i]) ;
                while(i < n) {
                    if(a != nums[i])
                        break;
                    i++;
                }
                // 循环大于数组长度时直接返回答案
                // 当最小的数都大于0时直接返回结果
                if(i >= n - 2 || nums[i] > 0)
                    return ans;
                if (nums[i] + nums[i+1] > 0 || nums[i] + nums[i+1] +nums[i+2] > 0)
                    return ans;
                j = i + 1;
                k = i + 2;
            }
        }
        return ans;
    }
};