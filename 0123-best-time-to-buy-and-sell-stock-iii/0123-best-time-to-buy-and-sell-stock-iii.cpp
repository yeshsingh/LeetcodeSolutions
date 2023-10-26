class Solution {
    int ans(int i,int buy,vector<int>& prices,int trans,vector<vector<vector<int>>>& dp)
    {
        if(i==prices.size() || trans==2)
        {
            return 0;
        }
        if(dp[i][buy][trans]!=-1)
        {
            return dp[i][buy][trans];
        }
        if(buy==0)
        {
            int take=ans(i+1,1,prices,trans,dp)-prices[i];
            int not_take=ans(i+1,0,prices,trans,dp);
            return dp[i][buy][trans]=max({take,not_take});
        }
        else 
        {
            int take=prices[i]+ans(i+1,0,prices,trans+1,dp);
            int not_take=ans(i+1,1,prices,trans,dp);
            return dp[i][buy][trans]=max({take,not_take});
        }
    }
    
public:
    int maxProfit(vector<int>& prices) {
        vector<vector<vector<int>>>dp(prices.size(),vector<vector<int>>(2,vector<int>(3,-1)));
        return ans(0,0,prices,0,dp);
    }
};