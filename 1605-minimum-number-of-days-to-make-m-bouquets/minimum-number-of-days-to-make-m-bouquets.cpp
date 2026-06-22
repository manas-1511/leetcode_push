class Solution {
public:
    int minDays(vector<int>& bloomDay, int m, int k) {
        int n = bloomDay.size();

        int low = 1;
        int high = *max_element(bloomDay.begin() , bloomDay.end());
        int min_day = 0 ; 
        while(low<=high){
            int mid = (low+high)/2;
            vector<int> done(n, 0);
            for(int i = 0 ; i< n ; i++){
                if(bloomDay[i] <= mid) done[i] = 1;
            }

            int cnt = 0 ;
            int totalB = 0 ;
            for(int i = 0 ; i < n;  i++){
                if(done[i] == 1) cnt++;
                else{
                    //reset the cnt = 0  and check how many bouquets you were able to form , form the prev streak of bouquets
                    totalB += cnt/k;
                    cnt = 0 ;
                }
            }

            totalB += cnt/k;

            if(totalB >= m){
                min_day = mid;
                high = mid-1;
            }

            else{
                //totalBouquets < m(req)
                //therefore have to increase the no. of days to increase the bloomed flowers
                low = mid+1;
            }
        }

        if(min_day == 0) return -1;
        return min_day;

    }
};