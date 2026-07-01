class Solution {
public:
    bool canJump(vector<int>& nums) {
        //S: O(1)
        int n = nums.size();

        int maxIndex = 0 ;
        for(int i = 0 ; i < n ; i ++){
            if(i > maxIndex){
                //it can be possible 
                return false;
            }
            maxIndex = max(maxIndex , i+nums[i]);

        }

        return true;

    }
};