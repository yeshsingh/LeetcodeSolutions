class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        vector<int> v,v1;
        int c=0;
        for(int i=0;i<nums.size();i++)
        {
            if(nums[i]==1)
            {
                c++;
            }
            else 
            {
                c=0;
            }
            v.push_back(c);
        }
        c=0;
        reverse(nums.begin(),nums.end());
        
        for(int i=0;i<nums.size();i++)
        {
            if(nums[i]==1)
            {
                c++;
            }
            else 
            {
                c=0;
            }
            v1.push_back(c);
        }
       if(v.size()==1)
       {
           return 0;
       }
        reverse(nums.begin(),nums.end());
        int maxi=-1;
        for(int i=0;i<v.size();i++)
        {
            if(i!=0 && i!=v.size()-1)
            {
                maxi=max({maxi,v[i-1]+v1[v.size()-i-2]});
            }
            else if(i==0)
            {
                maxi=max({maxi,v1[v.size()-i-2]});
            }
            else if(i==v.size()-1)
            {
                maxi=max({maxi,v[v.size()-2]});
            }
            //cout<<maxi<<" "<<i<<endl;
        }
        return maxi;
    }
};