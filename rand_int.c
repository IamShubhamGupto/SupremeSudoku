#include<stdio.h>
#include<time.h>
void main(){
	for(int i = 1; i < 10; i++){
		gen(i);
	}
	

}
void gen(int i){
	time_t my_time;
	struct tm * timeinfo; 
	time (&my_time);
	timeinfo = localtime (&my_time);
	int s = timeinfo->tm_sec;
	int m = timeinfo->tm_min;
	int h = timeinfo->tm_hour;
	long long int n = h*h*197+m*m*223+s*s*227+i*i*i;
	long long int rand = n%10;
	if(rand == 0)
		gen(197);
	else
		printf("%d\n",rand);
}
