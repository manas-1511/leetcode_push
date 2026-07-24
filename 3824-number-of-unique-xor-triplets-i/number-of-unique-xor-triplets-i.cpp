class Solution {
public:
    int uniqueXorTriplets(vector<int>& nums) {
        int n = nums.size();
        if(n==1 ) return 1;
        if(n==2) return 2;
        int bitLen = log2(n)+1;
        return  pow(2 , bitLen);


    }
};