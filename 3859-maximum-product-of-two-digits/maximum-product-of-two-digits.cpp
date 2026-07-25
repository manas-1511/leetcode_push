class Solution {
public:
    int maxProduct(int n) {
        vector<int> seen(10 , 0);
        while(n>0){
            seen[n%10]++;
            n/=10;
        }
            int first = -1;
            int  second = -1;
        for(int i = 9 ; i>= 0 ; i--){
            if(seen[i]>=2){
                if(first == -1){
                    first = i;
                    second = i;
                    break;
                }

                else{
                    second = i;
                    break;
                }
            }
            else if(seen[i] == 1){
                if(first == -1) first = i;
                else if(second == -1){
                     second = i;
                     break;
                }
            }
        }

        return first*second;
    }
};