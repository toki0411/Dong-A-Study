//
//  Copyright (c) 2021 HyeJin Shin All rights reserved.
//

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;
long long N,A,B;
long long sum = 0;
long long x_x, x_y=0;
long long where(long long X){
    long long s = 0;
    sum = 0;
    for(long long i=1;i<=N/2+N%2;i++){
        long long t = 4*N -i*8+4;
        if(X<=t+sum){
            s=i;
            break;
        }
        else {
            sum += t;
        }
    }
    return s;
}
void index(long long x,long long s){
    if(x>=sum+1&&x<=sum+N-(s-1)*2){
        
        x_x = s;
        x_y =x-sum-1+s;
    }
    sum = sum+N-(s-1)*2;
    
    if(x>=sum+1&&x<=sum+N-(s-1)*2-1){
        
        x_x =x-sum+s;
        x_y = N-s+1;
    }
    sum = sum+N-(s-1)*2-1;
    
    if(x>=sum+1&&x<=sum+N-(s-1)*2 -1){
        
        x_x=N-s+1;
        x_y =sum+N-(s-1)*2-1-x +s;
    }
    sum = sum+N-(s-1)*2 -1;
    
    if(x>=sum+1&&x<=sum+N-(s-1)*2-2){
        
        x_x =sum+N-(s-1)*2-2-x+s+1;
        x_y = s;
    }
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    freopen("snail.inp","r",stdin);
    freopen("snail.out","w",stdout);
    int T;
    cin >> T;
    while(T--){
        cin>>N>>A>>B;
        long long A_x, A_y = 0;
        long long B_x, B_y = 0;
        long long start_1 = where(A);
       
        index(A,start_1);
        A_x=x_x; A_y = x_y;
       
        sum = 0;
        
        long long start_2 = where(B);
        index(B,start_2);
        B_x=x_x; B_y = x_y;
   
        if(abs(A_x-B_x)==abs(A_y-B_y))cout<<"YES"<<'\n';
        else cout<<"NO"<<'\n';
    }
}

