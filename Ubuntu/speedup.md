# Trying to speed up git
# 实测没有屁用
## 查询所需连接DNS地址
    通过以下查询相关连接DNS网址
1.    github.com
2.    assets-cdn.github.com
3.    github.global.ssl.fastly.net
 
*[点这里进行查询](https://www.ipaddress.com/)
    对于有多个地址的情况，通过ping查询到的DNS来寻找统一网站更快的DNS地址。
    笔者查阅的结果三个网站分别对应为
    192.30.253.113
    185.199.108.153
    199.232.5.194
## 修改hosts
    sudo vim /etc/hosts
    在最后添加
    192.30.253.113   github.com
    185.199.108.153  assets-cdn.github.com
    199.232.5.194    github.global.ssl.fastly.net
    
## 重启电脑