class Solution {
    long long  dp[100005][2];
    long long ans(int i,int x,vector<int>& nums,int c)
    { 
       
    if(i==nums.size())
    {
        return 0;
    }
    if(dp[i][c]!=-1)
    {
        return dp[i][c];
    }
    long long a1=ans(i+1,x,nums,c);
    
    long long a2=nums[i]+ans(i+1,x,nums,(nums[i]&1));
    if((nums[i]&1) != c)
    {
        a2-=x;
    }
   
    return dp[i][c]=max(a1,a2);
    }
public:
    long long maxScore(vector<int>& nums, int x) {
        memset(dp, -1, sizeof(dp));
        return nums[0]+ans(1,x,nums,1&nums[0]);
    }
};