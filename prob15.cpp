#include <bits/stdc++.h>
int findMajorityElement(int nums[], int N) {
		int el=0,cnt=0;
        for(int i=0;i<N;i++){
            if(cnt==0){
                el=nums[i];
                cnt=1;
            }else{
                if(nums[i]==el)cnt++;
                else cnt--;
            }
        }
        cnt=0;
        for(int i=0;i<N;i++){
            if(nums[i]==el)cnt++;
        }
        return (cnt>N/2)?el:-1;
}