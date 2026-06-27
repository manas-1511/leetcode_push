class Solution {
public:
    bool checkValidString(string s) {
        //most optimized solution O(n)
        //dp memo O(n^2)
        //recursion O(3^n) because of three posibilities of * -1 , 0 , +1

        int min  = 0 ; 
        int max = 0;
        //min and max are the range on cnt 
        //( --> cnt++     ) ---> cnt--
        for(int i = 0 ; i < s.size() ; i++){
            if(s[i] == '('){
                min++;
                max++;
            }

            else if(s[i] == ')'){
                 min--;
                max--;
            }

            else{
                min--;
                max++;
            }
            
            //making min = 0 if neg because max may be +ve
            if(min < 0 ) min = 0;
            //but if max also goes -ve then there is no way it's valid 

            if(max<0) return false;
        }

        if(min == 0 ) return true;
        return false;

    }
    
};