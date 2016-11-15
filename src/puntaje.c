#include "header.h"
int MostrarPuntaje(int sockfd, ALLEGRO_FONT *fuente)
{
  FILE *error;
  error=fopen("./datos/errores","a");
  int i=0,a=20,b=20,n;
  char buffer[20]="pepe",salir[6]="salir";
  al_clear_to_color(al_map_rgb(0,0,0));
//  fprintf(stderr, "hola");
 while(strcmp(buffer,salir)!=0)
  {
//  fprintf(stderr, "hola");

    memset(buffer,0,20);
 // fprintf(stderr, "hola");
    n=read(sockfd,buffer,strlen(buffer));
//  fprintf(stderr, "hola");
    fprintf(stderr, "%s\n\n\n\n",buffer);
//	fgets(buffer,5,f);
    if (n < 0)
    {
          fprintf(error,"Error escribiendo al socket \n");
          return ERROR;
    }

    al_draw_textf(fuente,al_map_rgb(100,100,255),a,b,0,buffer);
    i++;
    a+=20;
  //  b+=20;
  }
  while(i<20)
  {
    printf("2\n\n\n\n\n");

    al_draw_textf(fuente,al_map_rgb(100,100,255),a,b,0,"..");
        a+=20;
  }
  al_flip_display();
printf("llegure\n\n\n\n\n");

  al_rest(10.0);
}
int MandarPuntaje(int puntaje, int puerto,char *iniciales,char *ip, ALLEGRO_FONT *fuente)
{
    int sockfd, portno, n;
    struct sockaddr_in serv_addr;
    struct hostent *server;
    FILE *error;
	  error=fopen("./datos/errores","a");
    char buffer[20];
    //fprintf(error,"El host no se mando \n");
  /*  if (ip==NULL) {
       exit(0);
    }*/

    portno = puerto;
    sockfd = socket(AF_INET, SOCK_STREAM, 0);

    if (sockfd < 0)
    {
          fprintf(error,"Error abriendo socket\n");
          return ERROR;

    }

    server = gethostbyname(ip);

    if (server == NULL)
    {
      fprintf(error,"Error no existe ese host \n");
        return ERROR;
    }

    memset((void *) &serv_addr, '\0', sizeof(serv_addr));

    serv_addr.sin_family = AF_INET;

    bcopy((char *)server->h_addr,
         (char *)&serv_addr.sin_addr.s_addr,
         server->h_length);

    serv_addr.sin_port = htons(portno);

    if (connect(sockfd,(struct sockaddr *) &serv_addr,sizeof(serv_addr)) < 0)
    {
          fprintf(error,"Error conectandose \n");
          return ERROR;
    }
    //printf("Escriba su mensaje: ");

  //  memset((void *) buffer, '\0', 256);
    //fgets(buffer,255,stdin);
    sprintf(buffer,"%d;%s",puntaje,iniciales);
    n = write(sockfd,buffer,strlen(buffer));

    if (n < 0)
    {
          fprintf(error,"Error escribiendo al socket \n");
          return ERROR;
    }
  //memset((void *) buffer, '\0', 256);
  //  n = read(sockfd,buffer,255);

  /*  if (n < 0)
    {
         fprintf(error,"Error leyendo desde el socket \n");
         return ERROR;
    }*/
  if(ERROR==MostrarPuntaje(sockfd,fuente))
  {
    return ERROR;
  }
   close(sockfd);
   fclose(error);
    return 0;
}
