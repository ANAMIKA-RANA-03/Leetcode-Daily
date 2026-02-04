class Solution {
public:
    int minimumCost(vector<int>& nums) {
        int sum = nums[0];
        int maxi1 = 0, maxi2 = 0;
        int val1 = INT_MAX, val2 = INT_MAX;
        for(int i = 1; i < nums.size(); i++){
            if(nums[i] < val1) {
                maxi1 = i;
                val2 = val1;
                val1 = nums[i];
            }
            if(nums[i] < val2 && i != maxi1) {
                maxi2 = i;
                val2 = nums[i];
            }
        }
        return sum + val2 + val1;
    }
};