class Solution {
public:
    int numIdenticalPairs(vector<int>& nums) {
        vector<int> v;
        map<int,int> m;
        for(int i=0;i<nums.size();i++)
        {
            m[nums[i]]++;
            if(m[nums[i]]==1)
            {
                v.push_back(nums[i]);
            }
        }
        int ans=0;
        for(int i=0;i<v.size();i++)
        {
            ans=ans+(m[v[i]]*(m[v[i]]-1))/2;
        }
        return ans;
    }
};