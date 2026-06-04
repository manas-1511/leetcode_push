class Solution {
public:
    void printf(int idx ,vector<int>& nums , vector<vector<int>> &ans , vector<int> &currarray  , int n ){
        if(idx == n){
            ans.push_back(currarray);

            return;
        }
        currarray.push_back(nums[idx]);
        printf(idx+1 , nums ,ans ,currarray , n);
        currarray.pop_back();

        printf(idx+1 , nums ,ans ,currarray , n);
        
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ans ;
        vector<int> currarray;
        printf(0 , nums , ans , currarray , nums.size());
        return ans;
    }
};