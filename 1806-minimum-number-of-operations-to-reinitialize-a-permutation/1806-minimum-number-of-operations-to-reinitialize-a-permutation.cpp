class Solution {
public:
    int reinitializePermutation(int n) {
        vector<int> v,v1,v2;
        for(int i=0;i<n;i++)
        {
            v.push_back(i);
        }
        v1=v;
        v2=v;
        int j=0,count=0;
        while(j==0)
        {
            count++;
            int c=0;
            for(int i=0;i<v.size();i++)
            { 
            if(i%2==0)
            { 
                
                v[i]=v1[i/2];
                if(v[i]==v2[i])
                {
                    c++;
                }
            }
            else 
            {
                v[i]=v1[n/2 + (i-1)/2];
                if(v[i]==v2[i])
                {
                    c++;
                }
            }
            if(c==n)
            {
                j=-1;
            }
            
            }
            v1=v;
        }
        return count;
    }
};