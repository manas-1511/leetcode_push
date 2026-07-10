class Solution {
public:
    vector<int> asteroidCollision(vector<int>& arr) {
        int n = arr.size();
        stack<int> st;
        for(int i = n-1 ; i >=0  ; i--){
            if(st.empty()){
                st.push(arr[i]);
                continue;
            }
            int top = st.top();
            
            if(top>0){
                //never collides
                st.push(arr[i]);
                continue;
            }

            else{
                if(arr[i] < 0){
                    st.push(arr[i]);
                    continue;
                }


                    //now my top is -ve and arr[i] is +ve 
                    // collides
                    else{
                        bool flag = true;
                    while(!st.empty()){
                        if(st.top() > 0) break; // no burst
                        if(arr[i] == abs(st.top())){
                             st.pop();
                             flag = false;
                                break;
                             //both burst
                        }

                        else if(arr[i] > abs(st.top())) st.pop(); // top buisted 
                        else{
                            flag = false;
                            break;
                        } // arr[i] bursted 
                    }

                    if(flag) st.push(arr[i]);

                    }
                
                }
            }



        vector<int> ans;
        while(!st.empty()){
            ans.push_back(st.top());
            st.pop();
        }

        return ans;

      
    
    }
};