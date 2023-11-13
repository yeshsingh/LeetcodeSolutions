class Solution {
public:
    string sortVowels(string s) {
        vector<char> v,v1;
        string s1;
        for(int i=0;i<s.size();i++)
        {
            if(s[i]=='a' || s[i]=='e' || s[i]=='o' || s[i]=='i' || s[i]=='u' || s[i]=='A' || s[i]=='E' || s[i]=='O' || s[i]=='I' || s[i]=='U')
            {
                v.push_back(s[i]);
            }
            else 
            {
                v1.push_back(s[i]);
            }
        }
        sort(v.begin(),v.end());
        int k=0;
        for(int i=0;i<s.size();i++)
        {
            if(s[i]=='a' || s[i]=='e' || s[i]=='o' || s[i]=='i' || s[i]=='u' || s[i]=='A' || s[i]=='E' || s[i]=='O' || s[i]=='I' || s[i]=='U')
            {
                s1+=v[k];
                k++;
            }
            else 
            {
                s1+=s[i];
            }
        }
        return s1;
    }
};