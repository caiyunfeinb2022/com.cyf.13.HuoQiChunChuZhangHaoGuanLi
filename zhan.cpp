/* ջ�ĳ�ʼ�� */ 
int InitStack(SqStack &S) 
{ 
S.base=(SelemType *)malloc(Stacks * sizeof(SelemType)); 
if(!S.base) 
exit(-1); 
S.top=S.base; 
S.stacksize=Stacks; 
return OK; 
} 
/* �п�*/ 
int StackEmpty(SqStack S) 
{ 
if(S.top==S.base) 
return TRUE; 
else 
return FALSE; 
} 
/* ��ջ*/ 
int Pop(SqStack &S,SelemType &e) 
{ 
if(S.top==S.base) 
return ERROR; 
e=*--S.top; 
return OK; 
} 
/* ��ջ*/ 
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
