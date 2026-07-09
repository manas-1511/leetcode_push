class Solution {
public:
    int sumSubarrayMins(vector<int>& arr) {
            int n = arr.size();
            //maintain a prev small element array and a next small array 
        vector<int> psmall(n , 0); 
        int MOD = 1e9+7;

        stack<pair<int , int>> st;
        // value , index 
        for(int i = 0 ; i < n ; i++){
            while(!st.empty() && arr[i] <= st.top().first ){
                st.pop();
            }

            if(st.empty()) psmall[i] = -1;
            else psmall[i] = st.top().second;

            st.push({arr[i] , i});
        }

        // next smaller element 
        st = stack<pair<int, int>>();
          vector<int> nextsmall(n , 0); 
          for(int i = n-1 ; i >= 0 ; i--){
            while(!st.empty() && arr[i] < st.top().first ){
                st.pop();
            }

            if(st.empty()) nextsmall[i] = n;
            else nextsmall[i] = st.top().second;

            st.push({arr[i] , i});
          }
            long long  sum = 0 ;
          for(int i = 0 ; i < n ; i ++){
            int cnt = (i-psmall[i])*(nextsmall[i]-i);
            sum = ( sum + cnt*(1LL)*arr[i]%MOD )%MOD;


          }


          return (int)sum;







    }
};