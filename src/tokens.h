#ifndef TOKENS_H
#define TOKENS_H

/*
    DEFINICAO DE TOKENS
*/
#define END_OF_STRING           0

#define IDENTIFICADOR           1
#define NUMERO_INTEIRO          2
#define NUMERO_REAL             3

#define ALGORITMO               4
#define INICIO                  5
#define FIM                     6
#define VARIAVEIS               7
#define INTEIRO                 8
#define REAL                    9
#define CARACTERE               10
#define LOGICO                  11
#define STRING                  50

#define VETOR                   12
#define MATRIZ                  13
#define TIPO                    14
#define FUNCAO                  15
#define PROCEDIMENTO            16
#define SE                      17
#define ENTAO                   18
#define SENAO                   19

#define ENQUANTO                20
#define FACA                    21
#define PARA                    22
#define DE                      23
#define ATE                     24
#define PASSO                   25
#define REPITA                  26
#define LEIA                    27

#define IMPRIMA                 28
#define VERDADEIRO              29
#define FALSO                   30
#define E                       31
#define OU                      32
#define NAO                     33
#define DIV                     34

#define PONTO_E_VIRGULA         35
#define VIRGULA                 36
#define DOIS_PONTOS             37
#define PONTO                   38
#define ABRE_COLCHETES          39
#define FECHA_COLCHETES         40
#define ABRE_PARENTESES         51
#define FECHA_PARENTESES        52
#define IGUAL                   41
#define DIFERENTE               42
#define MAIOR                   43
#define MAIOR_IGUAL             44
#define MENOR                   53
#define MENOR_IGUAL             54
#define MAIS                    45
#define MENOS                   46
#define VEZES                   47
#define DIVISAO                 48
#define ATRIBUICAO              49






typedef struct StToken
{
    int    id;
    void * data;
    int    line;
    int    column;
} * Token;

Token createToken(int, void *, int, int);

#endif