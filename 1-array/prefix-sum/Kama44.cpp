#include<iostream>
#include<vector>
#include<climits>

using namespace std;
int main(){
/*method1：using prefix sum*/
    // int n,m;
    // scanf("%d%d",&n,&m);
    // vector<vector<int>> arr(n,vector<int>(m,0));
    // int i,j;
    // int sum = 0;//存储所有区块价值之和，减去算的子区域剩下的就是另一个子区域的价值
    // for(i=0;i<n;i++){
    //     for(j=0;j<m;j++){
    //         scanf("%d",&arr[i][j]);
    //         sum+=arr[i][j];
    //     }
    // }
    // /*计算横向即行的前缀和*/
    // int presum = 0;
    // vector<int> ph(n);
    // for(i=0;i<n;i++){
    //     presum = 0;
    //     for(j=0;j<m;j++){
    //         presum+=arr[i][j];
    //     }
    //     ph[i] = presum;
    // }
    // /*计算纵向即列的前缀和*/
    // vector<int> pv(m);
    // for(j=0;j<m;j++){
    //     presum = 0;
    //     for(i=0;i<n;i++){
    //         presum+=arr[i][j];
    //     }
    //     pv[j] = presum;
    // }
    // /*横向切割*/
    // int res = INT_MAX;
    // int part = 0;
    // for(i=0;i<n-1;i++){//不可能全部分给一个区域，所以i=n-1不用考虑
    //     part+=ph[i];
    //     res = min(res,abs(sum-part-part));
    // }
    // /*纵向切割*/
    // part = 0;
    // for(j=0;j<m-1;j++){//不可能全部分给一个区域，所以j=m-1不用考虑
    //     part+=pv[j];
    //     res = min(res,abs(sum-part-part));
    // }
    // printf("%d\n",res);
/*method2：可以不计算前缀和，即ph/pv这些，再套一个内层循环即可*/
    int n,m;
    scanf("%d%d",&n,&m);
    vector<vector<int>> arr(n,vector<int>(m,0));
    int i,j;
    int sum = 0;//存储所有区块价值之和，减去算的子区域剩下的就是另一个子区域的价值
    for(i=0;i<n;i++){
        for(j=0;j<m;j++){
            scanf("%d",&arr[i][j]);
            sum+=arr[i][j];
        }
    }
    /*横向切割*/
    int res = INT_MAX;
    int part = 0;
    for(i=0;i<n-1;i++){//不可能全部分给一个区域，所以i=n-1不用考虑
        for(j=0;j<m;j++){
            part+=arr[i][j];
        }
        res = min(res,abs(sum-part-part));
    }
    /*纵向切割*/
    part = 0;
    for(j=0;j<m-1;j++){//不可能全部分给一个区域，所以j=m-1不用考虑
        for(i=0;i<n;i++){
            part+=arr[i][j];
        }
        res = min(res,abs(sum-part-part));
    }
    printf("%d\n",res);
    return 0;
}