class Solution {
public:
    int longestValidParentheses(string s) {
        int ans = 0 ;
        int left = 0 ;
        int right = 0 ;
        int n = s.size();
        for(int i = 0 ; i < n; i++){
            
            if(s[i] == '(') left++;
            else right++;
            if(left == right) ans = max(ans , left+right);
            if(right>left){
                left = 0 ;
                right = 0;
            }
        }

        //now check the same form the right side to ensure the case ( ( ) it will give 0 from the left traversal 
        left = 0 ;
        right = 0 ; 
        for(int i = n-1 ; i>= 0 ; i--){
            if(s[i] == '(') left++;
            else right++;
            if(left == right) ans = max(ans , left+right);
            if(right<left){
                left = 0 ;
                right = 0;
            }
        }

        

        return ans;
    }
};