class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin() , nums.end());
        vector<int> dp(n , 1);
        vector<int> hash(n , 0);
        for(int i = 0 ; i < n;  i++){
            hash[i] = i;
        }
        int maxIndex = 0;
        for(int i = 1 ; i < n ; i ++){
            for(int j = 0 ; j< i ; j++){
                if(nums[i]%nums[j] == 0 ){
                    if(dp[j]+1 > dp[i]){
                        dp[i] = 1+dp[j];
                        hash[i] = j;
                    }
                } 
            }

            if(dp[maxIndex]<dp[i]) maxIndex = i;


        }


        vector<int> ans;
        while(hash[maxIndex] != maxIndex){
            ans.push_back(nums[maxIndex]);
            maxIndex = hash[maxIndex];
        }

        ans.push_back(nums[maxIndex]);
        reverse(ans.begin() , ans.end());
        return ans;

    }
};