class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
          // if we maintain a prefix sum array that allows us to find whether the prefix sum at an index - k is present in the data structure storing all prefic sums for the array nums so
          unordered_map<int,int> mp;
          mp[0] = 1;


          int count = 0; //count of number of subarrays with the sum k
          int prefixSum = 0;
          for(int i = 0; i < nums.size(); i++){
            prefixSum += nums[i];

            if(mp.find(prefixSum - k) != mp.end()){
                count += mp[prefixSum - k];
            }

            mp[prefixSum]++;
          }
          return count;
    }
};