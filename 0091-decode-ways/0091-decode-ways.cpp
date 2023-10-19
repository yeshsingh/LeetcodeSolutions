class Solution {
    int solve(int i,string s,vector<int>& dp)
    { 
        if(s[i]=='0') return 0;
        if(dp[i]!=-1) return dp[i];
        
        int res = solve(i+1,s,dp);
        if(i<s.size()-1 && (s[i]=='1'||s[i]=='2'&&s[i+1]<'7')) res+=solve(i+2,s,dp);
        //cout<<i<<endl;
        return dp[i] = res;
}
public:
    int numDecodings(string s) {
        vector<int> dp(s.size()+1,-1);
        dp[s.size()]=1;
        return solve(0,s,dp);
    }
};