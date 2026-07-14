class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
       queue<int> zq;
       int n = nums.size();
       int l = 0;
        int r = 0;
        int zeroes = 0;
        int longest = 0 ;
        for(int r= 0 ; r < n ; r++){
            if(nums[r] == 0){
                zq.push(r);
                zeroes++;
            }

            if(zeroes<=k){
                longest = max(longest , r-l+1);
            }

            else{
                l = zq.front()+1;
                zq.pop();
                zeroes--;

            }


        }

        return longest;
    }
};