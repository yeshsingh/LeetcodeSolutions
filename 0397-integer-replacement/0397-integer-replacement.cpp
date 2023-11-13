class Solution {
    long long ans(long long n,vector<int>& dp)
    {
        if(n<=1)
        {
            return 0;
        }
        long long t=INT_MAX,n_t1=INT_MAX,n_t2=INT_MAX;
        if(n%2==0)
        {
            t=1+ans(n/2,dp);
        }
        
        else 
        {
            n_t1=1+ans(n-1,dp);
            n_t2=1+ans(n+1,dp);
        }
        return min({t,n_t1,n_t2});
    }
public:
    int integerReplacement(int n) {
        vector<int> dp(1e7,-1);
        return (int)ans(n,dp);
    }
};