#include<stdio.h>
#include<stdlib.h>
#include<string.h>
void main(){
	char file[50];	
	while(1){
		char command[60]="gcc ";
		printf("Enter the program name : ");
		scanf("%s",file);
		strcat(command,file);
		system(command);
		system("./a.out");	
		printf("\n\nFinished compilation or execution !!! \n\n");
	}
}