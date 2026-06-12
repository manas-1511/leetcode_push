class Solution {
public:
    long long maxTotal(vector<int>& nums, string s) {
        int i = 0 ;
        int n = nums.size();
        long long ans = 0 ;
        while(i< n && s[i] == '1'){
            ans += nums[i];
            i++;
        }

        for(i;  i <n ; i++){
            if(s[i] == '1'){
                long long csm = 0 ;
                csm += 1LL*nums[i-1];
                long long mn = 1LL*nums[i-1];
                while(i < n && s[i] == '1'){
                    csm += 1LL*nums[i];
                    mn = min(mn , 1LL*nums[i]);
                    i++;
                }

                ans+= csm-mn;
            }
        }

        return ans;
    }
};