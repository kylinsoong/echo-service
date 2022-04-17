#include <stdio.h>
#include <sys/types.h>
#include <sys/socket.h>

int sockbufsize = 1000; 
int trans;

int main(int argc, char **argv)
{

    int sockrcvbuf, socksndbuf;
    unsigned int rcvm = sizeof(sockrcvbuf);
    unsigned int sndm = sizeof(socksndbuf);
    int fdsocket = socket(AF_INET, SOCK_STREAM, 0);
    getsockopt(fdsocket,SOL_SOCKET,SO_SNDBUF,(void *)&socksndbuf, &sndm);
    getsockopt(fdsocket,SOL_SOCKET,SO_RCVBUF,(void *)&sockrcvbuf, &rcvm);
    

    if(sockbufsize) {
        if(trans)
            sockrcvbuf = sockbufsize;
        else
            socksndbuf = sockbufsize;
    }

    printf("sock_sndbuf_size=%d, sock_rcvbuf_size=%d\n", socksndbuf, sockrcvbuf);
    
    return 0;
}

