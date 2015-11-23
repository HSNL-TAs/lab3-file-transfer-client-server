#include <sys/types.h>
#include <sys/stat.h>
#include <sys/socket.h>
#include <sys/time.h>
#include <time.h>
#include <netinet/in.h>
#include <stdio.h>
#include <string.h>
#define MAXSIZE 2048

void client_fun (int sockfd) {
    char filename[MAXSIZE+1];
    char recvline[MAXSIZE+1]; /* variable to store data from server*/
    char path[MAXSIZE+1];
    int fileSize = 0, count = 0, n = 0;
    FILE *fp;

    /*create download dir*/
    sprintf(path, "./Download");
    mkdir(path, S_IRWXU|S_IRWXG|S_IROTH|S_IXOTH);
	
    /*
        TODO:
        Read file list from server.
    */

    printf("-----------\nEnter the filename:\n");
    while ((n = scanf(" %s", filename)) > 0) {
        if (strcmp(filename, ".exit") == 0) {
            break;
        }

        /**
            TODO:
            Send requested fileName to server.
        **/

        /*receive start message from server*/
        read(sockfd, recvline, MAXSIZE);
        printf("%s", recvline);

        /*receive file size*/
        read(sockfd, recvline, MAXSIZE);
        fileSize = atoi(recvline);

        /*receive file*/
        memset(path, '\0', MAXSIZE+1);
        n = 0;
        sprintf(path, "./Download/%s", filename);
        if ((fp = fopen(path, "wb+")) == NULL) {
            printf("Fail to allocate memory\n");
        }
        else {
            while ((count += n) < fileSize) {
                memset(recvline, '\0', MAXSIZE+1);
                
                /**
                    TODO:
                    Receive data from server and store it into recvline variable using read function.
                **/
				
                /* write file to local disk.*/
                fwrite(&recvline, sizeof(char), n, fp);
            }
            fclose(fp);
            /*receive download complete message*/
            memset(recvline, '\0', MAXSIZE+1);
            read(sockfd, recvline, MAXSIZE);
            printf("%s", recvline);
        }
    }
    printf("socket closed!\n");
}


int main (int argc, char **argv) {
    int sockfd, n;
    char recvline[MAXSIZE+1];
    struct sockaddr_in servaddr;

    if ((sockfd = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
        printf("socket error");
    }

    bzero(&servaddr, sizeof(servaddr));
    servaddr.sin_family = /*Protocol stack*/;
    servaddr.sin_port = /*Bind port on 8888*/;
    if (inet_pton(AF_INET, argv[1] ,&servaddr.sin_addr) <= 0) {
        printf("inet_pton error for %s", argv[1]);
        return 0;
    }

    printf("Connect to server.\n");
    if (connect(sockfd, (struct sockaddr *)&servaddr, sizeof(servaddr)) < 0) {
        printf("connect error");
        return 0;
    }

    client_fun(sockfd);
    close(sockfd);
    return 0;
}
