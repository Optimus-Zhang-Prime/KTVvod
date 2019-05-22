#include <stdlib.h>
#include <stdio.h>
#include<conio.h>
#include <windows.h>

#define MAXSIZE 256//最大歌曲数
struct Song {
    char songName[20];//歌曲名
    char singerName[10];//歌手名
    char filePath[80];//歌词的路径
};
typedef struct Song datatype;
typedef struct {
    datatype data[MAXSIZE];
    int last;
} SongSequenlist;
SongSequenlist *ALL;

extern void Output()//输出所有歌曲
{
    int i;
    if (ALL->last == -1) {
        printf("很遗憾，当前歌曲库为空，请联系管理员添加歌曲");
        return;
    }
    printf("全部的歌曲列表为：\n");
    for (i = 0; i <= ALL->last; i++) {
        printf("%s %s\n", ALL->data[i].songName, ALL->data[i].singerName);
    }
}

extern void play(int ans) {//播放指定序号的歌曲
    char*filepath;
    filepath=ALL->data[ans].filePath;
    FILE *fp = NULL;
    char str1[100];
    fp = fopen(filepath, "r");
    if (fp == NULL) {
        printf("该歌曲路径错误，播放失败，请联系管理员处理\n");
        return;
    }
    while (!feof(fp)) {
        fgets(str1, 99, fp);
        printf("%s", str1);
        Sleep(2000);//每句间隔三秒
    }
    printf("\n播放完毕");
    fclose(fp);
}

extern void start() {//初始化系统
    int i = 0, l;
    ALL = (SongSequenlist *) malloc(sizeof(SongSequenlist));
    ALL->last = -1;
    printf("KTV点歌系统正在启动，管理员请按照系统提示初始化歌曲库\n");
    printf("请输入您现在要加入歌曲库的歌曲数量:");
    scanf("%d", &l);
    getchar();
    while (l > 0) {
        printf("请输入歌曲名：\n");
        gets(ALL->data[i].songName);
        printf("请输入歌手名：\n");
        gets(ALL->data[i].singerName);
        printf("请输入歌词路径，格式如：C:/Users/14531/保卫黄河.txt  注意是 / 而不是\\ \n");
        gets(ALL->data[i].filePath);
        ALL->last++;
        l--;
        i++;
    }
    printf("歌曲添加完毕，点击回车启动KTV点歌系统\n");
    getchar();
}

extern int find(char *inputname) {
    int num = 0;//符合要求的歌曲数量
    int ans=0;//选择的歌曲编号
    for (int i = 0; i <= ALL->last; ++i) {
        if (strcmp(inputname, ALL->data[i].songName) == 0 || strcmp(inputname, ALL->data[i].singerName) == 0) {
            printf("歌曲库的第%d首歌符合您的搜索要求：\n", i);
            printf("歌名为%s,演唱者为%s\n", ALL->data[i].songName, ALL->data[i].singerName);
            num++;
            ans = i;
        }
    }
    if (num > 1) {
        printf("您要选择的歌曲的编号为：");
        scanf("%d", &ans);
    } else if (num == 0) {
        printf("抱歉，歌曲库中暂无相关，您可以联系管理员添加歌曲\n");
        return -1;
    }
    return ans;//返回该歌曲在歌曲库中的位置
}

extern void addSong(){
    ALL->last++;
    getchar();
    printf("请输入歌曲名：\n");
    gets(ALL->data[ALL->last].songName);
    printf("请输入歌手名：\n");
    gets(ALL->data[ALL->last].singerName);
    printf("请输入歌词路径，格式如：C:/Users/14531/保卫黄河.txt  注意是 / 而不是\\ \n");
    gets(ALL->data[ALL->last].filePath);
    printf("歌曲添加完毕\n");
}

extern void deleSong(int ans) {
    for (int i = ans; i <ALL->last ; ++i) {
        ALL->data[i] = ALL->data[i+1];
    }
    ALL->last--;
    printf("删除成功");
}