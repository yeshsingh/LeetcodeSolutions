class Solution {
public:
    int maxSubarraySumCircular(vector<int>& nums) {
        
        int sum=0,mini=INT_MAX,t_sum=0,maxi=INT_MIN,sum2=0;
        for(int i=0;i<nums.size();i++)
        {
            t_sum+=nums[i];
            if(nums[i]+sum>0)
            {
                sum=0;
            }
            else 
            {
                sum+=nums[i];
            }
            mini=min({sum,mini});
            if(nums[i]+sum2<nums[i]){
                sum2=nums[i];
            }else{
                sum2+=nums[i];
            }
            maxi=max({maxi,sum2});
        }
        if(mini==0)
        {
            return t_sum;
        }
        if(t_sum==mini)
        {
            return maxi;
        }
        if(t_sum==mini)
        {
            return maxi;
        }
        return max({t_sum-mini,maxi});
    }
};