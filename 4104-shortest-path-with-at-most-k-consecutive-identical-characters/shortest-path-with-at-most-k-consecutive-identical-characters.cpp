class Solution {
public:
    //see the solution upvoted 
    int shortestPath(int n, vector<vector<int>>& edges, string labels, int k) {
        if(n==1) return 0;
        //dijkstra algo 
        vector<vector<pair<int,int>>> adj(n);
        for(auto& e: edges){
            adj[e[0]].push_back({e[1] , e[2]});
        }

        vector<vector<long long >> dis(n , vector<long long >(k+1 , LLONG_MAX));

        // each [i][remaining_energy] represents a seprate unique nodes
        // {dis , node , remaining_energy } 
        //min heap pq
        priority_queue<vector<long long> , vector<vector<long long >> , greater<vector<long long>>> pq;

        pq.push({0 , 0 , k});
        while(!pq.empty()){
            auto it = pq.top();
            pq.pop();
            
            long long  d = it[0];long long  node = it[1] ;long long  rem = it[2];
            if(d > dis[node][rem]) continue;

            for(auto& it : adj[node]){
                int w = it.second;
                int new_node = it.first;
                if(labels[node] != labels[new_node]){
                    // energy regained 
                    if(1LL*w + d < dis[new_node][k]){
                        dis[new_node][k] = w+d;
                        pq.push({1LL*w+d , 1LL*new_node , 1LL*k});
                    }
                }

                else{
                    //its the same label reduce the energy if possible
                    // if(rem == 1) you cannot reduce it further because this energy has been used
                     //previously 
                    if(rem > 1 ){
                        if(w+d < dis[new_node][rem-1]){
                            dis[new_node][rem-1] = w+d;
                            pq.push({1LL*w+d , 1LL*new_node , 1LL*(rem-1)});
                        }
                    }
                }
                
            }
        }

        long long ans = INT_MAX;
        for(int i = 1 ; i <= k ; i++){
            ans = min(ans , dis[n-1][i]);
        }

        if(ans == INT_MAX) return -1;
        return ans;



    }
    
};