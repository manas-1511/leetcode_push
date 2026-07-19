class Solution {
public:
    vector<bool> transformStr(string s, vector<string>& strs) {
        int cnt1 = 0 ;
        int cnt0 = 0;
        int n = s.size();

        //counted the total no. of 0 and 1  in s
        for(int i = 0 ; i < s.size() ; i++){
            if(s[i] == '0') cnt0++;
            else cnt1++;
        }
            vector<bool> ans;
        
        for(auto& str:strs){
            int c1 = 0;
            int c0 = 0 ;

            bool flag = true;
            //counting the total no. of 0 and 1 for str
            for(int i = 0 ; i< str.size() ; i++){
                if(str[i] == '1') c1++;
                else if(str[i] == '0') c0++;

            }

            if(c1 > cnt1){
                ans.push_back(false);
                continue;
            }

            if(c0 > cnt0){
                ans.push_back(false);
                continue;
            }


            //greedily puting 0s in place of question mark since 
            //to make the count smaller 
            //if more 0 cannot be put then i will put 1 
            for(int i = 0 ; i<n ; i++){
                
                if(str[i] == '?'){
                    if(c0 < cnt0){
                        str[i] = '0';
                        c0++;
                    }

                    else if(c1 < cnt1){
                        str[i] = '1';
                        c1++;
                    }
                }
            }

                

                

                
            
           

            int buffer = 0;
            bool f = true;
            for(int i = 0 ; i < n ; i++){
                if(s[i] == '1' && str[i] == '0') buffer++;
                else if(s[i] == '0' && str[i] == '1')  buffer--;
                if(buffer<0){
                    f = false;
                    break;
                }
            }
            
            if(f) ans.push_back(true);
            else ans.push_back(false);

            

            
        }

        return ans;
    }
};