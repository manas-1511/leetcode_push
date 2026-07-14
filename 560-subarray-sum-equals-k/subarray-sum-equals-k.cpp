class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int , int> prefixSumMap;
        prefixSumMap[0] = 1;
        int sum = 0 ;
        int n = nums.size();
        int cnt = 0;
        for(int i = 0 ; i < n ; i ++){
            sum+=nums[i];


                int rem = sum-k;
                if(prefixSumMap.find(rem) != prefixSumMap.end()){
                    // int index = prefixSumMap[rem];
                    cnt+=prefixSumMap[rem];
                }

            //its  present or not present in the map just add it
            
                prefixSumMap[sum]++;
            
        }

        return cnt;
    }
};