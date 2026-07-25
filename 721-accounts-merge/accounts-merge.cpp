#include<iostream>
#include<vector>
using namespace std;
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

    // void unionBySize(int u , int v){
    //     int ulp_u = findUpar(u);
    //     int ulp_v = findUpar(v);

    //     if(ulp_u == ulp_v) return ;
    //     if(size[ulp_u] > size[ulp_v]){
    //         parent[ulp_v] = ulp_u;
    //         size[ulp_u]+=size[ulp_v];
    //     }

    //     else if(size[ulp_u] < size[ulp_v]){
    //         parent[ulp_u] = ulp_v;
    //         size[ulp_v]+=size[ulp_u];
    //     }

    //     else {
    //         parent[ulp_u] = ulp_v;
    //         size[ulp_v]+=size[ulp_u];
    //     }
    // }




};



class Solution {
public:
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        int n = accounts.size();
        DisjointUnion ds(n);
        unordered_map<string , int> mpp;
        for(int i = 0 ; i< n ; i++){
            for(int j = 1; j < accounts[i].size() ; j++){
                if(mpp.find(accounts[i][j]) == mpp.end()){
                    //not found
                    mpp[accounts[i][j]] = i;
                }

                else{
                    //found
                    int node_already_present = mpp[accounts[i][j]];
                    ds.unionByRank(node_already_present , i);
                }
            }
        }

        vector<vector<string>> ans(n);
        for(int i = 0 ; i < n ; i++){
            ans[i].push_back(accounts[i][0]);
        }
        for(auto& it : mpp){
            int node = it.second;
            string mailID = it.first;
            int i = ds.findUpar(node);

            ans[i].push_back(mailID);
        }

        vector<vector<string>> result;
        for(int i = 0 ; i < n ; i++){
            if(ans[i].size() != 1){
                sort(ans[i].begin()+1 , ans[i].end());
                result.push_back(ans[i]);
            }
        }

        

        

        return result;
    }
};