class Solution {
    int ans(int i,int j,vector<int>& cuts,vector<vector<int>>& dp)
    {
        if(j<=i+1)
        {
            return 0;
        }
        if(dp[i][j]!=-1)
        {
            return dp[i][j];
        }
        int mini=INT_MAX;
        for(int k=i+1;k<j;k++)
        {
            int cost=cuts[j]-cuts[i]+ans(i,k,cuts,dp)+ans(k,j,cuts,dp);
            mini= min({cost,mini});
        }
        return dp[i][j]=mini;
    }
public:
    int minCost(int n, vector<int>& cuts) {
        cuts.push_back(0);
        cuts.push_back(n);
        sort(cuts.begin(),cuts.end());
        vector<vector<int>>dp (cuts.size(),vector<int>(cuts.size()+1,-1));
        return ans(0,cuts.size()-1,cuts,dp);
    }
};