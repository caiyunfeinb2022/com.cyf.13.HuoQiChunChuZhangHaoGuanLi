#include <stdlib.h>
#include <stdio.h>
#include <windows.h>
#include <string.h>
//�Ӵ�����ȷ��ʾ
int Succes();
//�Ӵ��ڴ�����ʾ
int Fail();
//������ʾ
void menuShow();
//�û�ѡ��
void Function(int chose);
//ע��ҳ��ɹ���ʾ
int Register();
//��ͨ�û���¼����
int userCdFlag=0;


int chose;
//�û��˺�����У��
char userCheck[50];
char pwdCheck[16];

//ƥ���û��������� 
int isUserName;
int isUserPwd;

//�������Ա��¼�û��� �Լ����� 
char userNameR[50] = { "123" };
char userPwdR[16] = { "abc" };

//������ͨ�û���¼�û��� �Լ����� 
char userName[50]={"456"};
char userPwd[16]={"def"};

//������ʾ
void menuShow()
{
	printf("/*************************************/\n\n");
	printf("\t��ӭ��¼��ѧ�ƻ�����ϵͳ\n\n");
	printf("/*************************************/\n\n");

	printf("���������ѡ��:\n\n\t1.�û���¼\n\n\t2.�û�ע��\n\n\t3.�鿴����\n\n\t4.�˳�ϵͳ\n\n");
	printf("��ѡ��");
}

void PrintMode()
{//ϵͳ�˵�ҳ��
	printf("**************************************\n");
	printf("**************************************\n");
	printf("******                        ********\n");
	printf("******    ��ѧ�ƻ�����ϵͳ    ********\n");
	printf("******                        ********\n");
	printf("******                        ********\n");
	printf("******     0. �� �� ѧ ��     ********\n");
	printf("******     1. �� �� �� ��    ********\n");
	printf("******     2. �� ѯ �� Ϣ     ********\n");
	printf("******     3. �� �� �� ϵ     ********\n");
	printf("******     4. �� �� ϵ ͳ     ********\n");
	printf("******                        ********\n");
	printf("******                        ********\n");
	printf("**************************************\n");
	printf("**************************************\n\n\n\n");
	printf("��ѡ��Ҫʹ�õĹ��ܣ�");
}

//�û���¼ѡ��
void userLoginChose()
{
	printf("�û���½ѡ��\n1.��ͨ�û�\n2.����Ա�û�\n");
	scanf("%d",&userCdFlag);
	getchar();
	
}

//�û�ѡ��
void Function(int chose)
{
	switch (chose)
	{
		case 1:
			//��ͨ�û�
			userLoginChose();
			if (userCdFlag == 1)
			{
				userCdFlag = 0;
				printf("�������û�����");
				gets(userCheck);
				//user check
				isUserName = strcmp(userName, userCheck);
				printf("\n");

				printf("���������룺");
				gets(pwdCheck);
				printf("\n");
				//pwd check
				isUserPwd = strcmp(userPwd, pwdCheck);

				if ((isUserName == 0) && (isUserPwd == 0))
				{
					//�����жϷ��ز��
					if (Succes() == 0)
					{
						break;
					}
					else
					{
					  Succes();
					}
				}
				//ʧ��ҳ��
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
			//����Ա��¼ 
			else
			{
				printf("�������û�����");
				gets(userCheck);
				//user check
				isUserName = strcmp(userNameR, userCheck);
				printf("\n");

				printf("���������룺");
				gets(pwdCheck);
				printf("\n");
				//pwd check
				isUserPwd = strcmp(userPwdR, pwdCheck);

				if ((isUserName == 0) && (isUserPwd == 0))
				{
					//�����жϷ��ز��
					if (Succes() == 0)
					{
						break;
					}
					else
					{
					Succes();
					}
				}
				//ʧ��ҳ��
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
			printf("������û�����");
			gets(userName);
			printf("\n");
			printf("���������룺");
			gets(userPwd);
			if ((userName != NULL) && (userPwd != NULL))
			{
			Register();

			}
			printf("\n");
			userCdFlag = 2;
			break;
		case 3:
			printf("����Ա�˺�Ϊ123����Ϊabc��ѧ���˺�Ϊ456����Ϊdef");
			getchar();
			break;

		default:
			break;
	}
}


//�Ӵ�����ȷ��ʾ
int Succes()
{
	char succes;
	printf("/***********��¼�ɹ�***********/\n\n");
	printf("����'y'����ϵͳ\n");
	scanf("%c", &succes);
	return 	1;
}

//�Ӵ��ڴ�����ʾ
int Fail()
{
	char fail;
	printf("/***********��¼ʧ��***********/\n\n");
	printf("'y'������������\t'n'�����ʼĿ¼\n");
	scanf("%c", &fail);
	if (fail == 'n') return 0;
	else
	{
		return 1;
	}
}

//ע��ҳ��ɹ���ʾ
int Register()
{
	char succes;
	printf("�û�ע��ɹ�\n����'y'���ص�¼ҳ��\n\n");
	scanf("%c", &succes);
	if (succes == 'y') return 0;
}

//��ӭ����
int Welcome()
{
		int i = Succes();
	if (i == 1){//����½�ɹ���򿪲˵�ҳ��
		PrintMode();//��ӡ�˵�����
		return 0;
	}
}


int main()
{
		menuShow();//��ӡ�����溯��
	    scanf("%d", &chose);
		getchar();
		Function(chose);
		if (chose == 4)  
		return 0;
		Welcome();
	
	return 0;
}
