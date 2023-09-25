class Solution {
public:
    char findTheDifference(string s, string t) {
        sort(s.begin(),s.end());
        sort(t.begin(),t.end());
        char ch1;
        int z=0;
        map<char,int> m,m1;
        for(int i=0;i<s.size();i++)
        {
            m[s[i]]++;
            m1[t[i]]++;
        }
        m1[t[t.size()-1]]++;
        for(char ch='a';ch<='z';ch++)
        {
            //cout<<ch<<" ";
            if(m[ch]!=m1[ch])
            {
                ch1=ch;
                
                break;
            }
        }
        return ch1;
    }
};