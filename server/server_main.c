#include "server.h"

int main() {
	init_server();//初始化服务器端
	
	int tid;
	pthread_create(&tid, NULL, listen_thread_function, NULL);//创建监听套接字线程
	pthread_create(&tid, NULL, send_thread_function, NULL);//创建新的线程来接收用户的登陆

	char command[1024];
	while(1) {
		scanf("%s", command);
		exec_cmd(command);
	}
}