class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int n = piles.size();
        
        int low = 1 ; 
        int high = *max_element(piles.begin() , piles.end());
        int ans = high;
        while(low <= high){
            int mid = (low+high)/2;
            long long t = 0;
            for(int i = 0 ; i < n ; i++){
                t+=1LL*ceil((double)piles[i]/mid);
            }
            //if i am taking too much time to eat then increase the rate k
            if(t > h) low = mid+1;
            else if(t <= h){
                ans =mid;
                high = mid-1;
            }
        }

        return ans;
    }
};