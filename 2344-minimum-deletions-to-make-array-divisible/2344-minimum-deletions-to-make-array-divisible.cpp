class Solution {
public:
    int minOperations(vector<int>& nums, vector<int>& numsDivide) {
        int gcd=numsDivide[0];
        for(int i=1;i<numsDivide.size();i++)
        {
            gcd=__gcd(numsDivide[i],gcd);
        }
        
        sort(nums.begin(),nums.end());
        int ans=0;
        for(int i=0;i<nums.size();i++)
        {
            if(gcd%nums[i]!=0)
            {
                ans++;
            }
            else 
            {
                cout<<i<<endl;
                break;
            }
        }
        if(ans==nums.size())
        {
            return -1;
        }
        return ans;
    }
};