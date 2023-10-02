class Solution {
public:
    bool winnerOfGame(string colors) {
        int a=0,b=0,ans1=0,ans2=0;
        for(int i=0;i<colors.size();i++)
        {
            if(colors[i]=='A')
            {
                if(3<=b)
                { 
                ans1=ans1+(b-2);
                }
                a++;
                b=0;
            }
            else 
            {
                if(3<=a)
                { 
                ans2=ans2+(a-2);
                }
                b++;
                a=0;
            }
        }
        if(3<=b)
                { 
                ans1=ans1+(b-2);
                }
        if(3<=a)
                { 
                ans2=ans2+(a-2);
                }
        //cout<<ans2<<" "<<ans1<<endl;
        if(ans1<ans2)
        {
            return true;
        }
        else 
        {
            return false;
        }
    }
};