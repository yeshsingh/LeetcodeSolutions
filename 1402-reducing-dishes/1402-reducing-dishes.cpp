class Solution {
    int ans(int i,int j,vector<int>& satisfaction,vector<vector<int>>& dp)
    {
        if(i==satisfaction.size())
        {
            return 0;
        }
        if(dp[i][j]!=-1e7)
        {
            return dp[i][j];
        }
        int not_take=ans(i+1,j,satisfaction,dp);
        int take=(satisfaction[i]*(j+1))+ans(i+1,j+1,satisfaction,dp);
        return dp[i][j]=max({take,not_take});
    }
public:
    int maxSatisfaction(vector<int>& satisfaction) {
        vector<vector<int>> dp(501,vector<int>(1e4,-1e7));
        sort(satisfaction.begin(),satisfaction.end());
        return ans(0,0,satisfaction,dp);
    }
};
