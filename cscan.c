#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int rand_int(int l,int u){
	return (rand()%(u-l+1))+l;
}
int calc_dist(int y,int x){
	return abs(y-x);	
}
void sort(int arr[],int n){
	int i,j,temp,pos;
	for(i=0;i<=n;i++){
		pos=i;
		for(j=i+1;j<=n;j++){
			if(arr[j]<arr[pos]){
				pos=j;
			}
		}
		if(pos!=i){
			temp=arr[i];
			arr[i]=arr[pos];
			arr[pos]=temp;
		}
	}
}

int traverse_right(int arr[],int start,int end,int prev){
	int i,seek_time=0,dist,next;	
	for(i=start;i<end;i++){
		next=arr[i];
		printf("R/W head moves from %d to %d",prev,next);
		dist=calc_dist(prev,next);
		printf("\tSeek time : %d\n",dist);
		seek_time+=dist;
		prev=next;
	}
	return seek_time;
}
void main(){
	int low=0,high=199,n,seek_time=0,dist,prev,next,head,i,request[20],pos;
	printf("\n\t\tC-SCAN DISK SCHEDULING\n\n");
	srand(time(NULL));
	n=rand_int(6,15);
	head=rand_int(low+1,high-1);
		
	printf("No of Cylinders : ");
	printf("%d\n\n",n);
	printf("Head Position : ");
	printf("%d\n\n",head);
	request[0]=head;
	printf("I/0 Requests : ");
	for(i=0;i<n;i++){
		request[i+1]=rand_int(low,high);
		printf("%d  ",request[i+1]);
	}
	printf("\n");
	sort(request,n);
	printf("I/0 Requests sorted : ");
	for(i=0;i<=n;i++){
		printf("%d  ",request[i]);
	}
	printf("\n");	

	for(i=0;i<=n;i++){
		if(request[i]==head){
			pos=i+1;
			break;
		}
	}
	printf("\n");
	
	seek_time+=traverse_right(request,pos,n+1,head);
	dist=calc_dist(request[n],high);
	if(dist!=0){
		printf("R/W head moves from %d to %d",request[n],high);
		printf("\tSeek time : %d\n",dist);
		seek_time+=dist;
	}
	printf("R/W head moves from %d to %d",high,low);
	printf("\tSeek time : 1\n");
	seek_time+=1;
	seek_time+=traverse_right(request,0,pos-1,low);	
	
	printf("\nSeek Time : %d",seek_time);
	printf("\nAverage Seek Time : %f\n",(float)seek_time/n);
}
