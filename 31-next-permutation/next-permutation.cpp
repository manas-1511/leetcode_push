class Solution {
public:
    //for the brute force method simply create 
    void nextPermutation(vector<int>& nums) {
        next_permutation(nums.begin() , nums.end());
        // vector<vector<int>> all;
        // do{
        //     all.push_back(nums);
        // }while(next_permutation(nums.begin() , nums.end()));

        // for(int i = 0 ; i < all.size() ; i++){
        //     if(all[i] == nums){
        //         //if it is the last permu.
        //         if(i == all.size()-1){
        //             nums =  all[0];
        //             break;
        //         }

        //         else{
        //              nums =  all[i+1];
        //              break;
        //         }
        //     }
        // }
    }
};