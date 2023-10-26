class Solution {
public:
    bool ans(int i,int j,string& s,string& p, vector<vector<int>>& dp)
    {
        if(j==p.size() && i==s.size())
        {
            return true;
        }
        if(j>=p.size() && i<s.size())
        {
            return false;
        }
        if(j<p.size() && i>=s.size())
        {
            for(int k=j;k<p.size();k++)
            {
                if(p[k]!='*')
                {
                    return false;
                }
            }
            return true;
        }
        
        
        if(dp[i][j]!=-1)
        {
            return dp[i][j];
        }
        if(s[i]==p[j] || p[j]=='?')
        {
            return dp[i][j]=ans(i+1,j+1,s,p,dp);
        }
        
        else if(p[j]=='*')
        {
            bool b=ans(i+1,j,s,p,dp);
            bool c=ans(i,j+1,s,p,dp);
           
            return dp[i][j]=(b|c);
        }
        else 
        {
            return false;
        }
    }
    bool isMatch(string s, string p) {
        vector<vector<int>>dp(s.size(),vector<int>(p.size()+1,-1));
        return ans(0,0,s,p,dp);
    }
};