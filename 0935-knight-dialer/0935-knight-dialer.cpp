class Solution {
    vector<vector<int>> v={{1,2,3},{4,5,6},{7,8,9},{-1,0,-1}};
    int mod=1e9+7;
    int ans(int i,int n,int a,int b,vector<vector<vector<long>>>& dp)
    {
        if(i>n || a>=4 || b>=3 || a<0 || b<0 || v[a][b]==-1)
        {
            return 0;
        }
        if(i==n)
        {
            return 0;
        }
        if(i==n-1)
        {
            return 1;
        }
        if(dp[i][a][b]!=-1)
        {
            return dp[i][a][b]%mod;
        }
        long t1=0,t2=0,t3=0,t4=0,t5=0,t6=0,t7=0,t8=0;
        if(v[a][b]!=-1)
        {
            t1=ans(i+1,n,a+2,b+1,dp);
            t2=ans(i+1,n,a+2,b-1,dp);
            t3=ans(i+1,n,a-2,b+1,dp);
            t4=ans(i+1,n,a-2,b-1,dp);
            t5=ans(i+1,n,a+1,b+2,dp);
            t6=ans(i+1,n,a+1,b-2,dp);
            t7=ans(i+1,n,a-1,b+2,dp);
            t8=ans(i+1,n,a-1,b-2,dp);
        }
        dp[i][a][b]=(((((((t1%mod+t2%mod)%mod+t3%mod)%mod+t4%mod)%mod+t5%mod)%mod+t6%mod)%mod+t7%mod)%mod+t8%mod)%mod;
        return dp[i][a][b]%mod;
    }
public:
    int knightDialer(int n) {
        long a=0;
        vector<vector<vector<long>>> dp(n+1,vector<vector<long>>(4,vector<long>(3,-1)));
        for(int i=0;i<4;i++)
        {
            for(int j=0;j<3;j++)
            {
                a=(a%mod + (ans(0,n,i,j,dp))%mod)%mod;
                //cout<<a<<" ";
            }
            //cout<<endl;
        }
        if(n==1)
        {
            return 10;
        }
        return a;
    }
};