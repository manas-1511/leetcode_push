class Solution {
public:
    vector<string> ans ; 
    int total = 0;
    void helper(int pos , int k  , int n,bool flag ,  string& temp ){
        if(k>total) return;
        if(pos==n) {
            ans.push_back(temp);
            return;
        }

        temp+='0';
        helper(pos+1 , k , n ,false  , temp);
        temp.pop_back();

        if(flag == false){
            temp += '1';
            helper(pos+1 , k+pos , n , true  , temp);
            temp.pop_back();
        }





    }
    vector<string> generateValidStrings(int n, int k) {
        string temp = "";
        total = k;
        helper(0 , 0 , n , false , temp );
        return ans ;
        
    }
};