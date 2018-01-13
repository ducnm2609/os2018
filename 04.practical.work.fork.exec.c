#include<stdio.h>
#include<unistd.h>

int main()
{
	char* ps[] = {"ps","-ef",NULL};
	char* fr[] = {"free","-h",NULL};
	int pid;
	
	printf("parent\n");
	
	if ((pid = fork()) == 0)	
	execvp(ps[0],ps);
	if ((pid = fork()) == 0)
	execvp(fr[0],fr);
	
	return 0;
}
	
