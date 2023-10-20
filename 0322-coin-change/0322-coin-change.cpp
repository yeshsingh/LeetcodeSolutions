class Solution {
    int dp[12 + 1][10000 + 1];
    int ans(int i,vector<int>& coins, int amount)
    {
        if(amount<=0 || coins.size()<=i)
        {
            if(amount==0)
            {
                return 0;
            }
            else 
            {
                return INT_MAX-1;
            }
        }
        if(dp[i][amount]!=-1)
        {
            return dp[i][amount];
        }
        int take2=ans(i+1,coins,amount);
        int take1=INT_MAX;
        if(amount>=coins[i])
        {
            take1=1+ans(i,coins,amount-coins[i]);
            
        }
        dp[i][amount]=min({take2,take1});
        return dp[i][amount];
    }
public:
    int coinChange(vector<int>& coins, int amount) {
        memset(dp, -1, sizeof(dp));
        int a1=ans(0,coins,amount);
        if(a1==INT_MAX-1)
        {
            return -1;
        }
        else 
        {
            return a1;
        }
    }
};