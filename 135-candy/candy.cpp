class Solution {
public:
    //brute : S: O(3N)
    //better : S: O(N)
    //opti : S: O(1)
    int candy(vector<int>& ratings) {
        int n = ratings.size();
        int i = 1; 
        int sum = 1 ;
        //no matter what we initially assigned the first child with 1 candy 
        //if the downhill starts form the starting itself than the while loop will handle it
        //sum+=down-peak

        while(i < n){

            // if i have got the flat slope
            while(i < n && ratings[i] == ratings[i-1]){
                // no conditon for the ones having same ratings
                sum+=1 ; i++;
            }
                // going increasing slope
                int peak = 1;
            while(   i <n  && ratings[i-1] < ratings[i]){
                peak++;
                sum+=peak ;
                i++;

            }

            int down = 0;
            while(i < n && ratings[i-1] > ratings[i]){
                down++;
                sum+=down;
                i++;

            }

            if(down+1 > peak){
                sum+=down+1-peak;
            }
        }

        return sum;
    }
};