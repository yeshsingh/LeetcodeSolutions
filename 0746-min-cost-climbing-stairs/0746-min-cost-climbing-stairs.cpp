class Solution {
public:
    int ans(int i, vector<int> &dp, vector<int>& cost)
    {
        if(cost.size()<=i)
        {
            return 0;
        }
        if(dp[i]!=-1)
        {
            return dp[i];
        }
        int take1=cost[i]+ans(i+1,dp,cost);
        int take2=cost[i]+ans(i+2,dp,cost);
        if(take1<take2)
        {
            dp[i]=take1;
        }
        else 
        {
            dp[i]=take2;
        }
        return dp[i];
    }
    int minCostClimbingStairs(vector<int>& cost) {
        vector<int> dp;
        for(int i=0;i<cost.size();i++)
        {
            dp.push_back(-1);
        }
        int a1=ans(0,dp,cost);
        int a2=ans(1,dp,cost);
        int ans;
        if(a1<a2)
        {
            ans=a1;
        }
        else 
        {
            ans=a2;
        }
        return ans;
    }
};