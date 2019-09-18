#include<stdio.h>
#include<stdlib.h>


void main(){

	
	printf("%d",system("ls"));
	system("echo $?");

}