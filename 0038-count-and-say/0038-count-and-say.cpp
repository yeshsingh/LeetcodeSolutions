class Solution {
public:
//THIS FUNCTION THAT MAPS AN INTEGER TO PAIRS OF ITS DIGITS AND THEIR FREQUENCIES.
    vector<pair<char,int>> helper1(string n){    
        
      vector<pair<char,int>> ans;
        int count=1;
        
        for(int i=0;i<n.size();i++) {
           if(n[i]==n[i+1]) { count++; }
            
        else{
            ans.push_back({n[i],count});
            count=1;
            }
        }
        
        return ans;
    }
    // THIS FUNCTION THAT TAKES THE ARRAY OF PAIRS AND CREATES A NEW STRING .
	string helper2(vector<pair<char,int>> a){
        
        string st="";
        
        for(auto i : a){
            char ch1=i.first;
            string ch2=to_string(i.second);
            st+= ch1+ch2;
        }
        
        return st;
    }

        string countAndSay(int n) {
            
           string ans="1";
           string temp="";
            
           if(n==1)return ans;  //BASE CASE
            
        for(int i=1;i<n;i++){  ans=helper2(helper1(ans));} 
            
        for(int i=ans.size()-1;i>=0;i--) { temp+=ans[i]; }  // REVERSE THE STRING
            
        return temp;
        }
};