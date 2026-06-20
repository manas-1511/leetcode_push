class Solution {
public:
    int minLights(vector<int>& lights) {
        int n = lights.size();
        vector<int> diff(n , 0);
        for(int i = 0 ; i < n ; i++){
            int v = lights[i]; 
            if(v>0){
                int l = i-v;
                int r = min( n-1,i+v);
                diff[max(l , 0)]++;
                if(r+1<n) diff[r+1]--;

            }
        }

        for(int i =1 ; i < n ; i++){
            diff[i] = diff[i]+diff[i-1];
        }
int cnt = 0;
        for(int i = 0 ; i < n ; i++){
            if(diff[i] == 0){
                cnt++;
                if(i+1 < n) diff[i+1]++;
                if(i+2 < n) diff[i+2]++; 
            }
        }

        return cnt;

            
    }
};