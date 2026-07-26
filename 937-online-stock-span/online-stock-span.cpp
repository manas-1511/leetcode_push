class StockSpanner {
public:
        vector<int> ans ;

    StockSpanner() {
        ans.resize(0);

    }
        
    
    int next(int price) {
        ans.push_back(price);
        int cnt = 0 ;
        for(int i = ans.size()-1 ; i >= 0 ; i--){
            if(ans[i] > price) break;
            cnt++;
        }

        return cnt;
        

    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */