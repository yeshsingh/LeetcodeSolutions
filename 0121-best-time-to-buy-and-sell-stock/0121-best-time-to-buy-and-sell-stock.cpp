class Solution {
    
public:
    int maxProfit(vector<int>& prices) {
        int maxprofit=0,mini=prices[0];
        for(int i=1;i<prices.size();i++)
        {
            int cost=prices[i]-mini;
            mini=min({mini,prices[i]});
            maxprofit=max({maxprofit,cost});
        }
        return maxprofit;
    }
};