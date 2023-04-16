class Solution {
public:
    int maxDivScore(vector<int>& nums, vector<int>& divisors) {
        int maxi=INT_MIN,ans=0;
        for(int i=0;i<divisors.size();i++)
        {
            int c=0;
            for(int j=0;j<nums.size();j++)
            {
                if(nums[j]%divisors[i]==0)
                {
                    c++;
                }
            }
            if(c>maxi)
            {
                maxi=c;
                ans=divisors[i];
            }
            else if(c==maxi)
            {
                ans=min(ans,divisors[i]);
            }
        }
        return ans;
    }
};