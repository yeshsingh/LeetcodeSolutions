class Solution {
public:
    bool isUgly(int n) {
        map<int,int> m;
        vector<int> dp;
        if(n<=0)
        {
            return false;
        }
        while(n%2==0)
        {
            if(m[2]==0)
            {
                dp.push_back(2);
            }
            
            m[2]++;
            n=n/2;
        }
        for(int i=3;i<=sqrt(n);i=i+2)
        {
            while(n%i==0)
            {
                if(m[i]==0)
                {
                    dp.push_back(i);
                }
                m[i]++;
                n=n/i;
            }
        }
        bool b=true;
        if(n>2 )
        {
            if(m[n]==0)
            {
                dp.push_back(n);
            }
            m[n]++;
        }
        
        for(int i=0;i<dp.size();i++)
        {
            //cout<<dp[i]<<" ";
            if(dp[i]==2 || dp[i]==3 || dp[i]==5)
            {
                continue;
            }
            else 
            {
                b=false;
            }
        }
        return b;
    }
};