# shell-learning

## 对文件或文件夹改名 mv
    例如，将a.txt改名为b.txt
    mv a.txt b.txt

## 新建文件夹 mkdir
    例如，在当前文件夹下新建文件夹my_folder
    mkdir my_folder

## 新建文件 touch
    例如 touch test.txt

## 删除文件 rm
    删除文件夹需要 rm -rf

## 查看当前文件夹下的文件
    ls 
    ls -a可以查看包含隐藏文件的所有文件

## apt
    apt 是一个更上层的包装，包含了apt-get, apt-config, apt-cache三个工具的主要功能。但apt是真子集不是子集哦
    
    apt install 包名            安装软件包
    apt remove  包名            卸载软件包
    apt purge 包名              卸载软件包并清除配置信息
    apt update                 刷新存储库索引（就是更新与下载包有关的各种信息的意思）
    apt autoremove             自动删除不需要的包
    apt search 包名或正则表达式   在可供下载的包中搜索

    本条参考：https://blog.csdn.net/liudsl/article/details/79200134


