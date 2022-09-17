#include <iostream>
using namespace std;
int main() {
    freopen("stairs.inp", "r", stdin);
    freopen("stairs.out", "w", stdout);
    
    int T; cin>>T;
    while(T--){
        int M, F, N; cin>>M>>F>>N;
        cout<< (N + M - 2) / (M - 1) << '\n';
    }
}
