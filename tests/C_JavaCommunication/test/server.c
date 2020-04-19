#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <limits.h>
#include <fcntl.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#define SERVER_W "serverWrite"
#define SERVER_R "serverRead"

int main()
{
    printf("begin\n");
    //服务端读写文件描述符
    int fd_w,fd_r;
    //服务端读写管道
    int pid_w,pid_r;
    //读写数组
    char msg_w[BUFSIZ],msg_r[BUFSIZ];
    //进程id
    pid_t pid;

    //首先要检查文件的存在性
    //access 存在返回0，不存在返回-1
    //写管道
    if(access(SERVER_W,0) < 0){
        //文件不存在，创建管道
        pid_w = mkfifo(SERVER_W,0700);
        if(pid_w < 0){
            perror("server create write_pipe failed:");
            return 0;
        }
        printf("create %s success\n",SERVER_W);
    }
    //存在则打开管道
    fd_w = open(SERVER_W,O_RDWR);
    if(fd_w < 0){
        perror("open pipe failed");
    }
    printf("open pipe success\n");

    //读管道
    if(access(SERVER_R,0) < 0){
        //文件不存在，创建管道
        pid_r = mkfifo(SERVER_R,0700);
        if(pid_r < 0){
            perror("create read_pipe failed");
            return 0;
        }
         printf("create %s success\n",SERVER_R);
    }
    //存在则打开
    fd_r = open(SERVER_R,O_RDWR);
    if(fd_r < 0){
        perror("open read_pipe failed");
    }
    printf("open read_pipe success\n");

    printf("communication start\n");

    pid = fork();
    if(pid < 0){
        perror("son process create failed\n");
    }else if(pid == 0){
        //子进程用于父持续读
        printf("server son process start\n");
        printf("\n---------------------server can receive message\n");
        while(1){
            if( read(fd_r,msg_r,BUFSIZ) == -1 ){
                perror("server read message failed");
            }else{
                if( strlen(msg_r) > 0 ){
                    printf("****************server read message:%s\n",msg_r);
                    if (strcmp("EOF",msg_r) == 0){
                        printf("server lost end of read\n");
                        break;
                    }
                }else{
                    printf("no message to read\n");
                }
                printf("server finish read message\n\n");
            }
        }//while

        printf("---------------------son process end\n");
        _exit(0);
    }else{
        //父进程用于持续写
        printf("father process start\n");
        printf("\n---------------------server can write message\n");
        while(1){
            scanf("%s",msg_w);

            if ( write(fd_w,msg_w,strlen(msg_w)+1) == -1){
                perror("server send message failed");
            }else{
                printf("****************server sent:%s\n",msg_w);
                printf("server write finished\n\n");
                if (strcmp("EOF",msg_w) == 0){
                    break;
                }
            }
        }//while

        printf("---------------------server father process end write finished\n");
        wait(NULL);
    }

    //关闭文件
    close(fd_w);
    printf("close write_pipe\n");
    close(fd_r);
    printf("close read_pipe\n");
    printf("end of programme\n");
    return 0;
}
