// A diferença entre pilhas e filas é que nas pilhas, o ultimo adicionado é o primeiro a sair e nas filas, o primeiro a entrar é o primeiro a sair.
// frente é o primeiro termo da fila e o fundo é o byte anterior ao último termo da lista.
// é uma estrutura circular, quando o fundo sai do tamanho máximo, se ouver espaços vazios nos primeiros, inicia o ciclo.
#define MAX_FILA 50

struct fila_t {
    int fila[MAX_FILA];
    unsigned long frente, fundo;
};
typedef struct fila_t fila_t;

// Essa função verifica o tamanho da fila
unsigned long tamanhoFila (fila_t *const f) {
    if (f->frente < f->fundo) {
        return f->fundo - f->frente;
    }
    if (f->fundo < f->frente) {
        return MAX_FILA - (f->frente - f->fundo);
    return 0;
    }
}

// Essa função adiciona um elemento no final da fila
void adicionaFundo (fila_t *const f, const int n) {
    if (tamanhoFila(f) == MAX_FILA - 1) {
        return;
    }
    f->fila[f->fundo++] = n;
    f->fundo = f->fundo % MAX_FILA;
}

// Essa função lê a frente da fila
int leFrente (fila_t *const f) {
    return f->fila[f->frente];
}

// Essa função avança na fila
int avancarFila (fila_t *const f) {
    int temporaria = f->fila[f->frente++];
    f->frente = f->frente % MAX_FILA;
    return f->fila[f->frente++];
}

void limpaFila (fila_t *const f) {
    f->frente = f->fundo;
}

