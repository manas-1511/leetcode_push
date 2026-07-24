class Solution {
public:
    int largestRectangleArea(vector<int>& nums) {
        // most optimal approach 
        int n = nums.size();
        //pse , nse;
        stack<int> st;
        int mx = 0;
        for(int i = 0 ; i < n ; i++){
            if(st.empty()){
                st.push(i);
            }

            else{
                while( !st.empty() && nums[i] < nums[st.top()]){
                    //then i have got the nse for the st.top therefore have to pop it out 
                    int node = st.top();
                    st.pop();
                    int pse = (st.empty()) ? -1 : st.top();
                    int nse = i;

                    int area = (nse-pse-1)*nums[node];
                    mx = max(mx , area);
                }

                st.push(i);
            }
        }


        while(!st.empty()){
            int node = st.top();
            st.pop();
            int nse = n;
            int pse = (st.empty()) ? -1 : st.top();
            int area = (nse-pse-1)*nums[node];
            mx = max(mx , area);
        }

        return mx;

    }
};