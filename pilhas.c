#define MAX_PILHA 50
struct pilha_t {
    int pilha[MAX_PILHA];
    long topo;

};
typedef struct pilha_t pilha_t;

// Essa função adiciona elemento à pilha
void adicionaElemento (pilha_t *const p, const int n) {
    if (p->topo == MAX_PILHA - 1) {
        return;
    }

    p->topo++;
    p->pilha[p->topo] = n;
}

// Essa função remove elementos da pilha
int removeElemento (pilha_t *const p) {
    if (p->topo == -1) {
        return 0;
    }
    return p->pilha[p->topo--];

}

// Essa função diz o número de elementos na pilha
long verTamanho (pilha_t *const p) {
    return p->topo + 1;
}
