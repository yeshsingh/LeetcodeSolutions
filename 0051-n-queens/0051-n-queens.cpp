class Solution {
public:
    bool safe(int a,int b,vector<string> &sv,int n)
    {
        int i = 0 , j = 0 ;

        while(i<n)
            if(sv[i++][b]=='Q')
                return false;

        i = a-1 , j = b-1;
        while(i>= 0 && j>=0)
            if(sv[i--][j--]=='Q')
                return false;



        i = a-1 , j = b+1;
        while(i>= 0 && j<n)
            if(sv[i--][j++]=='Q')
                return false;

        


        return true;
    }
    void bk(int i ,  vector<string> &sv,vector<vector<string>> &ans,int q,int n)
    {
        if(i==n)
        {
            if(q==n)ans.push_back(sv);
            return;
        }

            for(int j = 0 ; j < n ; j ++)
                if(safe(i,j,sv,n)==true)
                {
                    sv[i][j] = 'Q';
                    bk(i+1,sv,ans,q+1,n);
                    sv[i][j] = '.';
                }
    }
    vector<vector<string>> solveNQueens(int n) {
        if(n==1)    return {{"Q"}};
        string s="";
        int i = n;
        while(i--)
            s+=".";
        vector<string> sv(n,s);
        vector<vector<string>> ans;
        bk(0,sv,ans,0,n);
        return ans;
    }
};