#define _CRT_SECURE_NO_WARNINGS 1
#include "contact.h"
static int postionsc(const struct Contact* c,char* name)
{
	int i;
	for (i = 0; i < c->size; i++)
	{
		if (strcmp(c->data[i].name, name) == 0)
		{
			return i;
		}
	}
	return -1;
}
void destroycontact(struct Contact* c)
{
	free(c->data);
	c->data = NULL;
}

void chaeckcapcity(struct Contact* c)
{
	if (c->size == c->capacity)
	{
		struct PeoInfo* pc = (struct PeoInfo*)realloc(c->data, (c->capacity + 2) * sizeof(struct PeoInfo));
		if (pc != NULL)
		{
			c->data = pc;
			c->capacity += 2;
			printf("扩容成功\n");
		}
		else
		{
			printf("扩容失败\n");
		}
	}
}
void initcontact(struct Contact* c)
{
	//struct Contact* con = c;
	//memset(con->data, 0, sizeof(con->data));
	//con->size = 0; //最初只有0个元素
	c->data = (struct PeoInfo*)malloc(3 * sizeof(struct PeoInfo));
	if (c->data == NULL)
		return;
	c->size = 0;
	c->capacity = 3;
}
void addcontact(struct Contact* c)
{
	//检测数据库容量
	//1.满了就增容
	//2.没满啥事不干
	chaeckcapcity(c);
	//增加数据
	printf("添加姓名：\n");
	scanf("%s", c->data[c->size].name);
	printf("添加年龄：\n");
	scanf("%d", &(c->data[c->size].age));
	printf("添加性别：\n");
	scanf("%s", c->data[c->size].sex);
	printf("添加手机号：\n");
	scanf("%s", c->data[c->size].tele);
	printf("添加地址：\n");
	scanf("%s", c->data[c->size].address);
	c->size++;
	/*if (c->size == MAX)
	{
		printf("通讯录已满\n");
	}
	else
	{
		printf("添加姓名：\n");
		scanf("%s",c->data[c->size].name);
		printf("添加年龄：\n");
		scanf("%d", &(c->data[c->size].age));
		printf("添加性别：\n");
		scanf("%s", c->data[c->size].sex);
		printf("添加手机号：\n");
		scanf("%s", c->data[c->size].tele);		
		printf("添加地址：\n");
		scanf("%s", c->data[c->size].address);
		c->size++;
	}*/
}
void showcontact(const struct Contact* c)
{
	//标题
	printf("\n%-20s  %-4s  %-4s  %-20s  %-30s\n", "姓名", "年龄", "性别", "手机号", "地址");
	int i;
	for (i = 0; i < c->size; i++)
	{
		//数据
		printf("%-20s  %-4d  %-4s  %-20s  %-30s\n",
			c->data[i].name,
			c->data[i].age,
			c->data[i].sex,
			c->data[i].tele,
			c->data[i].address);
	}
}
void deletcontact(struct Contact* c)
{
	char name[MAX_NAME];
	printf("\n选择删除的姓名：\n");
	scanf("%s", name);
	int i;
	int num = c->size;
	int pos = postionsc(c, name);
	if (pos == -1)
	{
		printf("查无此人\n");
	}
	else
	{
		int j;
		for (j = pos; j < c->size - 1; j++)
		{
			c->data[j] = c->data[j + 1];
		}
		c->size--;
		printf("删除成功\n");
	}
}
void searchcontact(const struct Contact* c)
{
	char name[MAX_NAME];
	printf("\n请输入查找人姓名：\n");
	scanf("%s", name);
	int pos = postionsc(c, &name);
	printf("\n%-20s  %-4s  %-4s  %-20s  %-30s\n", "姓名", "年龄", "性别", "手机号", "地址");
	printf("%-20s  %-4d  %-4s  %-20s  %-30s\n",
		c->data[pos].name,
		c->data[pos].age,
		c->data[pos].sex,
		c->data[pos].tele,
		c->data[pos].address);
}
void modifycontact(struct Contact* c)
{
	char name[MAX_NAME];
	printf("输入要修改的姓名：\n");
	scanf("%s", name);
	int pos = postionsc(c, name);
	if (pos == -1)
	{
		printf("查无此人\n");
	}
	else
	{
		printf("添加姓名：\n");
		scanf("%s", c->data[pos].name);
		printf("添加年龄：\n");
		scanf("%d", &(c->data[pos].age));
		printf("添加性别：\n");
		scanf("%s", c->data[pos].sex);
		printf("添加手机号：\n");
		scanf("%s", c->data[pos].tele);
		printf("添加地址：\n");
		scanf("%s", c->data[pos].address);
		printf("修改完成\n");
	}
}

