int main(){ 
ALGraph G; 
AdjList Temp; 
printf0(); 
struct Name 
name[N]={{"1"},{"2"},{"3"},{"4"},{"5"},{"6"},{"7"},{"8"},{"9"},{"10"},{"11"},{"12"}}; 
OUTPUT(); 
printf(" ��**** ��**** ���ѧ�ƻ�����ϵͳ�� **** ��**** ��\n\n"); 
printf(" ������ѧ�ڵ����� :"); 
scanf("%d",&TotalTerms); 
printf(" ������ѧ�ڵ�ѧ������ :"); 
scanf("%d",&MaxScores); 
CreateGraph(G); 
Display(G); 
TopoSort(G,Temp,name); 
printf(" ллʹ�� !\n"); 
} 
