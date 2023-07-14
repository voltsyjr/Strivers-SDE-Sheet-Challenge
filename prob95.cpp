#include <bits/stdc++.h> 
int atoi(string str) {
    if(str=="")return 0;
    string res="";
    int i=0,neg=0,n=str.size();
    while(i<n and (str[i]<'0' or str[i]>'9')){
        if(str[i]=='-')neg=1;
        i++;
    }
    while(i<n){
        if(str[i]>='0' and str[i]<='9')res+=str[i];
        i++;
    }
    int ans=0;
    i=0;
    unordered_map<char,int>mp={{'0',0},{'1',1},{'2',2},{'3',3},{'4',4}
                              ,{'5',5},{'6',6},{'7',7},{'8',8},{'9',9}};
    while(i<res.size()){
        ans*=10;
        ans+=mp[res[i]];
        i++;
    }
    return neg==0?ans:-1*ans;
}