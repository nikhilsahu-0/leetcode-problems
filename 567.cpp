class Solution {
public:
    
    bool check(vector<int> a,vector<int> b){
        for(int i = 0;i<26;i++)if(a[i] != b[i])return false;
        return true;
    }
    bool checkInclusion(string s1, string s2) {
        vector<int> hash_s1(26,0),hash_s2(26,0);
        int n = s1.size(), m = s2.size();
        
        if(m < n)return false;
        
        
        for(auto i:s1)hash_s1[i-'a']++;
        int l = 0, r = 0;
        for(;r<n;r++)hash_s2[s2[r]-'a']++;
        if(check(hash_s1,hash_s2))return true;
        
        for(;r<m;r++){
            hash_s2[s2[r]-'a']++;
            hash_s2[s2[l]-'a']--;
            l++;
            if(check(hash_s1,hash_s2))return true;
            
        }
        
        return false;
    }
};
