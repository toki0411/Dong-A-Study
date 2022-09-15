//
//  Copyright (c) 2021 HyeJin Shin All rights reserved.
//

#include <iostream>
#include <algorithm>
#include <memory.h>

using namespace std;
int T;
int N,M;
char arr[101][101];
char temp[101][101];
string str;
int c;
int cnt;
string s;
void push(){
    for(int k=0;k<N;k++){
        s.clear();
        for(int i=N-1;i>=0;i--){
            if(arr[i][k]!='.'){
                s+=arr[i][k];
            }
        }
        
        int idx =0;
        for(int i=N-1;i>=0;i--){
            if(idx < s.length()){
                arr[i][k]=s[idx];
                idx++;
            }
            else{
                
                arr[i][k]='.';
            }
            
        }
    }
}
void rotate(){
    for(int i=0; i<N; i++)
          for(int j=0; j<N; j++)
              temp[i][j] = arr[N - j -1][i];
    memmove(arr, temp, sizeof(arr));
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
//    freopen("spinslide.inp","r",stdin);
//    freopen("spinslide.out","w",stdout);
    cin>>T; 
    for(int l=1;l<=T;l++){
        cin>>N>>M;
        for(int i=0;i<N;i++){
            cin>>str;
            for(int k=0;k<N;k++){
                arr[i][k] = str[k];
            }
        }
        for(int i=0;i<M;i++){
            rotate();
            push();
        }
        cout<<"Case #"<<l<<":"<<'\n';
        for(int i=0;i<N;i++){
            for(int k =0;k<N;k++){
                cout<<arr[i][k];
            }
            cout<<'\n';
            memset(arr[i], 0, N);
        }
        cout<<'\n';
        
    }
}

