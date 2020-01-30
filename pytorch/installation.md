# Pytorch personal installation guide
以下适用于Ubuntu 18.04
## 下载CUDA
    虽然官网说适配的是CUDA10.1，但实测CUDA10.2也不会产生问题
    Nvidia官网 https://developer.nvidia.com/cuda-toolkit-archive

    在terminal中输入以下即可
    wget https://developer.download.nvidia.com/compute/cuda/repos/ubuntu1804/x86_64/cuda-ubuntu1804.pinsudo
    mv cuda-ubuntu1804.pin /etc/apt/preferences.d/cuda-repository-pin-600
    wget http://developer.download.nvidia.com/compute/cuda/10.2/Prod/local_installers/cuda-repo-ubuntu1804-10-2-local-10.2.89-440.33.01_1.0-1_amd64.debsudo dpkg -i cuda-repo-ubuntu1804-10-2-local-10.2.89-440.33.01_1.0-1_amd64.debsudo 
    apt-key add /var/cuda-repo-10-2-local-10.2.89-440.33.01/7fa2af80.pubsudo 
    apt-get updatesudo 
    apt-get -y install cuda

## 下载pytorch
    pip3 install torch torchvision -i https://pypi.tuna.tsinghua.edu.cn/simple 