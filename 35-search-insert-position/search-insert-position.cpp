class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        //find the lower bound
        int n = nums.size();
        int low = 0 ; 
        int high = n-1;
        int ans = n ;
        while(low <= high){
            int mid = (low+high)/2;
            if(target<= nums[mid]){
                ans = mid;
                high = mid-1;
            }

            else low = mid+1;
        }

        return ans;

    }
};