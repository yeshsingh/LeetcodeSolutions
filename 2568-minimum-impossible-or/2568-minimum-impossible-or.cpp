class Solution {
public:
    int minImpossibleOR(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int n = 1;
        for(int i = 0; i < nums.size(); ++i){
            if(nums[i] > n) return n;
            if(nums[i] == n) { n = n*2; }
        }
        return n;
    }
};