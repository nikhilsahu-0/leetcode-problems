/*
 *		02.02.2022 18:15:52 IST 
 */

#include <bits/stdc++.h>
#define mod 1000000007
#define inf 1e9
#define ninf -1e9
#define ll long long
 
using namespace std;
 
 
 


    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(),intervals.end());
        vector<vector<int>> finalIntervals;
        stack<vector<int>> st;
        
        for(auto i:intervals){
			if(st.empty())st.push(i);
			else {
				if(st.top()[1] >= i[0]){
					st.top()[0] = min(st.top()[0],i[0]);
					st.top()[1] = max(st.top()[1],i[1]);
					}
				}
			}
			
			
			while(!st.empty()){
				finalIntervals.push_back(st.top());
				st.pop();
				}
				
			return finalIntervals;
    }
 
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);	
	vector<vector<int>> intervals = {{1,4},{4,5}};
    vector<vector<int>> ans = merge(intervals);
    for(auto i: ans){
		for(auto j:i)cout << j << ' ';
		cout << '\n';
		}
    return 0;
	}

