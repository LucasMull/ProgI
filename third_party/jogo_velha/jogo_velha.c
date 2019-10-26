#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <ctype.h>

int lerInt(){
    int n;
    scanf("%d", &n);
    fflush(stdin);
    return n;
}

char lerChar(){
    char n;
    scanf("%c", &n);
    n = toupper(n);
    fflush(stdin);
    return n;
}

void imprimirCasa(int a){
    if(a == 0){
        printf("|   ");
    }else if(a == 1){
        printf("| X ");
    }else{
        printf("| O ");
    }
}

int possibilidadeGanhar(int casas[][3], int JM){
    int i, j, pos, pos0, aux=0;
    int posV, posH;
    ///Horizontalmente
    i=0;
    while(i<3 && aux==0){
        pos=0;
        pos0=0;
        for(j=0; j<3; j++){
            if(casas[i][j] == 0){
                pos0++;
                posV = i;
                posH = j;
            }else if(casas[i][j] == JM){
                pos++;
            }
        }
        if(pos0 == 1 && pos == 2){
            aux = 1;
            casas[posV][posH] = 2;
        }
        i++;
    }

    ///Verticalmente
    i=0;
    while(i<3 && aux==0){
        pos=0;
        pos0=0;
        for(j=0; j<3; j++){
            if(casas[j][i] == 0){
                pos0++;
                posV = j;
                posH = i;
            }else if(casas[j][i] == JM){
                pos++;
            }
        }
        if(pos0 == 1 && pos == 2){
            aux = 1;
            casas[posV][posH] = 2;
        }
        i++;
    }

    ///Diagonal primaria
    i=0;
    j=0;
    pos=0;
    pos0=0;
    while(i<3 && aux==0){
        if(casas[j][i] == 0){
            pos0++;
            posV = j;
            posH = i;
        }else if(casas[j][i] == JM){
            pos++;
        }
        i++;
        j++;
    }
    if(pos0 == 1 && pos == 2){
        aux = 1;
        casas[posV][posH] = 2;
    }

    ///Diagonal secundaria
    i=0;
    j=2;
    pos=0;
    pos0=0;
    while(i<3 && aux==0){
        if(casas[j][i] == 0){
            pos0++;
            posV = j;
            posH = i;
        }else if(casas[j][i] == JM){
            pos++;
        }
        i++;
        j--;
    }
    if(pos0 == 1 && pos == 2){
        aux = 1;
        casas[posV][posH] = 2;
    }

    return aux;
}

void valorAleatorio(int casas[][3]){
    int i, aux=0;
    do{
        i=rand()%9;
        switch(i){
        case 0:
            if(casas[0][0] == 0){
                casas[0][1] = 2;
                aux = 1;
            }
            break;
        case 1:
            if(casas[0][1] == 0){
                casas[0][1] = 2;
                aux = 1;
            }
            break;
        case 2:
            if(casas[0][2] == 0){
                casas[0][2] = 2;
                aux = 1;
            }
            break;
        case 3:
            if(casas[1][0] == 0){
                casas[1][0] = 2;
                aux = 1;
            }
            break;
        case 4:
            if(casas[1][1] == 0){
                casas[1][1] = 2;
                aux = 1;
            }
            break;
        case 5:
            if(casas[1][2] == 0){
                casas[1][2] = 2;
                aux = 1;
            }
            break;
        case 6:
            if(casas[2][0] == 0){
                casas[2][0] = 2;
                aux = 1;
            }
            break;
        case 7:
            if(casas[2][1] == 0){
                casas[2][1] = 2;
                aux = 1;
            }
            break;
        case 8:
            if(casas[2][2] == 0){
                casas[2][2] = 2;
                aux = 1;
            }
            break;
        }
    }while(aux == 0);
}

void valorAleatorioNaoCentro(int casas[][3]){
    int i, aux=0;
    do{
        i=rand()%8;
        switch(i){
        case 0:
            if(casas[0][0] == 0){
                casas[0][1] = 2;
                aux = 1;
            }
            break;
        case 1:
            if(casas[0][1] == 0){
                casas[0][1] = 2;
                aux = 1;
            }
            break;
        case 2:
            if(casas[0][2] == 0){
                casas[0][2] = 2;
                aux = 1;
            }
            break;
        case 3:
            if(casas[1][0] == 0){
                casas[1][0] = 2;
                aux = 1;
            }
            break;
        case 4:
            if(casas[1][2] == 0){
                casas[1][2] = 2;
                aux = 1;
            }
            break;
        case 5:
            if(casas[2][0] == 0){
                casas[2][0] = 2;
                aux = 1;
            }
            break;
        case 6:
            if(casas[2][1] == 0){
                casas[2][1] = 2;
                aux = 1;
            }
            break;
        case 7:
            if(casas[2][2] == 0){
                casas[2][2] = 2;
                aux = 1;
            }
            break;
        }
    }while(aux == 0);
}

void valorAleatorio4Bordas(int casas[][3]){
    int i, aux=0;
    do{
        i=rand()%4;
        switch(i){
        case 0:
            if(casas[0][1] == 0){
                casas[0][1] = 2;
                aux=1;
            }
            break;
        case 1:
            if(casas[1][0] == 0){
                casas[1][0] = 2;
                aux=1;
            }
            break;
        case 2:
            if(casas[1][2] == 0){
                casas[1][2] = 2;
                aux=1;
            }
            break;
        case 3:
            if(casas[2][1] == 0){
                casas[2][1] = 2;
                aux=1;
            }
            break;
        }
    }while(aux==0);
}

void valorAleatorioCantosPrincipais(int casas[][3]){
    int i, aux = 0;
    do{
        i=rand()%2;
        switch(i){
        case 0:
            if(casas[0][0] == 0){
                casas[0][0] = 2;
                aux = 1;
            }
            break;
        case 1:
            if(casas[2][2] == 0){
                casas[2][2] = 2;
                aux = 1;
            }
            break;
        }
    }while(aux == 0);
}

void valorAleatorioCantosSecundarios(int casas[][3]){
    int i, aux = 0;
    do{
        i=rand()%2;
        switch(i){
        case 0:
            if(casas[2][0] == 0){
                casas[2][0] = 2;
                aux = 1;
            }
            break;
        case 1:
            if(casas[0][2] == 0){
                casas[0][2] = 2;
                aux = 1;
            }
            break;
        }
    }while(aux == 0);

}

void valorAleatorio4cantos(int casas[][3]){
    int i, aux = 0;
    do{
        i=rand()%4;
        switch(i){
        case 0:
            if(casas[0][0] == 0){
                casas[0][0] = 2;
                aux = 1;
            }
            break;
        case 1:
            if(casas[0][2] == 0){
                casas[0][2] = 2;
                aux = 1;
            }
            break;
        case 2:
            if(casas[2][0] == 0){
                casas[2][0] = 2;
                aux = 1;
            }
            break;
        case 3:
            if(casas[2][2] == 0){
                casas[2][2] = 2;
                aux = 1;
            }
            break;
        }
    }while(aux == 0);
}

void valorAleatorioHorizontalNaoCentro(int casas[][3], int h){
    int i, aux = 0;
    do{
        i=rand()%2;
        switch(i){
        case 0:
            if(casas[h][0] == 0){
                casas[h][0] = 2;
                aux = 1;
            }
            break;
        case 1:
            if(casas[h][2] == 0){
                casas[h][2] = 2;
                aux = 1;
            }
            break;
        }
    }while(aux == 0);
}

void valorAleatorioVerticalNaoCentro(int casas[][3], int v){
    int i, aux = 0;
    do{
        i=rand()%2;
        switch(i){
        case 0:
            if(casas[0][v] == 0){
                casas[0][v] = 2;
                aux = 1;
            }
            break;
        case 1:
            if(casas[2][v] == 0){
                casas[2][v] = 2;
                aux = 1;
            }
            break;
        }
    }while(aux == 0);
}

void logicaPosicoes(int casas[][3], int turno){
    ///Provavelmente a parte mais dificil de explicar desse codigo...

    ///No primeiro turno do jogo, ela sempre jogara o seu X em um dos 4 cantos
    ///(maior chance de ganhar).

    ///Caso ela seja a segunda a jogar, ela forcara empate se o usuario nao
    ///escolheu um canto, colocando o seu X ao centro. Se o usuario escolheu o
    ///centro ou borda, ela colocara em algum dos cantos.

    ///No terceiro turno, ela verifica algum dos cantos contrario da qual ela jogou,
    ///e caso esteja ocupado pela posicao do usuario, ela joga em qualquer dos outros
    ///cantos restantes.

    ///No quarto turno, se o usuario dominou dois cantos, ela jogara na borda para
    ///forcar o usuario a sair dos cantos e nao deixar com que ele ganhe. Se o usuario
    ///dominou um canto e uma borda, ela jogara no centro para prevenir desastres.
    ///Por fim, caso o usuario dominou duas bordas, ela jogara em algum dos outros cantos.

    ///A partir do turno 5, a maquina escolhe posicoes aleatorias, ja que nao
    ///eh possivel planejar jogadas, a nao ser que o usuario cometa um erro muito
    ///grave e abra espaco, o qual ja eh analisado anteriormente.

    if(turno == 1 || (casas[1][1] == 1 && turno == 2)){
        valorAleatorio4cantos(casas);

    }else if(turno == 2){
        if(casas[0][0] == 1 || casas[0][2] == 1 || casas[2][0] == 1 || casas[2][2] == 1){
            casas[1][1] = 2;
        }else{
            if(casas[0][1] == 1){
                valorAleatorioHorizontalNaoCentro(casas, 0);
            }else if(casas[1][0] == 1){
                valorAleatorioVerticalNaoCentro(casas, 0);
            }else if(casas[1][2] == 1){
                valorAleatorioVerticalNaoCentro(casas, 2);
            }else if(casas[2][1] == 1){
                valorAleatorioHorizontalNaoCentro(casas, 2);
            }else{
                valorAleatorio4cantos(casas);
            }
        }

    }else if(turno == 3){
        if(casas[1][1] == 1){
            if(casas[0][0] == 2){
                if(casas[2][2] != 1){
                    casas[2][2] = 2;
                }else{
                    valorAleatorioCantosSecundarios(casas);
                }
            }else if(casas[2][2] == 2){
                if(casas[0][0] != 1){
                    casas[0][0] = 2;
                }else{
                    valorAleatorioCantosSecundarios(casas);
                }
            }else if(casas[0][2] == 2){
                if(casas[2][0] != 1){
                    casas[2][0] = 2;
                }else{
                    valorAleatorioCantosPrincipais(casas);
                }
            }else if(casas[2][0] == 2){
                if(casas[0][2] != 1){
                    casas[0][2] = 2;
                }else{
                    valorAleatorioCantosPrincipais(casas);
                }
            }
        }else if(casas[0][0] == 2 || casas[2][2] == 2){
            valorAleatorioCantosSecundarios(casas);
        }else{
            valorAleatorioCantosPrincipais(casas);
        }

    ///ContC = contador para cantos / ContB = contador para bordas
    }else if(turno == 4){
        int contC = 0, contB = 0;
        if(casas[0][0] == 1){
            contC++;
        }
        if(casas[0][1] == 1){
            contB++;
        }
        if(casas[0][2] == 1){
            contC++;
        }
        if(casas[1][0] == 1){
            contB++;
        }
        if(casas[1][2] == 1){
            contB++;
        }
        if(casas[2][0] == 1){
            contC++;
        }
        if(casas[2][1] == 1){
            contB++;
        }
        if(casas[2][2] == 1){
            contC++;
        }
        if(contC == 2){
            valorAleatorio4Bordas(casas);
        }else{
            if(casas[1][1] == 0){
                casas[1][1] = 2;
            }else{
                valorAleatorioNaoCentro(casas);
            }
        }

    }else if(turno == 5){
        if(casas[1][1] == 0){
            casas[1][1] = 2;
        }else{
            valorAleatorio(casas);
        }
    }else if(turno > 5){
        valorAleatorio(casas);
    }
}

void escolherPosicaoMaquina(int casas[][3], int turno){
    int aux;
    ///Ele nunca podera perder, portanto, verificara primeiro se pode ganhar
    ///Se nao, ela verifica ameacas para ele perder.
    ///Caso contrario, ele planeja jogar para tentar ganhar ou forcar empate,
    ///dependendo do estado do jogo.

    ///Verifica a possibilidade de ganhar
    aux = possibilidadeGanhar(casas, 2);

    ///Avaliar estado do jogador
    if(aux == 0){
        aux = possibilidadeGanhar(casas, 1);
    }
    ///Voce pode ter notado que as funcoes sao as mesmas, e so se alteram
    ///com o valor 2 ou 1. 2 indica posicoes da maquina e 1 indica posicoes
    ///do jogador, e como a funcao eh praticamente a mesma, nao ha necessidade
    ///de se criar toda uma nova variavel.

    ///Sem algum perigo obvio, a maquina fara sua jogada logica:
    if(aux == 0){
        logicaPosicoes(casas, turno);
    }
}

void escolherPosicaoJogador(int casas[][3]){
    int flag=0, pos;

    ///Para facilitar a escolha pro usuario, se utilizou um switch
    ///para que quando ele selecionar um numero, o programa
    ///ja organize certinho qual a posicao (por isso a impressao
    ///de uma tabela com os numeros das posicoes)

    ///Ademais, ele ainda verifica se a casa esta livre. Caso nao
    ///esteja, ele pede para que o usuario selecione novamente.
    printf("\n\nSelecione a posicao para jogar: ");
    do{
        pos = lerInt();
        switch(pos){
        case 7:
            if(casas[0][0] == 0){
                flag = 1;
                casas[0][0] = 1;
            }
            break;
        case 8:
            if(casas[0][1] == 0){
                flag = 1;
                casas[0][1] = 1;
            }
            break;
        case 9:
            if(casas[0][2] == 0){
                flag = 1;
                casas[0][2] = 1;
            }
            break;
        case 4:
            if(casas[1][0] == 0){
                flag = 1;
                casas[1][0] = 1;
            }
            break;
        case 5:
            if(casas[1][1] == 0){
                flag = 1;
                casas[1][1] = 1;
            }
            break;
        case 6:
            if(casas[1][2] == 0){
                flag = 1;
                casas[1][2] = 1;
            }
            break;
        case 1:
            if(casas[2][0] == 0){
                flag = 1;
                casas[2][0] = 1;
            }
            break;
        case 2:
            if(casas[2][1] == 0){
                flag = 1;
                casas[2][1] = 1;
            }
            break;
        case 3:
            if(casas[2][2] == 0){
                flag = 1;
                casas[2][2] = 1;
            }
            break;
        }
        if(flag == 0){
            printf("Posicao ocupada! Selecione outra: ");
        }
    }while(flag==0);
}

void imprimirJogoAtual(int casas[][3]){
    int i, j;
    printf("Estado do jogo: \n\n");
    printf("-------------\n");
    for(i=0; i<3; i++){
        for(j=0; j<3; j++){
            imprimirCasa(casas[i][j]);
        }
        printf("|\n-------------\n");
    }
}

void imprimirPosicoes(){
    int i, j, c;
    printf("Posicao das casas:\n\n");
    printf("-------------\n");
    c = 7;
    for(i=0; i<3; i++){
        for(j=0; j<3; j++){
            printf("| %d ", c);
            c++;
        }
        c = c - 6;
        printf("|\n-------------\n");
    }
}

int validarJogo(int casas[][3]){
    int i, j;

    ///Verifica linhas
    for(i=0; i<3; i++){
        if(casas[i][0] == casas[i][1] && casas[i][1] == casas[i][2]){
            if(casas[i][0] == 2){
                return 2;
            }
        }
    }

    ///Verifica colunas
    for(i=0; i<3; i++){
        if(casas[0][i] == casas[1][i] && casas[1][i] == casas[2][i]){
            if(casas[0][i] == 2){
                return 2;
            }
        }
    }

    ///Verifica diagonal principal
    if(casas[0][0] == casas[1][1] && casas[1][1] == casas[2][2]){
        if(casas[0][0] == 2){
            return 2;
        }
    }

    ///Verifica diagonal secundaria
    if(casas[0][2] == casas[1][1] && casas[1][1] == casas[2][0]){
        if(casas[0][2] == 2){
            return 2;
        }
    }

    ///Verifica se todas as casas foram ocupadas
    for(i=0; i<3; i++){
        for(j=0; j<3; j++){
            if(casas[i][j] == 0){
                return 0;
            }
        }
    }

    ///Se todas as casas foram ocupadas sem uma linha feita, ele retornara 1 para indicar empate.
    return 1;
}

void imprimirVez(char n1[], int vez){
    if(vez == 0){
        printf("\nVez de %s", n1);
    }else{
        printf("\nVez do computador, aguarde...");
    }
}

int jogoVelha(int casas[][3], char n1[], int vez){
    int flag = 0, pos, turno=1;
    do{
        ///Impressao de todo o quadro
        imprimirPosicoes();
        imprimirJogoAtual(casas);
        imprimirVez(n1, vez);

        ///Verifica de quem eh a vez
        if(vez == 0){
            escolherPosicaoJogador(casas);
        }else{
            escolherPosicaoMaquina(casas, turno);
        }

        ///Verifica a situacao do jogo
        flag = validarJogo(casas);

        ///Atualiza o turno e de quem eh a vez
        turno++;
        vez = !vez;
        system("clear");
    }while(flag == 0);
    return flag;
}

void limparMatriz(int casas[][3]){
    int i, j;
    for(i=0; i<3; i++){
        for(j=0; j<3; j++){
            casas[i][j] = 0;
        }
    }
}

void imprimirVencedor(int flag, int casas[][3]){
    imprimirJogoAtual(casas);
    printf("\n");

    ///Detalhe que eu so coloquei duas possibilidades, ja que a maquina jamais perde.
    if(flag == 1){
        printf("Empate!");
    }else if(flag == 2){
        printf("O computador venceu!");
    }
}

void lerJogador(char n1[]){
    printf("Insira o seu nome: ");
    gets(n1);
}

char decisaoUsuario(){
    char n;
    printf("\n\nDeseja jogar novamente?\nEscolha S para sim ou N para nao: ");
    do{
        n = lerChar();
    }while(n != 'S' && n != 'N');
    return n;
}

int quemComeca(){
    int vez;

    printf("Quem comecara jogando? Voce ou a maquina?\n");
    printf("1 - Voce\n2 - Maquina\nOpcao: ");
    do{
        vez = lerInt();
        vez--;
        if(vez != 1 && vez != 2){
            printf("Escolha uma opcao valida: ");
        }
    }while(vez != 0 && vez != 1);

    return vez;
}

void jogoCompleto(char n1[]){
    int casas[3][3], ganho, vez;
    char op;

    ///Ele ficara realizando o jogo ate o usuario optar por sair
    do{
        ///Funcao para limpar a matriz (deixar tudo em 0)
        limparMatriz(casas);

        ///Jogador decide quem comecara jogando, ele ou a maquina
        vez = quemComeca();
        system("clear");

        ///Ocorrimento do jogo, ate se ter o vencedor ou empate
        ganho = jogoVelha(casas, n1, vez);

        ///Imprime se foi empate ou se a maquina ganhou.
        imprimirVencedor(ganho, casas);

        ///Usuario opta por jogar de novo ou nao
        op = decisaoUsuario();
        system("clear");
    }while(op == 'S');
}

int main(){
    char n1[30];

    ///O jogador coloca o nome, detalhe adicional
    lerJogador(n1);
    srand(time(NULL));
    system("clear");

    ///Aqui eh onde ocorre toda a funcao do jogo
    jogoCompleto(n1);

    system("clear");
    printf("Obrigado por jogar!\n\n");
    return 0;
}
