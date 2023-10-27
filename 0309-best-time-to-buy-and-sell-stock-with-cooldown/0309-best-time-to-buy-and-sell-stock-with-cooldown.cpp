class Solution {
    int ans(int i,int buy, vector<int>& prices,vector<vector<int>>& dp)
    {
        if(i>=prices.size())
        {
            return 0;
        }
        if(dp[i][buy]!=-1)
        {
            return dp[i][buy];
        }
        if(buy==0)
        {
            int take=ans(i+1,1,prices,dp)-prices[i];
            int not_take=ans(i+1,0,prices,dp);
            return dp[i][buy]=max({take,not_take});
        }
        else 
        {
            int take=ans(i+2,0,prices,dp)+prices[i];
            int not_take=ans(i+1,1,prices,dp);
            return dp[i][buy]=max({take,not_take});
        }
    }
public:
    int maxProfit(vector<int>& prices) {
        vector<vector<int>> dp(prices.size(),vector<int>(2,-1));
        return ans(0,0,prices,dp);
    }
};