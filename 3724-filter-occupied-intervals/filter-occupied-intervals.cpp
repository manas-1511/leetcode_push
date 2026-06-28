class Solution {
public:
    vector<vector<int>> filterOccupiedIntervals(vector<vector<int>>& o, int freeStart, int freeEnd) {
        vector<vector<int>> m ;
        sort(o.begin() , o.end());
        int n = o.size();
        int start = o[0][0];
        int end = o[0][1];
        for(int i = 1 ; i < n ; i++){
            if(o[i][0] <= end+1) end = max(end , o[i][1]);
            else{
                m.push_back({start , end});
                start = o[i][0];
                end = o[i][1];
            }
        }

        m.push_back({start , end});

       
        
        vector<vector<int>> merged;
        

        for(int i = 0 ; i < m.size() ; i++){
            int l = m[i][0];
            int r = m[i][1];

            //no intersection 
            if(r < freeStart || l > freeEnd){
                 merged.push_back({l,r});
                continue;
            }

            //left part remain
            if(l<freeStart) merged.push_back({l , freeStart-1});
                //right part remian
             if(r>freeEnd) merged.push_back({freeEnd+1 , r});
           
        }

        return merged;


        
    }
};