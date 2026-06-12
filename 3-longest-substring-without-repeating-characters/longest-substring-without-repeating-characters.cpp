class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.size();
        
        // if(n==0 || n==1) return n;
        unordered_set<char> vis;
        int i  = 0 ; 
        int ans = 0 ;
        
        for( int j = 0 ; j < n ; j++){
            while(vis.count(s[j])){
                vis.erase(s[i]);
                i++;
            }

            vis.insert(s[j]);
            ans = max(ans , j-i+1);
        }


        return ans ;
    }
};