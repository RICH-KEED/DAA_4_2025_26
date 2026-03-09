class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        map<int,int,greater<int>> mp; 
        vector<int> res;
        for(int x: nums)
        {
            mp[x]++;
        }

        vector<pair<int,int>> v;

        for(auto it : mp)
            v.push_back({it.second, it.first}); 

        sort(v.rbegin(), v.rend());

        int count =0;
        for(int i=0;i<k;i++)  res.push_back(v[i].second);
        return res;
    }
};