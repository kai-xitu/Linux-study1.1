#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<sys/shm.h>
#include<signal.h>
#include<unistd.h>
#include<sys/ipc.h>
#include<sys/types.h>
struct shmbuf
{ char pid;
int buf[124];
};

void my(int signum)
{
printf("accept pid succes\n ");
	return ;
}
int main()
{
char b;
int pid;
int shmid;
int key;
struct shmbuf *p;

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
signal(SIGUSR1,my);
p=(struct shmbuf*)shmat(shmid,NULL,0);
if (p==NULL)
{	printf("shmat fail\n");
	return -1;
}
printf("shmat sucess\n");

p->pid=getpid();
printf("11\n");
pause();
printf("22\n");
pid=p->pid;
printf("33\n");

while(1)
{
printf("start write\n");
fgets(p->buf,128,stdin);
printf("fgets is ok\n");
kill(pid,SIGUSR2);
printf("kill is ok\n");
pause();
}
shmdt(p);
shmctl(shmid,IPC_RMID,NULL);
}
