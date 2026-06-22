class Solution {
public:
    int shipWithinDays(vector<int>& weights, int days) {
        int low = *max_element(weights.begin() , weights.end());
        int high = 0;
        int n = weights.size();
        int ans = 0;
        for(int i = 0 ; i < n ; i ++){
            high += weights[i];
        }
        while(low <= high){
            int mid = (low+high)/2;
            //mid represents the ships weight capacity for each day
            int daysReq = 0 ;
            int sumofW = 0 ;
            for(int i = 0 ; i< n ; i++){
                if(sumofW+weights[i] <= mid)sumofW+=weights[i];
                else{
                    //i am not able to take ith weight into the ship today therefore i am 
                    //going to put this weight inb the next day
                    daysReq++;
                    sumofW = 0+weights[i];

                }


            }

             if(sumofW > 0 ) daysReq++;


             if(daysReq <= days){
                ans = mid;
                //have to increase the reqDays therefore have to decrease the capacity 
                high = mid-1;
             }

             else{
                low = mid+1;
             }

        }

        return ans ;
    }
};