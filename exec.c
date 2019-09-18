#include<stdio.h>
#include<unistd.h>
#include<errno.h>
#include<string.h>

void main(){

	
	printf("%d\n",execlp("ls","ls",NULL));
	puts(strerror(errno));
	printf("I did not exit.....\n");

}