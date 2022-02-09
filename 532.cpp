class Solution {
public:
    int findPairs(vector<int>& nums, int k) {
        set<int> hash;
        set<vector<int>> ans;
        int cnt = 0;
        for(int i:nums){
            if(hash.find(k+i) != hash.end()){
                ans.insert({min(k+i,i),max(k+i,i)});
            }
            if(hash.find(i-k) != hash.end()){
                ans.insert({min(i-k,i),max(i-k,i)});
            }
            hash.insert(i);
        }
        return ans.size();
    }
};
