#include <stdio.h>
#include <stdlib.h>

typedef struct tipoNo{
    int dado;
    char cor;
    struct tipoNo *noEsquerdo;
    struct tipoNo *noDireito;
}tipoNo;

typedef struct tipoArvore{
    tipoNo *topo;
}tipoArvore;

void criarArvore(tipoArvore *arvore){
    arvore->topo = NULL;
}

tipoNo* buscarPai(int numero, tipoNo *raiz){
    tipoNo *aux;

    if(raiz == NULL){
        return NULL;
    }

    if(raiz->noEsquerdo == NULL && raiz->noDireito == NULL){
        return NULL;
    }

    else if((raiz->noEsquerdo != NULL) && (raiz->noEsquerdo->dado == numero)){
            return raiz;
    }

    else if((raiz->noDireito != NULL) && (raiz->noDireito->dado == numero)){
            return raiz;
    }

    else{
        aux = buscarPai(numero,raiz->noEsquerdo);
        if(aux==NULL){
            aux = buscarPai(numero,raiz->noDireito);
        }
        return aux;
    }
}

tipoNo* buscarAvo(int numero, tipoNo *raiz){
    tipoNo *pai;

    pai = buscarPai(numero,raiz);

    if(pai == NULL){
        return NULL;
    }
    else{
        return buscarPai(aux->dado, raiz);
    }
}

tipoNo* buscarTio(int numero, tipoNo *raiz){
    tipoNo *avo;
    int pai;

    avo = buscarAvo(numero, raiz);

    if(avo == NULL){
        return NULL;
    }

    else{
        if(avo->noEsquerdo == NULL || avo->noDireito == NULL){
            return NULL;
        }
        else{
            pai = (buscarPai(numero, raiz)->dado);
            if(avo->noEsquerdo->dado == pai){
                return avo->noDireito;
            }
            if(avo->noDireito->dado == pai){
                return avo->noEsquerdo;
            }
        }
    }
}

tipoNo* balancearCor(tipoNo *raiz){
}

void inserirElemento(int numero, tipoNo *raiz){
    if(raiz == NULL){
        tipoNo *aux;
        aux = (tipoNo *) malloc (sizeof(tipoNo));
        aux->dado = numero;
        aux->cor = 'V';
        aux->noEsquerdo = NULL;
        aux->noDireito = NULL;
        raiz = aux;
    }
    if(numero < raiz->dado){
        raiz->noEsquerdo = inserirElemento(numero, raiz->noEsquerdo);
    }
    else if (numero > raiz->dado){
        raiz->noDireito = inserirElemento(numero, raiz->noDireito);
    }
    return balancearCor(raiz);
}

void inserirArvore(int numero, tipoArvore* arvore){
    arvore->topo = inserirElemento(numero, arvore->topo);
}

tipoNo* buscarElemento(int numero, tipoNo *raiz){
    if(raiz == NULL){
        return NULL;
    }
    if (numero < raiz->dado){
        return buscarElemento(numero, raiz->noEsquerdo);
    }
    if(numero > raiz->dado){
        return buscarElemento(numero,raiz->noDireito);
    }
    return raiz;
}

tipoNo* buscarNaArvore(int numero, tipoArvore arvore){
    return buscarElemento(numero, arvore.topo);
}

tipoNo* removerElemento(int numero, tipoNo *raiz){
}

void removerDaArvore(int numero, tipoArvore *arvore){
    arvore->topo = removerElemento(numero, arvore->topo);
}

void lerArquivo(tipoArvore *arvore, char *nomeArquivo){
    FILE *arquivo;
    int valor;
    arquivo = fopen(nomeArquivo, "r");
    if(arquivo == 0){
        printf("\nNao existe o arquivo na pasta do programa.\n\n");
    } else {
        while((fscanf(arquivo,"%d",&valor) != EOF)){
            inserirArvore(valor, arvore);
        }
        printf("\nOs elementos do arquivo foram inseridos na arvore com sucesso.\n\n");
    }
    fclose(arquivo);
}

int main(){

}
