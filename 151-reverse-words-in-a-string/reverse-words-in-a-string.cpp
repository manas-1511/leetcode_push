class Solution {
public:
    string reverseWords(string s) {
        int n = s.size();
        int end = -1;
        string ans ;
        bool first_word = true;
        for(int j = n-1 ; j>= 0 ; j--){
            if(s[j] == ' '){
                if(end == -1) continue;
                else{
                    // end is pointing to some real char
                if(!first_word) ans+=' ';
                else{
                    //it is the first word then dont add space
                    first_word = false;
                }
                ans+=s.substr(j+1 , end-j);
                end = -1;
                
                }
                


            }

            else{
                if(j == n-1){
                    end = n-1;
                }

                else if(s[j+1] == ' ') end = j;
            }


        }
        
        if(s[0] != ' '){
            if(!first_word) ans+=' ';
            ans+=s.substr(0 , end+1);
        }



        return ans;
    }
};