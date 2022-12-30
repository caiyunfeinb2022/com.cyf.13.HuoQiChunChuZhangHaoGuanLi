int gongnengmain(){ 
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
