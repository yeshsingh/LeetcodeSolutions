class Solution {
    int ans(int i,int j,string& s,vector<vector<int>>& dp)
    {
        if(i>=s.size() || j<0)
        {
            return 0;
        }
        if(dp[i][j]!=-1)
        {
            return dp[i][j];
        }
        if(s[i]==s[j])
        {
            return dp[i][j]=1+ans(i+1,j-1,s,dp);
        }
        int f_move=ans(i+1,j,s,dp);
        int s_move=ans(i,j-1,s,dp);
        return dp[i][j]=max(f_move,s_move);
    }
public:
    int minInsertions(string s) {
        vector<vector<int>> dp(s.size(),vector<int>(s.size()+1,-1));
        return s.size()-ans(0,s.size()-1,s,dp);
    }
};