class Solution {
    int ans(int i,vector<int>& nums,vector<int>& dp)
    {
        if(nums.size()<=i)
        {
            return 0;
        }
    if(dp[i]!=-1)
    {
        return dp[i];
    }
    int a=nums[i]+ans(i+2,nums,dp);
    int a1=ans(i+1,nums,dp);
    a=max({a,a1});
    return dp[i]=a;
    }
public:
    int rob(vector<int>& nums) {
        vector<int> dp;
        for(int i=0;i<nums.size();i++)
        {
            dp.emplace_back(-1);
        }
        return ans(0,nums,dp);
    }
};