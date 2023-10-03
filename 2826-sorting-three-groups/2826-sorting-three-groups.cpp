class Solution {
public:
    int minimumOperations(vector<int>& nums) {
        int n=nums.size();
        vector<int> v(n,1);
        int maxi=1;
        for(int i=1;i<n;i++)
        {
            for(int j=0;j<i;j++)
            {
                if(nums[i]>=nums[j])
                {
                    if(v[i]<v[j]+1)
                    {
                        v[i]=v[j]+1;
                    }
                    if(maxi<v[i])
                    {
                        maxi=v[i];
                    }
                }
            }
        }
        return n-maxi;
    }
};