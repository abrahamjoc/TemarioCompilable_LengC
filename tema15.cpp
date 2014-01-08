/*
 *  Preparador: José Abraham (abrahamjoc@gmail.com)
 *  Diciembre 2013
 *  Asignatura: Sistemas Operativos (LINUX)
 *  
 *  Tema XV: Sockets en Lenguaje C
 * 
 *      La palabra SOCKET significa ENCHUFE en ingles, viene de la
 *  capacidad de poder conectar dos(2) ó más Sistemas Operativos entre sí,
 *  usualmente en distintas computadoras y posiblemente con diferentes 
 *  arquitecturas.
 * 
 *  Los Sockets son cables ficticios que permiten a través de un protocolo
 *  intercambiar STREAM de información entre un equipo local y un equipo
 *  remoto. Uno de estos dos(2) equipos debe ser el anfitrión ( SERVIDOR )
 *  y el otro debe ser el referido a conectarse ( CLIENTE ). Quedando la
 *  permuta de la siguiente forma:
 * 
 * 
 *            1.         __________________     ___________________
 * 			|   Equipo LOCAL   |   |   Equipo REMOTO   |
 * 			'------------------'   '-------------------'
 *                      |                  |   |                   |
 * 			|    SERVIDOR  <---|---|----- CLIENTE      |
 * 			|__________________|   |___________________|
 * 
 * 		
 *            2.         __________________     ___________________
 * 			|   Equipo LOCAL   |   |   Equipo REMOTO   |
 * 			'------------------'   '-------------------'
 *                      |                  |   |                   |
 * 			|     CLIENTE -----|---|---> SERVIDOR      |
 * 			|__________________|   |___________________|
 * 
 * 
 * 
 *  El flujo de la comunicación de los Sockets se basa en la técnología
 *  IP ( Internet Protocol ) que significa Protocolo de Internet, para el
 *  control de dicho flujo se deben tomar cuatro(4) cosas en cuenta:
 * 
 * 		1. Dirección IP Local
 * 		2. Dirección IP Remota
 * 		3. Puerto Local
 * 		4. Puerto Remoto
 * 
 * 
 * 	Requerimientos Locales: 
 *  
 *  	Como estamos usando tecnología basada en redes, debemos asegurarnos
 *  que nuestro equipo esté conectado y configurado perfectamente en el
 *  circuito de red con el que estemos trabajando, eso pasa por verificar
 *  que nuestro SO tenga una dirección IP válida y los permisos necesarios
 *  para el puerto que gestionemos localmente para las comunicaciones.
 *  
 * 
 *  Requerimientos Remotos:
 *  
 * 		Para poder hacer uso de los recursos de la conexión debemos tener
 *  en cuenta que debemos conocer la dirección física IP y el puerto al
 *  que deseamos conectarnos con el otro equipo, esto debido a que los
 *  Sockets gestionan comunicaciones entre parámetros ya conocidos.
 * 
 *  
 *  	La comunicación de los Sockets son bidireccionales entre sí, es
 *  decir el flujo de información puede ir del Cliente al Servidor, como
 *  del Servidor al Cliente, pero para poder establecer la conexión es
 *  necesario que el cliente intente un CONNECT ( conectar ) y el servidor
 *  establezca un ACCEPT ( aceptación ) de la conexión.
 * 
 *  El esquema de conexión quedaría así:
 * 			
 * 			 __________________     ___________________
 * 			|     SERVIDOR     |   |      CLIENTE      |
 * 			'------------------'   '-------------------'
 *                      |    accept(); <---|-1-|---- connect();    |
 *                      |                  |   |                   |
 *                      | IP servidor      |   |     IP cliente    |
 * 			|  PUERTO servidor |   |    PUERTO cliente |
 *                      |                  |   |                   |
 * 			|  stream Serv. <--|-2-|--> stream Client. |
 * 			|__________________|   |___________________|
 * 
 *  1. Se intenta una conexión de parte del cliente con la función
 *     CONNECT y el servidor acepta la conexión con la función ACCEPT.
 * 
 *  2. Luego de aceptar la conexión por parte del servidor, se establece
 *     un buffer de stream en el que se pueden hacer dos(2) cosas:
 * 
 * 		- escribir datos ( enviar información al equipo remoto )
 * 
 * 		- leer datos ( recibir información del equipo remoto )
 * 
 * 
 *  	Existen dos protocolos ampliamente usados de Sockets en la
 *  tecnología IP, estos son:
 * 
 * 		- TCP: Significa Protocolo de Control de Transporte en ingles,
 *             viene de la traducción de Transport Control Protocol, esté
 *             permite realizar una conexión remota con acuse de recibo,
 *             es decir cuando hacemos una conexión podemos determinar si
 *             la información que estamos enviando es o no recibida y
 *             determinar si el estado de la conexión entre los equipos
 *             se encuentra activa.
 * 
 * 		- UDP: Significa Protocolo de Datagramas de Usuario en ingles,
 *             viene de la traducción de User Datagram Protocol, muy al
 *             contrario del TCP, esté protocolo permite realizar una
 *             conexión sin acuse de recibo, es decir podemos enviar
 *             información sin saber si su llegada fue exitosa o no, al
 *             mismo tiempo que podemos esperar que nos llegue información
 *             sin saber en que calidad se pueda encontrar la conexión con
 *             el equipo remoto.
 * 
 *             
 *  El esquema de conexión de los protocolos quedaría así:
 * 
 *  
 * 		TCP	 __________________     ___________________
 * 			|     Equipo 1     |   |     Equipo 2      |
 * 			'------------------'   '-------------------'
 *                      |                  |   |                   |
 * 			|   TCP Envia  ----|-1-|---> TCP Recibe    |
 *                      |                  |   |                   |
 * 			|TCP Recibe Acuse<-|-2-|-- TCP Envia Acuse |
 * 			|__________________|   |___________________|
 * 
 * 				Nota: Toda acción realizada en TCP, es respondida con un
 *                    acuse, si no llega el acuse entonces se ha perdido
 *                    la conexión.
 * 
 * 
 * 		UDP	 __________________     ___________________
 * 			|     Equipo 1     |   |     Equipo 2      |
 * 			'------------------'   '-------------------'
 *                      |                  |   |                   |
 * 			|   UDP Envia -----|-1-|---> UPD Recibe    |
 *                      |                  |   |                   |
 * 			|   UDP Escucha <--|-2-|---- UDP Envia	   |
 * 			|__________________|   |___________________|
 * 
 * 				Nota: Toda acción realizada en UDP, se hace sin saber si
 *                    el equipo con el que estamos comunicandonos recibió
 *                    la información satisfactoriamente, eso porque como
 *                    estamos a la escucha recibimos información sin
 *                    responderla.
 * 
 *  Tópicos:
 *  - servidor TCP/IP
 *  - cliente  TCP/IP
 *  - servidor UDP/IP
 *  - cliente  UDP/IP
 */


#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>
#include <string.h>


/// Prototipos de Función
void ServidorTCP(int puerto);
void ClienteTCP(char ip[16], int puerto);
void ServidorUDP(int puerto);
void ClienteUDP(char ip[16], int puerto);


int main()
{
	printf("Implementacion de SOCKETS en modo:\n\n");
	printf("    1. TCP Servidor\n");
	printf("    2. TCP Cliente\n");
	printf("    3. UDP Servidor\n");
	printf("    4. UDP Cliente\n");
	
	char opc = ' ';
	
	while ( opc!='1' && opc!='2' && opc!='3' && opc!='4' )
	
		scanf("%c",&opc);
	
	getc(stdin);
	
	switch ( opc )
	{
		char ip[16];
		
		int puerto;
		
		case '1': 
				
			printf("\nTCP Servidor:\nPuerto: ");
			
			scanf("%d", &puerto);
			
			getc(stdin);
			
			ServidorTCP(puerto);
			
			break;
			
		case '2':
			
			printf("\nTCP Cliente:\n");
			
			printf("IP: "); scanf("%s", ip); getc(stdin);
			
			printf("Puerto: "); scanf("%d", &puerto); getc(stdin);
			
			ClienteTCP(ip,puerto);
			
			break;
			
		case '3':
		
			printf("\nUDP Servidor:\nPuerto: ");
			
			scanf("%d", &puerto);
			
			getc(stdin);
			
			ServidorUDP(puerto);
			
			break;
			
		case '4':
		
			printf("\nUDP Cliente:\n");
			
			printf("IP: "); scanf("%s", ip); getc(stdin);
			
			printf("Puerto: "); scanf("%d", &puerto); getc(stdin);
			
			ClienteUDP(ip,puerto);
			
			break;		
	}
	
	return 0;
}


/// TCP/IP Servidor Socket
void ServidorTCP(int puerto)
{
	int sock;
	
	int bytesRecibidos;
	
	int conectado;
	
	int hayConexion = 1;
	
	char datosEnviar[1024];
	
	char datosRecibir[1024];
	
	struct sockaddr_in servidor_addr;
	
	struct sockaddr_in cliente_addr;

	int sin_tam;
	
	if ( (sock = socket(AF_INET, SOCK_STREAM, 0)) == -1 ) 
	{
		printf("Error al iniciar Socket...\n");
		
		exit(1);
	}
	
	if ( setsockopt(
			sock,SOL_SOCKET,SO_REUSEADDR,&hayConexion,sizeof(int)
		 ) == -1 )
	{
		printf("Error al Configurar el Socket con SetSocketSockOpt...\n");
		
		exit(1);
	}
	
	servidor_addr.sin_family = AF_INET;         
    servidor_addr.sin_port = htons(puerto);
    servidor_addr.sin_addr.s_addr = INADDR_ANY; 
    bzero(&(servidor_addr.sin_zero),8); 
    
     if ( bind(
			sock,(struct sockaddr*)&servidor_addr,sizeof(struct sockaddr)
		  ) == -1 )
	{
		printf("Servidor no es capaz de Enlazar...\n");
        
        exit(1);
    }
    
    if ( listen(sock, 5) == -1)
    {
		printf("Servidor no es capaz de Escuchar...\n");
		
		exit(1);
	}
	
	printf("\nServidor TCP iniciado...\n");
	printf("Esperando por cliente en el puerto %d.\n", puerto);
	
	while ( true )
    {
		sin_tam = sizeof(struct sockaddr_in);
		
		conectado = accept(sock,(struct sockaddr*)&cliente_addr,
						  (socklen_t*)&sin_tam);
						  
		printf("Conexion Entrante de (%s , %d)\n",
			inet_ntoa(cliente_addr.sin_addr),ntohs(cliente_addr.sin_port));
		
		
		while ( true )
		{
			printf("Enviar (q or Q para cerrar) : ");
			gets(datosEnviar);
			 
			if ( 
					strcmp(datosEnviar,"q") == 0 ||
					strcmp(datosEnviar,"Q") == 0
				)
			{
				send(conectado, datosEnviar, strlen(datosEnviar), 0); 
                
                close(conectado);
                
                close(sock);
                
                printf("Servidor TCP terminado...\n");
                
                exit(1);
			}
			
			else
			{
				send(conectado, datosEnviar, strlen(datosEnviar), 0);
				
				printf("Enviado...\n");
			}
			
			printf("Esperando por recepcion de datos...\n");
			
			bytesRecibidos = recv(conectado, datosRecibir, 1024, 0);
			
			datosRecibir[bytesRecibidos] = '\0';
			
			if ( 
					strcmp(datosRecibir,"q") == 0 ||
					strcmp(datosRecibir,"Q") == 0
				)
			{
				close(conectado);
				
				close(sock);
				
				printf("\nServidor TCP terminado...\n");
                
                exit(1);
			}
			
			else 
              
              printf("\nDatos Recibidos  ->  %s\n", datosRecibir);
		}
	}
}


/// TCP/IP Cliente Socket
void ClienteTCP(char ip[16], int puerto)
{
	int sock;
	
	int bytesRecibidos;
	
	char datosEnviar[1024];
	
	char datosRecibir[1024];
	
	struct hostent *host;
	
	struct sockaddr_in servidor_addr;
	
	host = gethostbyname(ip);
	
	if ( (sock = socket(AF_INET, SOCK_STREAM, 0)) == -1 ) 
	{
		printf("Error al iniciar Socket...\n");
		
		exit(1);
	}
	
    servidor_addr.sin_family = AF_INET;
    servidor_addr.sin_port = htons(puerto);
    servidor_addr.sin_addr = *((struct in_addr *)host->h_addr);
    bzero(&(servidor_addr.sin_zero),8);
    
    if ( connect(
			sock,(struct sockaddr*)&servidor_addr,sizeof(struct sockaddr)
		) == -1 ) 
    {
		printf("Error al realizar Connect...\n");
		
		exit(1);
	}
	
	printf("Conexion exitosa con el Servidor TCP...\n");
	
	while ( true )
	{
		printf("Esperando por recepcion de datos...\n");
		
		bytesRecibidos = recv(sock, datosRecibir, 1024, 0);
			
		datosRecibir[bytesRecibidos] = '\0';
		
		if (
				strcmp(datosRecibir,"q") == 0 ||
				strcmp(datosRecibir,"Q") == 0
			)
		{
			close(sock);
			
			printf("\nCliente TCP terminado...\n");
			
			exit(1);
		}
		
		else 
              
              printf("\nDatos Recibidos  ->  %s\n", datosRecibir);
        
        printf("Enviar (q or Q para cerrar) : ");
		gets(datosEnviar);
		
		if (
				strcmp(datosEnviar,"q") == 0 ||
				strcmp(datosEnviar,"Q") == 0
			)
		{
			send(sock, datosEnviar, strlen(datosEnviar), 0);
			
			close(sock);
			
			printf("\nCliente TCP terminado...\n");
			
			exit(1);
		}
		
		else
		{
			send(sock, datosEnviar, strlen(datosEnviar), 0);
			
			printf("Enviado...\n");
		}
	}
}


/// UPD/IP Servidor Socket
void ServidorUDP(int puerto)
{
	int sock;
	
	int addr_tam;
	
	int bytesRecibidos;
	
    char datosRecibir[1024];
    
    struct sockaddr_in servidor_addr;
	
	struct sockaddr_in cliente_addr;

    if ( (sock = socket(AF_INET, SOCK_DGRAM, 0)) == -1 )
    {
		printf("Error al iniciar Socket...\n");
		
		exit(1);
	}
	
	servidor_addr.sin_family = AF_INET;
    servidor_addr.sin_port = htons(puerto);
    servidor_addr.sin_addr.s_addr = INADDR_ANY;
    bzero(&(servidor_addr.sin_zero),8);
    
    if ( bind(
		   sock,(struct sockaddr*)&servidor_addr, sizeof(struct sockaddr)
		 ) == -1 )
    {
		printf("Error al escuchar Socket...\n");
		
		exit(1);
	}
	
	addr_tam = sizeof(struct sockaddr);
		
	printf("Esperando por recepcion de datos...\n");
    
    fflush(stdout);

	while ( true )
	{
		bytesRecibidos = recvfrom(
							sock, datosRecibir, 1024, 0,
							(struct sockaddr *)&cliente_addr,
							(socklen_t*)&addr_tam);
	  

		datosRecibir[bytesRecibidos] = '\0';
		
		printf("\n(%s , %d) said : ", inet_ntoa(cliente_addr.sin_addr),
                                       ntohs(cliente_addr.sin_port));
		
		printf("%s", datosRecibir);
		
		fflush(stdout);
	}
}


/// UDP/IP Cliente Socket
void ClienteUDP(char ip[16], int puerto)
{
	int sock;
	
	struct sockaddr_in servidor_addr;
	
	struct hostent *host;
	
	char datosEnviar[1024];

	host = (struct hostent*) gethostbyname((char *)ip);

	if ( (sock = socket(AF_INET, SOCK_DGRAM, 0)) == -1 )
	{
		printf("Error al iniciar Socket...\n");
		
		exit(1);
	}

	servidor_addr.sin_family = AF_INET;
	servidor_addr.sin_port = htons(puerto);
	servidor_addr.sin_addr = *((struct in_addr *)host->h_addr);
	bzero(&(servidor_addr.sin_zero),8);
	
	while ( true )
	{
		printf("Enviar (q or Q para cerrar) : ");
		gets(datosEnviar);
		
		if ( 
				(strcmp(datosEnviar , "q") == 0) || 
				(strcmp(datosEnviar , "Q") == 0)
		   )
				
				break;

		else
		
		   sendto(sock, datosEnviar, strlen(datosEnviar), 0,
				 (struct sockaddr*)&servidor_addr, 
				  sizeof(struct sockaddr));
	   }
}
