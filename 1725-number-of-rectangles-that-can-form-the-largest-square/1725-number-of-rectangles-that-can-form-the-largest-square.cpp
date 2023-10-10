class Solution {
    public:
    int ans(vector<vector<int>>& rectangles,int min,int i,int n,map<int,int> a)
    {
        if(i==n)
        {
            return a[min];
        }
        if(rectangles[i][0]<=rectangles[i][1])
        {
            if(min<=rectangles[i][0])
            {
                min=rectangles[i][0];
                a[min]++;
            }
        }
        else 
        {
            if(min<=rectangles[i][1])
            {
                min=rectangles[i][1];
                a[min]++;
            }
        }
        
        return ans(rectangles,min,i+1,n,a);
    }
    int countGoodRectangles(vector<vector<int>>& rectangles) {
        map<int,int>a;
        int k=ans(rectangles , 0 , 0, rectangles.size(), a );
        cout<<k;
        return k;
    }
};