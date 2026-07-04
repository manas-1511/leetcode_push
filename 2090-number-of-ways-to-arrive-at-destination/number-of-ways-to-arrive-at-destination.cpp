#define ll long long
class Solution {
public:
    int countPaths(int n, vector<vector<int>>& roads) {
        vector<vector<pair<ll , ll >>>adj(n);
        for(auto& it : roads){
            adj[it[0]].push_back({1ll*it[1] , 1ll*it[2]});
            adj[it[1]].push_back({1ll*it[0] , 1ll*it[2]});
        }

        const int MOD = 1e9+7;

        priority_queue<pair<ll , ll > , vector<pair<ll , ll>> , greater<pair<ll , ll>>> pq;
        vector<long long > dis(n , LLONG_MAX);
        vector<int> ways(n, 0);
        dis[0] = 0;
        ways[0] = 1;
        pq.push({0 , 0});
        
        while(!pq.empty()){
            auto [d , node] = pq.top();
            pq.pop();

            if(d > dis[node]) continue;
            
            for(auto& it : adj[node]){
                ll newNode = it.first;
                ll w = it.second;
                    
                    
                        //not a target
                    if(d+w == dis[newNode]) ways[newNode] =  (ways[newNode]+ways[node]) % MOD;
                
                    else if(d+w < dis[newNode]){
                    ways[newNode] = ways[node];
                    dis[newNode] = d+w;
                    pq.push({dis[newNode] , newNode});

                }

                    
            }

        }
                    return ways[n-1];



    }
};