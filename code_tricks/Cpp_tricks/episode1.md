# Some rules and tricks
## 结构类型
    结构类型可以整体赋值，相同类型可以直接用=来赋值
## 可以将整型强制类型转化为枚举
    enum DAY {SAT, SUN};
    int i = 0;
    DAY day = (DAY)i;