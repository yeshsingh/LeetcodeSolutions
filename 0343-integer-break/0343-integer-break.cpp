class Solution {
public:
    int integerBreak(int n) {
        int ans=1;
        if(n==2)
        {
            return 1;
        }
        else if(n==3)
        {
            return 2;
        }
        else if(n%3==0)
        {
            for(int i=0;i<n/3;i++)
            {
                ans=ans*3;
            }
        }
        else if(n%3==1)
        {
            for(int i=0;i<n/3-1;i++)
            {
                ans=ans*3;
            }
            ans=ans*4;
        }
        else if(n%3==2)
        {
            for(int i=0;i<n/3;i++)
            {
                ans=ans*3;
            }
            ans=ans*2;
        }
        return ans;
    }
};