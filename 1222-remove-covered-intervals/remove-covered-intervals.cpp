class Solution {
public:
 static bool compare(vector<int>& a  , vector<int>& b){
        if(a[0] == b[0]) return a[1] > b[1];
        return (a[0] < b[0]);
    }
    int removeCoveredIntervals(vector<vector<int>>& intervals) {
         sort(intervals.begin() ,intervals.end(), compare);
        int endMax = INT_MIN;
        int cnt = 0 ;
        for(auto& in : intervals){
            int st = in[0];
            int en = in[1];
            if(en <= endMax)cnt++;
            endMax = max(endMax , en);
            
        }

        return intervals.size()- cnt;
    }
};