class Solution {
    int ans(int i,int j,string& s1,string& s2,vector<vector<int>>& dp)
    {
        if(s1.size()==i)
        {
            int ans=0;
            while(j<s2.size())
            {
                ans+=(s2[j]-'a'+97);
                j++;
            }
            return ans;
        }
        if(s2.size()==j)
        {
            int ans=0;
            while(i<s1.size())
            {
                ans+=(s1[i]-'a'+97);
                i++;
            }
            return ans;
        }
        if(dp[i][j]!=-1)
        {
            return dp[i][j];
        }
        int move=1e9,remove1=1e9,remove2=1e9;
        if(s1[i]==s2[j])
        {
            move=ans(i+1,j+1,s1,s2,dp);
        }
        else 
        {
            remove1=ans(i+1,j,s1,s2,dp)+(s1[i]-'a'+97);
            remove2=ans(i,j+1,s1,s2,dp)+(s2[j]-'a'+ 97);
        }
        return dp[i][j]=min({remove1,remove2,move});
    }
public:
    int minimumDeleteSum(string s1, string s2) {
        vector<vector<int>> dp(max({s1.size()+1,s2.size()+1}),vector<int>(1e5,-1));
        return ans(0,0,s1,s2,dp);
    }
};