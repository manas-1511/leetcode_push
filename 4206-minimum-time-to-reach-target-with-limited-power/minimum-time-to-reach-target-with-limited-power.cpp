class Solution {
public:
    vector<long long> minTimeMaxPower(int n, vector<vector<int>>& edges, int power, vector<int>& cost, int source, int target) {
        if(n== 1) return {0 , power};
        vector<vector<pair<long long  , long long >>> adj(n);
        for(auto& e: edges){
            adj[e[0]].push_back({e[1] , e[2]});
        }
        //dis , node , power rem
        priority_queue<vector<long long > , vector<vector<long long >> , greater<vector<long long>>> pq;

        //dis vector represents different states of the [node][remaining power]
        vector<vector<long long >> dis(n , vector<long long >(power+1 , LLONG_MAX ));
        pq.push({0 , source , power});
        dis[source][power] = 0;
        long long bestt =  -1; 
        long long  bestp = -1;
        while(!pq.empty()){
            auto it = pq.top();
            pq.pop();
            long long d = it[0] ; long long  u = it[1] ; long long rem = it[2];

            if(d > dis[u][rem]) continue;
            //therefore this distance is outdated 
            if(rem < cost[u]) //that means you cannot go anywhere because you have no power left
            continue;

            // THE TLE FIX: Early Exit
            // If we already found the target, and this new path takes LONGER, 
            // we can stop entirely because all future paths will only be longer.

            if (bestt != -1 && d > bestt) break;
            if(u == target){
                        if(bestt == -1) bestt = d;
                        // else bestt = min(bestt , d);
                        bestp = max(bestp , rem);
                        continue;
                        //because after reaching the target there is no need to traverse any further with 
                        //this node
                        
                    
                    }

            for(auto& itt :adj[u] ){
                long long  v = itt.first;
                long long  w = itt.second;

                if(d+w < dis[v][rem-cost[u]] ){
                    dis[v][rem-cost[u]] = d+w;
                    pq.push({d+w , v , rem-cost[u]});
                    
                }
                
            }
        }



        long long btime = LLONG_MAX; long long bp = -1;
        for(int i = 0 ; i <= power ; i ++){
            if(dis[target][i] <= btime){
                btime = dis[target][i];
                bp = i;
            }
        }

        if(btime == LLONG_MAX) return {-1 , -1};
        return {btime , bp};

    }
};