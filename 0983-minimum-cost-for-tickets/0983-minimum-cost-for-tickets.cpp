class Solution {
public:
    int ans(int i,vector<int>& days, vector<int>& costs,vector<int>& dp)
    {
        if(days.size()<=i)
        {
            return 0;
        }
        if(dp[i]!=-1)
        {
            return dp[i];
        }
        int d1= costs[0]+ans(i+1,days,costs,dp);
        int j;
        for(j = i ; j<days.size() && days[j]<days[i]+7 ; j++);
        int d2=costs[1]+ans(j,days,costs,dp);
        for(j = i ; j<days.size() && days[j]<days[i]+30 ; j++);
        int d3=costs[2]+ans(j,days,costs,dp);
        int ans;
        if(d1<d2)
        {
            ans=d1;
        }
        else if(d1>=d2)
        {
            ans=d2;
        }
        if(d3<ans)
        {
            ans=d3;
        }
        return dp[i]=ans;
    }
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        vector<int> dp;
        for(int i=0;i<days.size();i++)
        {
            dp.push_back(-1);
        }
        return ans(0,days,costs,dp);
    }
};