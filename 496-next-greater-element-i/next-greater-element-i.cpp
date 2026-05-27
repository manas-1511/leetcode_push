class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int , int> mpp; 
        int n1 = nums1.size();
        int n2 = nums2.size();
        for(int i = 0 ; i < nums2.size() ; i ++){
            mpp[nums2[i]] = i;
        }
        vector<int> res(n2);

        stack<int> st;
        for(int i = n2-1 ; i>=0; i--){
            while(!st.empty() && nums2[i] >= st.top()){
                st.pop();
            }

            if(st.empty()) res[i] = -1;
            else res[i] = st.top();

            st.push(nums2[i]);
        }

        for(int i = 0 ; i< n1 ; i ++){
            nums1[i] = res[mpp[nums1[i]]];
        }

        return nums1;
    }
};