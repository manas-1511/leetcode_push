class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int i  = 0 ;
        int n = s.size();
        unordered_set<char> vis;
    int longest  = 0 ;
        for(int j = 0 ; j < n ; j++){
            while(vis.find(s[j]) != vis.end()){
                vis.erase(s[i]);
                i++;
            }

            int len = j-i+1;
            longest = max(longest , len);
            vis.insert(s[j]);

        }

        return longest ;
    }
};