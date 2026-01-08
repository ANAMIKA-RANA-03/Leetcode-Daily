class Solution {
    int solve(vector<vector<int>> &dp, int n, int m,vector<int> &nums1, vector<int> &nums2, int i, int j){
        if( i == n || j == m) return INT_MIN / 2;

        if(dp[i][j] != INT_MIN) return dp[i][j];

        int t = nums1[i] * nums2[j];

        int result = max( {t + solve(dp,n,m,nums1, nums2,i+1,j + 1), t, solve(dp,n,m,nums1, nums2,i+1,j), solve(dp,n,m,nums1, nums2,i,j+1)});

        return dp[i][j] = result;
    }
public:

    int maxDotProduct(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size();
        int m = nums2.size();
        vector<vector<int>> dp(n, vector<int>(m, INT_MIN));

        return solve(dp,n,m,nums1, nums2, 0,0);
    }
};