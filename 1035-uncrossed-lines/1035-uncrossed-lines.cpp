class Solution {
public:
    int maxUncrossedLines(vector<int>& nums1, vector<int>& nums2) {
        int m=nums1.size(),n=nums2.size();
        if(m<n)
        {
            swap(nums1,nums2);
            swap(m,n);
        }
        vector<vector<int>> v(m+1,vector<int> (n+1,0));
        for(int i=1;i<=m;i++)
        {
            for(int j=1;j<=n;j++)
            {
                if(nums1[i-1]==nums2[j-1])
                {
                    v[i][j]=1+v[i-1][j-1];
                }
                else 
                {
                    v[i][j]=max(v[i-1][j],v[i][j-1]);
                }
            }
        }
        return v[m][n];
    }
};