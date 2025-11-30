#include<iostream>
#include<vector>
using namespace std;
int main(){
/*method1:brute force*/
    // int n;
    // cin>>n;
    // vector<int> arr(n);
    // for(int i=0;i<n;i++)
    //     cin>>arr[i];
    // int a,b;
    // int sum = 0;
    // while(cin>>a>>b){
    //     sum = 0;
    //     for(int i=a;i<=b;i++)
    //         sum+=arr[i];
    //     cout<<sum<<endl;
    // }
/*method2:prefix sum*/
    // int n;
    // cin>>n;
    // vector<int> arr(n);
    // vector<int> prefix(n,0);
    // int presum = 0;
    // for(int i=0;i<n;i++) {
    //     cin>>arr[i];
    //     presum+=arr[i];
    //     prefix[i] = presum;
    // }
    // int sum = 0;
    // int a,b;
    // // while(cin>>a>>b){
    // //     sum = prefix[b]-prefix[a]+arr[a];
    // //     cout<<sum<<endl;
    // // }
    // while(cin>>a>>b){
    //     if(a==0)
    //         sum = prefix[b];
    //     else
    //         sum = prefix[b]-prefix[a-1];
    //     cout<<sum<<endl;
    // }
/*improve:using scanf to accelerate*/
    int n;
    cin>>n;
    vector<int> arr(n);
    vector<int> prefix(n,0);
    int presum = 0;
    for(int i=0;i<n;i++){
        scanf("%d ",&arr[i]);
        presum+=arr[i];
        prefix[i] = presum;
    }
    int sum = 0;
    int a,b;
    while(scanf("%d%d",&a,&b)==2){
        if(a==0){
            sum=prefix[b];
        }
        else{
            sum=prefix[b]-prefix[a-1];
        }
        printf("%d\n",sum);
    }

    return 0;
}