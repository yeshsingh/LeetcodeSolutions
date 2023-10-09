class Solution {
public:
    int nextGreaterElement(int n) {
        vector<int> v,v1,ans;
        int n1=n;
        if(4294967296<n)
        {
            return -1;
        }
        while(n1)
        {
            v.push_back(n1%10);
            n1=n1/10;
        }
        
        stack<int> s;
        int pos=-1;
        for(int i=0;i<v.size();i++)
        {
            if(s.size()==0)
            {
                s.push(v[i]);
            }
            else 
            {
                if(v[i]<s.top())
                {
                    pos=i;
                    break;
                }
                else 
                {
                    s.push(v[i]);
                }
            }
        }
        int pos1=-1,k1=0;
        if(pos==-1)
        {
            return -1;
        }
        else 
        {
            for(int i=0;i<pos;i++)
            {
                if(v[pos]<v[i])
                {
                    k1=v[pos];
                    swap(v[i],v[pos]);
                    pos1=i;
                    break;
                }
            }
        }
        for(int i=0;i<pos;i++)
        {
            if(pos1!=i)
            {
                v1.push_back(v[i]);
            }
        }
        sort(v1.begin(),v1.end());
        for(int i=v.size()-1;i>=pos;i--)
        {
            ans.push_back(v[i]);
        }
        for(int i=0;i<v1.size();i++)
        {
            if(pos1==i)
            {
                ans.push_back(k1);
            }
            ans.push_back(v1[i]);
        }
        if(v1.size()==pos1)
        {
            ans.push_back(k1);
        }
        long f_ans=0;
        for(int i=0;i<ans.size();i++)
        {
            f_ans=f_ans*10+(long)ans[i];
            //cout<<f_ans<<endl;
        }
        if((int)f_ans<=-1 || 4294967296<f_ans)
        {
            f_ans=-1;
        }
        return f_ans;
    }
};

