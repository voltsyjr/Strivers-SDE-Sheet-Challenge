#include <bits/stdc++.h> 
int compareVersions(string a, string b) {
    int i=0,j=0;
    while(true){
        while(i<a.size() and a[i]=='0')i++;
        while(j<b.size() and b[j]=='0')j++;
        int x=i,y=j;
        while(i<a.size() and a[i]!='.')i++;
        while(j<b.size() and b[j]!='.')j++;
        if(i-x>j-y)return 1;
        else if(i-x<j-y)return -1;
        while(x<i){
            if(a[x]>b[y])return 1;
            else if(a[x]<b[y])return -1;
            x++;y++;
        }
        i++,j++;
        if(i>=a.size() and j>=b.size())return 0;
    }
    
    return 0;
}