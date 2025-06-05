#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#define pergunta_total 20
#define perguntass 10
#define alternativa 4

typedef struct {
    char pergunta[pergunta_total][200];
    char alternativas[alternativa][100];
    char resposta_certa;
} Questoes;

void perguntasAleatorias();


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

    int erros = 0, erros_tela[perguntass], contador = 0, opcoes;

    srand(time(NULL));


    do
    {
        printf("================QUIZ SOBRE C=================\n");
        printf("[1] - INICIAR O JOGO!\n");
        printf("[2] - COMO FUNCIONA?\n");
        printf("[3] - SAIR!\n");
        printf("Escolha a opcao: ");
        scanf("%i", &opcoes);

        switch (opcoes)
        {
        case 1:
            
            break;
        
        default:
            break;
        }
    } while (opcoes != 3);

    return 0;
}

void perguntasAleatorias(){

    for (int i = 0; i < perguntass; i++) {
        int num, repetido, sort[perguntass];

        do {
            repetido = 0;
            num = rand() % perguntass;

            for (int j = 0; j < i; j++) {
                if (sort[j] == num) {
                    repetido = 1;
                    break;
                }
            }
        } while (repetido);

        sort[i] = num;
    }


};