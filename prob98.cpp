int l=0,r=0,i=0,n=s.size(),m=p.size();
    vector<int>ans,z;
    string c=p+'#'+s;
    int k=c.size();
    z.push_back(0);//initially no match;
    for(i=1;i<k;i++){
        if(i>r){
            l=r=i;
            while(r<k and c[r]==c[r-l])r++;
            z.push_back((r--)-l);
            if(z[i]==m)ans.push_back(i-m);// 1based indexing nhi to 1 minus hota
        }else{
            int pos=i-l;
            if(z[pos]+i<=r){
                z.push_back(z[pos]);
                if(z[i]==m)ans.push_back(i-m);
            }else{
                l=i;
                while(r<k and c[r]==c[r-l])r++;
                z.push_back((r--)-l);
                if(z[i]==m)ans.push_back(i-m);
            }
        }
    }
    return ans;