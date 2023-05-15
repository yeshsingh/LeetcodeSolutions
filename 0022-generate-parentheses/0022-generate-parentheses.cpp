class Solution {
public:
    void generator(vector<string> & v,int o,int c,int n,string s){
        if(c==n && c==o){
            v.push_back(s);
            return ;
        }
        if(o<n) generator(v,o+1,c,n,s+"(");
        if(o>c) generator(v,o,c+1,n,s+")");
    }
    vector<string> generateParenthesis(int n) {
        vector<string> v;
        generator(v,0,0,n,"");
        return v;
        
    }
};