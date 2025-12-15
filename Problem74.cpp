class Solution {
public:
    vector<int> dailyTemperatures( vector<int>& temperatures) {
        stack<int> st;
        
        vector<int> res(temperatures.size(), 0);

        for (int i = temperatures.size() - 1; i >= 0; --i) {
            if (st.empty()) {
                st.push(i);
                res[i] = 0;
            } else {
                while (!st.empty() && temperatures[i] >= temperatures[st.top()]) {
                    st.pop();
                }

                if (st.empty()) {
                    res[i] = 0;
                } else {
                    res[i] = st.top() - i;
                }

                st.push(i);
            }
        }

        return res;
    }
}; 

