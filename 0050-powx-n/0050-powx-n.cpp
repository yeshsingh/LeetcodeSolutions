class Solution {
public:
    double myPow(double x, int n) {
        
        if(n==0){
            return 1;
        }
        if (n < 0) { 
            n = abs(n);
            x = 1/x;
        }
        if(n%2==0){
            return myPow(x*x,n/2);
        
        }else{
            return x*myPow(x*x,n/2);
        }
    }
};/*class Solution {
public:
    double ans(double x, int n)
    {
        if(n==0)
        {
            return 1.0000;
        }
        if(n<0)
        {
            return 1/x*ans(1/x,-(n+1));
        }
        if(n==2)
        {
            return x*x;
        }
        if(n%2==0)
        {
            return ans(ans(x,n/2),2);
        }
        else 
        { 
        return x*ans(ans(x,n/2),2);
        }
    }
    double myPow(double x, int n) {
        double d= ans(x,n);
        
        return d;
    }
};*/