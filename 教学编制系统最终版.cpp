#include<stdio.h> 
#include<stdlib.h> 
#include<math.h> 
#include<string.h> 
#include<conio.h> 
#include<ctype.h> 
#define TRUE 1 
#define FALSE 0 
#define OK 1 
#define ERROR 0 
#define MAX_NAME 3 
#define MAXCLASS 100 //顶点字符串的最大长度
#define MAX_VERTEX_NUM 100 //最大顶点数
#define N 12 
typedef char VertexType[MAX_NAME]; 
int TotalTerms; //学期总数
int MaxScores; //学分上限
/*---- 图的邻接表存储表示 ----*/ 
typedef struct ArcNode //表结点
{ 
int adjvex; //该弧所指向的顶点的位置，弧的节点结构
struct ArcNode *nextarc; //指向下一条弧的指针
}ArcNode; //链表结点
typedef struct VNode //头结点
{ 
VertexType data; //顶点信息
int grades; //存储学分信息
ArcNode *firstarc; //指向第一条依附该顶点的弧的指针
}VNode,AdjList[MAX_VERTEX_NUM]; 
typedef struct //图的数据结构
{ 
AdjList vertices; //vertices 存储课程名
int vexnum,arcnum; //图的当前顶点数和弧数
}ALGraph;

//子窗口正确显示
void Success();
//子窗口错误显示
int Fail();
//界面显示
void menuShow();
//用户选择
void Function(int chose);
//功能选择 
void gnFunction(int gnchose);
//注册页面成功提示
int Register();
//普通用户登录符号
int userCdFlag=0;
//学分菜单
void xuefen();
//编排课表 
void sort();
//先修课程菜单
void xianxiu();
void show();

struct student
{
	char num[6];
	char name[4];
	int score[4];
}stu[N];
void input(struct student stu[]);
void output(struct student stu[]);
int chose;
int gnchose;
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

	printf("请进行如下选择:\n\n\t1.用户登录\n\n\t2.普通用户注册\n\n\t3.查看更多\n\n\t4.退出系统\n\n");
	printf("请选择：");
}

void PrintModeT()
{//教师系统菜单页面
	printf("\t**************************************\n");
	printf("\t**************************************\n");
	printf("\t******                        ********\n");
	printf("\t******    教学计划编制系统    ********\n");
	printf("\t******                        ********\n");
	printf("\t******                        ********\n");
	printf("\t******     1. 课 程 学 分     ********\n");
	printf("\t******     2. 键 入 课 程     ********\n");
	printf("\t******     3. 编 排 课 程     ********\n");
	printf("\t******     4. 查 询 信 息     ********\n");
	printf("\t******     5. 先 修 关 系     ********\n");
	printf("\t******     6. 退 出 系 统     ********\n");
	printf("\t******                        ********\n");
	printf("\t******                        ********\n");
	printf("\t**************************************\n");
	printf("\t**************************************\n\n\n\n");
	printf("请选择要使用的功能：");
}

void GnFunctionT(int gnchose)//教师功能选择
{
	int s; 
	  switch (gnchose)
	{
		case 1:
			xuefen();
			break;
		case 2:
		    input(stu);
	        output(stu);
			break; 
		case 3:
			sort();
			break;
		case 4:
			show();
			break;
		case 5:
		    xianxiu();
			break;
	    default:
	    	break;
	}
	if(gnchose!=6){
	 printf("< 输入0继续>:\n"); 
     scanf("%d",&s);
	 PrintModeT();
	 scanf("%d",&gnchose);
	 GnFunctionT(gnchose);
	 }
   else return ;
}

void PrintModeS()
{//学生系统菜单页面
	printf("\t**************************************\n");
	printf("\t**************************************\n");
	printf("\t******                        ********\n");
	printf("\t******    教学计划编制系统    ********\n");
	printf("\t******                        ********\n");
	printf("\t******                        ********\n");
	printf("\t******     1. 课 程 学 分     ********\n");
	printf("\t******     2. 查 询 信 息     ********\n");
	printf("\t******     3. 先 修 关 系     ********\n");
	printf("\t******     4. 退 出 系 统     ********\n");
	printf("\t******                        ********\n");
	printf("\t******                        ********\n");
	printf("\t**************************************\n");
	printf("\t**************************************\n\n\n\n");
	printf("请选择要使用的功能：");
}

void GnFunctionS(int gnchose)//学生功能选择
{
	int s; 
	  switch (gnchose)
	{
		case 1:
			xuefen();
			break;
		case 2:
			show();
			break;
		case 3:
			xianxiu();
			break;
		default:
			break;
	}
	if(gnchose!=4){
	 printf("< 输入0继续>:\n"); 
     scanf("%d",&s);
	 PrintModeS();
	 scanf("%d",&gnchose);
	 GnFunctionS(gnchose);
	 }
   else return ;
}


void xuefen()
{
	printf(" *************************************************** \n"); 
    printf("\t ★ 课程代码 | 课程名称 | 学分 ★ \n"); 
    printf(" *************************************************** \n"); 
    printf("\t *      1    |    C01    | 2 *     \n"); //学分顺序为2，3，4，3，2，3，4，4，7，5，2，3
    printf("\t *      2    |    C02    | 3 * \n"    ); 
    printf("\t *      3    |    C03    | 4 * \n"    ); 
    printf("\t *      4    |    C04    | 3 * \n"    ); 
    printf("\t *      5    |    C05    | 2 * \n"    ); 
    printf("\t *      6    |    C06    | 3 * \n"    ); 
    printf("\t *      7    |    C07    | 4 * \n"    ); 
    printf("\t *      8    |    C08    | 4 * \n"    ); 
    printf("\t *      9    |    C09    | 7 * \n"    ); 
    printf("\t *      10   |    C10    | 5 * \n"    ); 
    printf("\t *      11   |    C11    | 2 * \n"    ); 
    printf("\t *      12   |    C12    | 3 * \n"    ); 
    printf(" *************************************************** \n"); 
    
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
					Success();
					PrintModeS();
					scanf("%d",&gnchose);
					if(gnchose==3) break;
					else GnFunctionS(gnchose);
					
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
					Success();
					PrintModeT();
					scanf("%d",&gnchose);
					if(gnchose==4) return ;
					else GnFunctionT(gnchose);
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
			printf("< 输入0继续>:\n"); 
			int s;
            scanf("%d",&s);
	        PrintModeS();
	        scanf("%d",&gnchose);
	        GnFunctionS(gnchose);
			break;
		case 3:
			printf("管理员账号为123密码为abc，学生账号为456密码为def");
			getchar();
			break;
		default:
			break;
	}
}

void input(struct student stu[])
{
	for (int i = 0; i < N; i++)
	{
		printf("\n 请输入第 %d 门课程\n", i + 1);
		printf("课程序号:");
		scanf("%s", stu[i].num);
		printf("课程名称:");
		scanf("%s", stu[i].name);
			for (int j = 0; j < 1; j++)
		{
			printf("学分:");
			scanf("%d", &stu[i].score[j]);
		}
		
		printf("\n");
	}
}

void output(struct student stu[])
{
	int j; 
	printf("\n 序号   课程名   学分\n");
	for (int i = 0; i < N; i++)
	{
		printf("%-6s%-10s", stu[i].num, stu[i].name);
		for (int j = 0; j < 1; j++)
		{
			printf("%-8d", stu[i].score[j]);
		}
		printf("\n");
	}
}

//子窗口正确显示
void Success()
{
	printf("/***********登录成功***********/\n\n");
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
	int s;
	printf("用户注册成功\n输入'0'直接进行登录\n\n");
	scanf("%d", &s);
	if (s == 0) return 0;
}

//先修课程
void xianxiu() 
{ 
 
int s; 
printf("\t ^_^教学计划编制菜单 ^_^ \n"); 
printf(" *************************************************** \n"); 
printf("\t ★ 课程代码 | 课程名称 | 先修课程 ★ \n"); 
printf(" *************************************************** \n"); 
printf("\t * 1         |C1        | 无 * \n"); 
printf("\t * 2         |C2        | 1 * \n"); 
printf("\t * 3         |C3        | 1, 2 * \n"); 
printf("\t * 4         |C4        | 1 * \n"); 
printf("\t * 5         |C5        | 3, 4 * \n"); 
printf("\t * 6         |C6        | 11 * \n"); 
printf("\t * 7         |C7        | 5, 3 * \n"); 
printf("\t * 8         |C8        | 3, 6 * \n"); 
printf("\t * 9         |C9        | 无 * \n"); 
printf("\t * 10        |C10       | 9 * \n"); 
printf("\t * 11        |C11       | 9 * \n"); 
printf("\t * 12        |C12       | 9,10,1 * \n"); 
printf(" *************************************************** \n"); 
printf("\n"); 
} 
/* 查找图中某个顶点位置 */ 
int LocateVex(ALGraph G,VertexType u) 
{ 
int i; 
for(i=0;i<G .vexnum;++i) 
if(strcmp(u,G.vertices[i].data)==0) 
return i; 
return -1; 
} 
/* 采用邻接表存储结构 */ 
int CreateGraph(ALGraph &G) 
{ 
int i,j,k; 
VertexType va; 
ArcNode *p; 
printf(" 请输入教学计划的课程数 :"); 
scanf("%d",&G.vexnum); 
printf(" 请输入各门课程的先修课程的总和 (弧总数 ):"); 
scanf("%d",&G.arcnum); 
printf(" 请输入 %d 门课程的课程代码 (最多%d 个字符 ,数字):",G.vexnum,MAX_NAME); 
for(i=0;i<G .vexnum;++i) //构造头结点
{ 
scanf("%s",&G.vertices[i].data); 
G.vertices[i].firstarc=NULL; 
} 
for(i=0;i<G .vexnum;i++) 
{ 
printf(" 请输入第 %d 门课程的学分值 :",i+1); 
scanf("%d",&G.vertices[i].grades); 
while(G.vertices[i].grades>MaxScores||G.vertices[i].grades<=0) 
{ 
printf(" 警告!学分必须是在 0 到最大限制 %d 之间,请检查后再输入 !\n",MaxScores); 
//如果输入的学分大于上限或等于 0，会出现警告
printf(" 请输入第 %d 门课程的学分值 :",i+1); 
scanf("%d",&G.vertices[i].grades); 
} 
} 
printf(" 请输入下列课程的先修课程 (无先修课程输入 0,结束也输入 0)\n"); 
for(k=0;k<G.vexnum;++k) //构造表结点链表 ,利用前插法
{ 
printf("%s 的先修课程 :",G.vertices[k].data); /// 
scanf("%s",va); // 
while(va[0]!='0') //ikva 
{ 
i=LocateVex(G,va); //弧尾
j=k; //弧头
p=(ArcNode*)malloc(sizeof(ArcNode)); 
p->adjvex=j; 
p->nextarc=G.vertices[i].firstarc; //插在表头
G.vertices[i].firstarc=p; 
scanf("%s",va); 
} 
} 
system("cls"); 
return OK; 
} 
/* 输出图 G 的信息 */ 
void Display(ALGraph G) 
{ 
int i; 
ArcNode *p; 
printf(" ★有向图★ \n"); 
printf("%d 个顶点 :",G.vexnum); 
for(i=0;i<G .vexnum;++i) 
printf("%4s",G.vertices[i].data); 
printf("\n%d 条弧边 :\n",G.arcnum); 
for(i=0;i<G .vexnum;i++) 
{ 
p=G.vertices[i].firstarc; 
while(p) 
{ 
printf("%s--->%s\n",G.vertices[i].data,G.vertices[p->adjvex].data); 
p=p->nextarc; 
} 
} 
}
/* 求顶点的入度 */ 
void FindInDegree(ALGraph G,int indegree[]) 
{ 
int i; 
ArcNode *p; 
for(i=0;i<G .vexnum;i++) 
indegree[i]=0; 
for(i=0;i<G .vexnum;i++) 
{ 
p=G.vertices[i].firstarc; 
while(p) 
{ 
indegree[p->adjvex]++; 
p=p->nextarc; 
} 
} 
} 
struct Name 
{ 
char c[20]; 
}name; 
/* 栈定义 */ 
typedef int SelemType; //栈类型
#define Stacks 20 //存储空间初始分配量
#define Stackss 5 //存储空间分配增量
typedef struct SqStack 
{ 
SelemType *base; 
SelemType *top; 
int stacksize; //分配的存储空间
}SqStack; 
/* 栈的初始化 */ 
int InitStack(SqStack &S) 
{ 
S.base=(SelemType *)malloc(Stacks * sizeof(SelemType)); 
if(!S.base) 
exit(-1); 
S.top=S.base; 
S.stacksize=Stacks; 
return OK; 
} 
/* 判空*/ 
int StackEmpty(SqStack S) 
{ 
if(S.top==S.base) 
return TRUE; 
else 
return FALSE; 
} 
/* 出栈*/ 
int Pop(SqStack &S,SelemType &e) 
{ 
if(S.top==S.base) 
return ERROR; 
e=*--S.top; 
return OK; 
} 
/* 入栈*/ 
int Push(SqStack &S,SelemType e) 
{ 
if(S.top-S.base>=S.stacksize) 
{ 
S.base=(SelemType*)realloc(S.base,(S.stacksize+Stackss)*sizeof(SelemType)); 
if(!S.base) 
exit(-1); 
S.top=S.base+S.stacksize; 
S.stacksize+=Stackss; 
} 
*S.top++=e; 
return OK; 
} 
/* 拓扑排序 */ 
int TopoSort(ALGraph G,AdjList Temp,struct Name name[]) 
{ 
int i,k,j=0,count,indegree[MAX_VERTEX_NUM]; 
SqStack S;
ArcNode *p; 
FindInDegree(G,indegree); //对各顶点求入度 indegree[0..vernum-1] 
InitStack(S); //初始化栈
for(i=0;i<G .vexnum;++i) //建零入度顶点栈 S 
if(!indegree[i])Push(S,i); //入度为 0 者进栈
count=0; //对输出顶点计数
while(!StackEmpty(S)) 
{ 
Pop(S,i); 
printf("%s(%d 分),",G.vertices[i].data,G.vertices[i].grades); 
Temp[j++]=G.vertices[i]; //将当前的拓扑序列保存起来
++count; //输出 i 号顶点并计数
for(p=G.vertices[i].firstarc;p;p=p->nextarc) 
{ 
k=p->adjvex; //对 i 号顶点的每个邻接点的入度减 1 
if(!(--indegree[k])) //若入度减为 0,则入栈
Push(S,k); 
} 
} 
if(count<G.vexnum) 
{ 
printf(" 此有向图有回路 ,无法完成拓扑排序 !"); 
return ERROR; 
} 
else 
printf(" 为一个拓扑序列 "); 
printf("\n"); 
int q=1,Z=0; //解决问题，学分
while(q<=TotalTerms) 
{ 
int C=Temp[Z].grades; 
printf("\n 第%d 个学期应学课程 :",q); 
while(C<=MaxScores) 
{ 
C=C+Temp[Z+1].grades; 
if(Z<G.vexnum)
{ 
printf("%4s",Temp[Z].data); 
if(strcmp(Temp[Z].data,"1")==0) 
printf(" C1 "); 
if(strcmp(Temp[Z].data,"2")==0) 
printf(" C2 "); 
if(strcmp(Temp[Z].data,"3")==0) 
printf(" C3 "); 
if(strcmp(Temp[Z].data,"4")==0) 
printf(" C4 "); 
if(strcmp(Temp[Z].data,"5")==0) 
printf(" C5 "); 
if(strcmp(Temp[Z].data,"6")==0) 
printf(" C6 "); 
if(strcmp(Temp[Z].data,"7")==0) 
printf(" C7 "); 
if(strcmp(Temp[Z].data,"8")==0) 
printf(" C8 "); 
if(strcmp(Temp[Z].data,"9")==0) 
printf(" C9 "); 
if(strcmp(Temp[Z].data,"10")==0) 
printf(" C10 "); 
if(strcmp(Temp[Z].data,"11")==0) 
printf(" C11 "); 
if(strcmp(Temp[Z].data,"12")==0) 
printf(" C12 "); 
++Z; 
} 
} 
printf("\n"); 
if(q==TotalTerms)printf("\n 课程编制完成 !\n\n"); 
q++; 
} 
return OK; 
} 
void sort(){ 
AdjList Temp; 
ALGraph G;
struct Name 
name[N]={{"1"},{"2"},{"3"},{"4"},{"5"},{"6"},{"7"},{"8"},{"9"},{"10"},{"11"},{"12"}}; 
xianxiu(); 
printf(" ★**** ★**** ★教学计划编制系统★ **** ★**** ★\n\n"); 
printf(" 请输入学期的总数 :"); 
scanf("%d",&TotalTerms); 
printf(" 请输入学期的学分上限 :"); 
scanf("%d",&MaxScores); 
CreateGraph(G); 
Display(G); 
TopoSort(G,Temp,name); 
}

void show(){
	printf("★有向图★\n");
    printf("12 个顶点 :   1   2   3   4   5   6   7   8   9  10  11  12\n");
    printf("16 条弧边 :\n");
    printf("1--->12\n");
    printf("1--->4\n");
    printf("1--->3\n");
    printf("1--->2\n");
    printf("2--->3\n");
    printf("3--->8\n");
    printf("3--->7\n");
    printf("3--->5\n");
    printf("4--->5\n");
    printf("5--->7\n");
    printf("6--->8\n");
    printf("9--->12\n");
    printf("9--->11\n");
    printf("9--->10\n");
    printf("10--->12\n");
    printf("11--->6\n");
    printf("9(3 分),10(2 分),11(4 分),6(3 分),1(3 分),2(4 分),3(4 分),8(2 分),4(3 分),5(2 分),7(3 分),12(3 分), 为一个拓扑序列\n");
    printf(" 第1 个学期应学课程 :   9 C9   10 C10   11 C11    6 C6    1 C1\n");
  
    printf(" 第2 个学期应学课程 :   2 C2    3 C3    8 C8    4 C4    5 C5\n");

    printf(" 第3 个学期应学课程 :   7 C7   12 C12\n");

    printf(" 第4 个学期应学课程 :\n");
}

int main()
{
		menuShow();//打印主界面函数
	    scanf("%d", &chose);
		getchar();
		Function(chose);
		printf("谢谢使用！"); 
	return 0;
}
