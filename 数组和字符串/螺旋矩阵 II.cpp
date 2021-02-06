class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> ans(n, vector<int>(n));
        int top = 0, bottom = n - 1, left = 0, right = n - 1;
        int num = 1;
        while(1) {
            for(int i = left; i <= right; i++) {
                ans[top][i] = num++;
            }
            top++;
            if(top > bottom) {
                return ans;
            }
            
            for(int i = top; i <= bottom; i++) {
                ans[i][right] = num++;
            }
            right--;

            for(int i = right; i >= left; i--) {
                ans[bottom][i] = num++;
            }
            bottom--;

            for(int i = bottom; i >= top; i--) {
                ans[i][left] = num++;
            }
            left++;
            if(left > right) {
                return ans;
            }
        }
        return ans;
    }
};