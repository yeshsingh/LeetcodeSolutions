class Solution {
   
public:
    int nthUglyNumber(int n) {
        vector<int> dp;
        
        dp.push_back(1);
        
        int i=1,a=0,b=0,c=0;
        while(dp.size()<n)
        {
            int ans=min({dp[a]*2,dp[b]*3,dp[c]*5});
            dp.push_back(ans);
            if(ans==dp[a]*2)
            {
                a++;
            }
            if(ans==dp[b]*3)
            {
                b++;
            }
            if(ans==dp[c]*5)
            {
                c++;
            }
        }
        return dp[dp.size()-1];
    }
};