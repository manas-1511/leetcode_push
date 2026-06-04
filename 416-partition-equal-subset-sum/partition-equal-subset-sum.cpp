class Solution {

    //dp with space optimization
public:
    
    bool canPartition(vector<int>& nums) {
        int sum = 0 ;
        for(int i = 0 ; i < nums.size() ; i ++){
            sum += nums[i];
        }
        if(sum %2 != 0 ) return false;
        int target = sum/2;
        int n= nums.size();
        vector<int> prev(target+1 , 0) ; 
        prev[0]= 1;
        if(nums[0] <= target ) prev[nums[0]] = 1;
        for(int i = 1 ; i < n ; i++){
            vector<int> curr(target+1 , 0);
            curr[0] = 1;
            for(int j = 1 ; j <= target  ; j++){
                bool notTaken = prev[j];
                bool taken = false;
                if(nums[i] <= j) taken = prev[j-nums[i]];

                curr[j] = notTaken || taken;
            }

            prev = curr;

        }

        return prev[target];
        
    }
};