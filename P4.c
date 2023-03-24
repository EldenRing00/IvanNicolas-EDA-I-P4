#include <stdio.h>
#include <stdlib.h>
#define columna 8
#define renglon 8

struct torre{
 int x;
 int y;
};

struct alfil{
 int x;
 int y;
};

struct reyna{
 int x;
 int y;
};

struct rey{
 int x;
 int y;
};

struct caballo{
 int x;
 int y;
};

void torre(struct torre *t);
void alfil(struct alfil *a);
void reyna(struct reyna *r);
void rey(struct rey *q);
void caballo(struct caballo *c);
void evaluacion(int x);

int main (){

struct torre t;
struct alfil a;
struct reyna r;
struct rey q;
struct caballo c;
int opcion = 0;

while(1){
   printf("\n\t*** TABLERO DE AJEDREZ****\n");
   printf("\nElige del 1 al 6 y presiona enter\n");
   printf("1) Torre.\n");
   printf("2) Alfil.\n");
   printf("3) Reyna.\n");
   printf("4) Rey.\n");
   printf("5) Caballo.\n");
   printf("6) Salir.\n");
   scanf("%d", &opcion);
   switch(opcion){
    case 1:
    torre(&t);
    break;

    case 2:
    alfil(&a);
    break;

    case 3:
    reyna(&r);
    break;

    case 4:
    rey(&q);
    break;

    case 5:
    caballo(&c);
    break;

    case 6:
    return 0;

    default:
    printf("Opcion no válida.\n");
   }
}

return 0;
}

void evaluacion(int x){
 while(x < 0 || x > 7){
  printf("Número no válido\n");
  printf("Ingresa coordenadas del 0 - 7 y presiona enter\n");
  scanf("%d", &x);
 }
}

void torre(struct torre *t){
 int i,j;
 char **arr = (char **) calloc(columna, sizeof(char *));
 for(i = 0; i < columna; i++){
  arr[i] = (char *) calloc(renglon, sizeof(char));
 }

 printf("Ingresa coordenada (x) del 0 - 7 y presiona enter\n");
 scanf("%d",&(t->x));
 evaluacion(t->x);

 printf("Ingresa coordenada (y) del 0 - 7 y presiona enter\n");
 scanf("%d",&(t->y));
 evaluacion(t->y);

 for(i = 0; i < columna; i++){
  for(j = 0; j < renglon; j++){
   if(i == (t->x) && j == (t->y)){
    arr[i][j] = 'T';
   }
   if(i == (t->x) && j != (t->y)){
    arr[t->x][j] = '-';
   }
   if(j == (t->y) && i != (t->x)){
    arr[i][t->y] = '+';
   }
   if(i != (t->x) && j != (t->y)){
    arr[i][j]= 'X';
   }

  }
 }
 for(i = 0; i < columna ; i++){
  printf("\n");
  for(j = 0; j < renglon ; j++){
   printf("%c  ",arr[i][j]);
  }
 }
 free(arr);
}

void alfil(struct alfil *a){

 int i,j;
 int filas = 8, columnas = 8;
 char **arr = (char **) malloc(filas * sizeof(char *));
  for(i = 0; i < filas; i++){
   arr[i] = (char *) malloc(columnas * sizeof(char));
  }
 printf("Ingresa coordenada (x) del 0 - 7 y presiona enter\n");
 scanf("%d",&(a->x));
 evaluacion(a->x);

 printf("Ingresa coordenada (y) del 0 - 7 y presiona enter\n");
 scanf("%d",&(a->y));
 evaluacion(a->y);

 arr[a->x][a->y] = 'A';
 for(i = 0; i < columna; i++){
  for(j = 0; j < renglon; j++){
   arr[i][j] = 'X';
  }
 }
 arr[a->x][a->y] = 'A';
 for(i = 0; i < columna; i++){
  for(j = 0; j < renglon; j++){
   if (abs(i - a->x) == abs(j - a->y)){
    arr[i][j] = '-';
   }
  }
 }
 arr[a->x][a->y] = 'A';
 for(i = 0; i < columna; i++){
  printf("\n");
  for(j = 0; j < renglon; j++){
   printf("%c  ",arr[i][j]);
  }
 }
 for(i = 0; i < filas; i++){
  free(arr[i]);
 }
 free(arr);
}

void reyna(struct reyna *r){

 int i,j;
 char **arr = (char **) calloc(columna, sizeof(char *));
 for(i = 0; i < columna; i++){
  arr[i] = (char *) calloc(renglon, sizeof(char));
 }

 printf("Ingresa coordenada (x) del 0 - 7 y presiona enter\n");
 scanf("%d",&(r->x));
 evaluacion(r->x);

 printf("Ingresa coordenada (y) del 0 - 7 y presiona enter\n");
 scanf("%d",&(r->y));
 evaluacion(r->y);

 for(i = 0; i < columna; i++){
  for(j = 0; j < renglon; j++){
   arr[i][j] = 'X';
  }
 }
 arr[r->x][r->y] = 'R';
 for(i = 0; i < columna; i++){
  for(j = 0; j < renglon; j++){
   if(abs(i - r->x) == abs(j - r->y)){
    arr[i][j] = '-';
   }
   if(i == r->x && j != r->y){
    arr[r->x][j] = '-';
   }
   if(j == r->y && i != r->x){
    arr[i][r->y] = '|';
   }
   arr[r->x][r->y] = 'R';
  }
 }
 for(i = 0; i < columna; i++){
  printf("\n");
  for( j = 0; j < renglon; j++){
   printf("%c  ",arr[i][j]);
  }
 }
 free(arr);
}

void rey(struct rey *q){

 int i,j;
 char **arr = (char **) calloc(columna, sizeof(char *));
 for(i = 0; i < columna; i++){
  arr[i] = (char *) calloc(renglon, sizeof(char));
 }

 printf("Ingresa coordenada (x) del 0 - 7 y presiona enter\n");
 scanf("%d",&(q->x));
 evaluacion(q->x);

 printf("Ingresa coordenada (y) del 0 - 7 y presiona enter\n");
 scanf("%d",&(q->y));
 evaluacion(q->y);

 for(i = 0; i < columna; i++){
  for(j = 0; j < renglon; j++){
   arr[i][j] = 'X';
  }
 }
 arr[q->x][q->y] = 'Q';
 for(i = 0; i < columna; i++){
  for(j = 0; j < renglon; j++){
   if(i == q->x && q->y-1 != -1){
    arr[i][q->y-1] = '-';
   }
   if(i == q->x && q->y+1 != 8){
    arr[i][q->y+1] = '-';
   }
   if(q->x-1 != -1 && j == q->y){
    arr[q->x-1][j] = '-';
   }
   if(q->x+1 != 8 && j == q->y){
    arr[q->x+1][j] = '-';
   }
   if(abs(i - q->x)==1 && abs(j - q->y)==1){
    arr[i][j]= '-';
   }
  }
 }
 arr[q->x][q->y] = 'Q';
 for(i = 0; i < columna; i++){
  printf("\n");
  for( j = 0; j < renglon; j++){
   printf("%c  ",arr[i][j]);
  }
 }
 free(arr);
}

void caballo(struct caballo *c){

 int i,j;
 char **arr = (char **) calloc(columna, sizeof(char *));
 for(i = 0; i < columna; i++){
  arr[i] = (char *) calloc(renglon, sizeof(char));
 }

 printf("Ingresa coordenada (x) del 0 - 7 y presiona enter\n");
 scanf("%d",&(c->x));
 evaluacion(c->x);

 printf("Ingresa coordenada (y) del 0 - 7 y presiona enter\n");
 scanf("%d",&(c->y));
 evaluacion(c->y);

 for(i = 0; i < columna; i++){
  for(j = 0; j < renglon; j++){
   arr[i][j] = 'X';
  }
 }

 arr[c->x][c->y] = 'C';

 int dx[] = {-2, -1, 1, 2, 2, 1, -1, -2};
  int dy[] = {1, 2, 2, 1, -1, -2, -2, -1};
   for(i = 0; i < 8; i++){
    int nx = c->x + dx[i];
    int ny = c->y + dy[i];
    if(nx >= 0 && nx < columna && ny >= 0 && ny < renglon){
     arr[nx][ny] = '-';
    }
   }
 for(i = 0; i < columna; i++){
  printf("\n");
  for(j = 0; j < renglon; j++){
   printf("%c  ",arr[i][j]);
  }
 }
 free(arr);
}


