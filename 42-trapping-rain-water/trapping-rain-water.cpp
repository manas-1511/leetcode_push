class Solution {
public:
    int trap(vector<int>& nums) {
        //T(3N)
        //S = O(2N)
        int n = nums.size();
        if(n==1) return 0;
        vector<int> prefix(n , 0);
        vector<int> suffix( n , 0 );
        prefix[0] = nums[0];
        for(int i = 1 ; i < n ; i++){
            prefix[i] = max(nums[i] , prefix[i-1]);
        }

        suffix[n-1] = nums[n-1];
        for(int i = n-2 ; i >= 0 ; i--){
            suffix[i] = max(nums[i] , suffix[i+1]);
        }
        int total  = 0;

            //leftMax , rightMax 
        for(int i = 0 ; i < n ; i++){
            if(min(prefix[i] , suffix[i]) - nums[i] > 0){
                total+=min(prefix[i] , suffix[i]) - nums[i];
            }
        }

        return total;
    }
};