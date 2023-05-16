class Solution {
public:
    vector<int> circularGameLosers(int n, int k) {
        map<int,int> m;
        m[1]++;
        int c=1,i=1,f=0;
        vector<int> v;
        if(n!=1)
        { 
        while(f==0)
        {
            if(i+c*k>n)
            {
                int z=n-i;
                int ans=abs(c*k - z),a1;
                if(ans%n==0)
                {
                    a1=n;
                }
                else 
                {
                    a1=ans%n;
                }
                m[a1]++;
                if(m[a1]==2)
                {
                    f=1;
                }
                i=ans%n;
                //cout<<ans<<" ";
            }
            else 
            {
                m[i+c*k]++;
                if(m[i+c*k]==2)
                {
                    f=1;
                }
                i=i+c*k;
                //cout<<i<<" ";
            }
            c++;
        }
        for(int i=1;i<=n;i++)
        {
            if(m[i]==0)
            {
                v.push_back(i);
            }
        }
        }
        
        return v;
    }
};