class Solution {
    private:
    int m ;
    int n ;
public:

    void dfs(int i  , int j , vector<vector<int>> &vis ,vector<vector<char>>& board ){
        vis[i][j] = 1;
        //right , down  , left  , up
        vector<pair<int , int>> directions = {{0, 1} , {1 , 0} , {0 , -1} , {-1 , 0}};
        for(auto& dir : directions){
            int next_i = i+dir.first;
            int next_j = j+dir.second;
            if(next_i < m && next_j < n && next_i >= 0 && next_j >= 0 
            && board[next_i][next_j] == 'O' &&  !vis[next_i][next_j]){
                dfs(next_i , next_j , vis  , board);
            }
        }

    }
    void solve(vector<vector<char>>& board) {
         m = board.size();
         n = board[0].size();
        vector<vector<int>> vis( m , vector<int>(n , 0));
        for(int i = 0 ; i < m ; i ++){
           if(board[i][0] == 'O' && !vis[i][0]){
             dfs(i , 0 , vis , board);
           }

           if(board[i][n-1] == 'O' && !vis[i][n-1]){
             dfs(i , n-1 , vis , board);
           }
        }


        for(int j = 0 ; j <n ; j++){
            if(board[0][j] == 'O' && !vis[0][j]){
             dfs(0 , j , vis , board);
           }

           if(board[m-1][j] == 'O' && !vis[m-1][j]){
             dfs(m-1 , j , vis , board);
           }
        }


        for(int i = 1 ; i < m-1 ; i++){
            for(int j = 1 ; j < n -1; j++){
                if(!vis[i][j] && board[i][j] == 'O'){
                    board[i][j] = 'X';
                }
            }
        }

           

    }
};