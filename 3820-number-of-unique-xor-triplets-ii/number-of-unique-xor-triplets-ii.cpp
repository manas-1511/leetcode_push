class Solution {
public:
    int uniqueXorTriplets(vector<int>& nums) {
        //brute force is O(n^3)
        //since the constraints nums[i] <= 1500 at most 11 bits 
        // the XOR pairs will also be in  11 bits ie 0 to 2047


        //O(n^2)
         vector<bool> XORpairs(2048 , false);
        int n = nums.size();
        for(int i = 0 ; i < n; i ++){
            for(int j = 0 ; j < n ; j++){
                XORpairs[nums[i]^nums[j]] = true;
            }
        }

        vector<bool> XOR_triplets( 2048 , false);
        for(int k = 0 ; k < n; k++){
            for(int l = 0; l < 2048 ; l++){
                if(XORpairs[l]) XOR_triplets[nums[k]^l] = true;
            }
        }


            int ans = 0 ;
        for(int i = 0 ; i < 2048 ; i++){
            if(XOR_triplets[i]) ans++;
        }

        return ans ;
    }
};