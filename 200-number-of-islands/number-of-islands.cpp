class Solution {
public:
    void traversal(vector<vector<char>>& grid ,vector<vector<int>> &visited , int i , int j, int m , int n  ){
        visited[i][j] = 1;
        //left
        if(j-1>=0 && j-1<n && grid[i][j-1] =='1' && !visited[i][j-1]){
            traversal(grid , visited , i , j-1 ,m , n );
        }
        //right 
        if(j+1>= 0 && j+1 <n && grid[i][j+1] == '1' && !visited[i][j+1]){
            traversal(grid , visited , i ,j+1 , m , n );
        }

        //down
        if(i-1 >= 0 && i-1 < m && grid[i-1][j] == '1' && !visited[i-1][j]){
            traversal(grid , visited , i-1 ,j , m , grid[i-1].size());
        }

        //up
        if(i+1 >= 0 && i+1 < m && grid[i+1][j] == '1' && !visited[i+1][j]){
            traversal(grid , visited , i+1 ,j , m , grid[i+1].size());
        }
        
    }
    int numIslands(vector<vector<char>>& grid) {
        int m = grid.size();
        vector<vector<int>> visited(m , vector<int>(grid[0].size() , 0));
        int count = 0 ;
        for(int i = 0 ; i < m ; i ++){
            int n = grid[i].size();
            for(int j = 0 ; j< n; j++){
                if(grid[i][j] == '1' && !visited[i][j]){
                    count++;
                    traversal(grid , visited , i , j  , m , n );
                }
            }
        }

        return count;
    }
};