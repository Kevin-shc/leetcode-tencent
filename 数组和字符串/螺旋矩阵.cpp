class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> ans;
        if(matrix.size() == 0 || matrix[0].size() == 0) {
            return ans;
        }
        int top = 0, bottom = matrix.size() - 1, left = 0, right = matrix[0].size() - 1;
        while(1) {

            for(int i = left; i <= right; i++) {
                ans.push_back(matrix[top][i]);
            }
            top++;
            if(top > bottom) {
                return ans;
            }

            for(int i = top; i <= bottom; i++) {
                ans.push_back(matrix[i][right]);
            }
            right--;
            if (right < left) {
                return ans;
            }

            for(int i = right; i >= left; i--) {
                ans.push_back(matrix[bottom][i]);
            }
            bottom--;
            if(top > bottom) {
                return ans;
            }

            for(int i = bottom; i >= top; i--) {
                ans.push_back(matrix[i][left]);
            }
            left++;
            if (right < left) {
                return ans;
            }
        }
        return ans;
    }
};