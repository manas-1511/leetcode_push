class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        vector<int> t = nums;
        sort(t.begin() , t.end());
        t.erase(unique(t.begin() , t.end()) , t.end());

        int m = nums.size();
        int n = t.size();

        vector<int> prev(n+1 , 0);
        for(int i = 1; i <= m ; i++){
            vector<int> curr(n+1 , 0);
            for(int j = 1; j <= n ;j ++){
                if(t[j-1] == nums[i-1]){

                    curr[j] = 1+prev[j-1];
                }




                else{
                    curr[j] = max(prev[j] , curr[j-1]);
                }
            }

            prev = curr;
            
        }

        return prev[n];


    }
};