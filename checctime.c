#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h> 
#include <time.h> 
#include<string.h>
#define Size 50
int main()
{
    //Current times
    time_t t; 
	struct tm *tmp ; 
	char day[Size], month[Size], hour[Size]; 
	time(&t);
	tmp = localtime(&t);
	strftime(day, sizeof(day), "%d", tmp);
	strftime(month, sizeof(month), "%B", tmp);
	strftime(hour, sizeof(hour), "%H", tmp);
	int h = atoi(hour);
		
	//File times
	struct stat s;
    int res = stat("file.txt", &s);
    char day1[Size], month1[Size], hour1[Size];
	//Access times
	struct tm *tmp1;
	tmp1 = localtime(&s.st_atime);
    strftime(day1, sizeof(day1), "%d", tmp1);
	strftime(month1, sizeof(month1), "%B", tmp1);
	strftime(hour1, sizeof(hour1), "%H", tmp1);
	int h1 = atoi(hour1);
	
	if(strcmp(day1, day) == 0)
	{
		if(strcmp(month, month1) == 0)
		{
			if((h - h1) < 2)
			{ chmod("file.txt", S_IWUSR | S_IRUSR); }
		}
	}
	
	printf("\n%s", ctime(&s.st_atime));
	printf("\n%s", ctime(&s.st_mtime));
	printf("\n%s", ctime(&s.st_ctime));
}
