class Solution {
    int solve(int i,int j, int m, int n, vector<vector<int>>& dp)
    {
        if(n<=j || m<=i)
        {
            return 0;
        }
        
        if(i==(m-1) && j==(n-1))
        {
            return 1;
        }
        if(dp[i][j]!=-1)
        {
            return dp[i][j];
        }
        int a1=solve(i+1,j,m,n,dp);
        int a2=solve(i,j+1,m,n,dp);
        dp[i][j]=a1+a2;
        return dp[i][j];
    }
public:
    int uniquePaths(int m, int n) {
        vector<vector<int>> dp(m,vector<int>(n));
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                dp[i][j]=-1;
            }
        }
        int ans= solve(0,0,m,n,dp);
        return ans;
    }
};