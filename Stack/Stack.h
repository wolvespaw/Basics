#include <stdlib.h>
#include <stdio.h>
typedef struct
{
	void *contents;
	void *top;
	int maxSize;
	int type:1; //1 if floating, 0 if non floating point
	int numBytes:7; //number of bytes needed for each element 
} stackT;
void stackResize(stackT *stackP) //used to auto increment
{
	void stackResize(stackT *stackP,int increment);
	stackResize(stackP,5);
}
void stackResize(stackT *stackP,int increment) //allows complete control of resize
{
	stackP->maxSize+=increment;
}
stackT stackInit(void *type)
{
	stackT stackP;
	if(*(long double *)type==(long)(*(long double *)type))
		stackP.type=1;
	else
		stackP.type=0;
	if(stackP.type)
	{
		if(*(long *)type==*(char *)type)
			stackP.numBytes=1;
		else if(*(long *)type==*(int *)type)
			stackP.numBytes=2;
		else
			stackP.numBytes=4;
	}
	else
	{
		if(*(long double *)type==*(float *)type)
			stackP.numBytes=4;
		else if(*(long double *)type==*(double *)type)
			stackP.numBytes=8;
		else
			stackP.numBytes=10;
	}
	void *newContents;
	newContents=malloc(stackP.numBytes*10);
	if(newContents ==NULL)
	{
		printf("Insufficient memory to initialize stack.\n");
		exit(1);
	}
	stackP.top=NULL;
	stackP.contents=NULL;
	stackP.maxSize=10;
	return stackP;
}
void stackDestroy(stackT *stackP)
{
	free(stackP->contents);
	free(stackP->top);
	stackP->maxSize=10;
}
int stackIsEmpty(stackT *stackP)
{
	if(sizeof(stackP))
		return 0;
	return 1;
}
int stackIsFull(stackT *stackP)
{
	if((stackP->top!=NULL) && sizeof(stackP)/sizeof(stackP->top)==stackP->maxSize)
		return 0;
	return 1;
}
int stackAdd(stackT *stackP,void *element)
{
	if(stackIsFull(stackP))
		return 1;
	if(stackP->type)
	{
		switch(stackP->numBytes)
		{
			case(1): {
						char *temp=(char *)stackP->contents; ++temp=(char *)element;stackP->top=element;
						stackP->contents=temp;free(temp);break;
					 }
			case(2): {
						int *temp=(int *)stackP->contents; ++temp=(int *)element;stackP->top=element;
						stackP->contents=temp;free(temp);break;
					 }
			case(4): {
						long *temp=(long *)stackP->contents; ++temp=(long *)element;stackP->top=element;
						stackP->contents=temp;free(temp);break;
					 }
		}
	}
	else
	{
		switch(stackP->numBytes)
		{
			case(4): {
						float *temp=(float *)stackP->contents; ++temp=(float *)element;stackP->top=element;
						stackP->contents=temp;free(temp);break;
					 }
			case(8): {
						double *temp=(double *)stackP->contents; ++temp=(double *)element;stackP->top=element;
						stackP->contents=temp;free(temp);break;
					 }
			case(10):{
						long double *temp=(long double *)stackP->contents; ++temp=(long double *)element;stackP->top=element;
						stackP->contents=temp;free(temp);break;
					  }
		}
	}
	return 0;
}
void stackPush(stackT *stackP,void *element)
{
	if(stackIsFull(stackP))
	{
		printf("Stack is full. Operation aborted.\n");
		exit(1);
	}
	if(stackP->type)
	{
		switch(stackP->numBytes)
		{
			case(1): {
						char *temp=(char *)stackP->contents; ++temp=(char *)element;stackP->top=element;
						stackP->contents=temp;free(temp);break;
					 }
			case(2): {
						int *temp=(int *)stackP->contents; ++temp=(int *)element;stackP->top=element;
						stackP->contents=temp;free(temp);break;
					 }
			case(4): {
						long *temp=(long *)stackP->contents; ++temp=(long *)element;stackP->top=element;
						stackP->contents=temp;free(temp);break;
					 }
		}
	}
	else
	{
		switch(stackP->numBytes)
		{
			case(4): {
						float *temp=(float *)stackP->contents; ++temp=(float *)element;stackP->top=element;
						stackP->contents=temp;free(temp);break;
					 }
			case(8): {
						double *temp=(double *)stackP->contents; ++temp=(double *)element;stackP->top=element;
						stackP->contents=temp;free(temp);break;
					 }
			case(10):{
						long double *temp=(long double *)stackP->contents; ++temp=(long double *)element;stackP->top=element;
						stackP->contents=temp;free(temp);break;
					  }
		}
	}
}
void *stackPop(stackT *stackP)
{
	if(stackIsEmpty(stackP))
	{
		printf("No element to pop.\n");
		exit(-1);
	}
	if(stackP->type)
	{
		switch(stackP->numBytes)
		{
			case(1): {
						char *temp=(char *)stackP->contents;stackP->contents=temp-1; free(temp); return stackP->top;
					 }
			case(2): {
						int *temp=(int *)stackP->contents; stackP->top=temp--;
						stackP->contents=temp; free(temp); return stackP->top;
					 }
			case(4): {
						long *temp=(long *)stackP->contents; stackP->top=temp--;
						stackP->contents=temp; free(temp); return stackP->top;
					 }
		}
	}
	else
	{
		switch(stackP->numBytes)
		{
			case(4): {
						float *temp=(float *)stackP->contents;
					 }
			case(8): {
						double *temp=(double *)stackP->contents; ++temp=(double *)element;stackP->top=element;
						stackP->contents=temp;free(temp);break;
					 }
			case(10):{
						long double *temp=(long double *)stackP->contents; ++temp=(long double *)element;stackP->top=element;
						stackP->contents=temp;free(temp);break;
					  }
		}
	}
}
void *stackPeek(stackT *stackP) //fix later
{
	return (stackIsEmpty(stackP))?NULL:stackP->top;
}
void *stackPoll(stackT *stackP)
{
	if(stackIsEmpty(stackP))
		return NULL;
}
int size(stackT *stackP)
{
	if(sizeof(stackP))
		return 0;
	return sizeof(stackP)/sizeof(stackP->top);
}