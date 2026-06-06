class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        int sum = 0 ; 
        int n = nums.size();
        for(int i = 0 ; i < n ; i ++) sum+=nums[i];
        if(sum < target) return 0;
        if((sum-target)%2 != 0) return 0;
        int b = (sum-target)/2;
        vector<int> prev(b+1 , 0);
        prev[0] = 1;
        if(nums[0] <= b) prev[nums[0]]++;

        for(int i = 1 ; i < n ; i ++){
            vector<int> curr(b+1 , 0);
            for(int j = 0 ; j <= b ; j++){
                int notTake = prev[j];
                int take = 0;
                if(nums[i] <= j) take = prev[j-nums[i]];
                curr[j] = take+notTake;

            }

            prev = curr;
        }

        return prev[b];
    }
};