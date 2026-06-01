class Solution {
public:
    void dfs(vector<vector<int>>& image, int sr, int sc, int color , vector<vector<int>> &visited  ,int originalcolor){
        int m = image.size();
        int n = image[0].size();
        visited[sr][sc] = 1 ; 
        if(originalcolor == image[sr][sc]){
            image[sr][sc] = color;
        }
        else return;
        for(int delrow = -1 ; delrow <= 1; delrow++){
            for(int delcol = - 1 ; delcol <= 1; delcol++){
                if(delcol != 0 && delrow != 0 ) continue;
                int row = sr + delrow;
                int col = sc + delcol;

                if(row >= 0 && row < m && col >= 0 && col < n && visited[row][col] != 1){
                    dfs(image , row , col , color , visited , originalcolor);
                }

            }
        }
    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int m = image.size();
        int n = image[0].size();
        int originalcolor = image[sr][sc];
        vector<vector<int>> visited(m , vector<int>( n , 0));

        dfs(image , sr , sc ,color , visited  , originalcolor);
        return image;

    }
};