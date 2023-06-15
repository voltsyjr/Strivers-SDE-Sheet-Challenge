#include<bits/stdc++.h>
int modularExponentiation(int xx,int n,int m){
    long long x=xx;
    long long ans=1;
    while(n>0){
        if(n&1)ans=(ans*x)%m,n--;
        else x=(x*x)%m,n/=2;
    }
    return ans%m;
}