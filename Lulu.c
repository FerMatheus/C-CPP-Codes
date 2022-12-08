#include <stdio.h>
#include <time.h>
#define RAND_MAX = 1000;

struct No
{
    long long record;
    char nome[10];
    long long idade;
    char endereco[10];
    long long numero;
    char complemento[10];
    long long cep;
    struct No *proximo;
};

void thread_func(){
    struct No *lista = malloc(sizeof(struct No));
    lista->record = 1;
    lista->nome[0] = '~';
    lista->idade = 1;
    lista->endereco[0] = '~';
    lista->complemento[0] = 1;
    lista->cep = 1;
    struct No *atual = lista;
    for (long long i = 0; i < 999999999; i++)
    {
        struct No *prox = malloc(sizeof(struct No));
        prox->record = atual->record + 1;
        prox->nome[0] = '~';
        prox->idade = 1;
        prox->endereco[0] = '~';
        prox->complemento[0] = 1;
        prox->cep = 1;
        atual->proximo = prox;
        atual = prox;
    }
    double testes[100];

    for (int i = 1; i <= 100; i++)
    {

        int inicio = (i - 1) * 1000 + 1;

        clock_t t = clock();
        for (int j = 0; j < 100; j++)
        {
            int r = rand() % 999;
            atual = lista;
            while (atual->record != inicio + r)
            {
                struct No *prox = atual->proximo;
                atual = prox;
            }
        }
        t = clock() - t;
        testes[i - 1] = ((double)t)*1000 / ((CLOCKS_PER_SEC));
        printf("%.3f\n", testes[i - 1]);
    }
    atual = lista;
}

int main(void)
{
    for(int i = 0 ; i < 10 ; i++){
        thread_func();
        thread_func();
        thread_func();
        for(int j = 0 ; j < 10 ; j++){
            thread_func();
            thread_func();
            thread_func();
            for(int k = 0 ; k < 10 ; k++) thread_func();
        }
    }

    return 0;
}