#include <stdio.h>
#include <stdlib.h>
#include "client.h"

int main(){

    FILE *mapa;
    mapa= fopen("mapa1.txt", "r");

    if(mapa==NULL){
        printf("ERROR");
    }

    int i=0, j, vida=0, nl, nc, m, l, c, pos1, pos2;//vida é um booleano, enquanto for 0 o jogador esta vivo
    int x, y; //posição do heroi no inicio do jogo
    char mov; //movimentação do herói
    char **linha;

    fscanf(mapa,"%d %d %d", &nl, &nc, &m);
    linha=(char**)malloc(nl*sizeof(char*));

    if(linha==NULL){
        printf("ERROR");
        exit(1);
    }

    for(i=0; i<nl+1;i++){
        linha[i]=(char*)malloc(nc*sizeof(char));
        if(linha[i]==NULL){
            printf("ERROR");
            exit(1);
        }
    }

    i=0;

    while(fscanf(mapa," %[^\n]", linha[i])!=EOF){
            printf("%s\n", linha[i]);
            ++i;
    }
    do {
        srand( (unsigned)time(NULL) );
        x= 2+ (rand()%(nl-5)); //pra não aparecer na borda
        y= 2+ (rand()%(nc-5));
        linha[x][y]='1';
    } while(linha[x][y]=='m');

    fclose(mapa);

    for(i=0;i<nl;i++){ //posição do herói
        for(j=0;j<nc;j++){
            if(linha[i][j]=='1'){
                l=i;
                c=j;
            }
        }
    }
    for (i=0; i<nl; i++){ //localização do monstro usando matriz

        for (j=0; j<nc; j++){

            if (linha[i][j]=='m'){
            pos1=i;
            pos2=j;
            }
        }
    }

    int aux; //auxiliares

    do{
            mov= getch();
            if(mov=='w' || mov=='W'){
                    if((linha[l-1][c]==' ' || linha[l-1][c]=='*') && (l<nl-1 && c<=nc-2 && c>=1) && l!=1){
                        linha[l][c]=' ';
                        linha[--l][c]='1';
                    }

            }
            else if(mov=='s'|| mov=='S'){
                    if((linha[l+1][c]==' ' || linha[l+1][c]=='*') && (l<nl-2 && c<=nc-2 && c>=1)){
                        linha[l][c]=' ';
                        linha[++l][c]='1';
                    }

            }
            else if(mov=='a'|| mov=='A'){
                    if((linha[l][c-1]==' ' || linha[l][c-1]=='*') && (l<nl-1 && c<=nc-2 && c>1)){
                        linha[l][c]=' ';
                        linha[l][--c]='1';
                    }

            }
            else if(mov=='d'|| mov=='D'){
                    if((linha[l][c+1]==' ' || linha[l][c+1]=='*') && (l<nl-1 && c<nc-2 && c>=1)){
                        linha[l][c]=' ';
                        linha[l][++c]='1';
                    }
        //srand( (unsigned)time(NULL) );
        aux = rand()%5;

        if (aux==0){

            if (linha[pos1-1][pos2]!='*' && linha[pos1-1][pos2]==' ')
            {
            linha[pos1][pos2]=' ';
            linha[--pos1][pos2]='m';

            }
        }
        else if (aux==1){

            if (linha[pos1][pos2-1]!='*'&& linha[pos1][pos2-1]==' ')
            {
            linha[pos1][pos2]=' ';
            linha[pos1][--pos2]='m';

            }
        }
        else if (aux==2){

            if (linha[pos1][pos2+1]!='*'&& linha[pos1][pos2+1]==' ')
            {
            linha[pos1][pos2]=' ';
            linha[pos1][++pos2]='m';

            }
        }
        else if (aux==3){

            if (linha [pos1+1][pos2]!='*'&& linha[pos1+1][pos2]==' ')
            {
            linha[pos1][pos2]=' ';
            linha[++pos1][pos2]='m';


            }
        }

        //Delay de 1 minuto entre cada movimentação
        usleep(2000);
        /* auxiliar mod 0: anda pra cima
        auxiliar mod 1: anda pra esquerda
        auxiliar mod 2: anda pra direita
        auxiliar mod 3: anda pra baixo
        auxiliar mod 4: não faz movimento */




            }
            system("clear"); //comando limpar tela no windows, alterar para system("clear")
            for(i=0;i<nl;i++){
                printf("%s\n", linha[i]);
            }



    }while(vida==0);


return 0;
}

