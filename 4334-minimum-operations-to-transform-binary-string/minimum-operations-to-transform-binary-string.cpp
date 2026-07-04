class Solution {
public:
    int minOperations(string s1, string s2) {
        int n = s1.size();
        int steps = 0;
        if(s1 == "1" && s2 == "0") return -1;

       
        for(int i = 0 ; i <n ; i++){
            if(s1[i] == s2[i]) continue;
                steps++; // atleast 1 change has to be done beacuse diff values
                if(s1[i] == '1'){
                    if(i == n-1) steps++;
                    else{
                        steps+= s1[i+1] == '0';
                        s1[i+1] = '0';
                    }
                }

            
               
            }

        return steps;
        }


        

        
    
};