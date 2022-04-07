class StockSpanner {
public:
    // price, i
    stack<pair<int,int>> st;
    int i=0;
    StockSpanner() {
        st.push({-1,-1});
    }
    
    int next(int price) {
        while(st.top().second!=-1 and price>=st.top().first)
            st.pop();
        int ans = i-st.top().second;
        st.push({price,i++});
        return ans;
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */