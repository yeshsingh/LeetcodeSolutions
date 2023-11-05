#define inf  0x3f3f3f
class Solution {
    int ans(int i,int j,string& s1,string& s2,vector<vector<int>>& dp)
    {
        if(s1.size()==i && s2.size()==j)
        {
            return 0;
        }
        if(s1.size()==i)
        {
            int ans=0;
            while(j<s2.size())
            {
                ans+=(s2[j]);
                j++;
            }
            return ans;
        }
        if(s2.size()==j)
        {
            int ans=0;
            while(i<s1.size())
            {
                ans+=(s1[i]);
                i++;
            }
            return ans;
        }
        if(dp[i][j]!=-1)
        {
            return dp[i][j];
        }
        int move=inf,remove1=inf,remove2=inf,remove3=inf;
        if(s1[i]==s2[j])
        {
            move=ans(i+1,j+1,s1,s2,dp);
        }
        else 
        {
            remove1=ans(i+1,j,s1,s2,dp)+(s1[i]);
            remove2=ans(i,j+1,s1,s2,dp)+(s2[j]);
            remove3=ans(i+1,j+1,s1,s2,dp)+(s2[j]+s1[i]);
        }
        return dp[i][j]=min({remove1,remove2,move,remove3});
    }
public:
    int minimumDeleteSum(string s1, string s2) {
        vector<vector<int>> dp(1e3+1,vector<int>(1e3+1,-1));
        return ans(0,0,s1,s2,dp);
    }
};