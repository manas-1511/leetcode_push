class Solution {
    private:
    void bfs(vector<pair<int , int>> &rotted_initially,vector<vector<int>>& grid ,vector<vector<int>>& visited ){
        int m = grid.size() ; 
        int n = grid[0].size();

        queue<pair<int ,int>> q;
        for(int k = 0 ; k < rotted_initially.size() ; k ++){
            int i = rotted_initially[k].first;
            int j = rotted_initially[k].second;
            visited[i][j] = 1;
            q.push({i , j});
        }
        
        while(!q.empty()){
            bool rotted = false;
            int size = q.size();
            for(int k = 0 ; k < size ; k++ ){

            
            int row = q.front().first;
            int col = q.front().second;
            q.pop();

            for(int delrow = -1 ; delrow <=1 ;  delrow++){
                for(int delcol = -1 ; delcol <= 1; delcol++){
                    if(delcol != 0 && delrow != 0) continue;
                    int nrow = row + delrow;
                    int ncol = col + delcol;

                    if(nrow >= 0 && ncol >= 0 && nrow < m && ncol < n && 
                    grid[nrow][ncol] == 1 && !visited[nrow][ncol]){
                        rotted = true;
                        visited[nrow][ncol] = 1;
                        grid[nrow][ncol] = 2;
                        q.push({nrow , ncol});
                    }
                }
            }
            }

            if(rotted == true) time++;
        }
    }
public:
    int time = 0;
    int orangesRotting(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        vector<vector<int>> visited(m , vector<int>( n , 0 ));
        vector<pair<int , int>> rotted_initially;
        for(int i = 0 ; i < m ; i ++){
            for(int j = 0 ; j < n ; j ++){
                if(!visited[i][j] && grid[i][j] == 2){
                    rotted_initially.push_back({i , j});
                }
            }
        }

        bfs(rotted_initially , grid ,visited);

        for(int i = 0 ; i < m ; i ++){
            for(int j = 0 ; j < n ; j ++){
                if(grid[i][j] == 1) return -1;
            }
        }



        return time;
    }
};