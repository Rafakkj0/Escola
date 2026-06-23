#include <stdio.h>

void apresentarMapa(int mapa[][10]){
    printf("\n");
    for(int i=0; i < 10; i++){
        for(int k=0; k < 10; k++){
            switch (mapa[i][k])
            {
            case 0:
                printf("🟩"); // Chão que se pode andar
                break;
            case 1:
                printf("🧱"); // Parede
                break;
            case 2:
                printf("😎"); // Player
                break;
            case 3:
                printf("🚪"); // Porta
                break;
            case 4:
                printf("🔑"); // Chave
                break;
            case 5:
                printf("👿"); // Inimigo
                break;
            case 6:
                printf("🏁"); // Final
            default:
                break;
            }
        }
        printf("\n");
    }
}

int main(){
    int mapa[10][10]={
        {2,0,0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0,5,0},
        {0,0,0,0,0,0,0,0,0,0}
    };
    int chave = 0;
    int posX = 0;
    int posY = 0;
    int posXinimigo = 8;
    int posYinimigo = 8;
    int passos = 0;

    while(1){
        apresentarMapa(mapa);
        char entrada;
        scanf(" %c", &entrada);
        if(entrada == 'w' || entrada == 'W'){
            int proxCasa = mapa[posY-1][posX];
            if(proxCasa == 0){
                mapa[posY-1][posX] = 2;
                mapa[posY][posX] = 0;
                posY--;
            }
            else{
                if(proxCasa == 4){
                    mapa[posY-1][posX] = 2;
                    mapa[posY][posX] = 0;
                    posY--;
                    chave++;
                }
                else{
                    if(proxCasa == 3){
                        if(chave > 0){
                            mapa[posY-1][posX] = 2;
                            mapa[posY][posX] = 0;
                            posY--;
                            chave--;
                        }
                    }
                    else{
                        if(proxCasa == 6){
                            printf("🏁Você venceu!🏁\n");
                            return 0;
                        }
                    }
                }
            }
        }
        else if(entrada == 'a' || entrada == 'A'){
            int proxCasa = mapa[posY][posX-1];
            if(proxCasa == 0){
                mapa[posY][posX-1] = 2;
                mapa[posY][posX] = 0;
                posX--;
            }
            else{
                if(proxCasa == 4){
                    mapa[posY][posX-1] = 2;
                    mapa[posY][posX] = 0;
                    posX--;
                    chave++;
                }
                else{
                    if(proxCasa == 3){
                        if(chave > 0){
                            mapa[posY][posX-1] = 2;
                            mapa[posY][posX] = 0;
                            posX--;
                            chave--;
                        }
                    }
                    else{
                        if(proxCasa == 6){
                            printf("🏁Você venceu!🏁\n");
                            return 0;
                        }
                    }
                }
            }
        }
        else if(entrada == 's' || entrada == 'S'){
            int proxCasa = mapa[posY+1][posX];
            if(proxCasa == 0){
                mapa[posY+1][posX] = 2;
                mapa[posY][posX] = 0;
                posY++;
            }
            else{
                if(proxCasa == 4){
                    mapa[posY+1][posX] = 2;
                    mapa[posY][posX] = 0;
                    posY++;
                    chave++;
                }
                else{
                    if(proxCasa == 3){
                        if(chave > 0){
                            mapa[posY+1][posX] = 2;
                            mapa[posY][posX] = 0;
                            posY++;
                            chave--;
                        }
                    }
                    else{
                        if(proxCasa == 6){
                            printf("🏁Você venceu!🏁\n");
                            return 0;
                        }
                    }
                }
            }
        }
        else if(entrada == 'd' || entrada == 'D'){
            int proxCasa = mapa[posY][posX+1];
            if(proxCasa == 0){
                mapa[posY][posX+1] = 2;
                mapa[posY][posX] = 0;
                posX++;
            }
            else{
                if(proxCasa == 4){
                    mapa[posY][posX+1] = 2;
                    mapa[posY][posX] = 0;
                    posX++;
                    chave++;
                }
                else{
                    if(proxCasa == 3){
                        if(chave > 0){
                            mapa[posY][posX+1] = 2;
                            mapa[posY][posX] = 0;
                            posX++;
                            chave--;
                        }
                    }
                    else{
                        if(proxCasa == 6){
                            printf("🏁Você venceu!🏁\n");
                            return 0;
                        }
                    }
                }
            }
        }
        int distanciaY = posY - posYinimigo;
        if (distanciaY < 0){
            distanciaY = -distanciaY;
        }
        int distanciaX = posX - posXinimigo;
        if (distanciaX < 0){
            distanciaX = -distanciaX;
        }
        if(distanciaX+distanciaY <= 6){
            if(passos%2 == 0){
                if(distanciaX>distanciaY){
                    if((posX - posXinimigo) < 0){
                        if(mapa[posYinimigo][posXinimigo-1] == 0){
                            mapa[posYinimigo][posXinimigo-1] = 5;
                            mapa[posYinimigo][posXinimigo] = 0;
                            posXinimigo--;
                        }
                        else{
                            if(mapa[posYinimigo][posXinimigo-1] == 2){
                                return 0;
                            }
                        }
                    }
                    else{
                        if((posX - posXinimigo) > 0){
                            if(mapa[posYinimigo][posXinimigo+1] == 0){
                                mapa[posYinimigo][posXinimigo+1] = 5;
                                mapa[posYinimigo][posXinimigo] = 0;
                                posXinimigo++;
                            }
                            else{
                                if(mapa[posYinimigo][posXinimigo+1] == 2){
                                    return 0;
                                }
                            }
                        }
                    }
                }
                else{
                    if((posY - posYinimigo) < 0){
                        if(mapa[posYinimigo-1][posXinimigo] == 0){
                            mapa[posYinimigo-1][posXinimigo] = 5;
                            mapa[posYinimigo][posXinimigo] = 0;
                            posYinimigo--;
                        }
                        else{
                            if(mapa[posYinimigo-1][posXinimigo] == 2){
                                return 0;
                            }
                        }
                    }
                    else{
                        if((posY - posYinimigo) > 0){
                            if(mapa[posYinimigo+1][posXinimigo] == 0){
                                mapa[posYinimigo+1][posXinimigo] = 5;
                                mapa[posYinimigo][posXinimigo] = 0;
                                posYinimigo++;
                            }
                            else{
                                if(mapa[posYinimigo+1][posXinimigo] == 2){
                                    return 0;
                                }
                            }
                        }
                    }
                }
            }
            passos++;
        }
    }
    return 0;
}