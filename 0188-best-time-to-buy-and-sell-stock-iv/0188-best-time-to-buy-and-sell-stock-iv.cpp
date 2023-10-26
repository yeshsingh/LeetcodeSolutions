class Solution {
    int ans(int i,int buy,vector<int>& prices,vector<vector<vector<int>>>& dp,int trans,int k)
    {
        if(i==prices.size()||trans==k)
        {
            return 0;
        }
        if(dp[i][buy][trans]!=-1)
        {
            return dp[i][buy][trans];
        }
        if(buy==0)
        {
            int take=ans(i+1,1,prices,dp,trans,k)-prices[i];
            int not_take=ans(i+1,0,prices,dp,trans,k);
            return dp[i][buy][trans]=max({take,not_take});
        }
        else 
        {
            int take=ans(i+1,0,prices,dp,trans+1,k)+prices[i];
            int not_take=ans(i+1,1,prices,dp,trans,k);
            return dp[i][buy][trans]=max({take,not_take});
        }
    }
public:
    int maxProfit(int k, vector<int>& prices) {
        vector<vector<vector<int>>> dp(prices.size(),vector<vector<int>>(2,vector<int>(k+1,-1)));
        return ans(0,0,prices,dp,0,k);
    }
};