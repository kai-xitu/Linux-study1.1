#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<sys/shm.h>
#include<signal.h>
#include<unistd.h>
#include<sys/ipc.h>
#include<sys/types.h>
struct shmbuf
{ int pid;
  int buf[124];
};

void my(int signum)

{
printf("accept pid success\n ");
	return ;
}
int main()
{
char b;
int pid;
int shmid;
int key;
struct shmbuf  *p;

key=ftok("./4",'b');
if(key<0)
{	printf("creat ftok fail\n");
return -1;
}
printf("creat ftok sucess\n");

shmid=shmget (key,128,IPC_CREAT |0777);
if (shmid<0)
{	printf("creat shmget fail\n");
return -1;
}
printf("creat shmget sucess\n");
signal(SIGUSR2,my);
p=(struct shmbuf*)shmat(shmid,NULL,0);
if (p==NULL)
{	printf("shmat fail\n");
	return -1;
}
printf("shmat sucess\n");


pid=p->pid;
printf("11\n");
p->pid=getpid();
printf("22\n");
kill(pid,SIGUSR1);
printf("33\n");

//fgets(p->buf,128,stdin);
while(1)
{
printf("will start pause\n");

pause();

printf("start read %ls\n",p->buf);
kill(pid,SIGUSR1);
}
shmdt(p);
shmctl(shmid,IPC_RMID,NULL);
}
