#include "sintatico.h"

#include <stdio.h>
#include <stdlib.h>

const int parse[38][55] = {
    {101,	100,	100,	100,	100,	100,	100,	100,	100,	100,	100,	100,	100,	100,	100,	100,	100,	100,	100,	100,	100,	100,	100,	100,	100,	100,	100,	100,	100,	100,	100,	100,	100,	100,	100,	100,	100,	100,	100,	100,	100,	100,	100,	100,	100,	100,	100,	100,	100,	100,	100,	100,	100,	100,	100},
    {100,	100,	100,	100,	102,	103,	100,	100,	100,	100,	100,	100,	100,	100,	100,	100,	100,	100,	100,	100,	100,	100,	104,	100,	100,	100,	100,	100,	100,	100,	100,	100,	100,	100,	100,	100,	100,	100,	100,	100,	100,	100,	100,	100,	100,	100,	100,	100,	100,	100,	100,	100,	100,	100,	100},
    {100,	100,	100,	100,	105,	100,	100,	100,	100,	100,	100,	100,	100,	100,	100,	100,	100,	100,	100,	100,	100,	100,	100,	100,	100,	100,	100,	100,	100,	100,	100,	100,	100,	100,	100,	100,	100,	100,	100,	100,	100,	100,	100,	100,	100,	100,	100,	100,	100,	100,	100,	100,	100,	100,	100},
    {100,	100,	100,	100,	100,	106,	100,	100,	100,	100,	100,	100,	100,	100,	100,	100,	100,	100,	100,	100,	100,	100,	100,	100,	100,	100,	100,	100,	100,	100,	100,	100,	100,	100,	100,	100,	100,	100,	100,	100,	100,	100,	100,	100,	100,	100,	100,	100,	100,	100,	100,	100,	100,	100,	100},
    {100,	100,	108,	100,	100,	100,	108,	107,	100,	100,	100,	100,	100,	100,	100,	100,	100,	100,	100,	100,	100,	100,	100,	100,	100,	100,	100,	100,	100,	100,	100,	100,	100,	100,	100,	100,	100,	100,	100,	100,	100,	100,	100,	100,	100,	100,	100,	100,	100,	100,	100,	100,	100,	100,	100},
    {100,	109,	100,	100,	110,	110,	100,	100,	100,	110,	109,	100,	100,	100,	100,	100,	100,	100,	109,	109,	109,	109,	110,	100,	100,	100,	100,	100,	100,	100,	100,	100,	100,	100,	100,	100,	100,	100,	100,	100,	100,	100,	100,	100,	100,	100,	100,	100,	100,	100,	100,	100,	100,	100,	100},
    {100,	100,	100,	100,	112,	112,	100,	100,	100,	111,	100,	100,	100,	100,	100,	100,	100,	100,	100,	100,	100,	100,	112,	100,	100,	100,	100,	100,	100,	100,	100,	100,	100,	100,	100,	100,	100,	100,	100,	100,	100,	100,	100,	100,	100,	100,	100,	100,	100,	100,	100,	100,	100,	100,	112},
    {100,	113,	100,	100,	100,	100,	100,	100,	100,	100,	113,	100,	100,	100,	100,	100,	100,	100,	113,	113,	113,	113,	100,	100,	100,	100,	100,	100,	100,	100,	100,	100,	100,	100,	100,	100,	100,	100,	100,	100,	100,	100,	100,	100,	100,	100,	100,	100,	100,	100,	100,	100,	100,	100,	100},
    {100,	114,	100,	100,	115,	115,	100,	100,	100,	115,	114,	100,	100,	100,	100,	100,	100,	100,	114,	114,	114,	114,	115,	100,	100,	100,	100,	100,	100,	100,	100,	100,	100,	100,	100,	100,	100,	100,	100,	100,	100,	100,	100,	100,	100,	100,	100,	100,	100,	100,	100,	100,	100,	100,	115},
    {100,	117,	100,	100,	100,	100,	100,	100,	100,	100,	116,	100,	100,	100,	100,	100,	100,	100,	117,	117,	117,	117,	100,	100,	100,	100,	100,	100,	100,	100,	100,	100,	100,	100,	100,	100,	100,	100,	100,	100,	100,	100,	100,	100,	100,	100,	100,	100,	100,	100,	100,	100,	100,	100,	100},
    {100,	100,	100,	100,	100,	100,	100,	100,	100,	100,	118,	100,	100,	100,	100,	100,	100,	100,	100,	100,	100,	100,	100,	100,	100,	100,	100,	100,	100,	100,	100,	100,	100,	100,	100,	100,	100,	100,	100,	100,	100,	100,	100,	100,	100,	100,	100,	100,	100,	100,	100,	100,	100,	100,	100},
    {100,	119,	100,	100,	100,	100,	100,	100,	100,	100,	100,	100,	100,	100,	100,	100,	100,	100,	119,	119,	119,	119,	100,	100,	100,	100,	100,	100,	100,	100,	100,	100,	100,	100,	100,	100,	100,	100,	100,	100,	100,	100,	100,	100,	100,	100,	100,	100,	100,	100,	100,	100,	100,	100,	100},
    {100,	120,	100,	100,	100,	100,	100,	100,	100,	100,	100,	100,	100,	100,	100,	100,	100,	100,	100,	100,	100,	100,	100,	100,	100,	100,	100,	100,	100,	100,	100,	100,	100,	100,	100,	100,	100,	100,	100,	100,	100,	100,	100,	100,	100,	100,	100,	100,	100,	100,	100,	100,	100,	100,	100},
    {100,	100,	122,	100,	100,	100,	100,	100,	122,	100,	100,	100,	100,	100,	121,	100,	100,	100,	100,	100,	100,	100,	100,	100,	100,	100,	100,	100,	100,	100,	100,	100,	100,	100,	100,	100,	100,	100,	100,	100,	100,	100,	100,	100,	100,	100,	100,	100,	100,	100,	100,	100,	100,	100,	100},
    {100,	100,	100,	100,	100,	100,	100,	100,	100,	100,	100,	100,	100,	100,	100,	123,	124,	100,	100,	100,	100,	100,	100,	100,	100,	100,	100,	100,	100,	100,	100,	100,	100,	100,	100,	100,	100,	100,	100,	100,	100,	100,	100,	100,	100,	100,	100,	100,	100,	100,	100,	100,	100,	100,	100},
    {100,	100,	100,	100,	100,	100,	100,	100,	100,	100,	100,	100,	100,	100,	100,	100,	100,	125,	100,	100,	100,	100,	100,	100,	100,	100,	100,	100,	100,	100,	100,	100,	100,	100,	100,	100,	100,	100,	100,	100,	100,	100,	100,	100,	100,	100,	100,	100,	100,	100,	100,	100,	100,	100,	100},
    {100,	100,	100,	100,	100,	100,	100,	100,	100,	100,	100,	100,	100,	127,	126,	100,	100,	100,	100,	100,	100,	100,	100,	100,	100,	100,	100,	100,	100,	100,	100,	100,	100,	100,	100,	100,	100,	100,	100,	100,	100,	100,	100,	100,	100,	100,	100,	100,	100,	100,	100,	100,	100,	100,	100},
    {100,	132,	100,	100,	100,	100,	100,	100,	100,	100,	100,	100,	100,	100,	100,	100,	100,	100,	128,	129,	130,	131,	100,	100,	100,	100,	100,	100,	100,	100,	100,	100,	100,	100,	100,	100,	100,	100,	100,	100,	100,	100,	100,	100,	100,	100,	100,	100,	100,	100,	100,	100,	100,	100,	100},
    {100,	100,	100,	100,	100,	100,	100,	100,	100,	100,	100,	100,	100,	100,	100,	100,	100,	100,	100,	100,	100,	100,	133,	100,	100,	100,	100,	100,	100,	100,	100,	100,	100,	100,	100,	100,	100,	100,	100,	100,	100,	100,	100,	100,	100,	100,	100,	100,	100,	100,	100,	100,	100,	100,	100},
    {100,	134,	100,	100,	100,	100,	100,	100,	100,	100,	100,	100,	100,	100,	100,	100,	100,	100,	100,	100,	100,	100,	100,	100,	100,	134,	100,	100,	134,	100,	134,	100,	100,	100,	134,	134,	134,	100,	100,	100,	100,	100,	100,	100,	100,	100,	100,	100,	100,	100,	100,	100,	100,	100,	100},
    {100,	135,	136,	100,	100,	100,	100,	100,	100,	100,	100,	100,	100,	100,	100,	100,	100,	100,	100,	100,	100,	100,	100,	136,	100,	135,	100,	136,	135,	100,	135,	100,	136,	100,	135,	135,	135,	100,	100,	100,	100,	100,	100,	100,	100,	100,	100,	100,	100,	100,	100,	100,	100,	100,	100},
    {100,	137,	100,	100,	100,	100,	100,	100,	100,	100,	100,	100,	100,	100,	100,	100,	100,	100,	100,	100,	100,	100,	100,	100,	100,	142,	100,	100,	145,	100,	146,	100,	100,	100,	149,	150,	151,	100,	100,	100,	100,	100,	100,	100,	100,	100,	100,	100,	100,	100,	100,	100,	100,	100,	100},
    {100,	100,	138,	100,	100,	100,	100,	139,	100,	100,	100,	100,	141,	100,	100,	100,	100,	100,	100,	100,	100,	100,	100,	100,	140,	100,	100,	100,	100,	100,	100,	100,	100,	100,	100,	100,	100,	100,	100,	100,	100,	100,	100,	100,	100,	100,	100,	100,	100,	100,	100,	100,	100,	100,	100},
    {100,	100,	100,	100,	100,	100,	100,	100,	100,	100,	100,	100,	100,	100,	100,	100,	100,	100,	100,	100,	100,	100,	100,	144,	100,	100,	100,	143,	100,	100,	100,	100,	100,	100,	100,	100,	100,	100,	100,	100,	100,	100,	100,	100,	100,	100,	100,	100,	100,	100,	100,	100,	100,	100,	100},
    {100,	100,	100,	100,	100,	100,	100,	100,	100,	100,	100,	100,	100,	100,	100,	100,	100,	100,	100,	100,	100,	100,	100,	100,	100,	100,	100,	100,	100,	148,	100,	100,	100,	147,	100,	100,	100,	100,	100,	100,	100,	100,	100,	100,	100,	100,	100,	100,	100,	100,	100,	100,	100,	100,	100},
    {100,	152,	152,	100,	100,	100,	100,	152,	152,	100,	100,	152,	100,	152,	152,	100,	100,	152,	100,	100,	100,	100,	100,	100,	100,	100,	152,	100,	100,	152,	100,	100,	152,	152,	100,	100,	100,	152,	152,	152,	152,	152,	152,	152,	100,	100,	100,	100,	100,	152,	152,	152,	152,	152,	100},
    {100,	100,	159,	100,	100,	100,	100,	100,	159,	100,	100,	153,	100,	159,	159,	100,	100,	100,	100,	100,	100,	100,	100,	100,	100,	100,	159,	100,	100,	159,	100,	100,	159,	159,	100,	100,	100,	154,	155,	156,	157,	158,	100,	100,	100,	100,	100,	100,	100,	100,	100,	100,	100,	100,	100},
    {100,	160,	160,	100,	100,	100,	100,	160,	160,	100,	100,	160,	100,	160,	160,	100,	100,	160,	100,	100,	100,	100,	100,	100,	100,	100,	160,	100,	100,	160,	100,	100,	160,	160,	100,	100,	100,	160,	160,	160,	160,	160,	160,	160,	100,	100,	100,	100,	100,	160,	160,	160,	160,	160,	100},
    {100,	163,	100,	100,	100,	100,	100,	163,	100,	100,	100,	100,	100,	100,	100,	100,	100,	163,	100,	100,	100,	100,	100,	100,	100,	100,	100,	100,	100,	100,	100,	100,	100,	100,	100,	100,	100,	100,	100,	100,	100,	100,	161,	162,	100,	100,	100,	100,	100,	163,	163,	163,	163,	163,	100},
    {100,	100,	167,	100,	100,	100,	100,	100,	167,	100,	100,	167,	100,	167,	167,	100,	100,	100,	100,	100,	100,	100,	100,	100,	100,	100,	167,	100,	100,	167,	100,	100,	167,	167,	100,	100,	100,	167,	167,	167,	167,	167,	164,	165,	166,	100,	100,	100,	100,	100,	100,	100,	100,	100,	100},
    {100,	168,	100,	100,	100,	100,	100,	168,	100,	100,	100,	100,	100,	100,	100,	100,	100,	168,	100,	100,	100,	100,	100,	100,	100,	100,	100,	100,	100,	100,	100,	100,	100,	100,	100,	100,	100,	100,	100,	100,	100,	100,	100,	100,	100,	100,	100,	100,	100,	168,	168,	168,	168,	168,	100},
    {100,	100,	173,	100,	100,	100,	100,	100,	173,	100,	100,	173,	100,	173,	173,	100,	100,	100,	100,	100,	100,	100,	100,	100,	100,	100,	173,	100,	100,	173,	100,	100,	173,	173,	100,	100,	100,	173,	173,	173,	173,	173,	173,	173,	173,	169,	170,	171,	172,	100,	100,	100,	100,	100,	100},
    {100,	181,	100,	100,	100,	100,	100,	174,	100,	100,	100,	100,	100,	100,	100,	100,	100,	176,	100,	100,	100,	100,	100,	100,	100,	100,	100,	100,	100,	100,	100,	100,	100,	100,	100,	100,	100,	100,	100,	100,	100,	100,	100,	100,	100,	100,	100,	100,	100,	175,	177,	178,	179,	180,	100},
    {100,	100,	183,	100,	100,	100,	100,	182,	183,	100,	100,	183,	183,	183,	183,	100,	100,	100,	100,	100,	100,	100,	100,	100,	100,	100,	183,	100,	100,	183,	100,	100,	183,	183,	100,	100,	100,	183,	183,	183,	183,	183,	183,	183,	183,	183,	183,	183,	183,	100,	100,	100,	100,	100,	100},
    {100,	184,	100,	100,	100,	100,	100,	100,	100,	100,	100,	100,	100,	100,	100,	100,	100,	100,	100,	100,	100,	100,	100,	100,	100,	100,	100,	100,	100,	100,	100,	100,	100,	100,	100,	100,	100,	100,	100,	100,	100,	100,	100,	100,	100,	100,	100,	100,	100,	100,	100,	100,	100,	100,	100},
    {100,	100,	186,	100,	100,	100,	100,	100,	186,	100,	100,	186,	185,	186,	186,	100,	100,	100,	100,	100,	100,	100,	100,	100,	100,	100,	186,	100,	100,	186,	100,	100,	186,	186,	100,	100,	100,	186,	186,	186,	186,	186,	186,	186,	186,	186,	186,	186,	186,	100,	100,	100,	100,	100,	100},
    {100,	187,	100,	100,	100,	100,	100,	187,	187,	100,	100,	187,	100,	187,	187,	100,	100,	187,	100,	100,	100,	100,	100,	100,	100,	100,	100,	100,	100,	100,	100,	100,	100,	100,	100,	100,	100,	187,	187,	187,	187,	187,	187,	187,	100,	100,	100,	100,	100,	187,	187,	187,	187,	187,	100},
    {100,	100,	100,	100,	100,	100,	100,	100,	189,	100,	100,	100,	100,	189,	188,	100,	100,	100,	100,	100,	100,	100,	100,	100,	100,	100,	100,	100,	100,	100,	100,	100,	100,	100,	100,	100,	100,	100,	100,	100,	100,	100,	100,	100,	100,	100,	100,	100,	100,	100,	100,	100,	100,	100,	100}
};

// Simbolos Nao-Terminais da Gramatica
enum NONTERMINALS {
    PROGRAMA,
    PROCEDIMENTOFUNCAO,
    DECLARAPROCEDIMENTO,
    DECLARAFUNCAO,
    PARAMETROS,
    DECLARAPARAMETROS,
    BLOCOVARIAVEIS,
    DECLARACOES,
    DECLARACOESBONUS,
    DECLARATIONS,
    DECLARATIPO,
    DECLARAVARIAVEIS,
    DECLARAIDENTIFICADOR,
    DECLARAIDENTIFICADORBONUS,
    VETORMATRIZ,
    DIMENSAO,
    DIMENSAOBONUS,
    TIPOBASICO,
    BLOCOCOMANDOS,
    LISTACOMANDOS,
    LISTACOMANDOSBONUS,
    COMANDOS,
    COMMANDSIDENTIFIER,
    ELSEIF,
    STEPFOR,
    EXPRESSAO,
    EXPRESSAONEW,
    EXPRESSAOSIMPLES,
    SIGNAL,
    EXPRESSAOSIMPLESNEW,
    TERMO,
    TERMONEW,
    FATOR,
    IDENTIFIERVARIABLE,
    VARIAVEL,
    VARIABLEEXP,
    EXPRITER,
    EXPRITERBONUS};


#define ACCEPTED 1
#define REJECTED 0

struct SINTATICO_GLOBALS {
    int token;
    int status;
    Queue tokens;
    Token tk;
};
struct SINTATICO_GLOBALS SINTATICO;


int getToken()
{
    if (!isEmpty(SINTATICO.tokens))
    {
        SINTATICO.tk = popInQueue(SINTATICO.tokens);
        return SINTATICO.tk->id;
    }
    else
        return -1;
}

void error(int t)
{
    if (SINTATICO.status == ACCEPTED)
    {
        printf("ERRO DE SINTAXE. Linha: %d Coluna: %d -> \'%s\'", SINTATICO.tk->line, SINTATICO.tk->column, (char *) SINTATICO.tk->data);
        SINTATICO.status = REJECTED;
    }
}
void advance() {SINTATICO.token = getToken(); /*printf("\navancou -> %d [%s]", SINTATICO.tk->id, (char *) SINTATICO.tk->data);*/}
void eat(int t) {if (SINTATICO.token == t) {/*printf("\ncomeu -> %d", SINTATICO.token);*/ advance();} else error(t);}























int getTerminal(int tokenId)
{
    switch(tokenId)
    {
        case ALGORITMO:             return  0;
        case IDENTIFICADOR:         return  1;
        case PONTO_E_VIRGULA:       return  2;
        case PONTO:                 return  3;
        case PROCEDIMENTO:          return  4;
        case FUNCAO:                return  5;
        case DOIS_PONTOS:           return  6;
        case ABRE_PARENTESES:       return  7;
        case FECHA_PARENTESES:      return  8;
        case VARIAVEIS:             return  9;
        case TIPO:                  return 10;
        case IGUAL:                 return 11;
        case ABRE_COLCHETES:        return 12;
        case FECHA_COLCHETES:       return 13;
        case VIRGULA:               return 14;
        case VETOR:                 return 15;
        case MATRIZ:                return 16;
        case NUMERO_INTEIRO:        return 17;
        case INTEIRO:               return 18;
        case REAL:                  return 19;
        case CARACTERE:             return 20;
        case LOGICO:                return 21;
        case INICIO:                return 22;
        case FIM:                   return 23;
        case ATRIBUICAO:            return 24;
        case SE:                    return 25;
        case ENTAO:                 return 26;
        case SENAO:                 return 27;
        case ENQUANTO:              return 28;
        case FACA:                  return 29;
        case PARA:                  return 30;
        case DE:                    return 31;
        case ATE:                   return 32;
        case PASSO:                 return 33;
        case REPITA:                return 34;
        case LEIA:                  return 35;
        case IMPRIMA:               return 36;
        case DIFERENTE:             return 37;
        case MENOR:                 return 38;
        case MENOR_IGUAL:           return 39;
        case MAIOR_IGUAL:           return 40;
        case MAIOR:                 return 41;
        case MAIS:                  return 42;
        case MENOS:                 return 43;
        case OU:                    return 44;
        case VEZES:                 return 45;
        case DIVISAO:               return 46;
        case DIV:                   return 47;
        case E:                     return 48;
        case NAO:                   return 49;
        case NUMERO_REAL:           return 50;
        case VERDADEIRO:            return 51;
        case FALSO:                 return 52;
        case STRING:                return 53;
        case END_OF_STRING:         return 54;
    }
}


void deriveProduction(int production);
void F(int nonterminal)
{
    // printf("\nF(~T:%d, T:%d[%d]) = %d", nonterminal, SINTATICO.token, getTerminal(SINTATICO.token), parse[nonterminal][getTerminal(SINTATICO.token)]);
    deriveProduction(parse[nonterminal][getTerminal(SINTATICO.token)]);
}

void deriveProduction(int production)
{
    if (SINTATICO.status == ACCEPTED)
    {
    // printf("\n-%d", production-100);
    switch(production - 100)
    {
        case  1: eat(ALGORITMO); eat(IDENTIFICADOR); eat(PONTO_E_VIRGULA); F(BLOCOVARIAVEIS); F(PROCEDIMENTOFUNCAO); F(BLOCOCOMANDOS); eat(PONTO); eat(END_OF_STRING); break;
        case  2: F(DECLARAPROCEDIMENTO); F(PROCEDIMENTOFUNCAO); break;
        case  3: F(DECLARAFUNCAO); F(PROCEDIMENTOFUNCAO); break;
        case  4: break;
        case  5: eat(PROCEDIMENTO); eat(IDENTIFICADOR); F(PARAMETROS); eat(PONTO_E_VIRGULA); F(DECLARAPARAMETROS); F(BLOCOVARIAVEIS); F(BLOCOCOMANDOS); eat(PONTO_E_VIRGULA); break;
        case  6: eat(FUNCAO); eat(IDENTIFICADOR); F(PARAMETROS); eat(DOIS_PONTOS); F(TIPOBASICO); eat(PONTO_E_VIRGULA); F(DECLARAPARAMETROS); F(BLOCOVARIAVEIS); F(BLOCOCOMANDOS); break;
        case  7: eat(ABRE_PARENTESES); F(DECLARAIDENTIFICADOR); eat(FECHA_PARENTESES); break;
        case  8: break;
        case  9: F(DECLARACOES); break;
        case 10: break;
        case 11: eat(VARIAVEIS); F(DECLARACOES); break;
        case 12: break;
        case 13: F(DECLARATIONS); F(DECLARACOESBONUS); break;
        case 14: F(DECLARACOES); break;
        case 15: break;
        case 16: F(DECLARATIPO); break;
        case 17: F(DECLARAVARIAVEIS); break;
        case 18: eat(TIPO); eat(IDENTIFICADOR); eat(IGUAL); F(VETORMATRIZ); eat(ABRE_COLCHETES); F(DIMENSAO); eat(FECHA_COLCHETES); F(TIPOBASICO); eat(PONTO_E_VIRGULA); break;
        case 19: F(TIPOBASICO); eat(DOIS_PONTOS); F(DECLARAIDENTIFICADOR); eat(PONTO_E_VIRGULA); break;
        case 20: eat(IDENTIFICADOR); F(DECLARAIDENTIFICADORBONUS); break;
        case 21: eat(VIRGULA); F(DECLARAIDENTIFICADOR); break;
        case 22: break;
        case 23: eat(VETOR); break;
        case 24: eat(MATRIZ); break;
        case 25: eat(NUMERO_INTEIRO); eat(DOIS_PONTOS); eat(NUMERO_INTEIRO); F(DIMENSAOBONUS); break;
        case 26: eat(VIRGULA); F(DIMENSAO); break;
        case 27: break;
        case 28: eat(INTEIRO); break;
        case 29: eat(REAL); break;
        case 30: eat(CARACTERE); break;
        case 31: eat(LOGICO); break;
        case 32: eat(IDENTIFICADOR); break;
        case 33: eat(INICIO); F(LISTACOMANDOS); eat(FIM); break;
        case 34: F(COMANDOS); eat(PONTO_E_VIRGULA); F(LISTACOMANDOSBONUS); break;
        case 35: F(LISTACOMANDOS); break;
        case 36: break;
        case 37: eat(IDENTIFICADOR); F(COMMANDSIDENTIFIER); break;
        case 38: break;
        case 39: eat(ABRE_PARENTESES); F(EXPRITER); eat(FECHA_PARENTESES); break;
        case 40: eat(ATRIBUICAO); F(EXPRESSAO); break;
        case 41: eat(ABRE_COLCHETES); F(EXPRITER); eat(FECHA_COLCHETES); eat(ATRIBUICAO); F(EXPRESSAO); break;
        case 42: eat(SE); F(EXPRESSAO); eat(ENTAO); F(LISTACOMANDOS); F(ELSEIF); eat(FIM); eat(SE); break;
        case 43: eat(SENAO); F(LISTACOMANDOS); break;
        case 44: break;
        case 45: eat(ENQUANTO); F(EXPRESSAO); eat(FACA); F(LISTACOMANDOS); eat(FIM); eat(ENQUANTO); break;
        case 46: eat(PARA); eat(IDENTIFICADOR); eat(DE); F(EXPRESSAO); eat(ATE); F(EXPRESSAO); F(STEPFOR); eat(FACA); F(LISTACOMANDOS); eat(FIM); eat(PARA); break;
        case 47: eat(PASSO); F(EXPRESSAO); break;
        case 48: break;
        case 49: eat(REPITA); F(LISTACOMANDOS); eat(ATE); F(EXPRESSAO); break;
        case 50: eat(LEIA); eat(ABRE_PARENTESES); F(VARIAVEL); eat(FECHA_PARENTESES); break;
        case 51: eat(IMPRIMA); eat(ABRE_PARENTESES); F(EXPRITER); eat(FECHA_PARENTESES); break;
        case 52: F(EXPRESSAOSIMPLES); F(EXPRESSAONEW); break;
        case 53: eat(IGUAL); F(EXPRESSAOSIMPLES); F(EXPRESSAONEW); break;
        case 54: eat(DIFERENTE); F(EXPRESSAOSIMPLES); F(EXPRESSAONEW); break;
        case 55: eat(MENOR); F(EXPRESSAOSIMPLES); F(EXPRESSAONEW); break;
        case 56: eat(MENOR_IGUAL); F(EXPRESSAOSIMPLES); F(EXPRESSAONEW); break;
        case 57: eat(MAIOR_IGUAL); F(EXPRESSAOSIMPLES); F(EXPRESSAONEW); break;
        case 58: eat(MAIOR); F(EXPRESSAOSIMPLES); F(EXPRESSAONEW); break;
        case 59: break;
        case 60: F(SIGNAL); F(TERMO); F(EXPRESSAOSIMPLESNEW); break;
        case 61: eat(MAIS); break;
        case 62: eat(MENOS); break;
        case 63: break;
        case 64: eat(MAIS); F(TERMO); F(EXPRESSAOSIMPLESNEW); break;
        case 65: eat(MENOS); F(TERMO); F(EXPRESSAOSIMPLESNEW); break;
        case 66: eat(OU); F(TERMO); F(EXPRESSAOSIMPLESNEW); break;
        case 67: break;
        case 68: F(FATOR); F(TERMONEW); break;
        case 69: eat(VEZES); F(FATOR); F(TERMONEW); break;
        case 70: eat(DIVISAO); F(FATOR); F(TERMONEW); break;
        case 71: eat(DIV); F(FATOR); F(TERMONEW); break;
        case 72: eat(E); F(FATOR); F(TERMONEW); break;
        case 73: break;
        case 74: eat(ABRE_PARENTESES); F(EXPRESSAO); eat(FECHA_PARENTESES); break;
        case 75: eat(NAO); F(FATOR); break;
        case 76: eat(NUMERO_INTEIRO); break;
        case 77: eat(NUMERO_REAL); break;
        case 78: eat(VERDADEIRO); break;
        case 79: eat(FALSO); break;
        case 80: eat(STRING); break;
        case 81: eat(IDENTIFICADOR); F(IDENTIFIERVARIABLE); break;
        case 82: eat(ABRE_PARENTESES); F(EXPRITER); eat(FECHA_PARENTESES); break;
        case 83: F(VARIABLEEXP); break;
        case 84: eat(IDENTIFICADOR); F(VARIABLEEXP); break;
        case 85: eat(ABRE_COLCHETES); F(EXPRITER); eat(FECHA_COLCHETES); break;
        case 86: break;
        case 87: F(EXPRESSAO); F(EXPRITERBONUS); break;
        case 88: eat(VIRGULA); F(EXPRITER);
        case 89: break;
        case  0: error(0); break;
        default: printf("\nFALTOU"); break;
    }
    }
}







void ACCEPT()
{
    printf("PROGRAMA CORRETO.");
}
// void reject(char * formatMsg)
// {
//     printf(formatMsg, getTokenString(token));
//     status = REJECTED;
// }

int sintatico()
{
    SINTATICO.status = ACCEPTED;
    SINTATICO.token  = 0;
    advance();
    deriveProduction(PROGRAMA + 101);
    return SINTATICO.status;
}





void main()
{
    SINTATICO.tokens = lexico();
    if (SINTATICO.tokens != NULL)
    {
        // for (Token t = popInQueue(SINTATICO.tokens); t != NULL; t = popInQueue(SINTATICO.tokens))
        // {
        //     printf("\n%d", t->id);
        // }
        int result = sintatico();
        if(result)
            ACCEPT();
    }
}