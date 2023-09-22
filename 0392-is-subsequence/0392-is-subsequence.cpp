class Solution {
public:
    bool isSubsequence(string s, string t) {
        if(s.size()==0) return 1; //Empty string is always a subsequence
        int i=0;
        int j=0;
        while(j<t.size()){
            if(s[i]==t[j]){
                i++;
                j++;
            }else j++;

            if(i==s.size()) return 1;  //if i is equal to S size then we found our subsequence
        }
        return 0; 
    }
};