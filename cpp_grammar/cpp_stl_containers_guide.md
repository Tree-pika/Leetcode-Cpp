# C++ STL 容器完整用法指南

## 目录
1. [顺序容器 (Sequence Containers)](#1-顺序容器-sequence-containers)
2. [关联容器 (Associative Containers)](#2-关联容器-associative-containers)
3. [无序容器 (Unordered Containers)](#3-无序容器-unordered-containers)
4. [容器适配器 (Container Adaptors)](#4-容器适配器-container-adaptors)
5. [与 `<algorithm>` 库的耦合](#5-与-algorithm-库的耦合)

---

# 1. 顺序容器 (Sequence Containers)

## 1.1 vector

`vector` 是动态数组，支持随机访问，尾部插入/删除高效，中间插入/删除低效。

### 1.1.1 构造与初始化

```cpp
#include <vector>
using namespace std;

// 默认构造：创建空vector
vector<int> v1;

// 指定大小，元素初始化为默认值(int为0)
vector<int> v2(5);           // {0, 0, 0, 0, 0}

// 指定大小和初始值
vector<int> v3(5, 10);       // {10, 10, 10, 10, 10}

// 列表初始化 (C++11)
vector<int> v4 = {1, 2, 3, 4, 5};
vector<int> v5{1, 2, 3, 4, 5};  // 等价写法

// 拷贝构造
vector<int> v6(v4);          // v6是v4的副本

// 移动构造 (C++11)
vector<int> v7(std::move(v5)); // v5的资源转移到v7

// 迭代器范围构造
vector<int> v8(v4.begin(), v4.begin() + 3);  // {1, 2, 3}

// 从数组构造
int arr[] = {1, 2, 3};
vector<int> v9(arr, arr + 3);
```

### 1.1.2 模板传参

```cpp
// 自定义类型
struct Person {
    string name;
    int age;
};
vector<Person> people;

// 嵌套容器
vector<vector<int>> matrix(3, vector<int>(4, 0));  // 3x4矩阵，初始化为0

// 自定义分配器（高级用法）
vector<int, std::allocator<int>> v_custom;
```

### 1.1.3 插入元素

```cpp
vector<int> v;

// push_back: 在尾部插入（拷贝）
v.push_back(10);

// emplace_back: 在尾部原地构造（C++11，更高效，避免临时对象）
v.emplace_back(20);

// insert: 在指定位置插入
v.insert(v.begin(), 5);           // 在开头插入5
v.insert(v.begin() + 1, 3, 7);    // 在位置1插入3个7
v.insert(v.end(), {8, 9, 10});    // 在尾部插入列表

// emplace: 在指定位置原地构造
v.emplace(v.begin(), 100);
```

### 1.1.4 删除元素

```cpp
vector<int> v = {1, 2, 3, 4, 5};

// pop_back: 删除最后一个元素
v.pop_back();  // v = {1, 2, 3, 4}

// erase: 删除指定位置或范围
v.erase(v.begin());              // 删除第一个，v = {2, 3, 4}
v.erase(v.begin(), v.begin()+2); // 删除前两个，v = {4}

// clear: 清空所有元素
v.clear();

// 删除特定值的所有元素（erase-remove idiom）
v = {1, 2, 3, 2, 4, 2};
v.erase(remove(v.begin(), v.end(), 2), v.end());  // 删除所有2，v = {1, 3, 4}
```

### 1.1.5 修改元素

```cpp
vector<int> v = {1, 2, 3, 4, 5};

// 下标访问修改（不检查边界）
v[0] = 10;

// at() 访问修改（检查边界，越界抛出out_of_range异常）
v.at(1) = 20;

// front() 和 back() 访问首尾元素
v.front() = 100;
v.back() = 500;

// 批量赋值
v.assign(5, 0);           // v = {0, 0, 0, 0, 0}
v.assign({1, 2, 3});      // v = {1, 2, 3}
```

### 1.1.6 查找元素

```cpp
#include <algorithm>
vector<int> v = {1, 2, 3, 4, 5};

// find: 返回迭代器，找不到返回end()
auto it = find(v.begin(), v.end(), 3);
if (it != v.end()) {
    cout << "Found: " << *it << endl;           // 输出: Found: 3
    cout << "Index: " << it - v.begin() << endl; // 输出: Index: 2
}

// find_if: 按条件查找
auto it2 = find_if(v.begin(), v.end(), [](int x) { return x > 3; });

// binary_search: 二分查找（需要有序）
sort(v.begin(), v.end());
bool found = binary_search(v.begin(), v.end(), 3);  // true

// lower_bound / upper_bound: 二分查找边界
auto lb = lower_bound(v.begin(), v.end(), 3);  // 第一个>=3的位置
auto ub = upper_bound(v.begin(), v.end(), 3);  // 第一个>3的位置
```

### 1.1.7 遍历容器

```cpp
vector<int> v = {1, 2, 3, 4, 5};

// 1. 下标遍历
for (size_t i = 0; i < v.size(); ++i) {
    cout << v[i] << " ";
}

// 2. 迭代器遍历
for (vector<int>::iterator it = v.begin(); it != v.end(); ++it) {
    cout << *it << " ";
}

// 3. 范围for循环（C++11，推荐）
for (int x : v) {
    cout << x << " ";
}

// 4. 引用遍历（可修改元素）
for (int& x : v) {
    x *= 2;  // 每个元素乘2
}

// 5. const引用遍历（只读，避免拷贝）
for (const int& x : v) {
    cout << x << " ";
}

// 6. 反向遍历
for (auto rit = v.rbegin(); rit != v.rend(); ++rit) {
    cout << *rit << " ";
}
```

### 1.1.8 容量与内存

```cpp
vector<int> v;

// size: 当前元素个数
cout << v.size();       // 0

// capacity: 当前分配的容量
cout << v.capacity();   // 实现相关，通常为0

// empty: 是否为空
if (v.empty()) { /* ... */ }

// reserve: 预分配容量（重要优化！）
v.reserve(100);  // 预留100个元素的空间，避免后续扩容时的大量复制
// 好处：如果预知元素数量，提前reserve可避免多次重新分配和复制

// resize: 改变元素个数
v.resize(10);        // 扩展到10个元素，新元素初始化为0
v.resize(20, -1);    // 扩展到20个元素，新元素初始化为-1
v.resize(5);         // 缩减到5个元素

// shrink_to_fit: 释放多余内存（C++11）
v.shrink_to_fit();   // capacity减少到size

// max_size: 理论最大容量
cout << v.max_size();

// data: 获取底层数组指针
int* ptr = v.data();
```

### 1.1.9 迭代器使用

```cpp
vector<int> v = {1, 2, 3, 4, 5};

// 正向迭代器
vector<int>::iterator it = v.begin();
vector<int>::iterator it_end = v.end();

// 常量迭代器（不能修改元素）
vector<int>::const_iterator cit = v.cbegin();

// 反向迭代器
vector<int>::reverse_iterator rit = v.rbegin();

// auto关键字简化（C++11）
auto it2 = v.begin();
auto cit2 = v.cbegin();

// 迭代器算术运算（随机访问迭代器支持）
it = v.begin() + 2;      // 指向第3个元素
int dist = it - v.begin(); // 距离为2
it += 1;                  // 前进1
it -= 1;                  // 后退1
```

### 1.1.10 计数与存在性

```cpp
#include <algorithm>
vector<int> v = {1, 2, 3, 2, 4, 2, 5};

// count: 统计元素出现次数
int cnt = count(v.begin(), v.end(), 2);  // cnt = 3

// count_if: 按条件统计
int cnt2 = count_if(v.begin(), v.end(), [](int x) { return x > 2; });  // cnt2 = 3

// 检查元素是否存在
bool exists = find(v.begin(), v.end(), 3) != v.end();  // true

// any_of, all_of, none_of (C++11)
bool any = any_of(v.begin(), v.end(), [](int x) { return x > 4; });   // true
bool all = all_of(v.begin(), v.end(), [](int x) { return x > 0; });   // true
bool none = none_of(v.begin(), v.end(), [](int x) { return x < 0; }); // true
```

---

## 1.2 list

`list` 是双向链表，任意位置插入/删除高效，不支持随机访问。

### 1.2.1 构造与初始化

```cpp
#include <list>

list<int> l1;                    // 空链表
list<int> l2(5);                 // 5个元素，值为0
list<int> l3(5, 10);             // 5个元素，值为10
list<int> l4 = {1, 2, 3, 4, 5};  // 列表初始化
list<int> l5(l4);                // 拷贝构造
list<int> l6(l4.begin(), l4.end()); // 迭代器范围构造
```

### 1.2.2 插入元素

```cpp
list<int> l = {2, 3, 4};

// 首尾插入
l.push_front(1);    // {1, 2, 3, 4}
l.push_back(5);     // {1, 2, 3, 4, 5}
l.emplace_front(0); // {0, 1, 2, 3, 4, 5}
l.emplace_back(6);  // {0, 1, 2, 3, 4, 5, 6}

// 指定位置插入
auto it = l.begin();
advance(it, 3);           // 移动到第4个位置
l.insert(it, 100);        // 在第4个位置前插入100
l.insert(it, 2, 200);     // 插入2个200
l.insert(it, {300, 400}); // 插入列表
```

### 1.2.3 删除元素

```cpp
list<int> l = {1, 2, 3, 2, 4, 2, 5};

l.pop_front();           // 删除首元素
l.pop_back();            // 删除尾元素
l.erase(l.begin());      // 删除指定位置

// remove: 删除所有等于指定值的元素（list专属成员函数）
l.remove(2);             // 删除所有2

// remove_if: 按条件删除
l.remove_if([](int x) { return x > 3; });

// unique: 删除连续重复元素（通常先排序）
l.sort();
l.unique();

l.clear();               // 清空
```

### 1.2.4 特殊操作

```cpp
list<int> l1 = {1, 3, 5};
list<int> l2 = {2, 4, 6};

// merge: 合并两个有序链表
l1.merge(l2);  // l1 = {1, 2, 3, 4, 5, 6}, l2变空

// splice: 将另一个链表的元素转移过来
list<int> l3 = {10, 20, 30};
l1.splice(l1.begin(), l3);  // l3的所有元素移到l1开头

// reverse: 反转链表
l1.reverse();

// sort: 排序（list有自己的sort，因为std::sort需要随机访问迭代器）
l1.sort();                           // 升序
l1.sort(greater<int>());             // 降序
l1.sort([](int a, int b) { return a > b; }); // 自定义比较
```

### 1.2.5 遍历与迭代器

```cpp
list<int> l = {1, 2, 3, 4, 5};

// 范围for
for (int x : l) {
    cout << x << " ";
}

// 迭代器遍历
for (auto it = l.begin(); it != l.end(); ++it) {
    cout << *it << " ";
}

// 注意：list迭代器只支持++和--，不支持+n或-n
auto it = l.begin();
++it;      // OK
// it + 2; // 错误！
advance(it, 2);  // 正确：使用advance移动迭代器
```

---

## 1.3 deque

`deque`（双端队列）支持两端高效插入/删除，支持随机访问。

### 1.3.1 构造与初始化

```cpp
#include <deque>

deque<int> d1;                   // 空
deque<int> d2(5);                // 5个0
deque<int> d3(5, 10);            // 5个10
deque<int> d4 = {1, 2, 3, 4, 5}; // 列表初始化
```

### 1.3.2 插入与删除

```cpp
deque<int> d = {2, 3, 4};

// 两端操作（高效）
d.push_front(1);   // {1, 2, 3, 4}
d.push_back(5);    // {1, 2, 3, 4, 5}
d.pop_front();     // {2, 3, 4, 5}
d.pop_back();      // {2, 3, 4}

// 中间插入/删除（与vector类似）
d.insert(d.begin() + 1, 100);  // 在位置1插入
d.erase(d.begin());            // 删除首元素
```

### 1.3.3 访问元素

```cpp
deque<int> d = {1, 2, 3, 4, 5};

// 随机访问
cout << d[2];       // 3
cout << d.at(2);    // 3（带边界检查）
cout << d.front();  // 1
cout << d.back();   // 5
```

---

## 1.4 array (C++11)

`array` 是固定大小的数组封装，大小在编译时确定。

### 1.4.1 构造与初始化

```cpp
#include <array>

array<int, 5> a1;                  // 未初始化（栈上可能是垃圾值）
array<int, 5> a2 = {};             // 全部初始化为0
array<int, 5> a3 = {1, 2, 3, 4, 5};
array<int, 5> a4 = {1, 2};         // {1, 2, 0, 0, 0}
```

### 1.4.2 基本操作

```cpp
array<int, 5> a = {1, 2, 3, 4, 5};

// 访问
cout << a[0];        // 1
cout << a.at(0);     // 1
cout << a.front();   // 1
cout << a.back();    // 5

// 大小（编译时常量）
cout << a.size();    // 5
cout << a.empty();   // false

// 填充
a.fill(0);           // 全部设为0

// 交换
array<int, 5> b = {6, 7, 8, 9, 10};
a.swap(b);

// 获取底层指针
int* ptr = a.data();
```

### 1.4.3 与C数组的区别

```cpp
array<int, 5> a = {1, 2, 3, 4, 5};

// 可以直接赋值
array<int, 5> b = a;  // 深拷贝

// 可以比较
if (a == b) { /* ... */ }
if (a < b)  { /* ... */ }

// 可作为函数返回值
array<int, 3> getArray() {
    return {1, 2, 3};
}
```

---

## 1.5 forward_list (C++11)

`forward_list` 是单向链表，比 `list` 更节省内存，只能单向遍历。

### 1.5.1 构造与初始化

```cpp
#include <forward_list>

forward_list<int> fl1;
forward_list<int> fl2(5);               // 5个0
forward_list<int> fl3(5, 10);           // 5个10
forward_list<int> fl4 = {1, 2, 3, 4, 5};
```

### 1.5.2 插入与删除

```cpp
forward_list<int> fl = {2, 3, 4};

// 只能在头部插入
fl.push_front(1);    // {1, 2, 3, 4}
fl.emplace_front(0); // {0, 1, 2, 3, 4}
fl.pop_front();      // {1, 2, 3, 4}

// 在指定位置之后插入
auto it = fl.begin();
fl.insert_after(it, 100);        // 在第1个元素后插入100
fl.emplace_after(it, 200);       // 原地构造

// 删除指定位置之后的元素
fl.erase_after(fl.begin());      // 删除第2个元素
fl.erase_after(fl.begin(), fl.end()); // 删除第1个元素后的所有元素

// remove / remove_if
fl.remove(2);
fl.remove_if([](int x) { return x < 0; });
```

### 1.5.3 特殊操作

```cpp
forward_list<int> fl = {3, 1, 4, 1, 5};

// before_begin: 返回第一个元素之前的迭代器
auto before = fl.before_begin();
fl.insert_after(before, 0);  // 在最前面插入0

// 排序与去重
fl.sort();
fl.unique();

// 合并与反转
forward_list<int> fl2 = {2, 6, 8};
fl.merge(fl2);
fl.reverse();
```

---

# 2. 关联容器 (Associative Containers)

关联容器基于红黑树实现，元素自动排序，查找/插入/删除时间复杂度为 O(log n)。

## 2.1 set

`set` 存储唯一元素，自动排序。

### 2.1.1 构造与初始化

```cpp
#include <set>

set<int> s1;                     // 空set
set<int> s2 = {3, 1, 4, 1, 5};   // {1, 3, 4, 5}，自动去重排序
set<int> s3(s2);                 // 拷贝构造

// 自定义比较器（降序）
set<int, greater<int>> s4 = {1, 2, 3};  // {3, 2, 1}

// 自定义比较函数
auto cmp = [](int a, int b) { return a > b; };
set<int, decltype(cmp)> s5(cmp);
```

### 2.1.2 插入元素

```cpp
set<int> s;

// insert: 返回pair<iterator, bool>
auto result = s.insert(10);
if (result.second) {
    cout << "Inserted: " << *result.first << endl;
} else {
    cout << "Already exists" << endl;
}

// 插入多个
s.insert({1, 2, 3, 4, 5});

// emplace: 原地构造
s.emplace(20);

// emplace_hint: 带提示的原地构造
s.emplace_hint(s.end(), 100);
```

### 2.1.3 删除元素

```cpp
set<int> s = {1, 2, 3, 4, 5};

// 按值删除：返回删除的元素个数
size_t removed = s.erase(3);  // removed = 1

// 按迭代器删除
s.erase(s.begin());

// 删除范围
s.erase(s.begin(), s.find(4));

s.clear();  // 清空
```

### 2.1.4 查找元素

```cpp
set<int> s = {1, 2, 3, 4, 5};

// find: 返回迭代器
auto it = s.find(3);
if (it != s.end()) {
    cout << "Found: " << *it << endl;
}

// count: 返回0或1
if (s.count(3)) {
    cout << "3 exists" << endl;
}

// contains (C++20): 更直观
// if (s.contains(3)) { /* ... */ }

// lower_bound: 第一个>=key的迭代器
auto lb = s.lower_bound(3);  // 指向3

// upper_bound: 第一个>key的迭代器
auto ub = s.upper_bound(3);  // 指向4

// equal_range: 返回[lower_bound, upper_bound)的pair
auto range = s.equal_range(3);
```

### 2.1.5 遍历

```cpp
set<int> s = {5, 2, 8, 1, 9};

// 正序遍历（自动排序后：1, 2, 5, 8, 9）
for (int x : s) {
    cout << x << " ";
}

// 反向遍历
for (auto rit = s.rbegin(); rit != s.rend(); ++rit) {
    cout << *rit << " ";
}
```

---

## 2.2 map

`map` 存储键值对，按键排序，键唯一。

### 2.2.1 构造与初始化

```cpp
#include <map>

map<string, int> m1;  // 空map

// 列表初始化
map<string, int> m2 = {
    {"apple", 1},
    {"banana", 2},
    {"cherry", 3}
};

// 拷贝构造
map<string, int> m3(m2);

// 自定义比较器
map<string, int, greater<string>> m4;  // 按键降序
```

### 2.2.2 插入元素

```cpp
map<string, int> m;

// 方式1: operator[]（如果键不存在，会创建默认值）
m["apple"] = 1;

// 方式2: insert（不覆盖已存在的键）
m.insert({"banana", 2});
m.insert(make_pair("cherry", 3));
m.insert(pair<string, int>("date", 4));

// insert返回pair<iterator, bool>
auto result = m.insert({"apple", 100});
if (!result.second) {
    cout << "apple already exists with value: " << result.first->second << endl;
}

// 方式3: emplace
m.emplace("elderberry", 5);

// 方式4: insert_or_assign (C++17，插入或更新)
m.insert_or_assign("apple", 999);  // 更新apple的值

// 方式5: try_emplace (C++17，只在键不存在时插入)
m.try_emplace("fig", 6);
```

### 2.2.3 删除元素

```cpp
map<string, int> m = {{"a", 1}, {"b", 2}, {"c", 3}};

// 按键删除
m.erase("b");

// 按迭代器删除
m.erase(m.begin());

// 删除范围
m.erase(m.find("a"), m.end());

m.clear();
```

### 2.2.4 修改元素

```cpp
map<string, int> m = {{"apple", 1}, {"banana", 2}};

// 方式1: operator[]
m["apple"] = 100;

// 方式2: at()（键不存在抛出out_of_range）
m.at("banana") = 200;

// 方式3: 迭代器
auto it = m.find("apple");
if (it != m.end()) {
    it->second = 300;
}
```

### 2.2.5 查找元素

```cpp
map<string, int> m = {{"apple", 1}, {"banana", 2}};

// find
auto it = m.find("apple");
if (it != m.end()) {
    cout << it->first << ": " << it->second << endl;
}

// count
if (m.count("apple")) {
    cout << "apple exists" << endl;
}

// operator[]（注意：如果键不存在会插入默认值！）
int val = m["cherry"];  // cherry不存在，会插入{"cherry", 0}

// at()（键不存在抛异常，更安全）
try {
    int val = m.at("date");
} catch (const out_of_range& e) {
    cout << "Key not found" << endl;
}
```

### 2.2.6 遍历

```cpp
map<string, int> m = {{"apple", 1}, {"banana", 2}, {"cherry", 3}};

// 方式1: 范围for + 结构化绑定 (C++17)
for (auto& [key, value] : m) {
    cout << key << ": " << value << endl;
}

// 方式2: 范围for + pair
for (const auto& p : m) {
    cout << p.first << ": " << p.second << endl;
}

// 方式3: 迭代器
for (auto it = m.begin(); it != m.end(); ++it) {
    cout << it->first << ": " << it->second << endl;
}
```

---

## 2.3 multiset

`multiset` 允许重复元素。

```cpp
#include <set>

multiset<int> ms = {1, 2, 2, 3, 3, 3};

// 插入（总是成功）
ms.insert(2);  // 现在有4个2

// count: 返回元素个数
cout << ms.count(2);  // 4

// equal_range: 获取相等元素的范围
auto range = ms.equal_range(3);
for (auto it = range.first; it != range.second; ++it) {
    cout << *it << " ";  // 3 3 3
}

// erase: 删除所有等于该值的元素
ms.erase(2);  // 删除所有2

// 只删除一个
auto it = ms.find(3);
if (it != ms.end()) {
    ms.erase(it);  // 只删除一个3
}
```

---

## 2.4 multimap

`multimap` 允许重复键。

```cpp
#include <map>

multimap<string, int> mm;

// 插入（总是成功，不用担心键冲突）
mm.insert({"apple", 1});
mm.insert({"apple", 2});
mm.insert({"apple", 3});
mm.insert({"banana", 4});

// 查找所有相同键的值
auto range = mm.equal_range("apple");
for (auto it = range.first; it != range.second; ++it) {
    cout << it->second << " ";  // 1 2 3
}

// count
cout << mm.count("apple");  // 3

// 注意：multimap没有operator[]
```

---

# 3. 无序容器 (Unordered Containers)

基于哈希表实现，平均O(1)查找/插入/删除，不保证顺序。

## 3.1 unordered_set

```cpp
#include <unordered_set>

unordered_set<int> us = {3, 1, 4, 1, 5};  // {3, 1, 4, 5}，去重但不排序

// 插入
us.insert(10);
us.emplace(20);

// 查找
if (us.find(3) != us.end()) { /* found */ }
if (us.count(3)) { /* exists */ }

// 删除
us.erase(3);

// 遍历（顺序不确定）
for (int x : us) {
    cout << x << " ";
}

// 哈希表相关操作
cout << us.bucket_count();      // 桶的数量
cout << us.load_factor();       // 负载因子
cout << us.max_load_factor();   // 最大负载因子
us.rehash(100);                 // 设置桶数量
us.reserve(100);                // 预留空间（设置合适的桶数）
```

### 3.1.1 自定义哈希和比较

```cpp
struct Person {
    string name;
    int age;
    
    bool operator==(const Person& other) const {
        return name == other.name && age == other.age;
    }
};

// 自定义哈希函数
struct PersonHash {
    size_t operator()(const Person& p) const {
        return hash<string>()(p.name) ^ (hash<int>()(p.age) << 1);
    }
};

unordered_set<Person, PersonHash> people;
people.insert({"Alice", 30});
people.insert({"Bob", 25});
```

---

## 3.2 unordered_map

```cpp
#include <unordered_map>

unordered_map<string, int> um = {
    {"apple", 1},
    {"banana", 2}
};

// 基本操作与map类似
um["cherry"] = 3;           // 插入或修改
um.insert({"date", 4});     // 插入
um.emplace("elderberry", 5);

// 查找
auto it = um.find("apple");
if (it != um.end()) {
    cout << it->second << endl;
}

// 遍历（顺序不确定）
for (auto& [key, value] : um) {
    cout << key << ": " << value << endl;
}
```

---

## 3.3 unordered_multiset / unordered_multimap

```cpp
#include <unordered_set>
#include <unordered_map>

// unordered_multiset: 允许重复元素
unordered_multiset<int> ums = {1, 2, 2, 3, 3, 3};
cout << ums.count(3);  // 3

// unordered_multimap: 允许重复键
unordered_multimap<string, int> umm;
umm.insert({"apple", 1});
umm.insert({"apple", 2});

auto range = umm.equal_range("apple");
for (auto it = range.first; it != range.second; ++it) {
    cout << it->second << " ";  // 1 2
}
```

---

# 4. 容器适配器 (Container Adaptors)

容器适配器基于底层容器实现，提供受限的接口。

## 4.1 stack

`stack` 是后进先出（LIFO）的数据结构，默认基于 `deque`。

### 4.1.1 构造与初始化

```cpp
#include <stack>

stack<int> s1;                        // 默认使用deque
stack<int, vector<int>> s2;           // 使用vector作为底层
stack<int, list<int>> s3;             // 使用list作为底层

// 从容器初始化
deque<int> d = {1, 2, 3};
stack<int> s4(d);                     // 3在栈顶
```

### 4.1.2 基本操作

```cpp
stack<int> s;

// 入栈
s.push(1);
s.push(2);
s.push(3);
s.emplace(4);

// 出栈
s.pop();  // 移除4

// 访问栈顶
cout << s.top();  // 3

// 修改栈顶
s.top() = 100;

// 大小与判空
cout << s.size();   // 3
cout << s.empty();  // false

// 交换
stack<int> s2;
s.swap(s2);
```

### 4.1.3 遍历（需要破坏性遍历）

```cpp
stack<int> s;
s.push(1);
s.push(2);
s.push(3);

// stack没有迭代器，只能边pop边访问
while (!s.empty()) {
    cout << s.top() << " ";  // 3 2 1
    s.pop();
}
```

---

## 4.2 queue

`queue` 是先进先出（FIFO）的数据结构，默认基于 `deque`。

### 4.2.1 构造与初始化

```cpp
#include <queue>

queue<int> q1;                        // 默认使用deque
queue<int, list<int>> q2;             // 使用list作为底层

// 从容器初始化
deque<int> d = {1, 2, 3};
queue<int> q3(d);                     // 1在队首
```

### 4.2.2 基本操作

```cpp
queue<int> q;

// 入队
q.push(1);
q.push(2);
q.push(3);
q.emplace(4);

// 出队
q.pop();  // 移除1

// 访问队首和队尾
cout << q.front();  // 2
cout << q.back();   // 4

// 修改
q.front() = 100;
q.back() = 400;

// 大小与判空
cout << q.size();   // 3
cout << q.empty();  // false
```

---

## 4.3 priority_queue

`priority_queue` 是优先队列（堆），默认最大堆，基于 `vector`。

### 4.3.1 构造与初始化

```cpp
#include <queue>

// 默认最大堆
priority_queue<int> pq1;

// 最小堆
priority_queue<int, vector<int>, greater<int>> pq2;

// 从容器初始化
vector<int> v = {3, 1, 4, 1, 5};
priority_queue<int> pq3(v.begin(), v.end());  // 堆顶是5

// 最小堆从容器初始化
priority_queue<int, vector<int>, greater<int>> pq4(v.begin(), v.end());
```

### 4.3.2 基本操作

```cpp
priority_queue<int> pq;

// 入队
pq.push(3);
pq.push(1);
pq.push(4);
pq.emplace(1);
pq.emplace(5);

// 访问堆顶（最大元素）
cout << pq.top();  // 5

// 出队
pq.pop();  // 移除5
cout << pq.top();  // 4

// 大小与判空
cout << pq.size();   // 4
cout << pq.empty();  // false
```

### 4.3.3 自定义比较

```cpp
// 方式1: 使用greater实现最小堆
priority_queue<int, vector<int>, greater<int>> minHeap;

// 方式2: 自定义结构体
struct Compare {
    bool operator()(int a, int b) {
        return a > b;  // 返回true表示a优先级低于b
    }
};
priority_queue<int, vector<int>, Compare> customHeap;

// 方式3: lambda (C++20之前需要一些技巧)
auto cmp = [](int a, int b) { return a > b; };
priority_queue<int, vector<int>, decltype(cmp)> lambdaHeap(cmp);

// 示例：自定义类型的优先队列
struct Task {
    int priority;
    string name;
};

auto taskCmp = [](const Task& a, const Task& b) {
    return a.priority < b.priority;  // 优先级高的先出队
};
priority_queue<Task, vector<Task>, decltype(taskCmp)> taskQueue(taskCmp);

taskQueue.push({3, "Low priority"});
taskQueue.push({10, "High priority"});
taskQueue.push({5, "Medium priority"});

while (!taskQueue.empty()) {
    cout << taskQueue.top().name << endl;  // High, Medium, Low
    taskQueue.pop();
}
```

---

# 5. 与 `<algorithm>` 库的耦合

## 5.1 排序算法

```cpp
#include <algorithm>
#include <vector>

vector<int> v = {5, 2, 8, 1, 9, 3};

// sort: 快速排序（不稳定）
sort(v.begin(), v.end());                        // 升序
sort(v.begin(), v.end(), greater<int>());        // 降序
sort(v.begin(), v.end(), [](int a, int b) {      // 自定义
    return a > b;
});

// stable_sort: 稳定排序
stable_sort(v.begin(), v.end());

// partial_sort: 部分排序，只排前n个
partial_sort(v.begin(), v.begin() + 3, v.end()); // 前3个是最小的3个

// nth_element: 找第n大元素
nth_element(v.begin(), v.begin() + 2, v.end());  // v[2]是第3小的

// is_sorted: 检查是否有序
bool sorted = is_sorted(v.begin(), v.end());
```

## 5.2 查找算法

```cpp
vector<int> v = {1, 2, 3, 4, 5};

// find / find_if
auto it = find(v.begin(), v.end(), 3);
auto it2 = find_if(v.begin(), v.end(), [](int x) { return x > 3; });

// binary_search（需要有序）
bool found = binary_search(v.begin(), v.end(), 3);

// lower_bound / upper_bound（需要有序）
auto lb = lower_bound(v.begin(), v.end(), 3);  // >=3的第一个
auto ub = upper_bound(v.begin(), v.end(), 3);  // >3的第一个

// equal_range（需要有序）
auto range = equal_range(v.begin(), v.end(), 3);

// min_element / max_element
auto minIt = min_element(v.begin(), v.end());
auto maxIt = max_element(v.begin(), v.end());

// minmax_element
auto [minI, maxI] = minmax_element(v.begin(), v.end());
```

## 5.3 修改算法

```cpp
vector<int> v = {1, 2, 3, 4, 5};

// fill: 填充
fill(v.begin(), v.end(), 0);  // 全部设为0

// generate: 生成
int n = 0;
generate(v.begin(), v.end(), [&n]() { return n++; });  // {0,1,2,3,4}

// transform: 变换
transform(v.begin(), v.end(), v.begin(), [](int x) { return x * 2; });

// replace / replace_if
replace(v.begin(), v.end(), 2, 20);  // 把2替换为20
replace_if(v.begin(), v.end(), [](int x) { return x < 0; }, 0);

// reverse: 反转
reverse(v.begin(), v.end());

// rotate: 旋转
rotate(v.begin(), v.begin() + 2, v.end());  // 把前2个移到后面

// shuffle: 随机打乱
random_device rd;
mt19937 g(rd());
shuffle(v.begin(), v.end(), g);

// unique: 去除连续重复（需配合erase）
v = {1, 1, 2, 2, 3, 3};
auto newEnd = unique(v.begin(), v.end());
v.erase(newEnd, v.end());  // {1, 2, 3}
```

## 5.4 复制与移动

```cpp
vector<int> src = {1, 2, 3, 4, 5};
vector<int> dst(5);

// copy
copy(src.begin(), src.end(), dst.begin());

// copy_if
vector<int> even;
copy_if(src.begin(), src.end(), back_inserter(even), [](int x) { return x % 2 == 0; });

// copy_n
copy_n(src.begin(), 3, dst.begin());  // 复制前3个

// move
vector<string> strings = {"hello", "world"};
vector<string> moved(2);
move(strings.begin(), strings.end(), moved.begin());

// swap_ranges
swap_ranges(src.begin(), src.begin() + 2, dst.begin());
```

## 5.5 删除算法

```cpp
vector<int> v = {1, 2, 3, 2, 4, 2, 5};

// remove: 不真正删除，只是移动元素
auto newEnd = remove(v.begin(), v.end(), 2);
v.erase(newEnd, v.end());  // 真正删除，这是erase-remove idiom

// remove_if
v = {1, 2, 3, 4, 5};
v.erase(remove_if(v.begin(), v.end(), [](int x) { return x % 2 == 0; }), v.end());
// v = {1, 3, 5}
```

## 5.6 集合操作

```cpp
vector<int> a = {1, 2, 3, 4, 5};
vector<int> b = {3, 4, 5, 6, 7};
vector<int> result;

// 注意：输入必须有序
sort(a.begin(), a.end());
sort(b.begin(), b.end());

// 并集
set_union(a.begin(), a.end(), b.begin(), b.end(), back_inserter(result));
// result = {1, 2, 3, 4, 5, 6, 7}

result.clear();

// 交集
set_intersection(a.begin(), a.end(), b.begin(), b.end(), back_inserter(result));
// result = {3, 4, 5}

result.clear();

// 差集 (a - b)
set_difference(a.begin(), a.end(), b.begin(), b.end(), back_inserter(result));
// result = {1, 2}

result.clear();

// 对称差集
set_symmetric_difference(a.begin(), a.end(), b.begin(), b.end(), back_inserter(result));
// result = {1, 2, 6, 7}
```

## 5.7 数值算法

```cpp
#include <numeric>

vector<int> v = {1, 2, 3, 4, 5};

// accumulate: 累加
int sum = accumulate(v.begin(), v.end(), 0);  // 15
int product = accumulate(v.begin(), v.end(), 1, multiplies<int>());  // 120

// partial_sum: 前缀和
vector<int> prefix(5);
partial_sum(v.begin(), v.end(), prefix.begin());  // {1, 3, 6, 10, 15}

// adjacent_difference: 相邻差
vector<int> diff(5);
adjacent_difference(v.begin(), v.end(), diff.begin());  // {1, 1, 1, 1, 1}

// inner_product: 内积
vector<int> w = {1, 2, 3, 4, 5};
int dot = inner_product(v.begin(), v.end(), w.begin(), 0);  // 55

// iota: 填充递增序列
iota(v.begin(), v.end(), 1);  // {1, 2, 3, 4, 5}

// reduce (C++17): 并行友好的累加
// int sum = reduce(v.begin(), v.end());
```

## 5.8 堆操作

```cpp
vector<int> v = {3, 1, 4, 1, 5, 9};

// make_heap: 建堆（最大堆）
make_heap(v.begin(), v.end());  // v[0]是最大值

// push_heap: 添加元素后调整堆
v.push_back(10);
push_heap(v.begin(), v.end());

// pop_heap: 移除堆顶
pop_heap(v.begin(), v.end());  // 最大值移到末尾
v.pop_back();                  // 真正移除

// sort_heap: 堆排序
sort_heap(v.begin(), v.end());  // 排序后不再是堆

// is_heap
bool isHeap = is_heap(v.begin(), v.end());
```

## 5.9 排列组合

```cpp
vector<int> v = {1, 2, 3};

// next_permutation: 下一个排列
do {
    for (int x : v) cout << x << " ";
    cout << endl;
} while (next_permutation(v.begin(), v.end()));
// 输出: 1 2 3, 1 3 2, 2 1 3, 2 3 1, 3 1 2, 3 2 1

// prev_permutation: 上一个排列
v = {3, 2, 1};
prev_permutation(v.begin(), v.end());  // {3, 1, 2}

// is_permutation: 检查是否为排列
vector<int> a = {1, 2, 3};
vector<int> b = {3, 1, 2};
bool isPerm = is_permutation(a.begin(), a.end(), b.begin());  // true
```

## 5.10 其他常用算法

```cpp
vector<int> v = {1, 2, 3, 4, 5};

// for_each: 对每个元素执行操作
for_each(v.begin(), v.end(), [](int& x) { x *= 2; });

// count / count_if
int cnt = count(v.begin(), v.end(), 4);
int cntIf = count_if(v.begin(), v.end(), [](int x) { return x > 2; });

// all_of / any_of / none_of
bool all = all_of(v.begin(), v.end(), [](int x) { return x > 0; });
bool any = any_of(v.begin(), v.end(), [](int x) { return x > 4; });
bool none = none_of(v.begin(), v.end(), [](int x) { return x < 0; });

// equal: 比较两个范围
vector<int> w = {2, 4, 6, 8, 10};
bool eq = equal(v.begin(), v.end(), w.begin());

// mismatch: 找第一个不匹配的位置
auto [it1, it2] = mismatch(v.begin(), v.end(), w.begin());

// clamp (C++17): 限制范围
// int x = clamp(15, 0, 10);  // x = 10
```

---

# 6. 容器选择指南

| 需求                | 推荐容器         |
| ------------------- | ---------------- |
| 随机访问 + 尾部增删 | `vector`         |
| 两端增删            | `deque`          |
| 中间频繁增删        | `list`           |
| 固定大小            | `array`          |
| 唯一元素 + 有序     | `set`            |
| 唯一元素 + 快速查找 | `unordered_set`  |
| 键值对 + 有序       | `map`            |
| 键值对 + 快速查找   | `unordered_map`  |
| LIFO                | `stack`          |
| FIFO                | `queue`          |
| 按优先级            | `priority_queue` |

---

# 7. 时间复杂度总结

| 操作     | vector | list | deque | set/map  | unordered_set/map |
| -------- | ------ | ---- | ----- | -------- | ----------------- |
| 随机访问 | O(1)   | O(n) | O(1)  | O(log n) | O(1)              |
| 头部插入 | O(n)   | O(1) | O(1)  | -        | -                 |
| 尾部插入 | O(1)*  | O(1) | O(1)  | -        | -                 |
| 中间插入 | O(n)   | O(1) | O(n)  | O(log n) | O(1)              |
| 头部删除 | O(n)   | O(1) | O(1)  | -        | -                 |
| 尾部删除 | O(1)   | O(1) | O(1)  | -        | -                 |
| 中间删除 | O(n)   | O(1) | O(n)  | O(log n) | O(1)              |
| 查找     | O(n)   | O(n) | O(n)  | O(log n) | O(1)              |

*vector尾部插入均摊O(1)，扩容时O(n)

---

*文档完*
