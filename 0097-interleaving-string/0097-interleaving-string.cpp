class Solution {
    bool ans(int i,int j,int k,string& s1,string& s2,string& s3,vector<vector<int>>& dp)
    {
        if(i==s1.size())
        {
            int b=1;
            while(j<s2.size() && k<s3.size())
            {
                if(s2[j]!=s3[k])
                {
                    b=0;
                    j=s2.size();
                }
                j++;k++;
            }
            
            if(j==s2.size() && k==s3.size())
            {
                
                return 1;
            }
            else 
            {
                
                return 0;
            }
            
        }
        if(dp[i][j]!=-1)
        {
            return dp[i][j];
        }
        if(j==s2.size())
        {
            int b=1;
            while(i<s1.size() && k<s3.size())
            {
                if(s1[i]!=s3[k])
                {
                    b=0;
                    i=s2.size();
                }
                i++;k++;
            }
            if(i==s1.size() && k==s3.size())
            {
                return b;
            }
            else 
            {
                return 0;
            }
            
        }
        int f1=0,f2=0;
        if(s1[i]==s3[k])
        {
            f1=ans(i+1,j,k+1,s1,s2,s3,dp);
        }
        if(s2[j]==s3[k])
        {
            f2=ans(i,j+1,k+1,s1,s2,s3,dp);
        }
        return dp[i][j]=(f1|f2);
    }
public:
    bool isInterleave(string s1, string s2, string s3) {
        vector<vector<int>> dp(1e2+1,vector<int>(1e3,-1));
        return ans(0,0,0,s1,s2,s3,dp);
    }
};