class Solution {
public:
    int findStu(vector<int>& nums , int mid){
        int students  = 1; 
        int currentSum = 0;
        for(int i = 0 ; i < nums.size() ; i++){
            if(currentSum + nums[i] <= mid){
                //add to current subarray 
                currentSum += nums[i];
            }

            else{
                students++;
                currentSum = nums[i];
            }
        }

        return students;
    }
    int splitArray(vector<int>& nums, int k) {
        int n = nums.size();
        int low = *max_element(nums.begin() , nums.end());
        int high = accumulate(nums.begin(), nums.end(), 0);

        while(low<=high){
            int mid = (low+high)/2;
            int student = findStu(nums , mid);
            //if the maximum number of pages is too high then students will be less
            //take the ex of high = sumofallelemt , subarray = 1
            if(student > k ){
                low = mid+1;
            }

            else high = mid-1;
        }

        return low ;
    }
};