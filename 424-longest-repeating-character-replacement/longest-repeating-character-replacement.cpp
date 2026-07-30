class Solution {
public:
    int characterReplacement(string s, int k) {
        int l = 0 ; 
        
        int n = s.size();
        vector<int> seen(26 , 0);
        int ans = 0 ;
        for(int r = 0 ; r < n ; r++){
            seen[s[r]-'A']++;
            int maxfreq = 0 ;
            for(int i = 0 ; i < 26 ; i++){
                maxfreq = max(maxfreq , seen[i]);
            }

            int len = r-l+1;
            if(len-maxfreq > k){
                seen[s[l]-'A']--;
                l++;
                
                continue;
            }

            else{
                // valid len of the new subarray
                
                ans = max(len , ans);
            }
        }

        return ans;
    }
};