bool comp(Item a,Item b){
    double r1=(double)a.value/a.weight,r2=(double)b.value/b.weight;
    return r1>r2;
}
class Solution
{
    public:
    //Function to get the maximum total value in the knapsack.
    double fractionalKnapsack(int W, Item arr[], int n)
    {
        sort(arr,arr+n,comp);
        int curWeight=0;
        double ans=0;
        for(int i=0;i<n;i++){
            if(curWeight+arr[i].weight<=W){
                curWeight+=arr[i].weight;
                ans+=arr[i].value;
            }else{
                ans+=((double)arr[i].value/arr[i].weight)*(W-curWeight);
                return ans;
            }
        }
        return ans;
    }
        
};