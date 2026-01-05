class Solution {
public:
    int jump(vector<int>& nums) {
         int end = 0, start = 0, steps = 0;

         while(end < nums.size() - 1){
            steps++;
            int maxend = end + 1;
            for(int i = start; i <= end; i++){
                if(i + nums[i] == nums.size()){
                    return steps;
                }
                maxend = max(maxend, i + nums[i]);
            }

            start = end + 1;
            end = maxend;
         }
         return steps;
    }
};