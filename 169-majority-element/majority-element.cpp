class Solution {
public:
        //MOORE's Algorihtm in this we will be creating section of arrays
        //first consider the element to be a majority and then propogate through by cnt++ or cnt--
    int majorityElement(vector<int>& nums) {
        int n= nums.size();
        int ele = nums[0]; 
        int cnt = 1 ;
        for(int i = 1 ; i<n ; i ++){
            //cnt == 0 then change the element

            if(cnt == 0) {
                ele = nums[i];
                cnt = 1;
            }

            else if(cnt != 0){
                if(ele == nums[i]) cnt++;
                else cnt--;
            }  
        }
        int check = 0 ;
        for(int i = 0 ; i < n ; i ++){
            if(nums[i] == ele) check++;
        }

        if(check>n/2) return ele;
        return -1;


    }
};