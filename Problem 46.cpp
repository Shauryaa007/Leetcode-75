// 399. Evaluate Division
 
class Solution {
public:
    unordered_map<string,vector<pair<string,double>>> mp;
    unordered_set<string> s;
    double helper(string node,string des){
        if(node==des){
            return 1;
        }
        s.insert(node);
        for(auto a:mp[node]){
            if(s.find(a.first)==s.end()){
                double temp=a.second*helper(a.first,des);
                if(temp>0){
                    return temp;
                }
            }
        }
        return -1;
    }
    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
        int n=equations.size();
        unordered_set<string> s2;
        for(int i=0;i<n;i++){
            mp[equations[i][0]].push_back({equations[i][1],values[i]});
            mp[equations[i][1]].push_back({equations[i][0],1.0/values[i]});
            s2.insert(equations[i][0]);
            s2.insert(equations[i][1]);
        }
        int m=queries.size();
        vector<double> ans;
        for(int i=0;i<m;i++){
            string a=queries[i][0];
            string b=queries[i][1];
            if(s2.find(a)==s.end() || s2.find(b)==s.end()){
                ans.push_back(-1);
                continue;
            }
            ans.push_back(helper(a,b));
            s.clear();
        }
        return ans;
    }
};