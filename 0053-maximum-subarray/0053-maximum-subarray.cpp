class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int sum=0,maxi=0,z=0,maxi1=-1e9;
        for(int i=0;i<nums.size();i++)
        {
            sum+=nums[i];
            if(sum<0)
            {
                sum=0;
                
            }
            else {
                z=1;
            }
            maxi=max(sum,maxi);
            maxi1=max(maxi1,nums[i]);
        }
        if(z==0)
        {
            return maxi1;
        }
        return maxi;
    }
};