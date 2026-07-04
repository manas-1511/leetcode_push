class Solution {
public:
    int minScore(int n, vector<vector<int>>& roads) {
        vector<vector<pair<int , int>>> adj(n+1);
        for(auto& it : roads){
            adj[it[0]].push_back({it[1] , it[2]});
            adj[it[1]].push_back({it[0] , it[2]});
        }
        //dis , node
        //dis = here is the min road length encountered till now
        // queue<pair<int , int>> q;
        priority_queue<pair<int , int> , vector<pair<int , int>> , greater<pair<int , int>>> pq;
        vector<int> dis(n+1 , INT_MAX);
        pq.push({INT_MAX , 1});
        while(!pq.empty()){
            auto [d , node] = pq.top();
            pq.pop();

            //we should use pq to reduce the inefficient traversal through the roads 

            for(auto& it : adj[node]){
                int newNode = it.first;
                int w = it.second;

                //even if I encounter n , I will not stop because we can visit 
                //each road multiple times , and 1 and can be visited multiple times 

                int min_road_till_now = min(w , d);
                if(min_road_till_now < dis[newNode]){
                    dis[newNode] = min_road_till_now;
                    pq.push({dis[newNode] , newNode});
                }

            }

        }

        return dis[n];




    }
};