class Solution {
public:
    int lengthOfLastWord(string s) {
        int i=s.size()-1;
        int ans=0;
        //cout<<s.size()<<endl;
        while(i>=0 && s[i]==' ')
        {
            i--;
        }
        while(i>=0 && s[i]!=' ')
        {
            ans++;
            i--;
        }
        return ans;
    }
};