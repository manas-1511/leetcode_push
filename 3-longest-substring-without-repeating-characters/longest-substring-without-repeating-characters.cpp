class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        
        unordered_set<char> visited;
        int n = s.size();
        if(n== 0 ||n==1 ) return n ;
        int i = 0 ; 
        int ans = 0;
        visited.insert(s[0]);
        for(int j = 1 ; j < n ; j++){
            while(visited.count(s[j])){
                visited.erase(s[i]);
                i++;
            }

            visited.insert(s[j]);
            ans = max(ans , j-i+1);
        }

        return ans;
    }
};