/* 拓扑排序 */ 
int TopoSort(ALGraph G,AdjList Temp,struct Name name[]) 
{ 
int i,k,j=0,count,indegree[MAX_VERTEX_NUM]; 
SqStack S;ArcNode *p; 
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
