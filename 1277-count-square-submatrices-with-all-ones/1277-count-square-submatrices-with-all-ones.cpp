class Solution {
public:
    int countSquares(vector<vector<int>>& mat) {
        int ans=0,dp[mat.size()+1][mat[0].size()+1];
        memset(dp,0,sizeof dp);
        
        for(int i=1;i<=mat.size();i++) {
            for(int j=1;j<=mat[0].size();j++) {
                if(mat[i-1][j-1] == 0) continue;
                
                dp[i][j]=min({dp[i-1][j]+1,dp[i][j-1]+1,dp[i-1][j-1]+1});
                ans+=dp[i][j];
            }
        }
        return ans;
    }
};