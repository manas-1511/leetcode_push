class Solution {
public:

    int helper(int r , int c , int m , int n , vector<vector<int>>& vis){
        if(vis[r][c] != -1) return vis[r][c];
        int right = 0 ; 
        int down = 0 ; 
        if(r+1 >= 0 && r+1 < m && c >= 0 && c< n ){
            down = helper(r+1 , c, m , n , vis);
        }

        if(r >= 0 && r < m && c+1 >= 0 && c+1< n ){
            right = helper(r , c+1, m , n , vis);
        }

        return vis[r][c] = right + down;

    }
    int uniquePaths(int m, int n) {
        vector<vector<int>> vis(m , vector<int>(n, -1));
        vis[m-1][n-1] = 1;
        return helper(0 , 0 , m , n , vis);
    }
};