class Solution {
public:
    int jump(vector<int>& nums) {
        //O(n^2);
        int n = nums.size();

        int l = 0 ;
        int r = 0 ;
        int jumps = 0;
        // we will create ranges of jumps 
        

       while( r< n-1){
        int farthest = l;

        //we will traverse through the window and update the new window to be created 
        //which is the farthest and the nearest we can go from the current window 
        // since it is garanteed that we will reach the target l will be always preogresive 
        //therefore l = r+1;
        for(int i = l ; i <= r; i++){
            farthest  = max(farthest , nums[i]+i);
        }

        l = r+1; r = farthest; jumps++;
       }

       return jumps;
    

        
    }
};