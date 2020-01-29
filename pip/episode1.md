# pip安装及使用

## 安装
    sudo apt install python3-pip
    注意，不是python-pip，否则会默认管理python2的包

## 常见命令
    注意，命令行调用时的名称为pip3，而不是pip。这样可以避免一些你可能遇到的问题。
    python3 -m pip 是另外一种避免出现问题的调用方法。

### 使用清华源
    末尾加参数 -i https://pypi.tuna.tsinghua.edu.cn/simple

### 查看所有安装包
    pip3 list

### 升级pip
    pip3 install --upgrade pip 

### 安装包
    pip3 install 包名

### 卸载包
    pip3 uninstall 包名
