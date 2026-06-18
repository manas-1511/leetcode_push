class Solution {
public:
    int findMin(vector<int>& nums) {
        int n = nums.size();
        int low = 0 ;
        int high = n-1;
        int mn = INT_MAX;
        while(low<=high){
            int mid = (low+high)/2;

            //check which part is sorted
            if(nums[low] <= nums[mid]){
                //that means the left part is sorted
                mn = min(mn , nums[low]);
                low = mid+1;
            }

            else{
                mn = min(mn , nums[mid]);
                high = mid-1;
            }
        }

        return mn;
    
    }
};