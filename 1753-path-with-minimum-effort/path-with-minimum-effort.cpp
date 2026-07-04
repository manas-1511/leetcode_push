class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& h) {

        int m = h.size();
        int n = h[0].size();
        vector<vector<int>> dis(m , vector<int>( n , INT_MAX));
        priority_queue<vector<int> , vector<vector<int>> , greater<vector<int>>> pq;
        dis[0][0] = 0;
        pq.push({0 , 0, 0});

        vector<int> dr = {0 , 0 , 1 , -1};
        vector<int> dc = {1 , -1 , 0 , 0};

        while(!pq.empty()){
            vector<int> temp = pq.top();
            pq.pop();
            int e = temp[0] ; int r = temp[1]; int c = temp[2];
                //remopve the outdated nodes having higger distances 
            // if(e > dis[r][c]) continue;
            if(r == m-1 && c == n-1){
                //target has been achieved with min effort because it has came out of the pq 
                //therefore no other path is left uncovered which has shorter effort to rach the dis
                return dis[r][c];
            }

            for(int i = 0 ; i < 4 ; i ++){
                int nr = r+dr[i];
                int nc = c+dc[i];

                if(nr>= 0 && nr<m && nc >=0 && nc < n ){
                    int current_effort = abs(h[r][c] - h[nr][nc]);
                    int max_current_effort = max(current_effort , e);

                    if(max_current_effort < dis[nr][nc]){
                        //even if it is equal i should not push it
                        //even if the target has been reached then also i should push it 
                        //because this may be not the optimall path i have covered

                        dis[nr][nc] = max_current_effort;
                        pq.push({dis[nr][nc] , nr , nc});
                    
                    }
                        
                }
            }
    }   

        return -1;



        
    }
};