#include <iostream>
#include <string>
using namespace std;
int main() {
//   string s;
//   cin >> s;
//   for (int i = 0; i < s.length(); i++) {
//     if (s[i] >= '0' && s[i] <= '9')
//       s.replace(i, 1, "number");
//       i+=5;
//   }
//   cout << s;
/*method2：不使用库函数:双指针法*/
    string s;
    while(cin>>s){
        int cnt = 0;//记录数字字符出现的字数，方便扩容预留大小
        int l = s.size()-1;//左指针，旧数组末尾
        for(char c:s)
            if(c>='0'&&c<='9') cnt++;
        s.resize(s.size()+cnt*(6-1));//原本的数字字符被覆盖
        int r = s.size()-1;//右指针，新数组末尾
        while(l>=0){
            //从后往前填充，规避大量复制和移动数组元素
            if(s[l]<'a'){
                s[r--]='r';
                s[r--]='e';
                s[r--]='b';
                s[r--]='m';
                s[r--]='u';
                s[r--]='n';
            }else{
                s[r--]=s[l];
            }
            l--;
        }
        cout<<s;
    }
  return 0;
}