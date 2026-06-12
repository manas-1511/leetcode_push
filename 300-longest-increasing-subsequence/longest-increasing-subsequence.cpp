class Solution {
public:
//binary search
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans;
        ans.push_back(nums[0]);
        int len = 1; 
        for(int i =1 ; i < n ; i++){
            if(ans.back() < nums[i]){
                ans.push_back(nums[i]);
                len++;
            }

            else{
                //it only works on sorted array
                //it will get the index of the number given and it not presnt then the index of the just greater than 
                int idx = lower_bound(ans.begin() , ans.end() , nums[i])  - ans.begin();
                ans[idx] = nums[i];
            }
        }

        return len;
    }
};