class Solution {
public:
    bool isAnagram(string s, string t) {
        
        if(s.size() != t.size())return false;

        int n = s.size();
        vector<int> hashS(26,0),hashT(26,0);
        for(int i = 0;i<n;i++)hashS[s[i]-'a']++;
        for(int j = 0;j<n;j++)hashT[t[j]-'a']++;
        for(int k = 0;k<26;k++)if(hashS[k] != hashT[k])return false;
        return true;
        
    }
};
