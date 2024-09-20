#include <math.h>
#include "Atividade5.c"

struct vetor_t;

double magnitudeVetor (vetor_t const *v);

vetor_t * somaVetor (vetor_t const *v, vetor_t const *w, vetor_t *u);

vetor_t * multEscalar (vetor_t const *v, double const e, vetor_t *u);

double ProdEscalar (vetor_t const *v, vetor_t const *w);

vetor_t * ProdVetorial (vetor_t const *v, vetor_t const *w, vetor_t *u);

double anguloVet (vetor_t const *v, vetor_t const *w);