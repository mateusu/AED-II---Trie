//TRIE
/*2.1
MATHEUS DE OLIVEIRA LÊU - 8802621

TRIE RETIRADA DE http://www.geeksforgeeks.org/trie-insert-and-search/
ADAPTADA PARA O EP
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define ALPHABET_SIZE (26)
#define CHAR_TO_INDEX(c) ((int)c - (int)'a')
#define MAX 10000

struct TrieNode
{
    struct TrieNode *filho[ALPHABET_SIZE];
//ARMAZENA AS POSIÇÕES DAS PALAVRAS NO TEXTO E O NÚMERO DE ELEMENTOS
    int pos[10000];
    int elem;
    bool ehFolha;
};

struct TrieNode *getNode(void)
{
    struct TrieNode *Node = NULL;

    Node = (struct TrieNode *)malloc(sizeof(struct TrieNode));

    if (Node)
    {
        int i;

        Node->ehFolha = false;

        for (i = 0; i < ALPHABET_SIZE; i++)
            Node->filho[i] = NULL;
    }

    return Node;
}

void insere(struct TrieNode *raiz, const char *chave, int pos)
{
    int level;
    int tam = strlen(chave);
    int indice;

    struct TrieNode *atual = raiz;
    atual->elem = 0;
    for (level = 0; level < tam; level++)
    {
        indice = CHAR_TO_INDEX(chave[level]);
        if(atual->elem > 0){

        }else{atual->elem = 0;}
        if (!atual->filho[indice])
            atual->filho[indice] = getNode();

        atual = atual->filho[indice];
    }

    // mark last node as leaf
    atual->ehFolha = true;
    atual->pos[atual->elem] = pos;
    //printf("%i ", atual->pos[atual->elem]);
    atual->elem++;
   // if(strcmp(chave, "ex") == 0) printf("%i\n", atual->elem);

}

bool busca(struct TrieNode *raiz, const char *chave)
{
    int level;
    int tam = strlen(chave);
    int indice;
    struct TrieNode *atual = raiz;

    for (level = 0; level < tam; level++)
    {
        indice = CHAR_TO_INDEX(chave[level]);

        if (!atual->filho[indice])
            return false;

        atual = atual->filho[indice];
    }
    int i;
    //printf("%i\n", atual->elem);
    for(i = 0; i < atual->elem; i++){
            if(i == 0)printf("%i", atual->pos[i]);
            else(printf(" %i", atual->pos[i]));
    }
    //printf("%i", pCrawl->elem);
    return (atual != NULL && atual->ehFolha);
}

int main()
{
    char texto[100000];
    char palavra[100];
    char padrao[100];
    int valor;
    scanf("%[^\n]s\n", &texto);
    scanf("%d", &valor);
    struct TrieNode *raiz = getNode();
    int count = 0, i, j;

    while(count < strlen(texto)-1)
    {
        j = 0;
        for(i = count; i < strlen(texto); i++)
        {
            j++;
            if(texto[i] == ' ')break;
            palavra[j-1] = texto[i];

        }
        insere(raiz, palavra, count);
        memset(&palavra[0], 0, sizeof(palavra));
        count += j;
    }
    int x, resp;
    for(x = 0; x < valor; x++){
        scanf("%s", &padrao);
        resp = busca(raiz, padrao);
        if(resp == 0) printf("%d", -1);
        printf("\n");
        memset(&padrao[0], 0, sizeof(padrao));

    }
    return 0;

}
