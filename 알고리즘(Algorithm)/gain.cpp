//
//  Copyright (c) 2021 HyeJin Shin All rights reserved.
//

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;
int T,n;
int arr[100000];
vector<int> v;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    freopen("gain.inp","r",stdin);
    freopen("gain.out","w",stdout);
    cin>>T;
    int l;
    while(T--){
        cin >> n;
        v.clear();
        for(int i=0;i<n;i++){
            cin >>l;
            v.push_back(l);
        }
        sort(v.begin(), v.end());
        int a = v[n-2];
        int b = v[1];
        int c =v[n-1];
        int d =v[0];
        int max_v = a-b+c-d;
        cout<<max_v<<'\n';
    }
}

