class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> s(wordList.begin() , wordList.end());
        queue<pair<string , int>> q;
        q.push({beginWord , 1});
        s.erase(beginWord);
        while(!q.empty()){
            auto [str , len] = q.front();
            q.pop();
            if(str == endWord) return len;
            
            for(int i = 0 ; i < str.length() ; i++){
                    string temp = str;
                for(char c = 'a' ; c <= 'z' ; c++){
                    str[i] = c;
                    if(s.count(str)){
                        q.push({str , len+1});
                        s.erase(str);
                    }

                    
                }
                    str = temp;
            }
        }

        return 0;


    }
};