#include <stdlib.h>
#include <stdio.h>
#include <windows.h>
#include <string.h>
//子窗口正确显示
int Succes();
//子窗口错误显示
int Fail();
//界面显示
void menuShow();
//用户选择
void Function(int chose);
//注册页面成功提示
int Register();
//普通用户登录符号
int userCdFlag=0;


int chose;
//用户账号密码校验
char userCheck[50];
char pwdCheck[16];

//匹配用户名与密码 
int isUserName;
int isUserPwd;

//定义管理员登录用户名 以及密码 
char userNameR[50] = { "123" };
char userPwdR[16] = { "abc" };

//定义普通用户登录用户名 以及密码 
char userName[50]={"456"};
char userPwd[16]={"def"};

//界面显示
void menuShow()
{
	printf("/*************************************/\n\n");
	printf("\t欢迎登录教学计划编制系统\n\n");
	printf("/*************************************/\n\n");

	printf("请进行如下选择:\n\n\t1.用户登录\n\n\t2.用户注册\n\n\t3.查看更多\n\n\t4.退出系统\n\n");
	printf("请选择：");
}

void PrintMode()
{//系统菜单页面
	printf("**************************************\n");
	printf("**************************************\n");
	printf("******                        ********\n");
	printf("******    教学计划编制系统    ********\n");
	printf("******                        ********\n");
	printf("******                        ********\n");
	printf("******     0. 课 程 学 分     ********\n");
	printf("******     1. 键 入 课 程    ********\n");
	printf("******     2. 查 询 信 息     ********\n");
	printf("******     3. 先 修 关 系     ********\n");
	printf("******     4. 退 出 系 统     ********\n");
	printf("******                        ********\n");
	printf("******                        ********\n");
	printf("**************************************\n");
	printf("**************************************\n\n\n\n");
	printf("请选择要使用的功能：");
}

//用户登录选择
void userLoginChose()
{
	printf("用户登陆选择：\n1.普通用户\n2.管理员用户\n");
	scanf("%d",&userCdFlag);
	getchar();
	
}

//用户选择
void Function(int chose)
{
	switch (chose)
	{
		case 1:
			//普通用户
			userLoginChose();
			if (userCdFlag == 1)
			{
				userCdFlag = 0;
				printf("请输入用户名：");
				gets(userCheck);
				//user check
				isUserName = strcmp(userName, userCheck);
				printf("\n");

				printf("请输入密码：");
				gets(pwdCheck);
				printf("\n");
				//pwd check
				isUserPwd = strcmp(userPwd, pwdCheck);

				if ((isUserName == 0) && (isUserPwd == 0))
				{
					//用于判断返回层次
					if (Succes() == 0)
					{
						break;
					}
					else
					{
					  Succes();
					}
				}
				//失败页面
				else
				{
					if (Fail() == 0)
					{
						break;
					}
					else
					{
						getchar();
					    Function(1);
					}
				}
				printf("\n");
				getchar();
			
			}
			//管理员登录 
			else
			{
				printf("请输入用户名：");
				gets(userCheck);
				//user check
				isUserName = strcmp(userNameR, userCheck);
				printf("\n");

				printf("请输入密码：");
				gets(pwdCheck);
				printf("\n");
				//pwd check
				isUserPwd = strcmp(userPwdR, pwdCheck);

				if ((isUserName == 0) && (isUserPwd == 0))
				{
					//用于判断返回层次
					if (Succes() == 0)
					{
						break;
					}
					else
					{
					Succes();
					}
				}
				//失败页面
				else
				{
					if (Fail() == 0)
					{
						break;
					}
					else
					{
						getchar();
						Function(1);
					}
				}
				printf("\n");
				getchar();
			}
		
			break;
		case 2:
			printf("请添加用户名：");
			gets(userName);
			printf("\n");
			printf("请输入密码：");
			gets(userPwd);
			if ((userName != NULL) && (userPwd != NULL))
			{
			Register();

			}
			printf("\n");
			userCdFlag = 2;
			break;
		case 3:
			printf("管理员账号为123密码为abc，学生账号为456密码为def");
			getchar();
			break;

		default:
			break;
	}
}


//子窗口正确显示
int Succes()
{
	char succes;
	printf("/***********登录成功***********/\n\n");
	printf("输入'y'进入系统\n");
	scanf("%c", &succes);
	return 	1;
}

//子窗口错误显示
int Fail()
{
	char fail;
	printf("/***********登录失败***********/\n\n");
	printf("'y'重新输入输入\t'n'返回最开始目录\n");
	scanf("%c", &fail);
	if (fail == 'n') return 0;
	else
	{
		return 1;
	}
}

//注册页面成功提示
int Register()
{
	char succes;
	printf("用户注册成功\n输入'y'直接进行登录\n\n");
	scanf("%c", &succes);
	if (succes == 'y') return 0;
}

//欢迎函数
int Welcome()
{
		int i = Succes();
	if (i == 1){//当登陆成功则打开菜单页面
		PrintMode();//打印菜单界面
		return 0;
	}
}


int main()
{
		menuShow();//打印主界面函数
	    scanf("%d", &chose);
		getchar();
		Function(chose);
		if (chose == 4)  
		return 0;
		Welcome();
	
	return 0;
}
