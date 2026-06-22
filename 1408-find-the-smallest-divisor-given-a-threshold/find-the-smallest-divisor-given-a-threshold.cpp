class Solution {
public:
    int smallestDivisor(vector<int>& nums, int threshold) {
        int low = 1 ;
        int n = nums.size();
        int high = *max_element(nums.begin() , nums.end());
         // low , high , mid represents the divisor
         int ans = 0 ;
         while(low <= high){
            int mid=(low+high)/2;
            int sum = 0 ;
            for(int i = 0 ; i < n ; i ++){
                //ceil(a/b) = (a-1)/b + 1;
                sum+= (nums[i]-1)/mid + 1;

            }

            if(sum<=threshold){
                ans = mid;
                //now my sum is smaller than the thres. therefore i need to decrease the divisor
                //in order to increase the sum
                high = mid-1;
            }

            else low = mid+1 ;
         }

         return ans;
    }
};