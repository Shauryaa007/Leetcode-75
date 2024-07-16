/ 216. Combination Sum III

class Solution {
public:
    void solve(vector<vector<int>>&ans, vector<int>& temp, int k, int n, int start){
        if(k==0 && n==0){
            ans.push_back(temp); 
            return; 
        }
        if((n==0) || (k==0 )){
            return; 
        }

        for(int num=start; num<=9; num++){
            if(num > n){
                break; 
            }
            temp.push_back(num); 
            solve(ans, temp, k-1, n-num, num+1); 
            temp.pop_back(); 
        }
    }
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>> ans; 
        vector<int> temp; 

        solve(ans, temp, k, n, 1); 
        return ans; 
    }
};