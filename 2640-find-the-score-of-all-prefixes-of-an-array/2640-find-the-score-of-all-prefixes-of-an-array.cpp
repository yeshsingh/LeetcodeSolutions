class Solution {
public:
    vector<long long> findPrefixScore(vector<int>& nums) {
        
        vector<long long> ans;
        vector<long long> conversion;
         long long sum = 0;
         
        for(int i =0 ; i<nums.size() ; i++){
            int maxi=max(nums[i],maxi);
            long long element=nums[i]+maxi;
            conversion.push_back(element);
        }
                                      
        for(int j = 0 ; j<nums.size() ; j++){ 
            sum=sum+conversion[j];
            ans.push_back(sum);
        }
                                         
        return ans;
        
    }
};