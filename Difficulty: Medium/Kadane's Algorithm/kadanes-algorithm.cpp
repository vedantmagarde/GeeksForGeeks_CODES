class Solution {
  public:
    int maxSubarraySum(vector<int> &arr) {
        int ans=INT_MIN;
        int sum=0;
        for(auto x:arr){
            sum+=x;
            ans=max(sum,ans);
            if(sum<0){
                sum=0;
                continue;
            }
        }
        return ans;
    }
};