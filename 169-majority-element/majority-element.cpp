class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int , int> mpp;
        for(int i = 0 ; i < n ; i ++){
            mpp[nums[i]] ++;
        }

        int ans = -1;
        int mx = 0 ;
        for(auto& it : mpp){
            if(mx < it.second){
                mx = it.second;
                ans = it.first;
            }
        }

        return ans;

    }
};