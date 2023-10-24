class Solution {
    int ans(int i, int j,string& word1, string& word2,vector<vector<int>>& dp)
    {
        if(i>=word1.size() || j>=word2.size())
        {
            return 0;
        }
        if(dp[i][j]!=-1)
        {
            return dp[i][j];
        }
        if(word1[i]==word2[j])
        {
            return dp[i][j]=1+ans(i+1,j+1,word1,word2,dp);
        }
        int f_move=ans(i+1,j,word1,word2,dp);
        int s_move=ans(i,j+1,word1,word2,dp);
        return dp[i][j]=max(f_move,s_move);
    }
public:
    int minDistance(string word1, string word2) {
        vector<vector<int>> dp(word1.size(),vector<int>(word2.size()+1,-1));
        int a=ans(0,0,word1,word2,dp);
        return ((word1.size()-a)+(word2.size()-a));
    }
};