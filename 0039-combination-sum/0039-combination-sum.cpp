class Solution {
   
    void ans(int i,vector<int>& candidates, int target, vector<int>& v,vector<vector<int>>& dp)
    {
        if(i>=candidates.size())
        {
            if(target==0)
            {
                dp.push_back(v);
            }
            return ;
        }
        
        if(candidates[i]<=target)
        {
            v.push_back(candidates[i]);
            ans(i,candidates,target-candidates[i],v,dp);
            v.pop_back();
        }
        ans(i+1,candidates,target,v,dp);
        
        
    }
    
    
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<int> v;
         vector<vector<int>> dp;
        ans(0,candidates,target,v,dp);
        return dp;
    }
};