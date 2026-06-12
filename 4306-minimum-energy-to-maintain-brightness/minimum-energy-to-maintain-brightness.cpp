class Solution {
public:
    long long minEnergy(int n, int brightness, vector<vector<int>>& intervals) {
        unsigned long long bulbs = (brightness+2)/3;
        sort(intervals.begin() , intervals.end());
        unsigned long long start = intervals[0][0];
        unsigned long long end = intervals[0][1];
        unsigned long long len = 0 ;
        for(auto& i : intervals){
            unsigned long long scurr = i[0];
            unsigned long long ecurr = i[1];
            if(scurr <= end){
                end = max(end , ecurr);
            }

            else{
                len += end-start+1;
                start = scurr;
                end = ecurr;
            }
        }

        len+=end-start+1;

        return bulbs*len;
    }
};