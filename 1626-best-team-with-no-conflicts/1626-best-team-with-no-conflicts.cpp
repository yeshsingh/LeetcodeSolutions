class Solution {
    int ans(int i,int prev,vector<pair<int,int>>& v,vector<vector<int>>& dp)
    {
        if(i>=v.size())
        {
            return 0;
        }
        if(dp[i][prev] != 0)
        {
            return dp[i][prev];
        }
        int not_take=ans(i+1,prev,v,dp);
        int take=0;
        
        if(prev<=v[i].second)
        {
            take=v[i].first+ans(i+1,v[i].second,v,dp);
        }
        //cout<<take<<" "<<not_take<<endl;
        return dp[i][prev]=max({take,not_take});
    }
public:
    int bestTeamScore(vector<int>& scores, vector<int>& ages) {
        vector<pair<int,int>> v;
        vector<vector<int>> dp(scores.size(),vector<int>(1001,0));
        for(int i=0;i<scores.size();i++)
        {
            v.push_back(make_pair(scores[i],ages[i]));
        }
        sort(v.begin(),v.end());
        
        
        return ans(0,0,v,dp);
        return 0;
    }
};