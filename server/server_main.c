#include "server.h"

int main() {
	init_server();//��ʼ����������
	
	int tid;
	pthread_create(&tid, NULL, listen_thread_function, NULL);//���������׽����߳�
	pthread_create(&tid, NULL, send_thread_function, NULL);//�����µ��߳��������û��ĵ�½

	char command[1024];
	while(1) {
		scanf("%s", command);
		exec_cmd(command);
	}
}