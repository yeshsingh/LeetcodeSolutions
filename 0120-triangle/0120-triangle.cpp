class Solution {
    int solve(int i,int j,int m,int n, vector<vector<int>>& triangle, vector<vector<int>>& dp)
    {
        if(i==m)
        {
            return triangle[i][j]; 
        }
        if(m<i)
        {
            return 1e9;
        }
        if(dp[i][j]!=-1)
        {
            return dp[i][j];
        }
        int a1=triangle[i][j]+solve(i+1,j,m,n,triangle,dp);
        int a2=triangle[i][j]+solve(i+1,j+1,m,n,triangle,dp);
        dp[i][j]=min({a1,a2});
        return dp[i][j];
    }
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int m=triangle.size();
        int n=triangle[triangle.size()-1].size();
        vector<vector<int>>dp(m,vector<int>(n));
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                dp[i][j]=-1;
            }
        }
        int ans=solve(0,0,m-1,n-1,triangle,dp);
        return ans;
    }
};