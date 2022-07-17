#define _CRT_SECURE_NO_WARNINGS 1

#include "contact.h"

//�˵���ӡ
void menu()
{
	printf("********************************\n");
	printf("****** 1.Add     2.Del    ******\n");
	printf("****** 3.Search  4.Modify ******\n");
	printf("****** 5.Show    6.Sort   ******\n");
	printf("****** 7.Save    0.Exit   ******\n");
	printf("********************************\n");
}

int main()
{
	int input;
	struct Contact con;
	
	//��ʼ��ͨѶ¼
	InitContact(&con);
	do
	{
		menu();
		printf("�����룺");
		scanf("%d", &input);
		switch (input)
		{
		case ADD:             //��ͷ�ļ��е�ö��
			AddContact(&con); //���ܺ�����д��contact.c�ļ���
			break;
		case DEL:
			DelContact(&con);
			break;
		case SEARCH:
			SearchContact(&con);
			break;
		case MODIFY:
			ModifyContact(&con);
			break;
		case SHOW:
			ShowContact(&con);
			break;
		case SORT:
			SortContact(&con);
			break;
		case SAVE:
			SaveContact(&con);
			break;
		case EXIT:
			SaveContact(&con);   //����ǰĬ�ϱ��浽�ļ�
			DestoryContact(&con);
			printf("�˳�ͨѶ¼��\n");
			break;
		default:
			printf("ѡ�����\n");
		}
	} while (input);
    return 0;
}