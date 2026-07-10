class Solution {
public:
    int trap(vector<int>& arr) {
        //TC O(n)
        //SC O(1)
        int n = arr.size();
        int l = 0 ; 
        int r= n-1 ;
        int lmax = 0 , rmax = 0 , total = 0 ;
        while(l<r){
            if(arr[l] <= arr[r]){
                if(lmax > arr[l]){
                    total+=lmax-arr[l];
                }

                else{
                    //arr[l] > lmax then update it
                    lmax = arr[l];
                }
                l++;
            }

            else{
                //now the arr[r] > arr[l] i have to decrease r-- and before moving have to check 
                //whether that cell can contain water or not just by checking the right side 
                //not the left side bcz the left side has already larger or equal walls than rmax 
                //if rcurr < rmax then the water can be stored 
                if(rmax > arr[r]) total+=rmax-arr[r];
                else rmax = arr[r];

                r--;
            }
        }

        return total;


    }
};