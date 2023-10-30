class Solution {
    map<int,int> m;
    int ans(int i,vector<int>& v,vector<int>& dp)
    {
        if(i>=v.size())
        {
            return 0;
        }
        if(dp[i]!=-1)
        {
            return dp[i];
        }
        int not_take=ans(i+1,v,dp);
        int take;
        if(m[v[i]+1]!=0)
        {
            take=(m[v[i]]*v[i])+ans(i+2,v,dp);
            
        }
        else if(m[v[i]+1]==0)
        {
            take=(m[v[i]]*v[i])+ans(i+1,v,dp);
        }
        
        return dp[i]=max({take,not_take});
    }
public:
    int deleteAndEarn(vector<int>& nums) {
        vector<int> v;
        vector<int> dp(nums.size()+1,-1);
        for(int i=0;i<nums.size();i++)
        {
            if(m[nums[i]]==0)
            {
                v.push_back(nums[i]);
            }
            m[nums[i]]++;
        }
        sort(v.begin(),v.end());
        return ans(0,v,dp);
    }
};
/*class Solution {
    map<int,int> m;
    int ans(int i,vector<int>& v, vector<int>& dp)
    {
        if(i>=v.size())
        {
            return 0;
        }
        if(dp[i]!=-1)
        {
            return dp[i];
        }
        int not_take=ans(i+1,v,dp);
        int take;
        if(m[v[i]+1]!=0 && m[v[i]-1]!=0)
        {
            take=(m[v[i]]*v[i])-(m[v[i]-1]*(v[i]-1))+ans(i+2,v,dp);
        }
        else if(m[v[i]+1]!=0 && m[v[i]-1]==0)
        {
            take=(m[v[i]]*v[i])+ans(i+2,v,dp);
        }
        else 
        {
            take=(m[v[i]]*v[i])+ans(i+1,v,dp);
        }
        return dp[i]=max({take,not_take});
    }
public:
    int deleteAndEarn(vector<int>& nums) {
        vector<int> v;
        vector<int> dp(nums.size()+1,-1);
        for(int i=0;i<nums.size();i++)
        {
            if(m[nums[i]]==0)
            {
                v.push_back(nums[i]);
            }
            m[nums[i]]++;
        }
        sort(v.begin(),v.end());
        return ans(0,v,dp);
    }
};*/