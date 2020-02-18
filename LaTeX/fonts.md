# The way to add fonts
    cd /usr/share/fonts
    根据字体格式cd opentype 或 cd truetype
    mkdir myfont
    cp [your font] myfont/
    cd myfont
    sudo mkfontscale
    sudo mkfontdir
    sudo fc-cache -fv