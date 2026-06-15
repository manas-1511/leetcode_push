class Solution {
public:
//better than brute tforce method : sort first 

//thios one is optimized approach 
    int longestConsecutive(vector<int>& nums) {
        int n = nums.size();
        unordered_set<int> st;
        for(int i = 0 ; i < n; i ++){
            st.insert(nums[i]);
        }
        int longest = 0;
        for(auto& it : st){
            if(st.count(it-1)) continue;
            else{
                int cnt = 0 ;
                auto temp = it;
                while(st.count(temp)){
                    cnt++;
                    temp++;
                }

                longest = max(cnt , longest);
            }
        }

        return longest;
    }
};