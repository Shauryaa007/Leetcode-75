// 735. Asteroid Collision

class Solution {
public:
    vector<int> asteroidCollision(vector<int>& as) {
        stack<int>st;
        for(int i=0;i<as.size();i++)
        {
            if(st.empty()|| as[i]>0)st.push(as[i]);

            else
            {
                while(!st.empty()&& st.top()>0 && st.top()<abs(as[i]))st.pop();
                if(st.empty()||st.top()<0)st.push(as[i]);
                
                //if(st.top()>0 && st.top()>as[i]) ignore

                if(!st.empty()&& st.top()>0 && st.top()==abs(as[i]))st.pop();
            }
        }

        vector<int> ans(st.size(), 0);
        int size = st.size();
        while(!st.empty()){
            ans[--size] = st.top();
            st.pop();
        }
        return ans;
    }
};