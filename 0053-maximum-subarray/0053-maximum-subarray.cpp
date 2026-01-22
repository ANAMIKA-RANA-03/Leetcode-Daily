class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int ans = nums[0];
        int start = nums[0];

        for(int i = 1; i < nums.size(); i++){
            int x = nums[i];
            start = max(start + x, x);
            ans = max(ans, start);
        }
        return ans;
    }

};