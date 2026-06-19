class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int m = mat.size();
        int n = mat[0].size();
        vector<vector<int>> dis(m , vector<int>(n , 0));
        vector<vector<int>> visited(m , vector<int>(n , 0));
        queue<vector<int>> q;

        for(int i = 0 ; i < m ; i++){
            for(int j = 0 ; j < n ; j++){
                if(mat[i][j] == 0){
                    visited[i][j] = 1;

                    q.push({i , j , 0});
                }
            }
        }

        while(!q.empty()){
            int sri = q.front()[0];
            int srj = q.front()[1];
            int d = q.front()[2];
            dis[sri][srj] = d;
            q.pop();
            
            //right , down , left  , up
            vector<int> dr = {0 , 1 , 0 , -1};
            vector<int> dc = {1 , 0 , -1 ,0};

            for(int i = 0 ; i < 4 ; i++ ){
                int next_i = sri+dr[i];
                int next_j = srj + dc[i];

                if(next_i < m && next_j < n && next_i >= 0 && next_j >=0 && !visited[next_i][next_j] ){
                    visited[next_i][next_j] = 1;
                    q.push({next_i , next_j , d+1});
                }
            }
        }

        return dis;

    }
};