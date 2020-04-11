# 一些概率论常用公式
## 条件概率
1. $P(A|B)=\frac{P(A,B)}{P(B)}$
2. $P(A|C)=\sum\limits_{B\in{\bf B}}P(A|B,C)P(B|C)$,其中${\bf B}$为互斥且可穷举的命题集合
3. $P(A|B)=\frac{P(B|A)P(A)}{P(B)}$
4. $P(a_1,a_2,...,a_n)=\prod\limits_{i=1}^{n-1}P(a_i|a_{i+1},...,a_{n})P(a_n),n\geq2$
5. 给定$Z$，变量$X$与$Y$是独立的，当且仅当$P(X,Y|Z)=P(X|Z)P(Y|Z)$，记作$(X\perp Y|Z)$
6. $(X\perp Y|Z)$当且仅当$P(X|Z)=P(X|Y,Z)$
7. 如果给定$a_n$，$a_i(1\leq i\leq n-1)$彼此条件独立,则4式$＝P(a_n)\prod\limits_{i=1}^{n-1}P(a_i|a_{n})$