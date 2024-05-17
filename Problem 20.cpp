// 2215. Find the Difference of Two Arrays
class Solution {
public:
    vector<vector<int>> findDifference(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int ,int>m1,m2;

        for(int i=0;i<nums1.size();i++)m1[nums1[i]]++;

        for(int i=0;i<nums2.size();i++)m2[nums2[i]]++;

        vector<int>ans1,ans2;

        for(auto it :m1)
        {
            if(m2.count(it.first)==0)ans1.push_back(it.first);
        }

        for(auto it :m2)
        {
            if(m1.count(it.first)==0)ans2.push_back(it.first);
        }

        return {ans1,ans2};
    }
};