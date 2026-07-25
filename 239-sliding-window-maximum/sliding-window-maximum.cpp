class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> ans;
        deque<int> dq;
        int n = nums.size();
        int start = 0 ;

        for(int i = 0 ; i< n ; i++){
            
                //dont have to remove anything form the front in order to maintain the window size
                int curr = nums[i];
                while(!dq.empty() && nums[dq.back()] <= curr){
                    //because the elem having smaller values are of no use form now 
                    // bcz the bigger elem (THE BOSS) has now entered the window
                    dq.pop_back();

                }

                dq.push_back(i);
        

            if(i-start+1 < k) continue;
            else if(i-start+1 == k){
                ans.push_back(nums[dq.front()]);
            }

            else{
                start++;
                if(dq.front() < start) dq.pop_front();
                ans.push_back(nums[dq.front()]);
            }


        }

        return ans;

        
    }
};