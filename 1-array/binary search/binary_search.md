# basic
* 对数
  ○ $如果
a^ 
b
 =c
那么
b=log_ 
a
​
 (c)$
  ○ 对数的底数与幂次的底数一致  = a
* 浮点数精度误差  
    ○ 计算机在存储和计算浮点数（double 或 float）时存在微小的精度误差。
    ○ 虽然数学上 $\sqrt{x}$ 应该是一个整数，但经过 log 和 exp 运算后，结果可能是一个无限接近该整数的浮点数，例如 2.999999999...。
    ○ 此时强制类型转换为int，结果=2，不正确
    ○  容错处理：判断一下 q + 1 的平方是否等于 x（或者是否小于等于 x），来修正那个微小的误差。 
* 存储数据类型

| 类型 | 关键字 | 一般占用字节 | 常用场景 | 取值范围 (近似) |
| :--- | :--- | :--- | :--- | :--- |
| **整型** | `int` | 4 Bytes | **默认首选**。循环计数、一般计算。 | $-2 \times 10^9$ ~ $2 \times 10^9$ |
| **长整型** | `long long` | 8 Bytes | **防溢出神器**。当结果可能超过 20 亿时必用。 | $-9 \times 10^{18}$ ~ $9 \times 10^{18}$ |
| **短整型** | `short` | 2 Bytes | 很少用，除非为了极度节省内存。 | $-32768$ ~ $32767$ |

* 整型之间的除法都是整除
  
| 类型 | 关键字 | 一般占用字节| 精度 | 常用场景 |
| :--- | :--- | :--- |:--- | :--- |
| **双精度** | `double` |8 Bytes |~15-16 位有效数字 | **算法题默认首选**。精度高，误差小。 |
| **单精度** | `float` |4 Bytes |~6-7 位有效数字 | 图形学常用，算法题中容易因精度不够导致 WA。 |
# binary search
* 二分查找的本质不是一定要在区间范围内找到最终的结果ans
我们要找到的值只要与ans有恒定的数学关系即可。

# 牛顿迭代法 (Newton's Method)

![alt text](image.png)
* 利用切线来逼近曲线的零点，快速求解函数零点的方法。
* 任何关系式能写为显函数即可
* 凸函数有几何性质：函数图像上的任意一点的切线，都在函数图像的下方。
  * 所以只要初始值选择零点右边，最后不断迭代，永远会在右边慢慢滑向零点，而不会超出。
* 二次收敛的，相较于二分查找更快。
* 模板：
  * 先列出方程组：C的的平方根就是函数$y=f(x)=x^2 −C$的零点。
  * 计算$f(x)$的导数，得出$x_{n+1}$的迭代式子：$x_{n+1}=x_n-\frac{f(x_n)}{f'(x_n)}$
  * 代入 $f(x) = x^2 - C$ 及其导数 $f'(x) = 2x$：$$x_{n+1} = x_n - \frac{x_n^2 - C}{2x_n} = x_n - (\frac{x_n}{2} - \frac{C}{2x_n}) = \frac{x_n}{2} + \frac{C}{2x_n}$$
  * $$x_{n+1} = \frac{1}{2} (x_n + \frac{C}{x_n})$$
  * 写代码，模板如下：
``` cpp
// 定义一个极小值，防止除以零
const double EPSILON = 1e-12;

class NewtonSolver {
public:
    /**
     * @brief 方案一：精确导数版
     * * @param func  原函数 f(x)
     * @param deriv 导函数 f'(x)
     * @param x0    初始猜测值
     * @param tol   容差 (Tolerance)
     * @param max_iter 最大迭代次数
     * @return double 求解出的零点
     */
    template <typename F, typename D>
    static double solve(F func, D deriv, double x0, double tol = 1e-7, int max_iter = 100) {//定义收敛距离和迭代次数
        double x = x0;
        for (int i = 0; i < max_iter; ++i) {
            double y = func(x);
            double dy = deriv(x);

            // 1. 安全检查：导数是否过小（防止除以0飞了）
            if (std::abs(dy) < EPSILON) {
                std::cerr << "Warning: Derivative is too close to zero." << std::endl;
                return x;
            }

            double next_x = x - y / dy;

            // 2. 收敛检查：如果两次迭代结果变化非常小，认为收敛
            if (std::abs(next_x - x) < tol) {
                return next_x;
            }

            x = next_x;//3. 继续迭代
        }
        return x; // 达到最大迭代次数，返回当前最佳值
    }
}
```
* 浮点数通用版