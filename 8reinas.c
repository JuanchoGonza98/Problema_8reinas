#include<stdio.h>
#include<math.h>
#include<stdlib.h>
void Nreinas(int reinas[],int n,int k);
int comprobar(int reinas[],int n,int k);
int cnt; //contabiliza la cantidad de soluciones
int main()
{
  int k;
  k=0; //inicializando en la raiz del arbol
  int cant_reinas; //Variable que contiene la cantidad de reinas
  cant_reinas = 4;
  //printf("Ingrese la cantidad de reinas: ");
  //scanf("%d",&cant_reinas);
  //int *reinas;
  //reinas=(int *)calloc(cant_reinas,sizeof(int));
  int reinas[cant_reinas];
  int i;
  for(i=0;i<cant_reinas;i++)
    {
      reinas[i]= -1;
    }
    Nreinas(reinas,cant_reinas,k);
}

void Nreinas(int reinas[],int n,int k)
{
  int i;
  if(k==n) //Caso base: Cuando todas las reinas ya se colocaron y ninguna puede tocarse entre si
    {
      cnt++;
      printf("Solucion # %d: ",cnt);
      for(i=0;i<n;i++)
      {
        printf("%d , ",reinas[i]);
      }
      printf("\n");
    }
    else{
      for(reinas[k]=0;reinas[k]<n;reinas[k]++)
      {
        if((comprobar(reinas,n,k) == 1))
        {
          Nreinas(reinas,n,k+1);
        }
      }
    }
}

int comprobar(int reinas[],int n,int k)
{
  int i;
  for(i=0;i<k;i++)
  {
    if( (reinas[i] == reinas[k]) || ( abs(k-i) == abs(reinas[k]-reinas[i]) ))
      {
        return 0;
      }
  } return 1;
} 