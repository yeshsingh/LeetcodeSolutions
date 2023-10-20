class Solution {
    int solve(int i, vector<int>& nums, vector<unordered_map<int,int>>& dp,int target,int sum)
    {
        if(i<0)
        {
            if(target==sum)
            {
                return 1;
            }
            else 
            {
                return 0;
            }
        }
        if(dp[i][sum]!=0)
        {
            return dp[i][sum];
        }
        int a1=solve(i-1,nums,dp,target,sum+nums[i]);
        int a2=solve(i-1,nums,dp,target,sum-nums[i]);
        dp[i][sum]=a1+a2;
        return dp[i][sum];
    }
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        vector<unordered_map<int,int>> dp(nums.size());
        return solve(nums.size()-1,nums,dp,target,0);
    }
};