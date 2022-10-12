//
//  Copyright (c) 2021 HyeJin Shin All rights reserved.
//

#include <iostream>
#include <algorithm>
#include <vector>
#include <iomanip>

using namespace std;
int n,m;
char c;
char ch;
string str;
vector<char> ans;
char arr[201][201];
void BtoD(int start1,int end1, int start2, int end2){
    if((end1-start1)<0)return;
    if((end2-start2)<0)return;
    bool flag_0 = false;
    for(int i=start1;i<=end1;i++){
        for(int k=start2;k<=end2;k++){
            if(arr[k][i]!='0'){
                flag_0 = true;
                break;
            }
        }
        if(flag_0)break;
    }
    if(!flag_0){
        ans.push_back('0');
        return;
    }
    bool flag_1 = false;
    for(int i=start1;i<=end1;i++){
        for(int k=start2;k<=end2;k++){
            if(arr[k][i]!='1'){
                flag_1 = true;
                break;
            }
        }
        if(flag_1)break;
    }
    if(!flag_1){
        ans.push_back('1');
        return;
    }
    else if(flag_1==true &&flag_0==true) {
        ans.push_back('D');
        int mid1 = (end1-start1)/2+start1;
        int mid2 = (end2-start2)/2+start2;
        
        BtoD(start1,mid1,start2,mid2);
        BtoD(mid1+1,end1,start2,mid2);
        
        BtoD(start1,mid1,mid2+1,end2);
        BtoD(mid1+1,end1,mid2+1,end2);
    }
}
void DtoB(int start1,int end1,int start2,int end2){
    if((end1-start1)<0){return;}
    if((end2-start2)<0){return;}
    ch = cin.get();
    if (ch == '0' || ch == '1'){
        for(int i=start1;i<=end1;i++){
            for(int k=start2;k<=end2;k++){
                arr[k][i]=ch;
            }
        }
        return;
    }
    else if(ch=='D'){  //D
        int mid1 = (end1-start1)/2+start1;
        int mid2 = (end2-start2)/2+start2;
        DtoB(start1,mid1,start2,mid2);
        DtoB(mid1+1,end1,start2,mid2);
        DtoB(start1,mid1,mid2+1,end2);
        DtoB(mid1+1,end1,mid2+1,end2);
    }
    else if(ch=='\n'){
        DtoB(start1,end1,start2,end2);
    }
    
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
//    freopen("bitmap.inp","r",stdin);
//    freopen("bitmap.out","w",stdout);
    while(cin >> c, c != '#'){
        cin>>n>>m;
        cin.ignore();
        
        if(c=='B'){
            int input = (n*m/50)+1;
            if((n*m)%50 ==0){input = (n*m/50);}
            int ii=1; int kk=1;
            while(input--){
                cin>>str;
                for(int idx=0;idx<str.length();idx++){
                    if(kk>m){
                        kk=1;
                        ii++;
                    }
                    arr[ii][kk]=str[idx];
                    kk++;
                }
            }
            cout<<'D'<<' '<<n<<' '<<m<<'\n';
            BtoD(1,m,1,n);
            int inp = ans.size()/50 +1;
            int idx = 0;
            while(inp--){
                for(int i=0;i<50;i++){
                    if(idx>ans.size()-1)break;
                    cout<<ans[idx];
                    idx++;
                }
                
                cout<<'\n';
                if(idx>ans.size()-1)break;
                
            }
        }
        else if(c=='D'){
            cout<<'B'<<' '<<n<<' '<<m<<'\n';
            DtoB(1,m,1,n);
            int input = (n*m/50)+1;
            if((n*m)%50 ==0){input = (n*m/50);}
            int ii=1; int kk=1;
            while(input--){
                for(int idx=0;idx<50;idx++){
                    if(kk>m){
                        kk=1;
                        ii++;
                    }
                    if(ii>n){break;}
                    cout<<arr[ii][kk];
                    kk++;
                }
                cout<<'\n';
                if(ii>n){break;}
            }

        }
        for(int i=0;i<=n;i++){
            for(int k=0;k<=m;k++){
                arr[i][k]='\0';
            }
        }
        ans.clear();

    }
}
