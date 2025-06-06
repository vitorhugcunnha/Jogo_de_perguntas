#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#define pergunta_total 20
#define perguntass 10
#define alternativa 4

typedef struct {
    char pergunta[200];
    char alternativas[alternativa][100];
    char resposta_certa;
} Questoes;

void perguntasAleatorias(int vetor[]);
void jogar(Questoes pergunta[]);
void comoFunciona();
void resultado(int acertos, int erros, int erros_tela[], int contador, Questoes pergunta[]);

int main() {
    Questoes pergunta[pergunta_total] = {
        {"Qual simbolo e usado para indicar o fim de uma instrucao em C?", {"A) :", "B) .", "C) ;", "D) ,"}, 'C'},
        {"Qual biblioteca padrao permite entrada e saida de dados em C?", {"A) stdio.h", "B) math.h", "C) string.h", "D) stdlib.h"}, 'A'},
        {"Qual palavra-chave e usada para declarar uma constante em C?", {"A) const", "B) let", "C) static", "D) define"}, 'A'},
        {"Qual operador e usado para comparar igualdade em C?", {"A) =", "B) ==", "C) !=", "D) <>"}, 'B'},
        {"Como se declara uma variavel inteira em C?", {"A) int numero;", "B) integer numero;", "C) num numero;", "D) number numero;"}, 'A'},
        {"Qual funcao e usada para imprimir na tela em C?", {"A) print()", "B) echo()", "C) printf()", "D) display()"}, 'C'},
        {"Qual comando le dados do teclado em C?", {"A) input()", "B) scanf()", "C) read()", "D) gets()"}, 'B'},
        {"Como e iniciada a funcao principal de um programa C?", {"A) start()", "B) program()", "C) int main()", "D) void main()"}, 'C'},
        {"Qual biblioteca e usada para funcoes matematicas como pow() e sqrt()?", {"A) stdio.h", "B) math.h", "C) stdlib.h", "D) string.h"}, 'B'},
        {"O que significa a sigla 'printf'?", {"A) Print File", "B) Print Function", "C) Print Formatted", "D) Print Format"}, 'C'},
        {"Qual operador e usado para incrementar uma variavel em C?", {"A) +=", "B) ++", "C) --", "D) +1"}, 'B'},
        {"Para que serve a diretiva #include em C?", {"A) Declarar funcoes", "B) Importar bibliotecas", "C) Declarar variaveis", "D) Encerrar programa"}, 'B'},
        {"Qual funcao encerra um programa em C retornando um valor ao sistema?", {"A) finish()", "B) stop()", "C) exit()", "D) return()"}, 'D'},
        {"Como se declara um vetor de 10 inteiros em C?", {"A) int v[10];", "B) int v(10);", "C) vetor int v;", "D) array v = 10;"}, 'A'},
        {"O que significa 'NULL' em C?", {"A) Zero inteiro", "B) String vazia", "C) Ponteiro sem endereco", "D) Falso"}, 'C'},
        {"Qual operador logico representa 'E' (AND) em C?", {"A) &&", "B) ||", "C) !", "D) &"}, 'A'},
        {"Qual operador logico representa 'OU' (OR) em C?", {"A) &&", "B) ||", "C) !", "D) |"}, 'B'},
        {"Como se cria um loop que executa 5 vezes?", {"A) for(int i=0; i<5; i++)", "B) repeat 5 times", "C) loop(5)", "D) while i<5"}, 'A'},
        {"Para que serve a funcao 'strlen()' da biblioteca string.h?", {"A) Copiar string", "B) Concatenar string", "C) Medir tamanho da string", "D) Comparar strings"}, 'C'},
        {"Qual comando permite a decisao condicional em C?", {"A) choose", "B) select", "C) if", "D) check"}, 'C'}
    };

    int opcoes;
    srand(time(NULL));

    system("cls");
    do {
        printf("\n============= QUIZ SOBRE C ============\n");
        printf("[1] - INICIAR O JOGO!\n");
        printf("[2] - COMO FUNCIONA?\n");
        printf("[3] - SAIR!\n");
        printf("Escolha a opcao: ");
        scanf("%i", &opcoes);

        switch (opcoes) {
            case 1:
                jogar(pergunta);
                break;
            case 2:
                comoFunciona();
                break;
            case 3:
                printf("Saindo...!\n");
                break;
            default:
                printf("Opcao invalida! Tente novamente.\n");
                break;
        }
    } while (opcoes != 3);

    return 0;
}


void perguntasAleatorias(int vetor[]) {
    int num, repetido;
    for (int i = 0; i < perguntass; i++) {
        do {
            repetido = 0;
            num = rand() % pergunta_total;

            for (int j = 0; j < i; j++) {
                if (vetor[j] == num) {
                    repetido = 1;
                    break;
                }
            }
        } while (repetido);

        vetor[i] = num;
    }
}

void jogar(Questoes pergunta[]) {
    system("cls");
    int sorteio[perguntass];
    char resposta;
    int acertos = 0, erros = 0;
    int erros_tela[perguntass], contador = 0;

    perguntasAleatorias(sorteio);

    for (int i = 0; i < perguntass; i++) {
        int indice = sorteio[i];

        printf("\nPergunta %d: %s\n", i + 1, pergunta[indice].pergunta);

        for (int j = 0; j < alternativa; j++) {
            printf("%s\n", pergunta[indice].alternativas[j]);
        }

        printf("Digite a sua resposta (A, B, C ou D): ");
        scanf(" %c", &resposta);

        if (resposta == pergunta[indice].resposta_certa || resposta == pergunta[indice].resposta_certa + 32) {
            printf(" Resposta correta!\n");
            acertos++;
        } else {
            printf(" Resposta errada! Resposta correta: %c\n", pergunta[indice].resposta_certa);
            erros_tela[contador++] = indice;
            erros++;
        }
    }

    resultado(acertos, erros, erros_tela, contador, pergunta);
}

void resultado(int acertos, int erros, int erros_tela[], int contador, Questoes pergunta[]) {
    printf("\n================== RESULTADO ==================\n");
    printf("Acertos: %d\n", acertos);
    printf("Erros: %d\n", erros);

    if (erros > 0) {
        printf("\nVoce errou as seguintes perguntas:\n");
        for (int i = 0; i < contador; i++) {
            printf("-> %s Resposta correta: %c)\n", pergunta[erros_tela[i]].pergunta, pergunta[erros_tela[i]].resposta_certa);
        }
    }

    printf("===========================================\n");
}


void comoFunciona() {
    system("cls");
    printf("\n============= COMO FUNCIONA =========\n");
    printf("-> O jogo sorteia 10 perguntas aleatorias sobre linguagem C.\n");
    printf("-> Cada pergunta tem 4 alternativas (A, B, C, D).\n");
    printf("-> Voce deve digitar a letra correspondente a sua resposta.\n");
    printf("-> Ao final, o jogo mostrara quantas voce acertou e errou.\n");
    printf("=====================================\n");
}
