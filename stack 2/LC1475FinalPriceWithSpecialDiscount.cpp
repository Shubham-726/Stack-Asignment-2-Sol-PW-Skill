class Solution {
public:
    vector<int> finalPrices(vector<int>& prices) {
        vector<int>v;
        stack<int>st;
        int len = prices.size();
        st.push(prices[len-1]);
        v.push_back(prices[len-1] - 0);
        for(int i = len-2; i>= 0; i--){
            while(!st.empty() && prices[i] < st.top()){
                st.pop();
            }
            if(st.size() == 0) v.push_back(prices[i]-0);
            else v.push_back(prices[i] - st.top());
            st.push(prices[i]);
        }
        reverse(v.begin(), v.end());
        return v;
    }
};