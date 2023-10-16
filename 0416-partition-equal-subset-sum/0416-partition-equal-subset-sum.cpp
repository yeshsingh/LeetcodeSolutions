class Solution {
    bool ans(int ind,int target,vector<int> &arr,vector<vector<int>>& dp)
{
    if(target==0) { return true;}
    if(ind == 0) {return (arr[0]==target);}
    if(dp[ind][target]!=-1)
    {
        return dp[ind][target];
    }
    
    bool not_take=ans(ind-1,target,arr,dp);
    bool take=false;
    if(arr[ind]<=target)
    {
        take=ans(ind-1,target-arr[ind],arr,dp);
    }
    return dp[ind][target]= (take|not_take);
}
public:
    bool canPartition(vector<int>& nums) {
        int sum=0;
        for(int i=0;i<nums.size();i++)
        {
            sum=sum+nums[i];
        }
        vector<vector<int>> dp(nums.size(),vector<int>(sum+1,-1));
        if(sum%2==0)
        {
            sum=sum/2;
            return ans(nums.size()-1,sum,nums,dp);
            
        }
        else 
        {
            return false;
        }
    }
};