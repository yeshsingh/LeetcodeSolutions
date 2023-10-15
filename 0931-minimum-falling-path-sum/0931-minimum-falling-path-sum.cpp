class Solution {
    int solve(int i,int j,int m,int n, vector<vector<int>>& matrix, vector<vector<int>>& dp)
    {
        
        if(n<j || j<0)
        {
            return 1e8;
        }
        if(i==m)
        {
        
            return matrix[i][j];
        }
        if(dp[i][j]!=1e9)
        {
            return dp[i][j];
        }
        
        int a2=matrix[i][j]+solve(i+1,j,m,n,matrix,dp);
        int a3=matrix[i][j]+solve(i+1,j+1,m,n,matrix,dp);
        int a4=matrix[i][j]+solve(i+1,j-1,m,n,matrix,dp);
        int ans=min({a2,a3});
        return dp[i][j]=min({ans,a4});
        
    }
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int m=matrix.size();
        int n=matrix[0].size();
        vector<vector<int>>dp(m,vector<int>(n));
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                dp[i][j]=1e9;
            }
        }
        int ans=1e9;
        int k=n;
        m--;
        n--;
        for(int j=0;j<k;j++)
        {
            ans=min(ans,solve(0,j,m,n,matrix,dp));
        }
        
        return ans;
    }
};