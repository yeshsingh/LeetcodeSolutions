class Solution {
public:
    vector<int> maxScoreIndices(vector<int>& nums) {
        int count=0;
        vector<int> v,v1;
        vector<int> v2;
        for(int i=0;i<nums.size();i++)
        {
            if(nums[i]==0)
            {
                count++;
            }
            v.push_back(count);
        }
        count=0;
        for(int j=0;j<nums.size();j++)
        {
            if(nums[j]==1)
            {
                count++;
            }
            v1.push_back(count);
        }
        int maxi=0;
        for(int i=0;i<nums.size();i++)
        {
            int ans=0;
            if(i==0)
            {
                ans=v1[nums.size()-1];
            }
            else 
            {
                ans=v[i-1]+(v1[nums.size()-1]-v1[i-1]);
            }
           maxi=max({maxi,ans});
        }
        if(maxi<v[nums.size()-1])
        {
            maxi=v[nums.size()-1];
        }
        for(int i=0;i<nums.size();i++)
        {
            int ans=0;
            if(i==0)
            {
                ans=v1[nums.size()-1];
            }
            else 
            {
                ans=v[i-1]+(v1[nums.size()-1]-v1[i-1]);
                
            }
           if(maxi==ans)
           {
               
               v2.push_back(i);
           }
        }
        if(v[nums.size()-1]==maxi)
        {
            v2.push_back(nums.size());
        }
        return v2;
    }
};