class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> ans;
        int m = matrix.size(), n = matrix[0].size();
        vector<vector<bool> > seen(m, vector<bool>(n, false));
        int d1[]={0 ,1 ,0, -1};
        int d2[]={1 ,0 ,-1, 0};
        int x=0,y=0,di=0;
        for(int i=0;i<m*n;i++)
        {
            ans.push_back(matrix[x][y]);
            seen[x][y]=true;
            int newx=x+d1[di];
            int newy=y+d2[di];
            if(0 <= newx && newx < m && 0 <= newy && newy < n
            && seen[newx][newy]==false)
            {
                x=newx;
                y=newy;
            }
            else 
            {
                di=(di+1)%4;
                x+=d1[di];
                y+=d2[di];
            }
        }
        return ans;
    }
};