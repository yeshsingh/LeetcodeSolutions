class Solution {
public:
    int countDigitOne(int n) {
        int ans=0;
        if(n<=0)
        {
            return 0;
        }
        if(n<=9)
        {
            return 1;
        }
        unordered_map<int,int> mp;
        mp[9]=1;
        for(int i=9;i<(INT_MAX-9)/10;i=10*i+9)
        {
            mp[10*i+9]=mp[i]*10 +(i+1);
        }
        int temp=n,divisor=1;
        while(temp/10)
        {
            divisor*=10;
            temp=temp/10;
        }
        int first_digit=n/divisor;
        int rem=n%divisor;
        
        ans+=mp[divisor-1]*first_digit;
        ans+=(first_digit>1)?divisor:0;
        ans+=(first_digit==1)? rem+1 : 0;
        cout<<ans<<" "<<rem<<endl;
        ans+=countDigitOne(rem);
        return ans;
    }
};