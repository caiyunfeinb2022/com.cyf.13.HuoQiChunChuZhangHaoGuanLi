/* �������� */ 
int TopoSort(ALGraph G,AdjList Temp,struct Name name[]) 
{ 
int i,k,j=0,count,indegree[MAX_VERTEX_NUM]; 
SqStack S;ArcNode *p; 
FindInDegree(G,indegree); //�Ը���������� indegree[0..vernum-1] 
InitStack(S); //��ʼ��ջ
for(i=0;i<G .vexnum;++i) //������ȶ���ջ S 
if(!indegree[i])Push(S,i); //���Ϊ 0 �߽�ջ
count=0; //������������
while(!StackEmpty(S)) 
{ 
Pop(S,i); 
printf("%s(%d ��),",G.vertices[i].data,G.vertices[i].grades); 
Temp[j++]=G.vertices[i]; //����ǰ���������б�������
++count; //��� i �Ŷ��㲢����
for(p=G.vertices[i].firstarc;p;p=p->nextarc) 
{ 
k=p->adjvex; //�� i �Ŷ����ÿ���ڽӵ����ȼ� 1 
if(!(--indegree[k])) //����ȼ�Ϊ 0,����ջ
Push(S,k); 
} 
} 
if(count<G.vexnum) 
{ 
printf(" ������ͼ�л�· ,�޷������������ !"); 
return ERROR; 
} 
else 
printf(" Ϊһ���������� "); 
printf("\n"); 
int q=1,Z=0; //������⣬ѧ��
while(q<=TotalTerms) 
{ 
int C=Temp[Z].grades; 
printf("\n ��%d ��ѧ��Ӧѧ�γ� :",q); 
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
if(q==TotalTerms)printf("\n �γ̱������ !\n\n"); 
q++; 
} 
return OK; 
} 
