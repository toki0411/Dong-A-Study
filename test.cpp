//
//  Copyright (c) 2021 HyeJin Shin All rights reserved.
//

#include <iostream>
#include <algorithm>
#include <vector>
#include <map>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    freopen("test.inp","r",stdin);
    freopen("test.out","w",stdout);
    map<string,int> m;
    vector<tuple<string, string, string>>v;
    int N;
    string num;
    string fn;
    string ln;
    int max = 0;
    cin >> N;
    for(int i=0;i<N;i++){
        cin >> num >> fn >> ln;
        v.push_back(make_tuple(num,fn,ln));
        m[ln]+=1;
        if(fn.length()>max){
            max = fn.length();
        }
    }
    sort(v.begin(), v.end());
    for(int i=0;i<N;i++){
        cout<<get<0>(v[i])<<' '<<get<1>(v[i]);
        for(int k=get<1>(v[i]).length();k<max;k++){
            cout<<' ';
        }
        cout<<' '<<get<2>(v[i])<<'\n';
    }
    cout<<'\n';
    for (auto iter = m.begin(); iter != m.end(); ++iter){
        if(iter->second > 1){
            cout << iter->first << " "<< iter->second<<'\n';
        }
    }
}


