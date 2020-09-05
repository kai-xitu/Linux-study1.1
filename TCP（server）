#include<stdio.h>
#include<pthread.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/socket.h>
#include<netinet/in.h>
#define MAX_LISTEN 10
int buf[128];
int main()
{
struct sockaddr_in server_ip,remate_ip;
int ad,err,dd;
int server_len,remate_len;
	
printf("start\n");
ad=socket(AF_INET,SOCK_STREAM,0);
if(ad==-1)
	printf("creat socket fail\n");
return ;
server_ip.sin_family=AF_INET;
server_ip.sin_port=htons(1234);
server_ip.sin_addr.s_addr=htonl(INADDR_ANY);
memset(server_ip.sin_zero,0,8);
server_len=sizeof(struct sockaddr);
err=bind(ad,(struct sockaddr*)(&server_ip),server_len);
if(err==-1)
	printf("creat bind fail\n");
//close(ad);
return ;
err=listen(ad,MAX_LISTEN);
if(err==-1)
	printf("creat listen fail\n");
//close(ad);
return ;
remate_len=sizeof(struct sockaddr);
dd=accept(ad,(struct sockaddr*)(&remate_ip),&remate_len);
if(dd==-1)
	printf("creat caccept fail\n");
//close(ad);
return ;

read(dd,buf,128);
printf("buf is %ls\n",buf);   


close(ad);
close(dd);


}
