class Solution {
public:
    // topo sort
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {

        int n = graph.size();
        // to store the reverse of the edges
        vector<vector<int>> adj(n);
        vector<int> indegree(n, 0);

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < graph[i].size(); j++) {
                adj[graph[i][j]].push_back(i);
                indegree[i]++;
            }
        }
        queue<int> q;
        // vector<int> vis(n , 0);

        
            
        for(int i = 0 ; i < n ;i++){
            if(!indegree[i]){
                q.push(i);
            }
        }
        vector<int> ans;
        while (!q.empty()) {
            int node = q.front();
            q.pop();
            ans.push_back(node);
            for (auto& it : adj[node]) {
                indegree[it]--;
                if (indegree[it] == 0) {
                    q.push(it);
                }
            }
        }

        sort(ans.begin(), ans.end());
        return ans;
    }
};