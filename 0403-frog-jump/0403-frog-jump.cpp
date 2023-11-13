class Solution {
    bool ans(int i,vector<int>& stones,int k,vector<vector<int>>& dp)
    {
        
        if(i==stones.size()-1)
        {
            return 1;
        }
        if(dp[i][k]!=-1)
        {
            return dp[i][k];
        }
        int t=0;
        for(int j=k-1;j<=k+1;j++)
        {
            for(int l = i+1 ; l<stones.size() && stones[l] <= stones[i]+k+1 ; l++){
                if(stones[l] == stones[i] + j )
                    t |= ans(l , stones,j,dp);
            }
        }
        return dp[i][k]=t;
    }
public:
    bool canCross(vector<int>& stones) {
        vector<vector<int>> dp(stones.size(),vector<int>(stones.size()+1,-1));
        if(stones[1]-stones[0]>1)
        {
            return 0;
        }
        return ans(1,stones,1,dp);
    }
};