class Solution {
public:
    int semiOrderedPermutation(vector<int>& nums) {
        int f1=find(nums.begin(),nums.end(),1)-nums.begin();
        int f2=find(nums.begin(),nums.end(),nums.size())-nums.begin();
       
        if(f1>f2)
        {
            return f1+(nums.size()-f2-1)-1;
        }
        else 
        {
            
            return f1+(nums.size()-f2-1);
        }
    }
};