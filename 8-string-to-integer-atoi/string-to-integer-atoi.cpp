#define ll long long 
class Solution {
public:
    int myAtoi(string s) {
        ll ans = 0 ;
        int sign = 1;
        bool valid = false;
        for(int i = 0 ; i <  s.size() ; i++){
            if(!valid){
                if(s[i] == ' ') continue;
                if(s[i] == '-'){
                    valid = true;
                    sign = -1;
                    continue;
                }
                if(s[i] == '+'){
                    valid = true;
                    sign = 1;
                    continue;
                }
                if(s[i] <= 57 && s[i] >= 48){
                    valid = true;
                    ans = ans*10 + 1LL*(s[i]-'0');
                }

                else break;
            }


            else{
                // now it is a valid ans
                if(s[i] <= 57 && s[i] >= 48){
                    if(ans > INT_MAX) break;
                    ans = ans*10 + 1LL*(s[i]-'0');
                }

                else break;
            }
        }

        ans *= sign;

        if(ans < INT_MIN) return INT_MIN;
        if(ans > INT_MAX) return INT_MAX;
         return (int)ans;
    }
};