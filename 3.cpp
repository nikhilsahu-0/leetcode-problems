class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        vector<int> hash(130);
        int l = 0,r = 1,res = 1;
        if(s.size()<2)return s.size();
        else{
            hash[s[l]]++;
            while(l < r && r < s.size()){
                hash[s[r]]++;
                if(hash[s[r]] > 1){
                    res = max(res,r-l);
                    while(hash[s[r]] > 1){
                        hash[s[l]]--;
                        l++;
                    }
                }
                if(r == s.size()-1){
                    res = max(res,r-l+1);
                    break;
                }
            r++;
            }
        }
        
        return res;
    }
};
