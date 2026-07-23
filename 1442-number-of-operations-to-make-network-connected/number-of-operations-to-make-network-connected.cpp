class DisjointUnion{
    public:
    int n ;
    vector<int> parent , rank;

    DisjointUnion(int n ){
        parent.resize(n);
        rank.resize(n, 0);

        for(int i = 0 ; i < n ; i++){
            parent[i] = i;
        }
    }

    int findUPar(int i){
        if(parent[i] == i) return i;
        else{
            return parent[i] = findUPar(parent[i]);
        }
    }

    void unionByRank(int u , int v){
        int ulp_u = parent[u];
        int ulp_v = parent[v];
        if(ulp_u == ulp_v) return;
        if(rank[ulp_u] < rank[ulp_v]){
            parent[ulp_u] = ulp_v;
        }

        else if(rank[ulp_u] < rank[ulp_v]){
            parent[ulp_v] = ulp_u;
        }

        else{
            parent[ulp_v] = ulp_u;
            rank[ulp_u]++;
        }
    }
};

class Solution {
public:
    int makeConnected(int n, vector<vector<int>>& connections) {
        DisjointUnion ds(n);
        int extraEdges = 0;
        for(auto& e: connections){
            int u = e[0];
            int v = e[1];
            if(ds.findUPar(u) == ds.findUPar(v)){
                extraEdges++;
            }

            else{
                ds.unionByRank(u ,v);
            }
        }
            int comp = 0 ;
        for(int i = 0 ; i < n ; i++){
            if(ds.parent[i] == i) comp++;
        }


        if(comp-1 <= extraEdges) return  comp-1;
        return -1;
    }
};