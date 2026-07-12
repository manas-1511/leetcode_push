class Solution {
public:
    long long  s(vector<int>& nums){
        int n = nums.size();
        vector<int> pse( n , 0 );
        stack<pair<int , int>> st;

        //for pse 
        for(int i= 0 ; i < n ; i++){
            while(!st.empty() && nums[i] <= st.top().first){
                st.pop();
            }

            if(st.empty()) pse[i] = -1;
            else pse[i] = st.top().second;
            st.push({nums[i] , i});
        }


        st = stack<pair<int , int>>();
        //for nse 
        vector<int> nse(n , 0);
        for(int i = n-1 ; i>= 0 ; i--){
            while(!st.empty() && nums[i] < st.top().first){
                st.pop();
            }

            if(st.empty()) nse[i] = n;
            else nse[i] = st.top().second;
            st.push({nums[i] , i});
        }
        long long  sum = 0;
        for(int i = 0 ; i < n;  i++){
            sum+=1LL*((i-pse[i])*(nse[i]-i)*(1LL)*nums[i]);
        }

        return sum ;


    }



    long long  g(vector<int>& nums){
        int n = nums.size();
        vector<int> pge(n,0);
        stack<pair<int , int>> st;

        //for pse 
        for(int i= 0 ; i < n ; i++){
            while(!st.empty() && nums[i] >= st.top().first){
                st.pop();
            }

            if(st.empty()) pge[i] = -1;
            else pge[i] = st.top().second;
            st.push({nums[i] , i});
        }


        st = stack<pair<int , int>>();
        //for nse 
        vector<int> nge(n , 0);
        for(int i = n-1 ; i>= 0 ; i--){
            while(!st.empty() && nums[i] > st.top().first){
                st.pop();
            }

            if(st.empty()) nge[i] = n;
            else nge[i] = st.top().second;
            st.push({nums[i] , i});
        }
        long long  sum = 0;
        for(int i = 0 ; i < n;  i++){
            sum+=1LL*((i-pge[i])*(nge[i]-i)*(1LL)*nums[i]);
        }

        return sum ;

    }
    long long subArrayRanges(vector<int>& nums) {
        //this q is divided i two parts 
        //1) pse + nse 
        //2) pge + nge

        return g(nums) -  s(nums);
    }
};