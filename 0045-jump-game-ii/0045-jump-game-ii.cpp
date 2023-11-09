class Solution {
    int create(vector<int>& nums, int idx, vector<int>& dp) {
        if(nums.size()==1)
        { 
            return 0;
        }
        if(idx+nums[idx] >= nums.size()-1) return 1;
        if(nums[idx] == 0) return 1e9;
        
        if(dp[idx] != -1) return dp[idx]; 
        int take=1e9;
       for(int i=idx+1;i<=idx+nums[idx];i++)
            { 
                //cout<<idx<<" "<<take<<endl;
        
                take=min(1+create(nums,i,dp),take);
            }
        
        
        
        //cout<<take<<" "<<not_take<<" "<<dp[idx]<<endl;
        return dp[idx]=take;
    }
public:
    int jump(vector<int>& nums) {
        vector<int> dp(nums.size(), -1);
        int a= create(nums, 0, dp);
        if(a==1e9)
        {
            return -1;
        }
        return a;
    }
    
};
/*
[2,3,1,1,4]
[2,3,0,1,4]
[0]
[3,2,1]*/