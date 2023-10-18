class Solution {
    bool ans(int n, vector<bool>& dp)
    {
        for(int i=2;i<=n;i++)
        {
            for(int j=1;j<i;j++)
            {
                if(i%j==0)
                {
                    if(dp[i-j]==0)
                    {
                        dp[i]=true;
                    }
                }
            }
        }
        return dp[n];
    }
public:
    bool divisorGame(int n) {
        vector<bool> dp(n+1);
        dp[0]=false;
        dp[1]=false;
        return ans(n,dp);
    }
};