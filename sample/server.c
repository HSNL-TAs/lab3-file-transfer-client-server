#include <sys/socket.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <stdio.h>
#include <string.h>
#include <netinet/in.h>
#include <unistd.h>
#include <errno.h>
#include <dirent.h>

#define MAXSIZE 2048

void download_fun (int sockfd) {
    int n;
    int fileSize = 0, byteNum = 0, count = 0;
    char filename[MAXSIZE+1], buf[MAXSIZE+1];
    char *fail="download failed!\n";
    FILE *fp;
    struct dirent* ent = NULL;
    DIR *pDir;

    memset(buf, '\0', MAXSIZE+1);
    memset(filename, '\0', MAXSIZE+1);
    /*send file list*/
    sprintf(buf, "%s", "Server reply!\nFiles on server:\n");
    if (write(sockfd, buf, strlen(buf)) == -1) {
        printf("write failed!\n");
    }

    /*travelling files and sending to client*/
    if ((pDir=opendir("./")) == NULL) {
        printf("open dir failed\n");
        return;
    }

    while ((ent=readdir(pDir)) != NULL) {
        if (strcmp(ent->d_name, ".") == 0  || strcmp(ent->d_name, "Download") == 0 || strcmp(ent->d_name, "..") == 0) {
            continue;
        }
        memset(buf, '\0', MAXSIZE+1);
        sprintf(buf, "%s\n", ent->d_name);
        /*
        	TODO
        	write a filename to client
        */
		
    }

    closedir(pDir);
    /*End of travelling files and sending to client*/

    while ((n = read(sockfd, filename, MAXSIZE)) > 0) {
        /*do string comparison*/
        if (strcmp(filename, ".exit") == 0) {
            break;
        }
        fp = fopen(filename, "rb+");
        if (fp) {
            /*send start message*/
            memset(buf, '\0', MAXSIZE+1); /*clean buff*/
            sprintf(buf, "Downloading %s...\n", filename);
            if (write(sockfd, buf, MAXSIZE) == -1) {
                printf("send failed!");
                continue;
            }

            /*get file size, store in fileSize.*/
            fseek(fp, 0, SEEK_END);
            fileSize = ftell(fp);
            rewind(fp);
            /*end of get file size, store in fileSize.*/
			
            memset(buf, '\0', MAXSIZE+1);
            sprintf(buf, "%d\n", fileSize);

            /**
                TODO:
                Send file size to client.
            **/

            byteNum = 0;
            /*read file and send to client*/
            while ((count += byteNum) < fileSize) {
                memset(buf, '\0', MAXSIZE+1);
                /*Read local file to buf*/
                byteNum = fread(&buf, sizeof(char), MAXSIZE, fp);
				
                /**
                    TODO:
                    send buf variable(file data) to client.
                    do error detection if writing to client failed.
                **/
               
            }

            fclose(fp);

            /*send download successful message*/
            /*sleep for a while.*/
            sleep(1);
            memset(buf, '\0', MAXSIZE+1);
            sprintf(buf, "%s", "Download successfully!\n");
            write(sockfd, buf, MAXSIZE);
        }
        else {
            /* fp is null*/
            write(sockfd, fail, strlen(fail));
        }
    }

    printf("socket closed\n");
    close(sockfd);
}


int main(int argc, char **argv) {
    int listenid; /*listen socketfd*/
    int clientfd /*accepted client socketfd*/
    int port;
    socklen_t clilen;
    struct sockaddr_in servaddr, cliaddr;

    listenid = socket(AF_INET, SOCK_STREAM, 0);
    bzero(&servaddr, sizeof(servaddr));
    servaddr.sin_family = /*Protocol stack*/;
    servaddr.sin_addr.s_addr = htonl(INADDR_ANY);
    servaddr.sin_port = /*Bind port on 8888*/;
	
    /**
        TODO:
        bind port
    **/
  	
    /**
        TODO:
        listen socket
    **/
	
    clilen = sizeof(struct sockaddr_in);
    for (;;) {
        /**
            TODO:
            waiting for a client using accept function
        **/
		
		
        download_fun(clientfd);
    }

    return 0;
}
