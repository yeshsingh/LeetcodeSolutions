class Solution {
    bool ans(int i,int j,vector<int>& piles,int k,int score1,int score2,vector<vector<int>>& dp)
    {
        if(i>=j)
        {
            if(score1>score2)
            {
                return 1;
            }
            return 0;
        }
        if(dp[i][j]!=-1)
        {
            return dp[i][j];
        }
        int f_take=0,b_take=0;
        if(k==0)
        {
            f_take=ans(i+1,j,piles,1,score1+piles[i],score2,dp);
            b_take=ans(i,j-1,piles,1,score1+piles[j],score2,dp);
        }
        else 
        {
            f_take=ans(i+1,j,piles,0,score1,score2+piles[i],dp);
            b_take=ans(i,j-1,piles,0,score1,score2+piles[j],dp);
        }
        return dp[i][j]=(f_take|b_take);
    }
public:
    bool stoneGame(vector<int>& piles) {
        vector<vector<int>> dp(piles.size()+1, vector<int>(piles.size()+1,-1));
        return ans(0,piles.size()-1,piles,0,0,0,dp);
    }
};