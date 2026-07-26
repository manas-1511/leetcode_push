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

        else if(size[ulp_u] < size[ulp_v]){
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

    bool isValid(int r , int c , int m , int n){
        return (r>= 0 && c>= 0 && r< m && c< n);
    }
    int largestIsland(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<int> dr = {0 , 0 , -1 , 1};
        vector<int> dc = {1 , -1 , 0 , 0};
        DisjointUnion ds(m*n);
        // make the islands without altering any thing
        for(int r = 0 ; r < m ; r++){
            for(int c = 0 ; c < n ; c++){
                if(grid[r][c] == 0) continue;
                for(int k = 0 ;  k < 4 ; k++){
                    int nr = r+dr[k];
                    int nc = c+dc[k];
                    if(isValid(nr , nc , m , n)){
                        
                        if(grid[nr][nc] == 0) continue;
                        int Node = r*n+c;
                        int adjNode = nr*n+nc;
                        if(ds.findUpar(Node) != ds.findUpar(adjNode) ){
                            ds.unionBySize(Node , adjNode);
                        }



                    }
                }
            }
        }

            int ans = 0;
        bool never_encountered_a_zero = true;
        for(int r = 0 ; r < m ; r++){
            for(int c = 0 ; c < n ; c++){
                if(grid[r][c] == 0){
                    never_encountered_a_zero = false;
                    //check the parents having unique ulm_parent(unique island ) and
                    //sum them all and +1 to get the size of the island when toggled this 0 to 1
                    unordered_set<int> unique_parents;
                    for(int k = 0 ; k < 4 ; k++){
                        int nr = r + dr[k];
                        int nc = c + dc[k];
                        if(isValid(nr , nc , m , n) && grid[nr][nc] == 1){
                            unique_parents.insert(ds.findUpar(nr*n+nc));
                        }
                    }

                    int total_size_of_island = 1;
                    for(auto& it : unique_parents){
                        total_size_of_island+=ds.size[it];
                    }
                            ans = max(ans , total_size_of_island);

                }
            }
        }


        if(never_encountered_a_zero) return n*m;
        return ans;
        
    }
};