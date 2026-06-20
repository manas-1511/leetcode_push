class Solution {
public:
    int minLights(vector<int>& lights) {

        int n = lights.size();
        vector<vector<int>> limits;
        for(int i = 0 ; i <n ; i++){
            int v = lights[i];
            if(v== 0) continue;
            limits.push_back({max(0 , i-v) , min(n-1 , i+v)});
        }
    if(limits.size() == 0 ) return (n+2)/3;

        
        sort(limits.begin() , limits.end());

        
        int cnt = 0;//cnt = the total number of darks positions 
        
        
       int last_covered = -1;
       //took -1 because we want to check the drak gaps at the starting
       //lets say [1,3] is the first limits lit then 1-(-1)-1 = 1 (that means 1 dark position)

        for(int i = 0; i < limits.size(); i++){
            if(limits[i][0] > last_covered+1){
                int gap = limits[i][0]-last_covered-1;
                cnt+=(gap+2)/3;
            }

                //in any of the case you have to update the last covered
                last_covered = max(last_covered , limits[i][1]);
        }

            //for trailling gaps 
            int final_dark_gaps = n-last_covered-1;
            if(final_dark_gaps > 0 ) {
                cnt+=(final_dark_gaps+2)/3;
            }

            return cnt;
            



            




        

        
    }
};