class Solution {
    int solve(int i,int j, int m, int n, vector<vector<int>>& obstacleGrid, vector<vector<int>>& dp)
    {
        if(n<=j || m<=i || obstacleGrid[i][j]==1)
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
        
        int a1=solve(i+1,j,m,n,obstacleGrid,dp);
        int a2=solve(i,j+1,m,n,obstacleGrid,dp);
        dp[i][j]=a1+a2;
        return dp[i][j];
    }
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m=obstacleGrid.size();
        int n=obstacleGrid[0].size();
        vector<vector<int>> dp(m,vector<int>(n));
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                dp[i][j]=-1;
            }
        }
        int ans= solve(0,0,m,n,obstacleGrid,dp);
        return ans;
    }
};
