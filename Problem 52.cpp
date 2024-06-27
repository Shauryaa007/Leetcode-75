//2462. Total Cost to Hire K Workers

class Solution {
public:
    long long totalCost(vector<int>& costs, int k, int candidates) {
        int n=costs.size();
        priority_queue<int, vector<int>, greater<int> >pq1,pq2;
        int i=0;
        int j=n-1;

        while(pq1.size()<candidates  && i<=j) pq1.push(costs[i++]);
        while(pq2.size()<candidates && j>=i) pq2.push(costs[j--]);

        long long ans=0;

        while(k--)
        {
            int a = pq1.size() > 0 ? pq1.top() : INT_MAX; 
            int b = pq2.size() > 0 ? pq2.top() : INT_MAX;
            if(a<=b){
                ans+=a;
                pq1.pop();
                if(i<=j)pq1.push(costs[i++]);
            }
            else{
                ans+=b;
                pq2.pop();
                if(i<=j)pq2.push(costs[j--]);
            }
        }

        return ans;
    }
};