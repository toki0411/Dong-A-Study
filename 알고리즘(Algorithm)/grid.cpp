//
//  Copyright (c) 2021 HyeJin Shin All rights reserved.
//

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;
int N, M;
int K;
vector<int> v;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    freopen("grid.inp","r",stdin);
    freopen("grid.out","w",stdout);
    
    int T;
    int a;
    cin >>T;
    while(T--){
        cin>>N>>M>>K;
        int num = 0;
        for(int i=0;i<K;i++){
            cin>>a;
            num+=a;
            v.push_back(a);
        }
        sort(v.rbegin(),v.rend());
        int sum = N*M;
        bool key1 = false;
        for(int i=0;i<K;i++){
            if(sum<=0)break;
            if(v[i]<N*2){  //세로
                key1 = true;
                break;
            }
            if(sum < N*2){
                if(sum %N==0){
                    break;
                }
                else {key1 = true;
                    break;}
            }
            if(i==K-1){
                if(v[i]<sum){
                    key1=true;
                    break;
                }
            }
            sum -=(v[i]/N)*N;
        }
        sum = N*M;
        bool key2 =false;
        for(int i=0;i<K;i++){
            if(sum<=0)break;
            if(v[i]<M*2){  //세로
                key2 = true;
                break;
            }
            if(sum < M*2){
                if(sum%M==0){
                    break;
                }
                else{
                key2 = true;
                break;
                    
                }
            }
            if(i==K-1){
                if(v[i]<sum){key2=true;break;}
            }
            sum -=(v[i]/M)*M;
        }
        if(num<N*M){
            key1=true;
            key2=true;
        }
        if(!key1||!key2)cout<<"Yes"<<'\n';
        else if(key1&&key2)cout<<"No"<<'\n';
        v.clear();
    }//while
    
}
