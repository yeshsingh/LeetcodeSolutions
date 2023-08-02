class Solution {
    private:
    void permutation(vector<vector<int>> &ans, int freq[], vector<int> &ds,vector<int> &n)
    {
        if(ds.size()==n.size())
        {
            ans.push_back(ds);
            return;
        }
        for(int i=0;i<n.size();i++)
        {
            if(!freq[i])
            {
                freq[i]=1;
                ds.push_back(n[i]);
                permutation(ans,freq,ds,n);
                freq[i]=0;
                ds.pop_back();
            }
        }
    }
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ans;
        int freq[nums.size()];
        for(int i=0;i<nums.size();i++)
        {
            freq[i]=0;
        }
        vector<int> ds;
        permutation(ans,freq,ds,nums);
        return ans;
    }
};