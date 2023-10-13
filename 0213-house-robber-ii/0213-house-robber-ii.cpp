class Solution {
    int ans(int i,vector<int>& nums,vector<int>& dp, int n)
    {
        if(n<=i)
        {
            return 0;
        }
    if(dp[i]!=-1)
    {
        return dp[i];
    }
    int a=nums[i]+ans(i+2,nums,dp,n);
    int a1=ans(i+1,nums,dp,n);
    a=max({a,a1});
    return dp[i]=a;
    }
public:
    int rob(vector<int>& nums) {
        vector<int> dp;
        if(nums.size()==1)
        {
            return nums[0];
        }
        for(int i=0;i<nums.size();i++)
        {
            dp.emplace_back(-1);
        }
        int a1= ans(1,nums,dp,nums.size());
        for(int i=0;i<nums.size();i++)
        {
            dp[i]=-1;
        }
        int a2=ans(0,nums,dp,nums.size()-1);
        a2=max({a1,a2});
        return a2;
    }
};