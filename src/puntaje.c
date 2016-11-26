#include "header.h"
void OrdenarPuntaje(Puntaje *puntaje)
{

  int i=1,A=100,j=0,s=0,n;


  do
  {
    j=0;
    do
    {
      if(puntaje[j].score<puntaje[j+1].score)
      {
        n=puntaje[j].score;
        puntaje[j].score=puntaje[j+1].score;
        puntaje[j+1].score=n;
      }

      j++;
    }while(j<A-i);

  i++;
  }while(i<=A );

}
int MostrarPuntaje(int sockfd, ALLEGRO_FONT *fuente)
{
  FILE *error;
  error=fopen("./datos/errores","a");
  int i=0,a=20,b=20,n;
  char buffer[20]="pepe",salir[6]="salir";
  Puntaje puntaje[100];
	for(i=0;i<100;i++)
	{
		puntaje[i].score=0;
	}
	i=0;
  al_clear_to_color(al_map_rgb(0,0,0));

   while(strcmp(buffer,salir)!=0 && i!=100)
  {

    memset(buffer,0,20);

    n=read(sockfd,buffer,10);
   if(strncmp(buffer,salir,5)==0)
	break;
    n=write(sockfd,"OK",2);

    if (n < 0)
    {
          fprintf(error,"Error escribiendo al socket \n");
 	        return ERROR;
    }


   puntaje[i].score=atoi(strtok(buffer,";"));
    strcpy(puntaje[i].nombre,strtok(NULL,"\n"));
  i++;

  }
  OrdenarPuntaje(puntaje);
  i=0;
 while(i<20)
  {
    al_draw_textf(fuente,al_map_rgb(100,100,255),a,b,0,"%s: %d",puntaje[i].nombre,puntaje[i].score);
        b+=20;
        i++;
  }
  al_flip_display();

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

    sprintf(buffer,"%d;%s",puntaje,iniciales);
    n = write(sockfd,buffer,strlen(buffer));

    if (n < 0)
    {
          fprintf(error,"Error escribiendo al socket \n");
          return ERROR;
    }

  if(ERROR==MostrarPuntaje(sockfd,fuente))
  {
    return ERROR;
  }
   close(sockfd);
   fclose(error);
    return 0;
}
