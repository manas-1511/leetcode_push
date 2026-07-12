class Solution {
public:
    string removeKdigits(string s, int k) {
        stack<char> st;
        int n = s.size();
        for(int i = 0 ; i < n ;i++){
            while(!st.empty() && st.top() > s[i] && k>0){
                k--;
                st.pop();
            }

            st.push(s[i]);



        }

            //if more k left to removed
            while(k>0 && !st.empty()){
                st.pop();k--;
            }

            if(st.empty()) return "0";

            //getting back with the ans 
            string res = "";
            while(!st.empty()){
                res+=st.top();
                st.pop();
            }

            //trimming zeros at back
            while(res.size() > 0 && res.back() == '0'){
                res.pop_back();
            }

            if(res.size() == 0) return "0";

            reverse(res.begin() , res.end());
            return res;


            
        }
    
};