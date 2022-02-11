class Solution {
public:
    int minSteps(string s, string t) {
        int cnt = 0;
        vector<int> hashS(26),hashT(26);
        for(auto i:s)hashS[i-'a']++;
        for(auto i:t)hashT[i-'a']++;
        for(int i = 0;i<26;i++){
            cnt += abs(hashS[i] - hashT[i]);
        }
        return cnt/2;
    }
};
