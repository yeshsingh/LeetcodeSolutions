class Solution {
public:
    int eliminateMaximum(vector<int>& dist, vector<int>& speed) {
        vector<int> v;
        for(int i=-0;i<speed.size();i++)
        {
            v.push_back(ceil((double)dist[i]/speed[i]));
        }
        int j=0,ans=0;
        sort(v.begin(),v.end());
        for(int i=0;i<v.size();i++)
        {
            
            if(v[i]<=j && j!=0)
            {
                break;
            }
            ans++;
            j++;
        }
        return ans;
    }
};