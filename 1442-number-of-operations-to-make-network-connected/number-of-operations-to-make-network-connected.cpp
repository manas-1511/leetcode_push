class Solution {
public:
    void dfs(int i  , vector<int>& vis , vector<vector<int>>& adj){
        vis[i] = 1;
        for(auto& it: adj[i]){
            if(!vis[it]) dfs(it , vis , adj);
        }

        
    }
    int makeConnected(int n, vector<vector<int>>& connections) {
        vector<vector<int>> adj(n);
        for(auto& e: connections){
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }
                int comp = 0 ;
            vector<int> vis(n, 0);
        for(int i = 0 ; i < n ; i++){
            if(!vis[i]){
                dfs(i , vis , adj);
                comp++;
            }
        }

        if(connections.size() < n-1) return -1;
        return comp-1;
    }
};