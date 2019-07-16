
/**************************************************************************************************************
 **文件:client.c
 **编写者:huangminqiang
 **编写日期:2012年11月1号
 **简要描述:UDP客户端
 **修改者:
 **修改日期:2012年11月5号
 **注:
 **************************************************************************************************************/
#include <sys/types.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <stdio.h>
#include <errno.h>

#define IP "192.168.1.15"
#define PORT 6666

int main(void)
{
	int cnt = -1;
	int sfd = -1;
	int len = -1;
	struct sockaddr_in ser_addr;
	char buf[128] = {0};
	char client_buf[128] = {0};

	//socket
	sfd = socket(AF_INET, SOCK_DGRAM, 0);
	if(0 > sfd)
	{
		perror("socket error:");
		goto _out;
	}

	//init
	ser_addr.sin_family = AF_INET;
	ser_addr.sin_port = htons(PORT);
	ser_addr.sin_addr.s_addr = inet_addr(IP);

	while(1)
	{
		len = sizeof(struct sockaddr);
		//sendto
		{
			//client_buf
			fgets(client_buf, sizeof(client_buf), stdin);
		}
		cnt = sendto(sfd, client_buf, sizeof(client_buf), 0, (struct sockaddr *)&ser_addr, len);
		if(0 > cnt)
		{
			perror("sendto error:");
			goto _out;
		}
printf("cnt = %d\n",cnt);
		//recvfrom
		/*cnt = recvfrom(sfd, buf, sizeof(buf), 0, (struct sockaddr *)&ser_addr, &len);
		if(0 > cnt)
		{
			perror("received error:");
			goto _out;
		}
*/
		printf("buf = %s\n",buf);
	}
	
	//close
	close(sfd);
	return 0;
_out:
	return -1;
}
