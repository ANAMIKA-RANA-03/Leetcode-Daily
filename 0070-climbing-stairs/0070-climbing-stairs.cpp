class Solution {
public:
    int climbStairs(int n) {
        if(n <= 3) return n; // any no of steps less than 3 or equal to 3 has exact same no of ways to reach the top as the no of steps

        int prev1 = 2; //two ways to climb if no of steps is 2
        int prev2 = 3; //three ways to climb if the no of steps is 3

        int curr = 0;
        for(int i = 4; i <= n; i++){
            curr = prev1+ prev2;
            prev1 = prev2;
            prev2 =curr;
        
        }
        return curr;
    }   
};