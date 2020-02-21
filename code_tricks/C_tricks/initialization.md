# Tricks 
## 数组初始化
    int a[size] = {[size-1]=value};
    将数组全部初始化为你想要的值
## 超好用的宏
    #ifdef DEBUG
    #define Log(format, ...) \
        printf("\33[1;35m[%s,%d,%s] " format "\33[0m\n", \
             __FILE__, __LINE__, __func__, ## __VA_ARGS__)
    #else
    #define Log(format, ...) ;
    #endif
## 可变参数
    