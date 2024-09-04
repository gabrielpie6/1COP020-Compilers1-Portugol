#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#include "queue.h"
#include "tokens.h"


#define NULL_STATE 0
typedef int State;

State currentState = (State) 10;
State validState   = (State) NULL_STATE;
int movCount       = 0;
int strLen         = 0;

int column = 1;
int line   = 1;


Queue buffer, tokens;
int seek;
int reading = 1;


struct LEXICO_GLOBALS {
    int status;
};
struct LEXICO_GLOBALS LEXICO;


char * strdup(const char *s) {
    size_t len = strlen(s) + 1;
    char *copy = malloc(len);
    if (copy) {
        memcpy(copy, s, len);
    }
    return copy;
}


char getCharToParse()
{
    char * w;
    if (seek < getQueueLength(buffer) || !reading)
    {
        w = (char *) seekInQueue(buffer, seek);
        seek++;
    } else
    {
        w = malloc(sizeof(char));
        int eof = scanf("%c", w);
        if (eof == EOF)
        {
            reading = 0;
            return eof;
        }
        insertInQueue(buffer, w);
        seek++;
    }
    return *w;
}

void appendToken(int id, void * data)
{
    insertInQueue(tokens, createToken(id, data, line, column));
}

void acceptWord(int length)
{
    char * w;
    char word[length + 1];
    char wordLowerCase[length + 1];
    for (int i = 0; i < length; i++)
    {
        w       = (char *) popInQueue(buffer);
        word[i] = *w;
        wordLowerCase[i] = ('A' <= word[i] && word[i] <= 'Z') ? (word[i] + ('a'-'A')) : (word[i]);
        free(w);
    }
    word[length] = '\0';
    seek = 0;

    



    // printf("\nTOKEN: %s", word);
    // if (validState != 16 && validState != 15) printf("\n");
    switch(validState)
    {
        case 11: // possible IDENTIFIER or any special word
            // printf("IDENTIFICADOR [%s]", word);
                 if (strcmp(wordLowerCase, "algoritmo")     == 0)   appendToken(ALGORITMO,      strdup(word));
            else if (strcmp(wordLowerCase, "inicio")        == 0)   appendToken(INICIO,         strdup(word));
            else if (strcmp(wordLowerCase, "fim")           == 0)   appendToken(FIM,            strdup(word));
            else if (strcmp(wordLowerCase, "variaveis")     == 0)   appendToken(VARIAVEIS,      strdup(word));
            else if (strcmp(wordLowerCase, "inteiro")       == 0)   appendToken(INTEIRO,        strdup(word));
            else if (strcmp(wordLowerCase, "real")          == 0)   appendToken(REAL,           strdup(word));
            else if (strcmp(wordLowerCase, "caractere")     == 0)   appendToken(CARACTERE,      strdup(word));
            else if (strcmp(wordLowerCase, "logico")        == 0)   appendToken(LOGICO,         strdup(word));
            else if (strcmp(wordLowerCase, "vetor")         == 0)   appendToken(VETOR,          strdup(word));
            else if (strcmp(wordLowerCase, "matriz")        == 0)   appendToken(MATRIZ,         strdup(word));
            else if (strcmp(wordLowerCase, "tipo")          == 0)   appendToken(TIPO,           strdup(word));
            else if (strcmp(wordLowerCase, "funcao")        == 0)   appendToken(FUNCAO,         strdup(word));
            else if (strcmp(wordLowerCase, "procedimento")  == 0)   appendToken(PROCEDIMENTO,   strdup(word));
            else if (strcmp(wordLowerCase, "se")            == 0)   appendToken(SE,             strdup(word));
            else if (strcmp(wordLowerCase, "entao")         == 0)   appendToken(ENTAO,          strdup(word));
            else if (strcmp(wordLowerCase, "senao")         == 0)   appendToken(SENAO,          strdup(word));
            else if (strcmp(wordLowerCase, "enquanto")      == 0)   appendToken(ENQUANTO,       strdup(word));
            else if (strcmp(wordLowerCase, "faca")          == 0)   appendToken(FACA,           strdup(word));
            else if (strcmp(wordLowerCase, "para")          == 0)   appendToken(PARA,           strdup(word));
            else if (strcmp(wordLowerCase, "de")            == 0)   appendToken(DE,             strdup(word));
            else if (strcmp(wordLowerCase, "ate")           == 0)   appendToken(ATE,            strdup(word));
            else if (strcmp(wordLowerCase, "passo")         == 0)   appendToken(PASSO,          strdup(word));
            else if (strcmp(wordLowerCase, "repita")        == 0)   appendToken(REPITA,         strdup(word));
            else if (strcmp(wordLowerCase, "leia")          == 0)   appendToken(LEIA,           strdup(word));
            else if (strcmp(wordLowerCase, "imprima")       == 0)   appendToken(IMPRIMA,        strdup(word));
            else if (strcmp(wordLowerCase, "verdadeiro")    == 0)   appendToken(VERDADEIRO,     strdup(word));
            else if (strcmp(wordLowerCase, "falso")         == 0)   appendToken(FALSO,          strdup(word));
            else if (strcmp(wordLowerCase, "e")             == 0)   appendToken(E,              strdup(word));
            else if (strcmp(wordLowerCase, "ou")            == 0)   appendToken(OU,             strdup(word));
            else if (strcmp(wordLowerCase, "nao")           == 0)   appendToken(NAO,            strdup(word));
            else if (strcmp(wordLowerCase, "div")           == 0)   appendToken(DIV,            strdup(word));
            else                                                    appendToken(IDENTIFICADOR,  strdup(word));
            break;
        case 12: // INTEGER
            appendToken(NUMERO_INTEIRO, strdup(word));
            break;
        case 14: // REAL
            appendToken(NUMERO_REAL, strdup(word));
            break;
        case 15: // SPACE
            break;
        case 16: // NEWLINE
            column = 0;
            line++;
            break;
        case 17:
        case 18:
        case 22:
        case 26: // DELIMITADOR
            // printf("DELIMITADOR [%s]", word);
                switch(*word)
                {
                    case ';':
                        // printf("PONTO_E_VIRGULA");
                        appendToken(PONTO_E_VIRGULA, strdup(word));
                        break;
                    case ',':
                        // printf("VIRGULA");
                        appendToken(VIRGULA, strdup(word));
                        break;
                    case ':':
                        // printf("DOIS_PONTOS");
                        appendToken(DOIS_PONTOS, strdup(word));
                        break;
                    case '.':
                        // printf("PONTO");
                        appendToken(PONTO, strdup(word));
                        break;
                    case '[':
                        // printf("ABRE_COLCHETES");
                        appendToken(ABRE_COLCHETES, strdup(word));
                        break;
                    case ']':
                        // printf("FECHA_COLCHETES");
                        appendToken(FECHA_COLCHETES, strdup(word));
                        break;
                    case '(':
                        // printf("ABRE_PARENTESES");
                        appendToken(ABRE_PARENTESES, strdup(word));
                        break;
                    case ')':
                        // printf("FECHA_COLCHETES");
                        appendToken(FECHA_PARENTESES, strdup(word));
                        break;
                    case '=':
                        // printf("IGUAL");
                        appendToken(IGUAL, strdup(word));
                        break;
                    case '>':
                        // printf("MAIOR");
                        appendToken(MAIOR, strdup(word));
                        break;
                    case '<':
                        // printf("MENOR");
                        appendToken(MENOR, strdup(word));
                        break;
                    case '+':
                        // printf("MAIS");
                        appendToken(MAIS, strdup(word));
                        break;
                    case '-':
                        // printf("MENOS");
                        appendToken(MENOS, strdup(word));
                        break;
                    case '*':
                        // printf("VEZES");
                        appendToken(VEZES, strdup(word));
                        break;
                    case '/':
                        // printf("DIVISAO");
                        appendToken(DIVISAO, strdup(word));
                        break;
                }
            break;
        case 19: // LINE COMMENT
            break;
        case 21: // BLOCK COMMENT
            break;
        case 23: // DIFERENTE
            // printf("DIFERENTE");
            appendToken(DIFERENTE, strdup(word));
            break;
        case 24: // MENOR_IGUAL
            // printf("MENOR_IGUAL");
            appendToken(MENOR_IGUAL, strdup(word));
            break;
        case 25: // ATRIBUICAO
            // printf("ATRIBUICAO");
            appendToken(ATRIBUICAO, strdup(word));
            break;
        case 27: // MAIOR_IGUAL
            // printf("MAIOR_IGUAL");
            appendToken(MAIOR_IGUAL, strdup(word));
            break;
        case 28: // ERROR: not in alphabet
            printf("ERRO LEXICO. Linha: %d Coluna: %d -> \'%s\'", line, column, word);
            LEXICO.status = 0;
            break;
        case 30:
            // printf("STRING");
            appendToken(STRING, strdup(word));
            break;
    }

    column += length;

    currentState = (State) 10;
    validState   = (State) NULL_STATE;
    movCount     = 0;
    strLen       = 0;
}


















int getState(State s)
{
    return (int) s - 10;
}
int getSymbol(char w)
{
         if(('a' <= w && w <= 'z') ||
            ('A' <= w && w <= 'Z'))return 1;
    else if('0' <= w && w <= '9')  return 2;
    else if(w == '_')              return 3;
    else if(w == '.')              return 4;
    else if(w == ' ')              return 5;
    else if(w == '\n')             return 6;
    else if(w == '/')              return 7;
    else if(('(' <= w && w <= ',') ||
            (':' <= w && w <= ';') ||
            w == '[' || w == ']' ) return 8;
    else if(w == '{')              return 10;
    else if(w == '}')              return 11;
    else if(w == '<')              return 12;
    else if(w == '>')              return 13;
    else if(w == '=')              return 14;
    else if(w == '-')              return 15;
    else if(w == '"')              return 16;
    else // w nao pertence ao alfabeto
        return 9;
}

State delta(State q, char w)
{
    int delta[21][17] = {
    //                1       2      3       4       5       6       7            8              9      10      11      12      13      14      15      16
    //    	NULl  [a-z]	  [0-9]      _	     .   blank	    \n	     /	 delim-.-/-<->-=--	  alfa	     {	     }	     <	     >	     =	     -       "
    /*10*/	{00,	11,		12,		11,		17,		15,		16,		18,		     17,    		28,		20,		28,		22,		26,		17,		17,     29},
    /*11*/	{00,	11,		11,		11,		00,		00,		00,		00,		     00,    		00,		00,		00,		00,		00,		00,		00,     00},
    /*12*/	{00,	00,		12,		00,		13,		00,		00,		00,		     00,    		00,		00,		00,		00,		00,		00,		00,     00},
    /*13*/	{00,	00,		14,		00,		00,		00,		00,		00,		     00,    		00,		00,		00,		00,		00,		00,		00,     00},
    /*14*/	{00,	00,		14,		00,		00,		00,		00,		00,		     00,    		00,		00,		00,		00,		00,		00,		00,     00},
    /*15*/	{00,	00,		00,		00,		00,		00,		00,		00,		     00,    		00,		00,		00,		00,		00,		00,		00,     00},
    /*16*/	{00,	00,		00,		00,		00,		00,		00,		00,		     00,    		00,		00,		00,		00,		00,		00,		00,     00},
    /*17*/	{00,	00,		00,		00,		00,		00,		00,		00,		     00,    		00,		00,		00,		00,		00,		00,		00,     00},
    /*18*/	{00,	00,		00,		00,		00,		00,		00,		19,		     00,    		00,		00,		00,		00,		00,		00,		00,     00},
    /*19*/	{00,	19,		19,		19,		19,		19,		00,		19,		     19,    		19,		19,		19,		00,		00,		00,		00,     00},
    /*20*/	{00,	20,		20,		20,		20,		20,		20,		20,		     20,    		20,		20,		21,		00,		00,		00,		00,     00},
    /*21*/	{00,	00,		00,		00,		00,		00,		00,		00,		     00,    		00,		00,		00,		00,		00,		00,		00,     00},
    /*22*/	{00,	00,		00,		00,		00,		00,		00,		00,		     00,    		00,		00,		00,		00, 	23,		24,		25,     00},
    /*23*/	{00,	00,		00,		00,		00,		00,		00,		00,		     00,    		00,		00,		00,		00,		00,		00,		00,     00},
    /*24*/	{00,	00,		00,		00,		00,		00,		00,		00,		     00,    		00,		00,		00,		00,		00,		00,		00,     00},
    /*25*/	{00,	00,		00,		00,		00,		00,		00,		00,		     00,    		00,		00,		00,		00,		00,		00,		00,     00},
    /*26*/	{00,	00,		00,		00,		00,		00,		00,		00,		     00,    		00,		00,		00,		00,		00,		27,		00,     00},
    /*27*/	{00,	00,		00,		00,		00,		00,		00,		00,		     00,    		00,		00,		00,		00,		00,		00,		00,     00},
    /*28*/	{00,	00,		00,		00,		00,		00,		00,		00,		     00,    		00,		00,		00,		00,		00,		00,		00,     00},
    /*29*/  {00,    29,     29,     29,     29,     29,     29,     29,          29,            29,     29,     29,     29,     29,     29,     29,     30},
    /*30*/  {00,	00,		00,		00,		00,		00,		00,		00,		     00,    		00,		00,		00,		00,		00,		00,		00,     00},
    };

    return (State) delta[getState(q)][getSymbol(w)];
}
int isFinal(State q)
{
    int F[] = {11, 12, 14, 15, 16, 17, 18, 19, 21, 22, 23, 24, 25, 26, 27, 28, 30};
    int len = 17;
    int i = 0;
    while (i < len)
    {
        if (F[i] == (int) q)
            return 1;
        i++;
    }
    return 0;
}






















Queue lexico()
{
    char w;
    int result, eof;
    State q;

    LEXICO.status = 1;

    buffer = createQueue();
    tokens = createQueue();



    eof  = 0;
    seek = 0;
    while(reading || !isEmpty(buffer))
    {
        w = getCharToParse();

        if (w == EOF && isEmpty(buffer))
            break;

        q = delta(currentState, w);
        movCount++;

        if (q == NULL_STATE)
        { // Fim de reconhecimento
            acceptWord(strLen);
            if (!LEXICO.status)
            {
                // stopScanningDueLexicalError();
                return NULL;
            }
        } else
        {
            currentState = q;
            if (isFinal(q))
            {
                validState = q;
                strLen = movCount;
            }
        }

        // acceptWord(1);
        // printf("%3c", w);
    }
    // Tratamento de ultimo reconhecimento

    // printf("\n");

    // printf("%3c", popInQueue(buffer));
    // printf("%3c", popInQueue(buffer));
    // printf("TAMANHO: %d", getQueueLength(buffer));
    // int k = getQueueLength(buffer);
    // for (int i = 0; i < k; i++)
    //     printf("%3c", popInQueue(buffer));

    // printf("TAMANHO: %d", getQueueLength(buffer));






    // w      = getCharToParse();
    // result = process(w)
    // if (result == END_OF_WORD)
    // {
    //     acceptWord(length)
    //     break;
    // }

    appendToken(END_OF_STRING, NULL);
    return tokens;
}