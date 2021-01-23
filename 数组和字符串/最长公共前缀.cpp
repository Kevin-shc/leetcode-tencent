class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string ans;
        if (strs.size() == 0)
            return ans;
        if (strs.size() == 1)
            return strs[0];
        int i = 0, j = 0, num_str = strs.size(), len_str = strs[0].length();
        while (1)
        {
            for (i = 1; i < num_str; i++) {
                if (j >= strs[0].length() || j >= strs[i].length() || strs[0][j] != strs[i][j]) {
                    return ans;
                }
            }
            ans += strs[0][j];
            j++;
        }
        return ans;
    }
};