class Solution {
    int ans(int i,int n,vector<int>& v,vector<vector<int>>& dp)
    {
        //cout<<v[i]<<" ";
        if(i>=v.size())
        {
            return 1e9;
        }
        if(n==0)
        {
            return 0;
        }
        if(v[i]>n)
        {
            return 1e9;
        }
        
        if(dp[i][n]!=-1)
        {
            return dp[i][n];
        }
        int take=1e9;
        if(v[i]<=n)
        {
            take=1+ans(i,n-v[i],v,dp);
        }
        int not_take=ans(i+1,n,v,dp);
        return dp[i][n]=min({take,not_take});
    }
    
public:
    int numSquares(int n) {
        
        vector <int> v;
        for(int i=1;i<=100;i++)
        {
            v.push_back(i*i);
        }
        vector<vector<int>> dp(v.size()+1,vector<int>(n+1,-1));
        return ans(0,n,v,dp);
    }
};