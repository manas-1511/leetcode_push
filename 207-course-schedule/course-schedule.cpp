class Solution {
public:

   
    bool canFinish(int n, vector<vector<int>>& prerequisites) {
        //bfs
        vector<vector<int>> adj(n);
        vector<int> indegree(n);
        for(auto& e : prerequisites){
            adj[e[1]].push_back(e[0]);
            indegree[e[0]]++;
        }
        vector<int> vis(n , 0);

        

         queue<int> q;
         int cnt = 0;
         for(int i = 0 ; i < n ; i ++){
            if(indegree[i] == 0 ) {
                q.push(i);

            }
         }

         while( !q.empty()){
            int node = q.front();
            q.pop();
            cnt++;
            for(auto& it : adj[node]){
                if(!vis[it]){
                    indegree[it]--;
                    if(indegree[it] == 0)q.push(it);
                    
                }
            }
         }

         if(cnt == n) return true;
         return false;
 


    }
};