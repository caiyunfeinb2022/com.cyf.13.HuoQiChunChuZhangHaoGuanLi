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
int main(){ 
ALGraph G; 
AdjList Temp; 
printf0(); 
struct Name 
name[N]={{"1"},{"2"},{"3"},{"4"},{"5"},{"6"},{"7"},{"8"},{"9"},{"10"},{"11"},{"12"}}; 
OUTPUT(); 
printf(" ★**** ★**** ★教学计划编制系统★ **** ★**** ★\n\n"); 
printf(" 请输入学期的总数 :"); 
scanf("%d",&TotalTerms); 
printf(" 请输入学期的学分上限 :"); 
scanf("%d",&MaxScores); 
CreateGraph(G); 
Display(G); 
TopoSort(G,Temp,name); 
printf(" 谢谢使用 !\n"); 
} 
