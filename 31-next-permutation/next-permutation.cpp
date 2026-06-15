class Solution {
public:

       
    void nextPermutation(vector<int>& nums) {
        int n = nums.size();
        if(n == 1) return;
        int breakpoint = -1;
            //have to find the break point
        for(int i = n-2 ; i >= 0 ; i --){
            if(nums[i] < nums[i+1]){
                breakpoint = i;
                break;

                    
            }
        }
            if(breakpoint == -1){
                sort(nums.begin() , nums.end());
                return;
            }
        int mnIndex =breakpoint+1;
                for(int j = breakpoint+1 ; j < n ; j++){
                    if(nums[j] > nums[breakpoint]){
                        if(nums[mnIndex] > nums[j]){
                            mnIndex = j;
                        }
                    }
                }

                swap(nums[breakpoint] , nums[mnIndex]);

                sort(nums.begin()+breakpoint+1 , nums.end());
    }
};