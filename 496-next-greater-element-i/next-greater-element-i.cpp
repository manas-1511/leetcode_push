class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int , int>mpp;
        stack<int> st;
        int n = nums2.size();
        for(int i = n-1 ; i>= 0 ; i --){
            int copy = nums2[i];
            mpp[nums2[i]] = i;
            while(!st.empty() && st.top() <= copy){
                st.pop();
            }

            if(st.empty()) nums2[i] = -1;
            else nums2[i] = st.top();
            st.push(copy);
        }

        for(int i = 0 ; i < nums1.size() ; i++){
            nums1[i] = nums2[mpp[nums1[i]]];
        }

        return nums1;
    }
};