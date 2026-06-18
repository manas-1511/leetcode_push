class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int n = nums.size();
        //edge cases;
        if(n== 1) return 0;
        if(nums[0] > nums[1]) return 0;
        if(nums[n-1] > nums[n-2]) return n-1;

        int low = 0 ;
        int high = n-1;
        while(low<= high){
            int mid =(low + high)/2;
            // if(mid == 0 || mid == n-1) break;
            //if i ahve got the peak
            if(nums[mid] > nums[mid-1] && nums[mid] > nums[mid+1]) return mid;


            else if(nums[mid] > nums[mid+1]){
                high = mid;

            }

            else if(nums[mid] > nums[mid-1] ) low = mid;

            
            // because there are multiple peaks in the graph so we may reach a point of minima in that case 
            // this condition is not necessary if only one peak is present
            else{
                // now i can move wherever i want to because both sides would be having peaks to create this minima

                low = mid+1;
            }
        }

        return -1;


    }
};