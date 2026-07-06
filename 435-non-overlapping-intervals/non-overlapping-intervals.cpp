class Solution {
public:
    static bool compare(vector<int>& a  , vector<int>& b){
        if(a[1] == b[1]) return a[0] > b[0];
        return (a[1] < b[1]);
    }
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin() ,intervals.end(), compare);
        int end_prev = INT_MIN;
        int cnt = 0 ;
        for(auto& in : intervals){
            int st = in[0];
            int en = in[1];

            if(end_prev<=st){
                cnt++;
                end_prev = en;
            }
        }

        return intervals.size() - cnt;

    }
};