class Solution {
public:
    int maxArea(vector<int>& height) {
        int n = height.size();
        if(n <= 1) {
            return 0;
        }
        int max_size = 0;
        for (int i = 0; i < n - 1; i++) {
            if(i > 0 && height[i] < height[i - 1]) {
                continue;
            }
            for (int j = n - 1; j > i; j--) {
                if(max_size > height[i] * (j - i)) {
                    break;
                }
                if(j < n - 1 && height[j] < height[j + 1]) {
                    continue;
                }
                if (max_size < min(height[i], height[j]) * (j - i)) {
                    max_size = min(height[i], height[j]) * (j - i);
                }
            }
        }
        return max_size;
    }
};