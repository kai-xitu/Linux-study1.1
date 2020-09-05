#include<stdio.h>
#include<string.h>
#include<unistd.h>
#include<dirent.h>
#include<fcntl.h>
#include<sys/types.h>
int main ()
{	
DIR*bp;
struct dirent*dir;
char server[128]={0};
char readbuf[128]={0};
char file[128]={0};
FILE * src_a,*des_a;

start:
printf("input server and directory name\n");
scanf("%s",server);
bp=opendir(server);
if (bp==NULL)
{
printf("open the server: %s fail\n",server);
goto start;
}
printf("open the server: %s sucess\n",server); //输入服务器和本地文件夹
//
while(1)
{
dir=readdir(bp);
 if(dir!=NULL)
printf("inode %ld\t,name %s\n",dir->d_ino,dir->d_name);
 else  break;
}//显示文件号和文件名
//
scanf ("%s",file);
src_a=fopen(file,"a+");
if (src_a=NULL)
{	
printf("open  download the %s failure \n" ,file);
return -1;
}
printf ("open download the %s sucess\n",file);//打开目录内一个需要下载的文件

des_a=fopen(file,"w+");
if (des_a=NULL)
{	printf("creat %s fail\n",file);
return -2;
}
else  printf("creat %s sucess\n",file);

while (1)
{	
fgets(readbuf,128,src_a);
if(feof(src_a))
{	printf("sucess\n");
	break;
}
fputs(readbuf,des_a);
}
fclose(src_a);
fclose(des_a);
closedir(bp);
return 0;
}
