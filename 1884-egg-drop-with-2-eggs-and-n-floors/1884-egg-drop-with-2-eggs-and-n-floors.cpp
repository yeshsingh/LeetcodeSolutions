class Solution {
    int dp[1005][4];
    int ans(int n,int eggs)
    {
        if(dp[n][eggs]!=-1)
        {
            return dp[n][eggs];
        }
        if(n<=1)
        {
            return n;
        }
        if(eggs==1)
        {
            return n;
        }
        int mini=1e6;
        for(int i=1;i<n;i++)
        {
            mini=min(mini,max(ans(i-1,eggs-1),ans(n-i,eggs))+1);
        }
        return dp[n][eggs]=mini;
    }
public:
    int twoEggDrop(int n) {
        memset(dp,-1,sizeof(dp));
        return ans(n,2);
    }
};

