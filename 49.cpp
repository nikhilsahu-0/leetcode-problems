class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string,vector<string>> hash;
        vector<vector<string>> vs;
        for(auto i:strs){
            string temp = i;
            sort(temp.begin(),temp.end());
            hash[temp].push_back(i);
        }
        for(auto &i:hash)vs.push_back(i.second);
        return vs;
    }
};
