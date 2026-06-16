class Solution {

    //first method will be a brute force 
    // creating a new matrix and (i, j ) -----> (j , n-1-i)

    
    //         intution -> every element gets a place from 
// (i,j) ---------(j , n-1-i)
// for that first take the transpose---->(j , i)
// then reverse each row -- > (j , n-1-i)
public:
    void rotate(vector<vector<int>>& matrix) {

        int n = matrix.size();
        //transpose
        for(int i  = 0 ; i < n-1; i++){
            for(int j = i+1 ; j < n ; j++ ){
                swap(matrix[i][j]  , matrix[j][i]);
            }
        }
        //reverse each rows
        for(int i = 0 ; i < n ; i ++ ){
            reverse(matrix[i].begin() , matrix[i].end());
        }
    }
};