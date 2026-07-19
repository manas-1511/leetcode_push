class Solution {
public:
    int minAdjacentSwaps(vector<int>& nums, int a, int b) {
       
        long long  MOD = 1e9+7;
        int n = nums.size();
        long long  res = 0 ;
        long long c1 = 0  , c2 = 0;

        for(int i = 0 ; i < n; i ++){
            if(nums[i] < a){
                res+=(c1+c2)%MOD;
                res%=MOD;
            }

            else if(nums[i] >= a && nums[i] <= b){
                c1++;
                res+=(c2)%MOD;
                res%=MOD;
            }

            else{
                c2++;
                // no need of swaping because it should be already at the right most of the array traversed till now
            }
        }

        return (int)res;
        
        
    }
};