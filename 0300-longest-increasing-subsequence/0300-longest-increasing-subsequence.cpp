class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        vector<int> ans;
        ans.push_back(nums[0]);

        for(int i = 1; i < nums.size(); i++){
            if(nums[i] > ans.back()){
                //the longest subsequence has one more member
                ans.push_back(nums[i]);
            }
            else{
                //find the lower bound or the first element that is not less than nums[i]
                int low = lower_bound(ans.begin(), ans.end(), nums[i]) - ans.begin();

                ans[low] = nums[i];
            }
        }
        return ans.size();
    }
};