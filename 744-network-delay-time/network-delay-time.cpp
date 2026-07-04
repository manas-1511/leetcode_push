class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        //bfs 
        vector<vector<pair<int , int >>>adj(n+1);
        for(auto& it : times){
            adj[it[0]].push_back({it[1] , it[2]});
        }

        priority_queue<pair<int , int> , vector<pair<int , int>> , greater<pair<int , int>>> pq;
        vector<int> dis(n+1 , INT_MAX);
        dis[k] = 0;
        pq.push({0 , k});


        //time , node

        

        while(!pq.empty()){
            auto [t , node] = pq.top();
            pq.pop();
            if(t > dis[node]) continue;

            for(auto& it: adj[node]){
                int newNode = it.first;
                int w = it.second;

                if(t+w < dis[newNode]){
                    dis[newNode] = t+w;
                    pq.push({dis[newNode] , newNode});
                }
            }
        }
        int ans  =-1 ;
        for(int i = 1 ; i <= n ; i++){
            if(dis[i] == INT_MAX) return -1;
            ans = max(ans ,dis[i] );
        }

        return ans ;
            

    }
};