#include <iostream>
#include "tad.h"
using namespace std;

/*
FUNÇÃO: criaPilha
RESUMO: Cria uma nova pilha vazia
PARAM: void
RETORNO: Pilha* (ponteiro para a pilha);
*/
Pilha* criaPilha(){
	Pilha* p = new Pilha;
	p->topo = NULL;
	return p;
}

/*
FUNÇÃO: vazia
RESUMO: verifica se a pilha está vazia
PARAM: Pilha* (ponteiro para a pilha)
RETORNO: int (1 se está vazia, 0 se não está)
*/
int vaziaPilha(Pilha* pilha){
	if( pilha->topo == NULL)
		return 1;
	else return 0;
}

/*
FUNÇÃO: push
RESUMO: empilha novo elemento na pilha
PARAM: Pilha* (ponteiro para a pilha), int (valor a ser empilhado);
RETORNO: Pilha* (ponteiro para a pilha);
*/
Pilha* push(Pilha* pilha, int valor){
	Node* novo = new Node;
	novo->info = valor;
	novo->prox = pilha->topo;
	pilha->topo = novo;
	return pilha;
}

/*
FUNÇÃO: pop
RESUMO: desempilha o elemento no topo da pilha e retorna seu valor
PARAM: Pilha* (ponteiro para a pilha), int (valor a ser desempilhado);
RETORNO: Pilha* (ponteiro para a pilha);
*/
int pop(Pilha* pilha){
    Node* aux = pilha->topo;
    int valor;
    if(!vaziaPilha(pilha)){
        valor = aux->info;
        pilha->topo = (pilha->topo)->prox;
        delete aux;
    } else cout << "pilha vazia!" << endl;
    return valor;
}

/*
FUNÇÃO: top
RESUMO: informa o valor do primeiro elemento da pilha
PARAM: Pilha* (ponteiro para a pilha)
RETORNO: int (valor da informação do nó armazenado no topo)
*/
int top(Pilha* pilha){
	if (!vaziaPilha(pilha))
        return (pilha->topo)->info;
    else cout << "pilha vazia!";
}

/*
FUNÇÃO: destroiPilha
RESUMO: exclui todo conteúdo da pilha
PARAM: Pilha* (ponteiro para a pilha)
RETORNO: nada
*/
void destroiPilha(Pilha* pilha){
	while (!vaziaPilha(pilha))
        pop(pilha);
    cout << "pilha destruída com sucesso!" << endl;
}
/*
FUNÇÃO: print
RESUMO: imprime a pilha
PARAM: Pilha* (ponteiro para a pilha)
RETORNO: void
*/
void printPilhaControle(Pilha* pilha){
	Node* aux = pilha->topo;
	cout << "____" << endl;
	while(aux){
		cout << "| " << aux->info << " |\n"<< "____" << endl;
		aux = aux->prox;
	}
	cout << "X" << endl;
}

// a. Busca um elemento na pilha
int buscaElementoPilha(Pilha* pilha, int valor) {
    Node* aux = pilha->topo;
    while (aux) {
        if (aux->info == valor)
            return 1;
        aux = aux->prox;
    }
    return 0;
}

// b. Busca e remove um elemento da pilha
int buscaRemoveElementoPilha(Pilha* pilha, int valor) {
    Pilha* temp = criaPilha();
    int found = 0;
    while (!vaziaPilha(pilha)) {
        int topo = top(pilha);
        if (topo == valor && !found) {
            pop(pilha);
            found = 1;
        } else {
            push(temp, pop(pilha));
        }
    }
    // devolve elementos para pilha original
    while (!vaziaPilha(temp)) {
        push(pilha, pop(temp));
    }
    delete temp;
    return found;
}

// c. Remove todos os números pares da pilha
void removeParesPilha(Pilha* pilha) {
    Pilha* temp = criaPilha();
    while (!vaziaPilha(pilha)) {
        int topo = top(pilha);
        if (topo % 2 != 0) {
            push(temp, pop(pilha));
        } else {
            pop(pilha);
        }
    }
    while (!vaziaPilha(temp)) {
        push(pilha, pop(temp));
    }
    delete temp;
}

// d. Remove todos os valores repetidos da pilha
void removeRepetidosPilha(Pilha* pilha) {
    Pilha* temp = criaPilha();
    while (!vaziaPilha(pilha)) {
        int topo = top(pilha);
        pop(pilha);
        // verifica se já existe em temp
        Pilha* check = criaPilha();
        int repetido = 0;
        while (!vaziaPilha(temp)) {
            int v = top(temp);
            if (v == topo) repetido = 1;
            push(check, pop(temp));
        }
        // devolve para temp
        while (!vaziaPilha(check)) {
            push(temp, pop(check));
        }
        delete check;
        if (!repetido) push(temp, topo);
    }
    // devolve para pilha original
    while (!vaziaPilha(temp)) {
        push(pilha, pop(temp));
    }
    delete temp;
}

