class Solution {
public:
    bool canMakeSubsequence(string s, string t) {
        int m = s.size();
        int n = t.size();
        if(m>n) return false;
        vector<int> left(m ,-1) , right(m , -1);
        int p = 0;
        for(int i = 0 ; i < m ; i ++){
            while(p<n && s[i]!=t[p]){
                p++;
            }

            if(p == n) break;
            left[i] = p++;
        }

        if(left[m-1]!=-1) return true; // that s is already a subsequemnce for t

        p = n-1;
        for(int i = m-1 ; i>= 0 ; i--){
            while(p>=0 && s[i]!=t[p]) p--;
            if(p<0) break;
            right[i] = p--;
        }

        for(int i = 0 ; i < m ; i++){
            if((i==0 || left[i-1] != -1) && (i==m-1 || right[i+1] != -1)){
                // that means there exist a prefix and a suffix subsequnce for the i-1 and i+1 and have to check for the i

                int L = (i==0)?-1:left[i-1];
                int R = (i==m-1)?n:right[i+1];

                if(L+1<R) return true; // yhere exist a element in t such that ith element can be changed to makr the pair perfect

            }
        }

        return false;


    }
};