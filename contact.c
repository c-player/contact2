#define _CRT_SECURE_NO_WARNINGS 1

#include "contact.h"

void LoadContact(Contact* ps);
static int CheckContact(Contact* ps);

void InitContact(Contact* ps)
{
	ps->data = (PeoInfo*)malloc(DEFAULT_SZ * sizeof(PeoInfo));
	if (ps->data == NULL)
	{
		return;
	}
	ps->capacity = DEFAULT_SZ;
	ps->size = 0;
	LoadContact(ps);
}

void LoadContact(Contact* ps)
{
	PeoInfo tmp = { 0 };
	FILE* PfRead = fopen("contact.dat", "rb");
	if (PfRead == NULL)
	{
		printf("LoadContact::%s\n", strerror(errno));
		return;
	}
	while (fread(&tmp, sizeof(PeoInfo), 1, PfRead))
	{
		if (CheckContact(ps) != 0)
		{
			ps->data[ps->size] = tmp;
			ps->size++;
		}
	}
	fclose(PfRead);
	PfRead = NULL;
}

//���ͨѶ¼�Ƿ�����
static int CheckContact(Contact* ps)
{
	if (ps->size == ps->capacity)  //������ˣ��ٿ���2���ռ�
	{
		PeoInfo* ptr = (PeoInfo*)realloc(ps->data, (ps->capacity + 2) * sizeof(PeoInfo));
		if (ptr != NULL)
		{
			ps->data = ptr;
			ps->capacity += 2;
			return 1;             //���ٳɹ�������1
		}
		else
		{
			printf("����ʧ�ܡ�\n");//����ʧ�ܣ�����0
			return 0;
		}
	}
	return 1;                     //��ǰ�ռ�δ�������迪�٣�����1
}

void AddContact(Contact* ps)
{
	if(1 == CheckContact(ps))    //����ռ�δ������ռ��������ٳɹ���������
	{
		printf("���������֣�");
		scanf("%s", ps->data[ps->size].name);
		printf("���������䣺");
		scanf("%d", &ps->data[ps->size].age);
		printf("�������Ա�");
		scanf("%s", ps->data[ps->size].sex);
		printf("������绰��");
		scanf("%s", ps->data[ps->size].tele);
		printf("�������ַ��");
		scanf("%s", ps->data[ps->size].addr);
		ps->size++;
		printf("��ӳɹ���\n");
	}
}

void ShowContact(const Contact* ps)
{
	int i;
	if (ps->size == 0)
	{
		printf("ͨѶ¼Ϊ�ա�\n");
	}
	else
	{
		printf("%-20s\t%-4s\t%-5s\t%-12s\t%-30s\n", "����", "����", "�Ա�", "�绰", "��ַ");
		for (i = 0; i < ps->size; i++)
		{
			printf("%-20s\t%-4d\t%-5s\t%-12s\t%-30s\n",
				ps->data[i].name,
				ps->data[i].age,
				ps->data[i].sex,
				ps->data[i].tele,
				ps->data[i].addr);
		}
	}
}

//������������ϵ�ˣ����ҳɹ�������ϵ��λ�ã�ʧ�ܷ���-1
static int FindByName(const Contact* ps, char name[MAX_NAME])
{
	int i;
	for (i = 0; i < ps->size; i++)
	{
		if (0 == strcmp(ps->data[i].name, name))
		{
			return i;
		}
	}
	return -1;
}

//ɾ������ϵ�˺󣬽��������ϵ�˾���ǰ�ƶ�
void DelContact(Contact* ps)
{
	char name[MAX_NAME];
	printf("��������ϵ��������");
	scanf("%s", name);
	int pos = FindByName(ps, name);
	if (pos == -1)
	{
		printf("û�и���ϵ����Ϣ��\n");
	}
	else
	{
		int j;
		for (j = pos; j < ps->size - 1; j++)
		{
			ps->data[j] = ps->data[j + 1];
		}
		ps->size--;
		printf("ɾ���ɹ���\n");
	}
}

void SearchContact(const Contact* ps)
{
	char name[MAX_NAME];
	printf("��������ϵ��������");
	scanf("%s", name);
	int pos = FindByName(ps, name);
	if (pos == -1)
	{
		printf("û�и���ϵ����Ϣ��\n");
	}
	else
	{
		printf("%-20s\t%-4s\t%-5s\t%-12s\t%-30s\n", "����", "����", "�Ա�", "�绰", "��ַ");
		printf("%-20s\t%-4d\t%-5s\t%-12s\t%-30s\n",
			ps->data[pos].name,
			ps->data[pos].age,
			ps->data[pos].sex,
			ps->data[pos].tele,
			ps->data[pos].addr);
	}
}

void ModifyContact(Contact* ps)
{
	char name[MAX_NAME];
	printf("��������ϵ��������");
	scanf("%s", name);
	int pos = FindByName(ps, name);
	if (pos == -1)
	{
		printf("û�и���ϵ����Ϣ��\n");
	}
	else
	{
		printf("���������֣�");
		scanf("%s", ps->data[pos].name);
		printf("���������䣺");
		scanf("%d", &ps->data[pos].age);
		printf("�������Ա�");
		scanf("%s", ps->data[pos].sex);
		printf("������绰��");
		scanf("%s", ps->data[pos].tele);
		printf("�������ַ��");
		scanf("%s", ps->data[pos].addr);
		printf("�޸���ɡ�\n");
	}
}

//ʹ��qsort�������Լ���д�ȽϺ���
//void qsort (void* base, size_t num, size_t size,
//int(*compar)(const void*, const void*));
//qsort�����ܹ������������飬�������͡������͡��ṹ��ȡ�
//
//��һ������base : �������������Ԫ�ص�ַ
//�ڶ�������num�������Ԫ�ظ���
//����������size������ÿ��Ԫ�ش�С���ֽڣ�
//���ĸ�����compar������ָ�룬�ȽϺ����ĵ�ַ������ȽϺ���ʹ�����Լ���д�����������Ǵ��Ƚ�����Ԫ�ص�ַ
//��1��Ԫ�� > ��2��Ԫ�أ����� > 0 ����
//��1��Ԫ�� = ��2��Ԫ�أ����� 0
//��1��Ԫ�� < ��2��Ԫ�أ����� < 0 ����
static int CompareByName(const void* p1, const void* p2)
{
	return strcmp(((PeoInfo*)p1)->name, ((PeoInfo*)p2)->name);
}

void SortContact(Contact* ps)
{
	qsort(ps->data, ps->size, sizeof(ps->data[0]), CompareByName);
	printf("������ɡ�\n");
}

void DestoryContact(Contact* ps)
{
	free(ps->data);
	ps->data = NULL;
}

void SaveContact(Contact* ps)
{
	FILE* PfWrite = fopen("contact.dat", "wb");
	if (PfWrite == NULL)
	{
		printf("SaveContact::%s\n", strerror(errno));
		return;
	}
	fwrite(ps->data, sizeof(PeoInfo), ps->size, PfWrite);
	fclose(PfWrite);
	PfWrite = NULL;
}