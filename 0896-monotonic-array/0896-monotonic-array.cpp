class Solution {
public:
    bool isMonotonic(vector<int>& nums) {
        //int maxi=-100005,pos;
        vector<int> v=nums,v1=nums;
            int z=0,y=0;
        sort(v.begin(),v.end());
        sort(v1.begin(),v1.end(),greater<int>());
        
        for(int i=0;i<nums.size();i++)
        {
            if(nums[i]!=v[i])
            {
                z=1;
            }
            if(nums[i]!=v1[i])
            {
                y=1;
            }
        }
        bool b=false;
        if(z==0 || y==0)
        {
            b=true;
        }
        return b;
    }
};