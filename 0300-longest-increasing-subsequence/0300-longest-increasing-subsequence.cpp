class Solution {
    int ans(int ind,int previous,vector<int>& nums,vector<vector<int>>& dp)
    {
        if(ind==nums.size())
        {
            return 0;
        }
        if(dp[ind][previous+1]!=-1)
        {
            return dp[ind][previous+1];
        }
        int not_take=ans(ind+1,previous,nums,dp);
        int take=0;
        if(previous==-1 || nums[ind]>nums[previous])
        {
            take=1+ans(ind+1,ind,nums,dp);
        }
        return dp[ind][previous+1]=max({not_take,take});
    }
public:
    int lengthOfLIS(vector<int>& nums) {
        vector<vector<int>> dp(nums.size(),vector<int>(nums.size()+2,-1));
        return ans(0,-1,nums,dp);
    }
};