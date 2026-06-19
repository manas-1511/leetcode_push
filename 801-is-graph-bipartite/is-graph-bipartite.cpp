class Solution {
public:

    bool dfs(int i , vector<int>& vis , vector<int>& color ,vector<vector<int>>& graph , int parent_color ){
        vis[i] = 1;
        color[i] = !parent_color;
        for(auto& it : graph[i]){

             if(!vis[it]){
                if(!dfs(it , vis , color , graph , color[i])){
                    return false;
                }
             } 
            else{
                if(color[i] == color[it]) return false;
            }
        }

        return true;

    }
    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();
       vector<int> color(n , -1);
       vector<int> vis(n , 0 ); 

       for(int i = 0 ; i < n ; i ++){
        if(!vis[i]){
            if(!dfs(i , vis , color , graph , 1)) return false;
        }
       }

       return true;
    }
};