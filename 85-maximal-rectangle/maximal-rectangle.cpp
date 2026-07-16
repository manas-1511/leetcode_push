class Solution {
public:
        //largest rectangel in histrogram
    int lrih(vector<int>& nums ){
        // brute force ap. 
        //take out the nse pse for each ele and  
        // use (nse-pse-1)*arr[i]

        //now the optimal approach
        int n = nums.size();
        stack<int> st; //storing the index
        int maxArea = 0;
        for(int i = 0 ; i < n; i ++){
            while(!st.empty() && nums[st.top()] > nums[i]){
                //that means the element at the top has now found its nse since
                //nums[i] < st.top() now update area for this height since the pse
                //can always be found out as we are traversing through the left
                //already seen the prev element so we have the idea of pse al the time 
                int eleIndex  = st.top() ; 
                st.pop();
                int nse = i;
                int pse = (st.empty()) ? -1 :st.top();
                maxArea = max(maxArea , (nse-pse-1)*nums[eleIndex]);

            }

            st.push(i);
        }
            //if something is still left in the stack that indicates we have got no nse for them
        while(!st.empty()){
            int eleIndex  = st.top() ; 
            st.pop();
            int nse = n ; 
            int pse = (st.empty()) ? -1 : st.top();
                maxArea = max(maxArea , (nse-pse-1)*nums[eleIndex]);
        }

        return maxArea;
    }
    int maximalRectangle(vector<vector<char>>& matrix) {
        // extended verison of laregest rectangle  on histogram
        int m = matrix.size();
        int n = matrix[0].size();
        int maxArea = 0 ;
            vector<int> prev(n , 0);
        for(int i = 0; i  <m ; i++){
             vector<int> height(n , 0);
            for(int j = 0 ; j < n ; j++){

                if( matrix[i][j] == '1' ){
                    height[j] = prev[j]+1;
                }
                
            }

            prev = height;

            maxArea = max(maxArea , lrih(height));
        }

        return maxArea;
        
    }
};