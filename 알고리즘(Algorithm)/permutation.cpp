//
//  Copyright (c) 2022 HyeJin Shin All rights reserved.
//

#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
using namespace std;
int n;
map <int, int> m;
vector<int> v;
vector<int>height[1001];
void inorder(int start, int end, int level){
    if(start > end) return;
    int max=-1;
    int max_idx=0;
    for(int i=start;i<=end;i++){
        if(max<v[i]){max=v[i];max_idx = i;}
    }
    height[level].push_back(v[max_idx]);
    
    inorder(start, max_idx-1, level+1);
    inorder(max_idx+1, end, level+1);

}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    freopen("permutation.inp","r",stdin);
    freopen("permutation.out","w",stdout);
    int T;
    int a;
    cin>>T;
    while(T--){
        cin>>n;
        for(int i=0;i<n;i++){
            cin>>a;
            v.push_back(a);
        }
        inorder(0, n-1, 1);

        for(int i=1; i<=n; i++){
            for(auto it: height[i]){
                m.insert({it,i});
            }
        }
        
        for(int i=0;i<n;i++){
            cout<<m[v[i]]-1<<' ';
        }
        cout<<'\n';
        m.erase(m.begin(), m.end());
        v.clear();
        for(int i=0;i<=n;i++){
            height[i].clear();
        }
    }
}

