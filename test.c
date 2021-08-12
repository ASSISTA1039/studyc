#define _CRT_SECURE_NO_WARNINGS 1
#include "contact.h"

void menu()
{
	printf("\n************************************\n");
	printf("*****1.add            2.delet  *****\n");
	printf("*****3.search      4.modify   *****\n");
	printf("*****5.show         6.sort    *****\n");
	printf("*****0.exit                   ******\n");
	printf("***********************************\n");

}
enum Option
{
	EXIT,
	ADD,
	DELET,
	SEARCH,
	MODIFY,
	SHOW,
	SORT
};
int main()
{
	//创建通讯录
	int input = 0;
	struct Contact con;
	//初始化通讯录
	initcontact(&con);
	while (1)
	{
		menu();
		printf("请选择：\n");
		scanf("%d", &input);
		switch (input)
		{
		case ADD:
			addcontact(&con);
			break;
		case DELET:
			deletcontact(&con);
			break;
		case SEARCH:
			searchcontact(&con);
			break;
		case MODIFY:
			modifycontact(&con);
			break;
		case SHOW:
			showcontact(&con);
			break;
		case SORT:
			break;
		case EXIT:
			//销毁通讯录-释放动态开辟的内存空间
			destroycontact(&con);
			printf("退出通讯录\n");
			break;
		default:
			printf("选择错误\n");
			break;
		}
	}
	return 0;
}
