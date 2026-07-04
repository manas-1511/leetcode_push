class Solution {
public:
    static bool compare(vector<int>& a , vector<int>& b){
        
        if(a[1] != b[1]) return  (a[1] < b[1]);
        return a[0] < b[0];
    }
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        //reverse of N-meeting problem just framed differently 
        sort(intervals.begin() , intervals.end(), compare);
        int ans = 0 ;
        int pre_end = INT_MIN;
        for(auto &it : intervals){
            if(pre_end <= it[0]){
                ans++;
                pre_end = it[1];
            }

        }

        return intervals.size() - ans;
    }
};