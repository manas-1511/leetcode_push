class DisjointUnion{
    public:


    vector<int> parent;
    vector<int> rank;
    vector<int> size;

    DisjointUnion(int n){
        parent.resize(n);
        rank.resize(n , 0);
        size.resize(n,1);
        for(int i = 0 ; i< n ; i++){
            parent[i] = i;
        }
    }

    int findUpar(int i){
        if(parent[i] == i) return i;
        return parent[i] = findUpar(parent[i]);
    }

    void unionByRank(int u , int v){
        int ulp_u = findUpar(u);
        int ulp_v = findUpar(v);

        if(ulp_u == ulp_v) return ;
        if(rank[ulp_u] > rank[ulp_v]){
            parent[ulp_v] = ulp_u;
        }

        else if(rank[ulp_u] < rank[ulp_v]){
            parent[ulp_u] = ulp_v;
        }

        else {
            parent[ulp_u] = ulp_v;
            rank[ulp_v]++;
        }
    }

    void unionBySize(int u , int v){
        int ulp_u = findUpar(u);
        int ulp_v = findUpar(v);

        if(ulp_u == ulp_v) return ;
        if(size[ulp_u] > size[ulp_v]){
            parent[ulp_v] = ulp_u;
            size[ulp_u]+=size[ulp_v];
        }

        else if(rank[ulp_u] < rank[ulp_v]){
            parent[ulp_u] = ulp_v;
            size[ulp_v]+=size[ulp_u];
        }

        else {
            parent[ulp_u] = ulp_v;
            size[ulp_v]+=size[ulp_u];
        }
    }




};
class Solution {
public:
    int removeStones(vector<vector<int>>& stones) {
        int n = stones.size();
        int maxCol = 0;
        int maxRow = 0;
        for(auto& it : stones){
            maxRow = max(it[0] , maxRow);
            maxCol =max(it[1] , maxCol);
        }
            // unordered_map<int , int > stoneNode;  //just to maintain which rows and cols have stones
            //because the node(row or col here) having no stones will still represent a independent node 
            // total number of rows = maxRow+1 and cols = maxCol+1
        DisjointUnion ds(maxRow+maxCol+2);
       
        for(auto& it : stones){
            int row = it[0];
            int col = maxRow+it[1]+1;
            ds.unionByRank(row , col);
            // stoneNode[row] = 1;
            // stoneNode[col] = 1;

        }

        int comp = 0;
        //M1 using unordered_map to find the actual comp
        // for(auto& it : stoneNode){
        //     if(ds.parent[it.first] == it.first) comp++;
        // }

        //another way to check the nodes(i.e. rows/cols which dont contain any stones)
        //will have the size == 1 since each of the node is paired/ grouped with some other nodes
        //since a stone is represented by (i,j) and therefore should be paired with other node 
        //if not paired then it is a no stone cell and dosenot represent a individual componenent


        //m2 to find the actual comp 
        for(int i = 0 ; i < maxRow+maxCol+2; i++){
            if(ds.parent[i] == i && ds.rank[i] > 0) comp++;
        }

        return n-comp;

    }
};