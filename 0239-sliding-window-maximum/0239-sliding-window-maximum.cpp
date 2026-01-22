class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        deque<int> dq;

        int n = nums.size();
        for(int i = 0 ; i < k; i++){
            while(!dq.empty() && nums[i] >= nums[dq.back()]){
                dq.pop_back();
            }
            dq.push_back(i); //insert the index of the largest element in the first window of k size in nums
        }
        vector<int> ans; //to store the maximum element of each window of k size
        for(int i = k; i < n; i++){
            ans.push_back(nums[dq.front()]);
            while(!dq.empty() && dq.front() <= i - k ){ //out of window
                dq.pop_front();
            }
            while(!dq.empty() && nums[i] >= nums[dq.back()]){
                dq.pop_back(); //remove all smaller elements from the deque
            }
            dq.push_back(i);
        }
        ans.push_back(nums[dq.front()]);
        return ans;
    }
};