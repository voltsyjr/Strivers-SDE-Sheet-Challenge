int aggressiveCows(vector<int> &stalls, int k)
{
    long long l=1,r=0;
    sort(stalls.begin(),stalls.end());
    r=stalls.back()-stalls.front();
    long long ans=r;
    while(l<=r){
        long long m=(l+r)/2;
        long long cows=1,prev=stalls[0];
        for(int i=1;i<stalls.size();i++){
            int dist=stalls[i]-prev;
            if(dist>=m)prev=stalls[i],cows++;
        }
        if(cows<k) r=m-1;
        else ans=m,l=m+1;
    }
    return ans;
}