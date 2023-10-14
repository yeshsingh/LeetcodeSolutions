class Solution {
    int solve(int m,int n, vector<vector<int>>& grid, vector<vector<int>>& dp)
    {
        if(m==0 && n==0)
        {
            return grid[m][n];
        }
        if(m<0 || n<0)
        {
            return 1e9;
        }
        if(dp[m][n]!=-1)
        {
            return dp[m][n];
        }
        int a1=grid[m][n]+solve(m-1,n,grid,dp);
        int a2=grid[m][n]+solve(m,n-1,grid,dp);
        dp[m][n]=min({a1,a2});
        return dp[m][n];
    }
public:
    int minPathSum(vector<vector<int>>& grid) {
        int m=grid.size();
        int n=grid[0].size();
        vector<vector<int>> dp(m,vector<int>(n));
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                dp[i][j]=-1;
            }
        }
        int ans=solve(m-1,n-1,grid,dp);
        return ans;
    }
};