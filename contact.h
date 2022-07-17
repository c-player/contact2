#pragma once

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <errno.h>

#define MAX_NAME 20
#define MAX_SEX 5
#define MAX_TELE 12
#define MAX_ADDR 30
#define DEFAULT_SZ 3

//将选项增删查改等设为枚举类型，更为直观，便于阅读
enum Option
{
	EXIT,
	ADD,
	DEL,
	SEARCH,
	MODIFY,
	SHOW,
	SORT,
	SAVE
};

//结构体存放联系人信息
typedef struct PeoInfo
{
	char name[MAX_NAME];
	int age;
	char sex[MAX_SEX];
	char tele[MAX_TELE];
	char addr[MAX_ADDR];
}PeoInfo;

typedef struct Contact
{
	struct PeoInfo *data; //存放信息
	int capacity; //最大容量
	int size; //记录元素个数
}Contact;

//函数声明
//通讯录初始化
void InitContact(Contact* ps);

//添加联系人信息
void AddContact(Contact* ps);

//显示通讯录信息
void ShowContact(const Contact* ps); 

//删除联系人
void DelContact(Contact* ps);

//查找联系人
void SearchContact(const Contact* ps);

//修改联系人信息
void ModifyContact(Contact* ps);

//按姓名首字母对联系人信息进行排序
void SortContact(Contact* ps);

//删除通讯录（释放动态内存）
void DestoryContact(Contact* ps);

//保存文件
void SaveContact(Contact* ps);
