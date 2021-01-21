class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int m = nums1.size(), n = nums2.size();
        int i = 0, j = 0, k = 0;
        double ans = 0;
        vector<int> nums(m+n);
        while(i + j < m + n) {
            if (i == m) {
                while (j < n) {
                    nums[k++] = nums2[j++];
                }
            } else if (j == n) {
                while (i < m) {
                    nums[k++] = nums1[i++];
                }
            } else if (nums1[i] < nums2[j]) {
                nums[k++] = nums1[i++];
            } else {
                nums[k++] = nums2[j++];
            }
        }
        if ((m + n) % 2) {
            ans = nums[(m + n) / 2];
        } else {
            ans = nums[(m + n) / 2] + nums[(m + n) / 2 - 1];
            ans = ans / 2;
        }
        return ans;
    }
};