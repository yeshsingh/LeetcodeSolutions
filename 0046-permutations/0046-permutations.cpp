class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        int ans=1;
        vector<vector<int>> v;
        for(int i=1;i<=nums.size();i++)
        {
            ans=ans*i;
        }
        for(int i=0;i<ans;i++)
        {
            next_permutation(nums.begin(),nums.end());
            v.push_back(nums);
        }
        return v;
    }
};