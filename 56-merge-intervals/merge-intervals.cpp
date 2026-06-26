class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin() , intervals.end());
        int n = intervals.size();
        vector<vector<int>> ans;
        int start = intervals[0][0];
        int end = intervals[0][1];
        for(auto& it :intervals){
            if(it[0] <= end) end = max( end , it[1]);
            else {
                ans.push_back({start , end});
                start = it[0];
                end = it[1];
            }
        }

        ans.push_back({start , end});
        return ans ;
    }
};