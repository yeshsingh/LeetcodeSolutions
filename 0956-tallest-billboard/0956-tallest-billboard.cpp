class Solution {
    int ans(int i,int diff,vector<int>& rods,vector<vector<int>>& dp)
    {
        if(i==rods.size())
        {
            if(diff==0)
            {
                return 0;
            }
            else 
            {
                return -1e9;
            }
        }
        if(dp[i][diff]!=-1)
        {
            return dp[i][diff];
        }
        int not_take=ans(i+1,diff,rods,dp);
        int l=rods[i]+ans(i+1,diff+rods[i],rods,dp);
        int r=ans(i+1,abs(diff-rods[i]),rods,dp)+max({0,rods[i]-diff});
        return dp[i][diff]=max({l,r,not_take});
    }
public:
    int tallestBillboard(vector<int>& rods) {
        vector<vector<int>> dp(rods.size()+1,vector<int>(5e4+2,-1));
        return ans(0,0,rods,dp);
    }
};