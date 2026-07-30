class Solution {
public:
    int minimumPushes(string word) {
        unordered_set<char> sett; 
        for(int i = 0 ; i < word.size() ; i++){
            sett.insert(word[i]);
        }

        int size = sett.size();
        int cnt = 0 ; 
        int multi = 1;
        while(size>0){
            if(size <= 8){
                cnt+=size*multi;
                size = 0;
            }

            else{
                cnt+=8*multi;
                size-=8;
                multi+=1;
            }
        }

        return cnt ;
    }
};