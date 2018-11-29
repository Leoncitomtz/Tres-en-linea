#include <stdio.h>
#include <conio.h>

int i,j;
int ganador;
void imprimir_gato(char gato[3][3])
{
    printf("\n_______________________\n");
    for(i=0;i<3;i++)
	{
    	for(j = 0;j < 3; j++)
		{
			printf("|  %c  |",gato[i][j]);
			
		}
		printf("\n");
		printf("_______________________");
		printf("\n");
	}
    
}
quien_gana(char gato[3][3])
{
	ganador=0;
	if ((gato[0][0]=='X')&&(gato[0][1]=='X')&&(gato[0][2]=='X')){ganador=1;}
	if (gato[1][0]=='X'&&gato[1][1]=='X'&&gato[1][2]=='X'){ganador=1;}
	if (gato[2][0]=='X'&&gato[2][1]=='X'&&gato[2][2]=='X'){ganador=1;}
	if (gato[0][0]=='X'&&gato[1][0]=='X'&&gato[2][0]=='X'){ganador=1;}
	if (gato[0][1]=='X'&&gato[1][1]=='X'&&gato[2][1]=='X'){ganador=1;}
	if (gato[0][2]=='X'&&gato[1][2]=='X'&&gato[2][2]=='X'){ganador=1;}
	if (gato[0][0]=='X'&&gato[1][1]=='X'&&gato[2][2]=='X'){ganador=1;}
	if (gato[2][0]=='X'&&gato[1][1]=='X'&&gato[0][2]=='X'){ganador=1;}

		
	if ((gato[0][0]=='O')&&(gato[0][1]=='O')&&(gato[0][2]=='O')){ganador=2;}
	if (gato[1][0]=='O'&&gato[1][1]=='O'&&gato[1][2]=='O'){ganador=2;}
	if (gato[2][0]=='O'&&gato[2][1]=='O'&&gato[2][2]=='O'){ganador=2;}
	if (gato[0][0]=='O'&&gato[1][0]=='O'&&gato[2][0]=='O'){ganador=2;}
	if (gato[0][1]=='O'&&gato[1][1]=='O'&&gato[2][1]=='O'){ganador=2;}
	if (gato[0][2]=='O'&&gato[1][2]=='O'&&gato[2][2]=='O'){ganador=2;}
	if (gato[0][0]=='O'&&gato[1][1]=='O'&&gato[2][2]=='O'){ganador=2;}
	if (gato[2][0]=='O'&&gato[1][1]=='O'&&gato[0][2]=='O'){ganador=2;}
		
}

main(){
	int k=1,fila,columna,opcion;
	char gato[3][3]={' ',' ',' ',' ',' ',' ',' ',' ',' ',};
	printf("                   3 EN LINEA O JUEGO DEL GATO      \n");
	printf("El juego del gato conciste en un tablero de tres por tres, en el que se tendra que llenar cada casilla con una X o un O");
	printf("\n\nInstrucciones:\n-En su turno el jugador escoge una casilla vacía del tablero y coloca su figura en esa casilla escribiendo un número de fila seguido con un espacio y anotando posteriormente el número de la columna.\n-Termina su turno cuando acaba de dibujar su figura en la casilla.\n-No se puede: cambiar de figura ni colocar una figura en una casilla ya ocupada por cualquier figura.\n");
	printf("\nFinal del Juego:\n-GANA el jugador que logre poner 3 figuras en una línea (vertical, horizontal o diagonal). Se tacha con una línea recta las 3 figuras que forman la línea ganadora.\n-EMPATE: en el caso de que se ocupen todas las casillas y ningún jugador haya realizado una línea recta, se declara empate y se juega una nueva partida.");
	printf("\n-Las casillas estan enumeradas en 3 x 3 tanto fila como en columna");
	printf("\n-Ejemplo: si queremos elegir la primera casilla tendríamos que poner '1 1' y se marcará la casilla elegida");
	do
	{
		printf("\n\nÉste es el tablero");
		imprimir_gato(gato);
		do
		{
			
			printf("\nÉste es el turno numero %d",k);
			if(k%2 !=0)
			{
				do
				{
					do
					{
						printf("\nEs turno del jugador 1");
						printf("\nPor favor ingrese las coordenadas de la casilla que quiere\n");
						scanf("%d",&fila);
						scanf("%d",&columna);
						if (fila > i ||columna>3)
						{
							printf("\nÉsta coordenada ya ha sido usada o no existe en el tablero");
						}
					}
					while (fila >4||columna>4);	
				}
				while(gato[fila-1][columna-1]!=' ');
				gato[fila-1][columna-1]='X';
				imprimir_gato(gato);
				quien_gana(gato);	
			}
			if (k%2 == 0)
			{
				do
				{
					do
					{
						printf("\nEs turno del jugador 2");
						printf("\nPor favor ingrese las coordenadas de la casilla que quiere\n");
						scanf("%d",&fila);
						scanf("%d",&columna);
						if (fila > i ||columna>3)
						{
							printf("\nEsta coordenada ya ha sido usada o no existe en el tablero");
						}
					}
					while(fila>4 ||columna>4);
				}
				while (gato[fila-1][columna-1]!=' ');
				gato[fila-1][columna-1]='O';
				imprimir_gato(gato);
				quien_gana(gato);	
			}
			k=k+1;	
		}
		while (k<10 && ganador==0);
		if (ganador==1)
			{
				printf("\nEl ganador es el jugador 1");
			}
			if (ganador==2)
			{
				printf("\nEl ganador es el jugador 2");
			}
			if (ganador ==0)
			{
				printf("\nEsto es un empate");
			}
	printf("\n¿Quieres jugar de nuevo? Pulsa 1 para volver a jugar");
	scanf("\n%d",&opcion);
	k=1;
	for (i=0;i<3;i++)
	{
		for(j=0;j<3;j++)
		{
			gato[i][j]=' ';
		}
	}
	}
	while (opcion==1);
			
	getch();		
	return 0;	
	}