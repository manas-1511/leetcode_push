class Solution {
public:
    int maximumProduct(vector<int>& nums) {
        // int pos = 0;
        // int neg = 0 ;
        // int zero = 0 ;
        int n = nums.size();
        // if(n== 3) return nums[0]*nums[1]*nums[2];
        // for(int i = 0 ; i < nums.size() ; i++){
        //     if(nums[i] < 0) neg++;
        //     else if(nums[i] > 0 ) pos ++;
        //     else zero++;
        // }
        sort(nums.begin() , nums.end());
        // if(pos == 0) return nums[n-1]*nums[n-2]*nums[n-3];
        // if(pos == 0 && zero >0) return 0;
        // if(pos==1) return nums[n-1]*nums[0]*nums[1];
        // if(pos==2) return nums[0]*nums[1]*nums[n-1];
        return max( nums[n-1]*nums[n-2]*nums[n-3] , nums[0]*nums[1]*nums[n-1]);

    }
};