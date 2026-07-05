class Solution {
    private:
    int n ;
public:

    pair<int , int> expand(int left , int right , string& s ){
        while(left>=0 && right <n && s[left] == s[right]){
            left--;
            right++;
        }
        return {left+1 , right-left-1};
    }

    string longestPalindrome(string s) {
    
        int ans = 0 ;
        int start = -1;
         n = s.size();
         for(int i = 0 ; i < n ; i ++){
            

            
            auto [i1 , n1] = expand(i , i , s);
            

            // if(i != n-1) no need of this myh expand f handles everthing

         auto [i2, n2] = expand(i ,i+1 , s);
                if(ans < n1){
                    ans = n1;
                    start = i1;
                }

                if(ans < n2){
                    ans = n2;
                    start = i2;
                }

         }

         if(ans == 0 ) return "";
         return s.substr(start , ans);




    }
};