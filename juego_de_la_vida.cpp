#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<time.h>
int main()
{
	int generaciones,vecinos,generacion=1,filas,columnas;
	int xR, xE, yH, yL;
	puts("NUMERO DE GENERACIONES");
	scanf("%d",&generaciones);
	printf("********JUEGO DE LA VIDA CON %d GENERACIONES********\n",generaciones);

	//DECLARACION DE MI TABLERO
	filas=15; columnas=20;
	int tablero[filas][columnas];
	int tablero_1[filas][columnas];
	
	//RELLENA TABLERO CON CEROS
	for(int x=0; x<filas; x++)
	{
		for(int y=0; y<columnas; y++)
		{
			tablero[x][y]=0;
		}	
	}
	
	/*
	//RELLENA TABLERO CON UNOS ALEATORIOS
	srand(time(NULL));
	for(int i=0;i<filas;i++)
	{
		int x=rand()%filas+1; //NUMERO DE LAS FILAS
		int y=rand()%columnas+1; //NUMERO DE LAS COLUMNAS
		if(tablero[x][y]==1)
		{
			i--;
		}else
		{
			tablero[x][y]=1;
		}
	}*/
	
	//PATRON MIO
	tablero[10][3]=1;tablero[10][4]=1;tablero[9][5]=1;tablero[11][5]=1;tablero[10][6]=1;
	tablero[10][7]=1;tablero[10][8]=1;tablero[10][9]=1;tablero[9][10]=1;tablero[11][10]=1;tablero[10][11]=1;tablero[10][12]=1;
	
	tablero[1][1]=1;tablero[1][2]=1;tablero[1][3]=1;tablero[1][5]=1;tablero[1][6]=1;tablero[1][7]=1;tablero[1][9]=1;tablero[1][11]=1;tablero[1][13]=1;tablero[1][14]=1;tablero[1][15]=1;
	tablero[2][1]=1;tablero[2][2]=1;tablero[2][3]=1;tablero[2][5]=1;tablero[2][6]=1;tablero[2][7]=1;tablero[2][9]=1;tablero[2][10]=1;tablero[2][13]=1;tablero[2][15]=1;
	tablero[3][1]=1;tablero[3][5]=1;tablero[3][7]=1;tablero[3][9]=1;tablero[3][11]=1;tablero[3][13]=1;tablero[3][14]=1;tablero[3][15]=1;
	
	//while(true)
	while(generacion!=generaciones)
	{
		printf("GENERACION: %d\n",generacion);
		for(int x=0; x<filas; x++)
		{
			for(int y=0; y<columnas; y++)
			{
				if(tablero[x][y]==1)
				{
					printf("*");
				}else
				{
					printf(" ");
				}
			}	
			printf("\n");
		}
		
		system("pause");
		
		for(int x=0; x<filas; x++)
    {
			for(int y=0; y<columnas; y++)
			{
				vecinos=0;
				if(x==0&&y==0)
				{
					//ESQUINA SUPERIOR IZQUIERDA
					if(x>=filas-1) xR=0;
					else xR=x+1;
					if(y>=columnas-1) yL=0;
					else yL=y+1;
						
					if(tablero[xR][y]==1) vecinos++;
					if(tablero[x][yL]==1) vecinos++;
					if(tablero[xR][yL]==1) vecinos++;
				}else if(x==0&&y==columnas-1)
				{
					//ESQUINA SUPERIOR DERECHA
					if(x>=filas-1) xR=0;
					else xR=x+1;
					if(y<=0) yH=columnas-1;
					else yH=y-1;
					
					if(tablero[xR][y]==1) vecinos++;
					if(tablero[x][yH]==1) vecinos++;
					if(tablero[xR][yH]==1) vecinos++;
				}else if(x==filas-1&&y==0)
				{
					//ESQUINA INFERIOR IZQUIERDA
					if(y>=columnas-1) yL=0;
					else yL=y+1;
					if(x<=0) xE=filas-1;
					else xE=x-1;
					
					if(tablero[xE][y]==1) vecinos++;
					if(tablero[x][yL]==1) vecinos++;
					if(tablero[xE][yL]==1) vecinos++;
				}else if(x==filas-1&&y==columnas-1)
				{
					//ESQUINA INFERIOR DERECHA
					if(x<=0) xE=filas-1;
					else xE=x-1;
					if(y<=0) yH=columnas-1;
					else yH=y-1;
					
					if(tablero[xE][y]==1) vecinos++;
					if(tablero[x][yH]==1) vecinos++;
					if(tablero[xE][yH]==1) vecinos++;
				}else if(x==0&&y!=0&&y!=columnas-1)
				{
					//ARRIBA
					if(x>=filas-1) xR=0;
					else xR=x+1;
					if(y<=0) yH=columnas-1;
					else yH=y-1;
					if(y>=columnas-1) yL=0;
					else yL=y+1;
					
					if(tablero[xR][y]==1) vecinos++;
					if(tablero[xR][yL]==1) vecinos++;
					if(tablero[xR][yH]==1) vecinos++;
					if(tablero[x][yL]==1) vecinos++;
					if(tablero[x][yH]==1) vecinos++;
				}else if(x!=0&&x!=filas-1&&y==columnas-1)
				{
					//DERECHA
					if(x>=filas-1) xR=0;
					else xR=x+1;
					if(x<=0) xE=filas-1;
					else xE=x-1;
					if(y<=0) yH=columnas-1;
					else yH=y-1;
					
					if(tablero[xR][y]==1) vecinos++;
					if(tablero[xE][y]==1) vecinos++;
					if(tablero[x][yH]==1) vecinos++;
					if(tablero[xR][yH]==1) vecinos++;
					if(tablero[xE][yH]==1) vecinos++;
				}else if(x!=0&&x!=filas-1&&y==0)
				{
					//IZQUIERDA
					if(x>=filas-1) xR=0;
					else xR=x+1;
					if(x<=0) xE=filas-1;
					else xE=x-1;
					if(y>=columnas-1) yL=0;
					else yL=y+1;
					
					if(tablero[xR][y]==1) vecinos++;
					if(tablero[xE][y]==1) vecinos++;
					if(tablero[x][yL]==1) vecinos++;
					if(tablero[xR][yL]==1) vecinos++;
					if(tablero[xE][yL]==1) vecinos++;	
				}else if(x==filas-1&&y!=0&&y!=columnas-1)
				{
					//ABAJO
					if(x<=0) xE=filas-1;
					else xE=x-1;
					if(y<=0) yH=columnas-1;
					else yH=y-1;
					if(y>=columnas-1) yL=0;
					else yL=y+1;
					
					if(tablero[xE][y]==1) vecinos++;
					if(tablero[x][yH]==1) vecinos++;
					if(tablero[x][yL]==1) vecinos++;
					if(tablero[xE][yH]==1) vecinos++;	
					if(tablero[xE][yL]==1) vecinos++;	
				}else
				{
					//DEMAS POSICIONES
					if(x>=filas-1) xR=0;
					else xR=x+1;
					if(y>=columnas-1) yL=0;
					else yL=y+1;
					if(x<=0) xE=filas-1;
					else xE=x-1;
					if(y<=0) yH=columnas-1;
					else yH=y-1;
					
					if(tablero[xR][y]==1) vecinos++;
					if(tablero[xE][y]==1) vecinos++; 
					if(tablero[x][yH]==1) vecinos++;
					if(tablero[x][yL]==1) vecinos++;
					if(tablero[xR][yH]==1)  vecinos++;
					if(tablero[xE][yH]==1)  vecinos++;
					if(tablero[xR][yL]==1)  vecinos++;
					if(tablero[xE][yL]==1)  vecinos++;	
				}
				
				if(tablero[x][y]==1)
				{
					if(vecinos<=1 || vecinos>3)
					{
						tablero_1[x][y]=0;
					}else
					{	
						tablero_1[x][y]=1;
					}
					}else
					{
					if(vecinos==3)
					{
						tablero_1[x][y]=1;
					}else
					{
						tablero_1[x][y]=0;
					}
					}
			}	//FIN DEL SEGUNDO FOR
		} //FIN DEL PRIMER FOR
		
		for(int x=0; x<filas; x++)
		{
			for(int y=0; y<columnas; y++)
			{
				tablero[x][y]=tablero_1[x][y];
			}
		}
		generacion++;
		system("cls");
	} //FIN DEL WHILE
	return 0;	
}
