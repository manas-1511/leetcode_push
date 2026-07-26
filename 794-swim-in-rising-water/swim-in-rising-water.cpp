class Solution {
public:
bool isValid(int r , int c , int n){
    return (r>=0 && c>= 0 && r<n && c < n);
}
    int swimInWater(vector<vector<int>>& grid) {
        //using dikstra 
        int n = grid.size();
        priority_queue<tuple<int , int , int > , vector<tuple<int , int , int >> , greater<>> pq;
        // max_time , i , j 

        vector<vector<int>> time(n, vector<int>(n , INT_MAX));
        pq.push({grid[0][0] , 0 , 0});
        time[0][0] = grid[0][0];
        vector<int> dr = {0 , 0, 1 , -1};
        vector<int> dc = {1 , -1,0 , 0};
        while(!pq.empty()){
            auto [t , r , c] = pq.top();
            pq.pop();
            if(t > time[r][c]) continue;
            if(r == n-1 && c == n-1){
                // reached the target with min time so return 
                return t;
            }
            
            for(int k = 0 ; k < 4 ; k++){
                int nr = r+dr[k];
                int nc = c + dc[k];
                if(isValid(nr , nc , n)){
                    int newTime = max(grid[nr][nc] , t);
                    if(newTime < time[nr][nc]){
                        time[nr][nc] = newTime;
                        pq.push({newTime , nr , nc});
                    }
                }
            }
        }

        return -1;


    }
};