#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>


void error(const char *msg)
{
    printf("%s\n",msg);
    exit(1);
}

int main(int argc, char *argv[])
{
     int sockfd, newsockfd, portno;
     socklen_t clilen;
     char buffer[20];
     char salir[6]="salir",ok[2]="OK";
     struct sockaddr_in serv_addr, cli_addr;
     int n,arch;
     int uno=1,i=0;
	FILE *f;
	f=fopen("puntajes","a+");



     if (argc < 2)
     {
         fprintf(stderr,"ERROR, no port provided\n");
         exit(1);
     }
     while(salir)
     {

       sockfd = socket(AF_INET, SOCK_STREAM, 0);

       if (sockfd < 0)
          error("ERROR opening socket");
          if(setsockopt(sockfd, SOL_SOCKET, SO_REUSEADDR, (void*)&uno,(socklen_t)(sizeof(uno))))
          error("error opciones de socket");
          // Armando la estructura "sockaddr_in"
          portno = atoi(argv[1]);
          serv_addr.sin_family = AF_INET;
          serv_addr.sin_addr.s_addr = INADDR_ANY;
          serv_addr.sin_port = htons(portno);
          memset((void *) &(serv_addr.sin_zero), '\0', 8); // Poner a cero el resto de la estructura

       if (bind(sockfd, (struct sockaddr *) &serv_addr, sizeof(serv_addr)) < 0)
              error("ERROR on binding");

      listen(sockfd,5);

      clilen = sizeof(cli_addr);


      printf("Esperando conexiones...\n");
      // Llamado bloqueante a accept()
      newsockfd = accept(sockfd, (struct sockaddr *) &cli_addr, &clilen);
      if (newsockfd < 0)
           error("ERROR on accept");

      memset((void *) buffer, '\0', 20);

      n = read(newsockfd,buffer,20);
      if(strncmp("-1;a",buffer,4)!=0)
      {
      if (n < 0) error("ERROR reading from socket");

     fputs(buffer,f);

     fputs("\n",f);
    }
     rewind(f);


     while(!feof(f)  )
      {
        fgets(buffer,20,f);

	 n = write(newsockfd,buffer,strlen(buffer));
        if (n < 0) error("ERROR writing to socket");
        n=read(newsockfd,ok,2);
	 if(strncmp("OK",ok,2)!=0)
	  	fprintf(stderr,"error\n\n");

      }
    n = write(newsockfd,salir,strlen(salir));
    sleep(2);
  }
	 close(newsockfd);
	 close(sockfd);
	 fclose(f);
     return 0;
}
