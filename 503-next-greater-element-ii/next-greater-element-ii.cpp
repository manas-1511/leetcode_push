class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
      int n = nums.size();
      if(n==1) return {-1};
      stack<int>st ; 
      for(int i = n-2 ; i>= 0 ;  i--) st.push(nums[i]);
      for(int i = n-1 ; i >= 0 ; i --){
        int copy = nums[i];
        while(!st.empty() && st.top() <= nums[i])  st.pop();

        if(st.empty()) nums[i] = -1;
        else nums[i] = st.top();
        st.push(copy);
      }  

      return nums;
    }
};