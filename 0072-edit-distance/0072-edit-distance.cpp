class Solution {
    int ans(int i,int j , string& word1, string& word2, vector<vector<int>>& dp)
    {
        if(i<0)
        {
            return (j+1);
        }
        if(j<0)
        {
            return (i+1);
        }
        if(dp[i][j]!=-1)
        {
            return dp[i][j];
        }
        if(word1[i]==word2[j])
        {
            return dp[i][j]=0+ans(i-1,j-1,word1,word2,dp);
        }
        return dp[i][j]=min({(1+ans(i-1,j,word1,word2,dp)),(1+ans(i,j-1,word1,word2,dp)),(1+ans(i-1,j-1,word1,word2,dp))});
    }
    
public:
    int minDistance(string word1, string word2) {
        vector<vector<int>> dp(word1.size(),vector<int>(word2.size()+1,-1));
        return ans(word1.size()-1,word2.size()-1,word1,word2,dp);
    }
};