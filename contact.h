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

//��ѡ����ɾ��ĵ���Ϊö�����ͣ���Ϊֱ�ۣ������Ķ�
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

//�ṹ������ϵ����Ϣ
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
	struct PeoInfo *data; //�����Ϣ
	int capacity; //�������
	int size; //��¼Ԫ�ظ���
}Contact;

//��������
//ͨѶ¼��ʼ��
void InitContact(Contact* ps);

//�����ϵ����Ϣ
void AddContact(Contact* ps);

//��ʾͨѶ¼��Ϣ
void ShowContact(const Contact* ps); 

//ɾ����ϵ��
void DelContact(Contact* ps);

//������ϵ��
void SearchContact(const Contact* ps);

//�޸���ϵ����Ϣ
void ModifyContact(Contact* ps);

//����������ĸ����ϵ����Ϣ��������
void SortContact(Contact* ps);

//ɾ��ͨѶ¼���ͷŶ�̬�ڴ棩
void DestoryContact(Contact* ps);

//�����ļ�
void SaveContact(Contact* ps);
