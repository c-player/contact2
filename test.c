#define _CRT_SECURE_NO_WARNINGS 1

#include "contact.h"

//菜单打印
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
	
	//初始化通讯录
	InitContact(&con);
	do
	{
		menu();
		printf("请输入：");
		scanf("%d", &input);
		switch (input)
		{
		case ADD:             //见头文件中的枚举
			AddContact(&con); //功能函数编写在contact.c文件中
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
			SaveContact(&con);   //销毁前默认保存到文件
			DestoryContact(&con);
			printf("退出通讯录。\n");
			break;
		default:
			printf("选择错误。\n");
		}
	} while (input);
    return 0;
}