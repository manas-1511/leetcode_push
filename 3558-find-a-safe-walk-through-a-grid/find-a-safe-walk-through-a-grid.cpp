class Solution {
public:
    bool findSafeWalk(vector<vector<int>>& grid, int health) {
        //since it is a weighted undirected graph apply djikstra 
        int m = grid.size();
        int n = grid[0].size();
        //min- heap pq
        priority_queue<vector<int> , vector<vector<int>> , greater<vector<int>>> pq;
        //dis  , i , j;
        pq.push({grid[0][0] , 0 , 0});
        vector<vector<int>> dis(m , vector<int>(n , INT_MAX));
        vector<vector<int>> dr = {{0,1} , {-1,0} , {0,-1} , {1,0}};
        while(!pq.empty()){
            vector<int> temp = pq.top();
            pq.pop();


            int d = temp[0] ; int i = temp[1] ; int j = temp[2];
            
            if(d > dis[i][j]) continue; //outdated node no need ; we already covered a shorter distance till here
            for(int k = 0 ; k < 4 ; k++){
                int ni = i+dr[k][0];
                int nj = j+dr[k][1];

                if(ni>= 0 && ni<m && nj < n && nj>= 0 ){
                    if(dis[ni][nj] > d+grid[ni][nj]){
                        dis[ni][nj] = d+grid[ni][nj];
                        if(ni == m-1 && nj == n-1){
                            //if the target has been reached no need to push it
                            if(dis[ni][nj] < health) return true;
                            return false;
                        }
                        else pq.push({dis[ni][nj] , ni, nj});
                        
                    }
                }
            }
        }


        return false ;



    }
};