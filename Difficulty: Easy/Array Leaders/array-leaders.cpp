class Solution {
  public:
    vector<int> leaders(vector<int>& arr) {
        // code here
        vector<int>ans;
        stack<int>st;
        int i=arr.size()-1;
        while(i>=0){
           if(st.empty()||st.top()<=arr[i]){
               ans.push_back(arr[i]);
               st.push(arr[i]);
           } 
           
           i--;
        }
        
        reverse(ans.begin(),ans.end());
        return ans;
    }
};