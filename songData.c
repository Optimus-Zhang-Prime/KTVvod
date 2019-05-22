#include <stdlib.h>
#include <stdio.h>
#include<conio.h>
#include <windows.h>

#define MAXSIZE 256//��������
struct Song {
    char songName[20];//������
    char singerName[10];//������
    char filePath[80];//��ʵ�·��
};
typedef struct Song datatype;
typedef struct {
    datatype data[MAXSIZE];
    int last;
} SongSequenlist;
SongSequenlist *ALL;

extern void Output()//������и���
{
    int i;
    if (ALL->last == -1) {
        printf("���ź�����ǰ������Ϊ�գ�����ϵ����Ա��Ӹ���");
        return;
    }
    printf("ȫ���ĸ����б�Ϊ��\n");
    for (i = 0; i <= ALL->last; i++) {
        printf("%s %s\n", ALL->data[i].songName, ALL->data[i].singerName);
    }
}

extern void play(int ans) {//����ָ����ŵĸ���
    char*filepath;
    filepath=ALL->data[ans].filePath;
    FILE *fp = NULL;
    char str1[100];
    fp = fopen(filepath, "r");
    if (fp == NULL) {
        printf("�ø���·�����󣬲���ʧ�ܣ�����ϵ����Ա����\n");
        return;
    }
    while (!feof(fp)) {
        fgets(str1, 99, fp);
        printf("%s", str1);
        Sleep(2000);//ÿ��������
    }
    printf("\n�������");
    fclose(fp);
}

extern void start() {//��ʼ��ϵͳ
    int i = 0, l;
    ALL = (SongSequenlist *) malloc(sizeof(SongSequenlist));
    ALL->last = -1;
    printf("KTV���ϵͳ��������������Ա�밴��ϵͳ��ʾ��ʼ��������\n");
    printf("������������Ҫ���������ĸ�������:");
    scanf("%d", &l);
    getchar();
    while (l > 0) {
        printf("�������������\n");
        gets(ALL->data[i].songName);
        printf("�������������\n");
        gets(ALL->data[i].singerName);
        printf("��������·������ʽ�磺C:/Users/14531/�����ƺ�.txt  ע���� / ������\\ \n");
        gets(ALL->data[i].filePath);
        ALL->last++;
        l--;
        i++;
    }
    printf("���������ϣ�����س�����KTV���ϵͳ\n");
    getchar();
}

extern int find(char *inputname) {
    int num = 0;//����Ҫ��ĸ�������
    int ans=0;//ѡ��ĸ������
    for (int i = 0; i <= ALL->last; ++i) {
        if (strcmp(inputname, ALL->data[i].songName) == 0 || strcmp(inputname, ALL->data[i].singerName) == 0) {
            printf("������ĵ�%d�׸������������Ҫ��\n", i);
            printf("����Ϊ%s,�ݳ���Ϊ%s\n", ALL->data[i].songName, ALL->data[i].singerName);
            num++;
            ans = i;
        }
    }
    if (num > 1) {
        printf("��Ҫѡ��ĸ����ı��Ϊ��");
        scanf("%d", &ans);
    } else if (num == 0) {
        printf("��Ǹ����������������أ���������ϵ����Ա��Ӹ���\n");
        return -1;
    }
    return ans;//���ظø����ڸ������е�λ��
}

extern void addSong(){
    ALL->last++;
    getchar();
    printf("�������������\n");
    gets(ALL->data[ALL->last].songName);
    printf("�������������\n");
    gets(ALL->data[ALL->last].singerName);
    printf("��������·������ʽ�磺C:/Users/14531/�����ƺ�.txt  ע���� / ������\\ \n");
    gets(ALL->data[ALL->last].filePath);
    printf("����������\n");
}

extern void deleSong(int ans) {
    for (int i = ans; i <ALL->last ; ++i) {
        ALL->data[i] = ALL->data[i+1];
    }
    ALL->last--;
    printf("ɾ���ɹ�");
}