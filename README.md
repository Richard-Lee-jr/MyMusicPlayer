# 基于Qt的本地音乐播放器
使用Qt框架开发一款本地音乐播放器的过程，包括添加歌曲、播放/暂停、上一曲/下一曲功能以及音量和播放进度控制。

开通过创建自定义按钮和布局实现界面，利用QMediaPlayer进行音频播放控制，并通过信号与槽进行功能交互。

使用LavFilter底层音频解析，因此需要手动运行安装LavFilter/LAVFilters-0.77.2-Installer.exe，否则可能会出现播放没有声音问题

详细介绍：https://blog.csdn.net/SNAKEpc12138/article/details/117395628?sharetype=blogdetail&sharerId=117395628&sharerefer=PC&sharesource=SNAKEpc12138&spm=1011.2480.3001.8118

# 构建步骤
1. git clone https://github.com/Richard-Lee-jr/MyMusicPlayer --recursive -v

2. 手动安装LavFilter/LAVFilters-0.77.2-Installer.exe

3. Qt Creator打开KuGouMusicPlayer.pro运行
