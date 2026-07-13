class Solution {
public:

    bool check(string temp){
        if(temp.size() ==1) return true;
        for(int i = 1 ; i < temp.size() ; i++){
            if(temp[i] != temp[i-1]+1) return false;
        }

        return true;
    }

    vector<int> sequentialDigits(int low, int high) {
        
        
    string s = to_string(low);
    int size = s.size();
    // if(size>=10) return -1;
    string temp  = "";
    string add = "";
    
    for(int i = 1 ; i <= size ; i++){
        temp+=to_string(i);
        add+='1';
    }
    vector<int> ans;
    string l = to_string(low);
    string h = to_string(high);
    
        while(stoi(temp)<=high){
            if(check(temp)){
                if(stoi(temp)>=low)ans.push_back(stoi(temp));
                temp = to_string(stoi(temp)+stoi(add));
            }

            else{
                add+='1';
                size++;
                temp.clear();
                for(int i = 1 ; i <= size ; i++){
                    temp+=to_string(i);

                }

            }

            if(temp.size() > 9) break;
        }

        return ans;
    }
};