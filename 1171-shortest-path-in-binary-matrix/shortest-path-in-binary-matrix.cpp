class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n = grid.size();
        priority_queue<vector<int>, vector<vector<int>> , greater<vector<int>>> pq;
        vector<vector<int>> dp(n , vector<int>(n , INT_MAX));
        if(grid[0][0] == 0) {
            dp[0][0] = 1;
            pq.push({1 , 0 , 0});
        }
        //dis , i , j;
        
        while(!pq.empty()){
            auto temp = pq.top();
            int dis = temp[0];
            int x = temp[1];
            int y = temp[2];
            pq.pop();

            if(dis > dp[x][y]) continue;

            for(int i = -1 ; i<=1 ; i++ ){
                for(int j = - 1; j <= 1 ; j++){
                    int nx = x+i;
                    int ny = y+j;

                    if(nx >= 0 && nx < n && ny < n && ny >= 0 && grid[nx][ny] == 0 ){
                        if(dis+1 < dp[nx][ny]){
                            dp[nx][ny] = dis+1;
                            pq.push({dis+1 , nx , ny});
                        }
                    }
                }
            }
        }

        if(dp[n-1][n-1] == INT_MAX) return -1;
        return dp[n-1][n-1];

    }
};