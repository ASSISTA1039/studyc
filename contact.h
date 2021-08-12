#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#define MAX 5
#define MAX_NAME 20
#define MAX_SEX 4
#define MAX_TELE 20
#define MAX_ADDRESS 30
#define DEFAULT_SZ 3

struct PeoInfo
{
	char name[MAX_NAME];
	int age;
	char sex[MAX_SEX];
	char tele[MAX_TELE];
	char address[MAX_ADDRESS];
};
//通讯录信息
struct Contact
{
	//创建通讯录
	struct PeoInfo *data;//存放信息
	int size;//记录当前已有的元素个数
	int capacity;//当前通讯录最大容量
};

//声明函数
void initcontact(struct Contact* c);
void addcontact(struct Contact* c);
void showcontact(const struct Contact* c);
void deletcontact(struct Contact* c);
void searchcontact(const struct Contact* c);
void modifycontact(struct Contact* c);
void destroycontact(struct Contact* c);
