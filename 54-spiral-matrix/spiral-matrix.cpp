class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n  = matrix[0].size();
        vector<vector<int>> visited( m , vector<int>(n , 0 ));
        int i = 0 , j = 0;
        vector<int> ans ;

        int dr[] = {0 , 1 ,  0 , -1};
        int dc[] = {1 , 0 , -1 , 0};
        // right down left up
        int dir = 0;
        for(int steps = 0 ; steps< m*n ; steps++ ){
            ans.push_back(matrix[i][j]);
            visited[i][j] = 1;

            int next_i = i + dr[dir];
            int next_j = j + dc[dir];

            if(next_i >= m || next_j >= n || next_i < 0 || next_j < 0 || visited[next_i][next_j]){
                dir = (dir+1)%4;
                 next_i = i + dr[dir];
                 next_j = j + dc[dir];
            }

            i = next_i;
            j = next_j;


        }

        return ans ;


    }
};