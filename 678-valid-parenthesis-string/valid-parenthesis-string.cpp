class Solution {
public:
    bool checkValidString(string s) {
        //most optimized solution O(n)
        //dp memo O(n^2)
        //recursion O(3^n) because of three posibilities of * -1 , 0 , +1

        int min  = 0 ; 
        int max = 0;
        for(int i = 0 ; i < s.size() ; i++){
            if(s[i] == '('){
                min++;
                max++;
            }

            else if(s[i] == ')'){
                if(min >0) min--;
                max--;
            }

            else{
                if(min >0)min--;
                max++;
            }

            if(max<0) return false;
        }

        if(min == 0 ) return true;
        return false;

    }
    
};