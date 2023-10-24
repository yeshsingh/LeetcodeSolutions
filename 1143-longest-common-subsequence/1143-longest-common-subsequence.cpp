class Solution {
    int ans(int i,int j,string& text1, string& text2,vector<vector<int>>& dp)
    {
        if(i>=text1.size() || j>=text2.size())
        {
            return 0;
        }
        if(dp[i][j]!=-1)
        {
            return dp[i][j];
        }
        if(text1[i]==text2[j])
        {
            return dp[i][j]=1+ans(i+1,j+1,text1,text2,dp);
        }
        int f_move=ans(i+1,j,text1,text2,dp);
        int s_move=ans(i,j+1,text1,text2,dp);
        dp[i][j]=max(f_move,s_move);
        return dp[i][j];
    }
    
public:
    int longestCommonSubsequence(string text1, string text2) {
        vector<vector<int>> dp(text1.size(),vector<int>(text2.size()+1,-1));
        return ans(0,0,text1,text2,dp);
    }
};