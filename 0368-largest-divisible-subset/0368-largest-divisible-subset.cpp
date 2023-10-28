class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        vector<int> ans(nums.size(),1),f_ans,v;
        for(int i=0;i<nums.size();i++)
        {
            f_ans.push_back(i);
        }
        for(int i=0;i<nums.size();i++)
        {
            for(int j=0;j<i;j++)
            {
                if(nums[i]%nums[j]==0)
                {
                    if(ans[j]+1>ans[i])
                    {
                        ans[i]=ans[j]+1;
                        f_ans[i]=j;
                    }
                }
            }
        }
        int maxi=-1,pos=0;
        for(int i=0;i<nums.size();i++)
        {
            if(maxi<ans[i])
            {
                maxi=ans[i];
                pos=i;
            }
        }
        
        //cout<<pos<<endl;
        int prev=pos;
        v.push_back(nums[pos]);
        pos=f_ans[pos];
        while(prev!=pos)
        {
            prev=pos;
            v.push_back(nums[pos]);
            pos=f_ans[pos];
        }
        reverse(v.begin(),v.end());
        return v;
    }
};