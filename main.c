#include <stdlib.h>
#include <stdio.h>
#include<conio.h>
int realpwd=123456;// 初始密码为123456； 
int main() {//业务函数
    int pwd();//管理员密码验证函数
    void menu();//菜单显示函数
    //以下是来自文件songData的外部函数
    void Output();//输出全部歌曲
    void play(int ans);//播放音乐
    void start();//初始化系统
    int find(char *inputname);//点歌
    void addSong();//添加歌曲
    void deleSong(int ans);//删除歌曲
    void changePwd();//修改密码 
    char order;//用户指令
    start();//初始化系统乐曲库
    while (1) {//业务循环
        menu();//清屏并显示菜单
        order = getchar();//输入命令号
        if (order == '1') {//点歌
            int ans;//歌曲编号
            char inputname[20];
            printf("请输入歌曲名或歌手名：\n");
            scanf("%s",inputname);//输入相关信息
            ans = find(inputname);//查找相关歌曲，返回歌曲编号
            if(ans!=-1)play(ans);//播放音乐
            getchar();
            system("pause");//按回车结束操作
        } else if (order == '2') {//全部歌曲
            Output();//输出整个歌曲库
            getchar();//按回车结束操作
            system("pause");
        } else if (order == '3') {//添加歌曲（管理员权限）
            if (pwd()) {//验证管理员密码
                addSong();//添加歌曲函数
            }
            getchar();
            system("pause");
        } else if (order == '4') {//删除歌曲（管理员权限）
            if (pwd()) {
                int ans;//存放歌曲路径
                char inputname[20];
                printf("请输入要删除的歌曲名或者歌手名：\n");
                scanf("%s",inputname);//输入相关信息
                ans = find(inputname);//查找相关歌曲，返回歌曲路径
                if(ans!=-1)deleSong(ans);
            }
            getchar();
            system("pause");
        } else if (order == '5') {//退出系统（管理员权限）
            if (pwd())break;//危险！退出程序
        }
        else if (order == '6') {//修改密码（管理员权限）
            if (pwd()){
            	changePwd();
			} 
			getchar();
			system("pause");
        }
        else {
        	printf("指令无效");
        	getchar();
        	system("pause");
		}
    }
    return 0;
}

void menu() {
    //菜单显示函数
    system("cls");//清屏
    printf("**************************************************\n");
    printf("*******功能菜单*****输入功能的数字标号执行该功能**\n");
    printf("用户功能：----《1.点歌》----《2.显示全部歌曲》----\n");
    printf("**************************************************\n");
    printf("管理员功能：3.添加歌曲 4.删除歌曲 5.退出系统 6.改密\n");
    printf("**************************************************\n");
    printf("请输入指令数字：");
}

int pwd() {
    //管理员密码验证函数
    //初始密码为123456
    long int inputpwd;//用户输入的密码
    printf("请输入管理员密码：");
    scanf("%ld", &inputpwd);
    if (inputpwd == realpwd)return 1;//验证成功则返回1
    else {
        printf("密码错误，操作失败");
        return 0;
    }
}
void changePwd(){
	printf("请输入您的新密码");
	scanf("%d",&realpwd);
	printf("修改成功，您的新密码为%d",realpwd); 
} 
//前端部分结束 
