class Solution {
    bool ans(vector<int>& arr, int start, vector<bool>& b,vector<int>& dp)
    {
        if(start<0)
        {
            return false;
        }
        if(start>=arr.size())
        {
            return false;
        }
        if(arr[start]==0)
        {
            return true;
        }
        if(dp[start]!=-1)
        {
            return dp[start];
        }
        bool left,right;
        if(!b[start])
        {
            left=ans(arr,start+arr[start],b,dp);
        }
        if(!b[start])
        {
            b[start]=true;
            right=ans(arr,start-arr[start],b,dp);
        }
        b[start]=false;
        return dp[start]=left|right;
    }
public:
    bool canReach(vector<int>& arr, int start) {
        vector<bool> b(arr.size()+1,false); 
        vector<int> dp(arr.size()+1,-1);
        return ans(arr,start,b,dp);
    }
};