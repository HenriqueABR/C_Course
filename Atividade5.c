#include <math.h>
struct vetor_t {
    double x;
    double y;
    double z;
};

typedef struct vetor_t vetor_t;

// Aqui, reitero que, nessa biblioteca, para funções que precisam de valores em módulo, essa questão não foi implementada.
// Essa decisão foi por que, normalmente, ou os termos são ao quadrado (obrigatoriamente positivos) ou apresentam resultados que nunca resultaram em valores negativos de qualquer forma.

// Essa função calcula a magnitude de um vetor v.
// Essa função utiliza de varias funções pow para calcular as potencias e o posterior somatorio dos termos de dentro da raiz.
// Em seguida, a raiz é retirada e a função retorna uma variável, visto que a resposta é um escalar.
double magnitudeVetor (vetor_t const *v) {
    double x_2 = pow(v->x, 2);
    double y_2 = pow(v->y, 2);
    double z_2 = pow(v->z, 2);
    double mag_2 = x_2 + y_2 + z_2;
    return (pow(mag_2, 0.5));
};

// Essa função calcula a soma de dois vetores v e w, que é um vetor u
// Aqui, é criado um vetor resultado u que tem seus termos calculados um a um, depois eles são armazenados no vetor e a função retorna o vetor.
vetor_t * somaVetor (vetor_t const *v, vetor_t const *w, vetor_t *u) {
    double u_x = v->x + w->x;
    double u_y = v->y + w->y;
    double u_z = v->z + w->z;
    u->x = u_x;
    u->y = u_y;
    u->z = u_z;
    return u;
};

// Essa função realiza a multiplicação de um vetor v por um escalar e, resultando em um vetor u.
// Aqui, um vetor resultado u tem seus termos calculados um a um, armazenados na estrutura vetor_t de u e depois a função retorna esse vetor u.
vetor_t * multEscalar (vetor_t const *v, double const e, vetor_t *u) {
    double u_x = (v->x)*e;
    double u_y = (v->y)*e;
    double u_z = (v->z)*e;
    u->x = u_x;
    u->y = u_y;
    u->z = u_z;
    return u;
};

// Essa função realiza o produto escalar entre dois vetores v e w.
// Aqui, como o resultado é um escalar, os valores de cada termo são calculados um a um e depois somados em uma unica variavel, que é retornada.
double ProdEscalar (vetor_t const *v, vetor_t const *w) {
    double u_x = v->x * w->x;
    double u_y = v->y * w->y;
    double u_z = v->z * w->z;
    double multVet = u_x + u_y + u_z;
    return multVet;
};

// Essa função realiza o produto vetorial entre dois vetores v e w, resultando em um vetor u.
// Aqui, um vetor resultado u é criado e seus termos são calculados um a um, e depois a função retorna o vetor
vetor_t * ProdVetorial (vetor_t const *v, vetor_t const *w, vetor_t *u) {
    double u_x = ((v->y * w->z) - (w->y * v->z));
    double u_y = ((w->x * v->z) - (v->x * w->z));
    double u_z = ((v->x * w->y) - (w->x * v->y));
    u->x = u_x;
    u->y = u_y;
    u->z = u_z;
    return u;
};

// Essa função calcula o ângulo entre dois vetores v e w.
// Aqui, a função utiliza das funções de produto escalar e de magnitude de vetor, além da função arccos, para calcular o angulo entre os vetores.
double anguloVet (vetor_t const *v, vetor_t const *w) {
    double numerador = ProdEscalar(v, w);
    double denominador = magnitudeVetor(v) * magnitudeVetor(w);
    double termo_interno = numerador/denominador;
    double angulo = acos(termo_interno);
    return angulo;
// O valor calculado de angulo aqui é em RADIANOS ( 0 < angulo < pi)
};
    