#include<iostream>
#include<string>
// #include<algorithm>
#include<utility>
using namespace std;
template<class BidirIt>
void my_reverse(BidirIt first,BidirIt last){
    while(first!=last--&&first!=last){
        iter_swap(first,last);
        first++;
    }
}
int  main(){
    string s;
    int k;
    cin >> k>>s;
    // 防止后续除以0
    int n = s.size();
    if(n==0){
        cout<<s;
        return 0;
    }
    // 处理 k 大于字符串长度的情况
    k = k % n;
    // my_reverse(s.begin(),s.end());
    // my_reverse(s.begin(),s.begin()+k);
    // my_reverse(s.begin()+k,s.end());
    // cout << s;
    /*左旋转k位*/
    my_reverse(s.begin(),s.end());
    my_reverse(s.begin(),s.begin()+n-k);
    my_reverse(s.begin()+n-k,s.end());
    cout << s;
    return 0;
}