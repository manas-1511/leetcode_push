class Solution {
public:
    //this was using the pathvis and vis 
    bool checkdfs(int i ,vector<vector<int>>& adj , vector<int>& vis , vector<int> pathvis ){
        vis[i] = 1;
        pathvis[i] = 1;
        for(auto&it : adj[i]){
            if(!vis[it]){
                if(checkdfs(it , adj , vis , pathvis)){
                    return true;
                    //yes its a cycle 
                }
            }

            else{
                //that indicates that the node is visited and also it is 
                //path visited that means the current path in which i am travelling in 
                //has already encountered this node and now i am in a cycle
                if(pathvis[it]) return true;
            }
        }

        pathvis[i] = 0;
        return false;

    }
//check if the directed graph is the cyclic one
    bool canFinish(int n, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adj(n);
        for(auto& e : prerequisites){
            adj[e[1]].push_back(e[0]);
        }
        vector<int> vis(n , 0);
        vector<int> pathvis(n , 0);

        for(int i = 0 ; i < n ; i++){
            if(!vis[i]){
                bool flag = checkdfs(i , adj , vis , pathvis);
                //if the flag = true that means it is a directed graph so have to return false to say that the courses can cannot be ever completed by the student 
                if(flag) return false;
            }
        }

        return true;
    }
};