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
    #define Log(format, ...) 
    #endif
## 可变参数
    

## 字符串转数字
    #include <stdlib.h>
    int atoi(const char* str);
    错误返回0，正确返回对应数字

## 获取参数
    抄写自： https://blog.csdn.net/qq_33850438/article/details/80172275
    #include <getopt.h>
    int getopt_long(int argc, char * const argv[], const char *optstring, const struct option *longopts, int *longindex);

    关于optstring的说明
    例如"ab:c::"，无冒号表示无参数，一个冒号表示强制参数，两个冒号表示可选参数


    flag:这个参数有两个意思，空或者非空。
        a:如果参数为空NULL，那么当选中某个长选项的时候，getopt_long将返回val值。          
        b:如果参数不为空，那么当选中某个长选项的时候，getopt_long将返回0，并且将flag指针参数指向val值。
    val：表示指定函数找到该选项时的返回值，或者当flag非空时指定flag指向的数据的值val。
    longindex：longindex非空，它指向的变量将记录当前找到参数符合longopts里的第几个元素的描述，即是longopts的下标值

    全局变量：
        （1）optarg：表示当前选项对应的参数值。
        （2）optind：表示的是下一个将被处理到的参数在argv中的下标值。
        （3）opterr：如果opterr = 0，在getopt、getopt_long、getopt_long_only遇到错误将不会输出错误信息到标准输出流。opterr在非0时，向屏幕输出错误。
        （4）optopt：表示没有被未标识的选项。

    返回值：
         （1）如果短选项找到，那么将返回短选项对应的字符。
         （2）如果长选项找到，如果flag为NULL，返回val。如果flag不为空，返回0
         （3）如果遇到一个选项没有在短字符、长字符里面。或者在长字符里面存在二义性的，返回“？”
         （4）如果解析完所有字符没有找到（一般是输入命令参数格式错误，eg： 连斜杠都没有加的选项），返回“-1”
         （5）如果选项需要参数，忘了添加参数。返回值取决于optstring，如果其第一个字符是“：”，则返回“：”，否则返回“？”。

    注意：
        （1）longopts的最后一个元素必须是全0填充，否则会报段错误
        （2）短选项中每个选项都是唯一的。而长选项如果简写，也需要保持唯一性。
