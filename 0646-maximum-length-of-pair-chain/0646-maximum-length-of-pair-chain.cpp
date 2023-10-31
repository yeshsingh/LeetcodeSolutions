class Solution {
    int ans(int i,int prev,vector<vector<int>>& pairs,vector<vector<int>>& dp)
    {
        if(i>=pairs.size())
        {
            return 0;
        }
        if(dp[i][prev+1]!=-1)
        {
            return dp[i][prev+1];
        }
        int not_take=ans(i+1,prev,pairs,dp);
        int take=0;
        if(prev==-1 || pairs[prev][1]<pairs[i][0])
        {
            take=1+ans(i+1,i,pairs,dp);
        }
        return dp[i][prev+1]=max({take,not_take});
    }
public:
    int findLongestChain(vector<vector<int>>& pairs) {
        vector<vector<int>> dp(pairs.size()+1,vector<int>(pairs.size()+2,-1));
        sort(pairs.begin(),pairs.end());
        return ans(0,-1,pairs,dp);
    }
};