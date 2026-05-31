class Solution {
public:

    void traversal(int i , vector<vector<int>>& isConnected , vector<int> & visited , int n ){
        visited[i] = 1;
        
            for(int j = 0 ; j < n ; j ++){
                if(i != j && isConnected[i][j] == 1 && !visited[j] ){
                    traversal(j , isConnected , visited , n);
                }
            }
        
    }
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        int comp = 0 ;
        vector<int> visited(n, 0);
        for(int i = 0 ; i < n ; i ++){
            if(!visited[i]){
                comp++;

                traversal(i , isConnected , visited, n );
            }
        }

        return comp;
    }
};