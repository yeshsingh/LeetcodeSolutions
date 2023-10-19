class Solution {
public:
    int ans(int i,int j,int k,vector<int>& v,vector<int>& v1,int m,int n,vector<vector<vector<int>>>& dp)
    {
        if(j==m && k==n)
        {
            return 0;
        }
        if(i>=v.size())
        {
            return 0;
        }
        if(dp[i][j][k]!=-1)
        {
            return dp[i][j][k];
        }
        //cout<<i<<" "<<j<<" "<<k<<endl;
        int take=0;
        if(j+v[i]<=m && k+v1[i]<=n)
        {
            take=1+ans(i+1,j+v[i],k+v1[i],v,v1,m,n,dp);
            
        }
        int not_take=ans(i+1,j,k,v,v1,m,n,dp);
        dp[i][j][k]=max({take,not_take});
        return dp[i][j][k];
    }
    int findMaxForm(vector<string>& strs, int m, int n) {
        vector<int> v,v1;
        for(int i=0;i<strs.size();i++)
        {
            string s=strs[i];
            int one=0,zero=0;
            for(int j=0;j<s.size();j++)
            {
                if(s[j]=='1')
                {
                    one++;
                }
                else 
                {
                    zero++;
                }
            }
            v.push_back(zero);
            v1.push_back(one);
        }
        vector<vector<vector<int>>> dp(strs.size() + 1 , vector<vector<int>>(m + 1 , vector<int>(n + 1 , -1)));
        return ans(0,0,0,v,v1,m,n,dp);
    }
};