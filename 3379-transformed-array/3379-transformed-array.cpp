class Solution {
public:
    vector<int> constructTransformedArray(vector<int>& nums) {
        int n = nums.size();
        vector<int> res(n,0);

        for(int i = 0; i < n; i++){
            if(nums[i] > 0){
                int index = (i + nums[i]) % n + n;
                res[i] = nums[index  % n];
            }
            else{
                int index = (i - abs(nums[i])) % n + n;
                res[i] = nums[index % n];
            }
        }
        return res;
    }
};