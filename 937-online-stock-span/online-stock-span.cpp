class StockSpanner {
public:
        int i ; 
        stack<pair<int , int>> st;
    StockSpanner() {
         i = 0 ;
    }
        
        
        
    
    int next(int price) {
        while(!st.empty() && st.top().first <= price) st.pop();
        int pge = (st.empty())?-1:st.top().second;
        int len = i-pge;
        st.push({price , i});
        i++;
        return len;
        

    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */