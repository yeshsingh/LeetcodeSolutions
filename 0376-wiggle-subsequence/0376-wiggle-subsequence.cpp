class Solution {
    int ans(int i,int prev,vector<int>& nums,int last,vector<vector<vector<int>>>& dp)
    {
        if(i>=nums.size())
        {
            return 0;
        }
        if(dp[i][prev+1][last]!=-1)
        {
            return dp[i][prev+1][last];
        }
        int not_take=ans(i+1,prev,nums,last,dp);
        int take1=0;
        if(prev==-1)
        {
            take1=1+ans(i+1,i,nums,last,dp);
        }
        if(prev!=-1 && nums[i]-nums[prev]>0 && last==0)
        {
            take1=1+ans(i+1,i,nums,
                        1,dp);
        }
        if(prev!=-1 && nums[i]-nums[prev]<0 && last==1)
        {
            take1=1+ans(i+1,i,nums,0,dp);
        }
        return dp[i][prev+1][last]=max({take1,not_take});
        
    }
    
public:
    int wiggleMaxLength(vector<int>& nums) {
        vector<vector<vector<int>>>dp(nums.size()+1,vector<vector<int>>(nums.size()+2,vector<int>(2,-1)) );
        int a=ans(0,-1,nums,0,dp);
        int b= ans(0,-1,nums,1,dp);
        //return a;
        return max({a,b});
    }
};