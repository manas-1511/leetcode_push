class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int m = mat.size();
        int n = mat[0].size();
        vector<vector<int>> dis(m , vector<int>(n , INT_MAX));
        vector<vector<int>> vis(m , vector<int>(n , 0));

                    queue<vector<int>> q;
        for(int i =0 ; i <m ; i ++){
            for(int j = 0 ; j< n ; j++){
                if(mat[i][j] == 0){
                    vis[i][j] = 1;
                    dis[i][j] = 0;
                    q.push({i , j , 0});

                }
            }
        }
            vector<int> dr = {0, 0 , -1 , 1};
            vector<int> dc = {1 , -1 , 0 , 0};
        while(!q.empty()){
            auto temp = q.front();
            int r = temp[0];
            int c = temp[1];
            int d = temp[2];
            q.pop();

            
            for(int i = 0 ; i < 4 ; i++){
                int nr  = r+dr[i];
                int nc = c+dc[i];

            if(nr >=0 && nc>=0 && nr<m && nc < n  && d+1 < dis[nr][nc]){
                
                dis[nr][nc] = d+1;
                q.push({nr , nc , d+1});

            }
            }


        }

        return dis;

    }
};