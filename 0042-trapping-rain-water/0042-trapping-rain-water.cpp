class Solution {
public:
    int trap(vector<int>& v) {
        //through 2 pointers by yesh singh
        int a=0,b=v.size()-1,ans=0,left=0,right=0;
        while(a<=b)
        {
            left=max({left,v[a]});
            right=max({right,v[b]});
            if(left<=right)
            {
                ans+=(left-v[a]);
                a++;
            }
            else 
            {
                ans+=(right-v[b]);
                b--;
            }
        }
        return ans;
    }
};