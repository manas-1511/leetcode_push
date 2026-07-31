class Solution {
public:
    int minimumPushes(string word) {
        int total_no_of_char_filled = 0;
        vector<int> seen(26,0);
        for(int i = 0 ; i < word.size() ; i++){
            seen[word[i]-'a']++;
        }

        vector<int> unique;
        for(int i = 0 ; i< 26 ; i++){
            if(seen[i] != 0) unique.push_back(seen[i]);
        }

        sort(unique.begin(), unique.end());
        int cnt = 0 ;
        for(int j = unique.size() -1; j>=0 ;j--){
            total_no_of_char_filled++;
            
                // cnt+=1*unique[i];
            

                if(total_no_of_char_filled%8 == 0) cnt+=(total_no_of_char_filled/8)*unique[j];
                else cnt+=(total_no_of_char_filled/8 +1)*unique[j];
            
        }

        return cnt;
    }
};