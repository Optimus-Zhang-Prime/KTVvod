#include <stdlib.h>
#include <stdio.h>
#include<conio.h>

int main() {//ҵ����
    int pwd();//����Ա������֤����
    void menu();//�˵���ʾ����
    //�����������ļ�songData���ⲿ����
    void Output();//���ȫ������
    void play(int ans);//��������
    void start();//��ʼ��ϵͳ
    int find(char *inputname);//���
    void addSong();//��Ӹ���
    void deleSong(int ans);//ɾ������
    char order;//�û�ָ��
    start();//��ʼ��ϵͳ������
    while (1) {//ҵ��ѭ��
        menu();//��������ʾ�˵�
        order = getchar();//���������
        if (order == '1') {//���
            int ans;//�������
            char inputname[20];
            printf("��������������������\n");
            scanf("%s",inputname);//���������Ϣ
            ans = find(inputname);//������ظ��������ظ������
            if(ans!=-1)play(ans);//��������
            system("pause");//���س���������
        } else if (order == '2') {//ȫ������
            Output();//�������������
            getchar();//���س���������
            system("pause");
        } else if (order == '3') {//��Ӹ���������ԱȨ�ޣ�
            if (pwd()) {//��֤����Ա����
                addSong();//��Ӹ�������
            }
            system("pause");
        } else if (order == '4') {//ɾ������������ԱȨ�ޣ�
            if (pwd()) {
                int ans;//��Ÿ���·��
                char inputname[20];
                printf("������Ҫɾ���ĸ��������߸�������\n");
                scanf("%s",inputname);//���������Ϣ
                ans = find(inputname);//������ظ��������ظ���·��
                if(ans!=-1)deleSong(ans);
            }
            system("pause");
        } else if (order == '5') {//�˳�ϵͳ������ԱȨ�ޣ�
            if (pwd())break;//Σ�գ��˳�����
        }
    }
    return 0;
}

void menu() {
    //�˵���ʾ����
    system("cls");//����
    printf("**************************************************\n");
    printf("*******���ܲ˵�*****���빦�ܵ����ֱ��ִ�иù���**\n");
    printf("�û����ܣ�        1.���          2.��ʾȫ������   \n");
    printf("����Ա���ܣ� 3.��Ӹ���   4.ɾ������    5.�˳�ϵͳ\n");
    printf("**************************************************\n");
    printf("������ָ�����֣�");
}

int pwd() {
    //����Ա������֤����
    int realpwd = 123456;//��ʵ����Ϊ123456
    long int inputpwd;//�û����������
    printf("���������Ա���룺");
    scanf("%ld", &inputpwd);
    if (inputpwd == realpwd)return 1;//��֤�ɹ��򷵻�1
    else {
        printf("������󣬲���ʧ��");
        return 0;
    }
}

