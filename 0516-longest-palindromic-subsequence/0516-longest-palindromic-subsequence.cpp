class Solution {
    int ans(int i,int j,string& s,vector<vector<int>>& dp)
    {
       if(i>=s.size() || 0>j)
       {
           return 0;
       }
    if(s[i]==s[j])
    {
        return dp[i][j]=1+ans(i+1,j-1,s,dp);
    }
        if(dp[i][j]!=-1)
        {
            return dp[i][j];
        }
    int f_move=ans(i+1,j,s,dp);
    int s_move=ans(i,j-1,s,dp);
        return dp[i][j]=max(f_move,s_move);
    }
public:
    int longestPalindromeSubseq(string s) {
        vector<vector<int>>dp(s.size()+1,vector<int>(s.size()+2,-1));
       
        
        return ans(0,s.size()-1,s,dp);
    }
};