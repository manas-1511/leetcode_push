class Solution {
    private:
    int m ;
    int n ;
public:
    void dfs(int i , int j , vector<vector<int>>& vis ,vector<vector<int>>& grid ){
        vis[i][j] = 1;
        vector<pair<int , int>> directions{{0 , 1} , {1 , 0} , {0 , -1} , {-1 , 0}};
        for(auto& dir :directions){
            int ni = i+dir.first;
            int nj = j+dir.second;

            if(ni < m && ni>= 0 && nj < n && nj >= 0 && grid[ni][nj] == 1 && !vis[ni][nj]){
                dfs(ni , nj , vis , grid);
            }
        }
    }
    int numEnclaves(vector<vector<int>>& grid) {
        m = grid.size();
        n =grid[0].size();
        vector<vector<int>> vis(m , vector<int>(n , 0));


        //traverse through the boundaries

        for(int i = 0 ; i < m ; i ++){
            if(grid[i][0] == 1 && !vis[i][0]){
                dfs(i , 0 , vis , grid);
            }

            if(grid[i][n-1] == 1 && !vis[i][n-1]){
                dfs(i , n-1 , vis , grid);
            }
        }

         for(int j = 0 ; j < n ; j ++){
            if(grid[0][j] == 1 && !vis[0][j]){
                dfs(0 , j , vis , grid);
            }

            if(grid[m-1][j] == 1 && !vis[m-1][j]){
                dfs(m-1 , j , vis , grid);
            }
        }

        int cnt  = 0 ;
        for(int i = 1 ; i < m-1 ; i++){
            for(int j = 1 ; j < n-1 ; j++){
                if(grid[i][j] == 1 && !vis[i][j]) cnt++;
            }
        }

        return cnt;





        


    }
};