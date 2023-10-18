class Solution {
    int ans(int i,int n,vector<vector<int>>& dp)
    {
        if(n==0)
        {
            return 1;
        }
        if(i>=5)
        {
            return 0;
        }
        if(dp[i][n]!=-1)
        {
            return dp[i][n];
        }
        int pick=ans(i,n-1,dp);
        int not_pick=ans(i+1,n,dp);
        return dp[i][n]=pick+not_pick;
    }
public:
    int countVowelStrings(int n) {
        vector<vector<int>> dp(5, vector<int>(n+1,-1));
        return ans(0,n,dp);
    }
};