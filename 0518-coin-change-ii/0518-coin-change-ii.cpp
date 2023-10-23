class Solution {
    int ans(int i,int amount,vector<int>& coins,vector<vector<int>>& dp)
    {
        if(i>=coins.size() || amount<=0)
        {
            
            if(amount==0)
            {
                //cout<<i<<endl;
                return 1;
            }
            else 
            {
                return 0;
            }
            
        }
        if(amount==0)
        {
            
            return 1;
        }
        if(dp[i][amount]!=-1)
        {
            return dp[i][amount];
        }
        if(amount>=coins[i])
        {
            int stay=ans(i,amount-coins[i],coins,dp);
            int move=ans(i+1,amount,coins,dp);
            dp[i][amount]=stay+move;
            return dp[i][amount];   
        }
        else 
        {
            dp[i][amount]=ans(i+1,amount,coins,dp);
            return dp[i][amount];  
        }
    }
public:
    int change(int amount, vector<int>& coins) {
        vector<vector<int>> dp(coins.size()+2,vector<int>(amount+2,-1));
        return ans(0,amount,coins,dp);
    }
};