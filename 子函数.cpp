
void OUTPUT() 
{ 
system("color E"); 
int s; 
printf("\t ^_^教学计划编制菜单 ^_^ \n"); 
printf("\t *************************************************** \n"); 
printf("\t ★ 课程代码 | 课程名称 | 先修课程 ★ \n"); 
printf("\t *************************************************** \n"); 
printf("\t * 1 |C1 | 无 * \n"); 
printf("\t * 2 |C2 | 1 * \n"); 
printf("\t * 3 |C3 | 1, 2 * \n"); 
printf("\t * 4 |C4 | 1 * \n"); 
printf("\t * 5 |C5 | 3, 4 * \n"); 
printf("\t * 6 |C6 | 11 * \n"); 
printf("\t * 7 |C7 | 5, 3 * \n"); 
printf("\t * 8 |C8 | 3, 6 * \n"); 
printf("\t * 9 |C9 | 无 * \n"); 
printf("\t * 10 |C10 | 9 * \n"); 
printf("\t * 11 |C11 | 9 * \n"); 
printf("\t * 12 |C12 | 9,10,1 * \n"); 
printf("\t *************************************************** \n"); 
printf("\n"); 
printf("< 按 Enter继续>:"); 
scanf("%c",&s); //scanf("格式控制符 ",& 地址表列 )格式输入函数，即按用户
指定的格式从键盘上把数据输入到指定的变量之中
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
第 24 页 共 29 页
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
第 25 页 共 29 页
{ 
system("color B"); 
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


