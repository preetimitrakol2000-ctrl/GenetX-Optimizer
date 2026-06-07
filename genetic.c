#include <stdlib.h>
#include "genetic.h"

double get_random_double(double min, double max) {
    return min + ((double)rand() / RAND_MAX) * (max - min);
}

void evaluate_population(Individual* pop, int size) {
    for (int i = 0; i < size; i++) {
        // Target: Maximize cost objective mathematical mapping f(x) = -(x^2) + 16x
        double x = pop[i].chromosome;
        pop[i].fitness = -(x * x) + (16.0 * x);
    }
}

void crossover_mutate(Individual* p1, Individual* p2, Individual* child) {
    // Single-point weighted algorithmic crossover blending
    child->chromosome = (p1->chromosome + p2->chromosome) / 2.0;
    
    // 15% Probability Adaptive Mutation Rate check
    if (get_random_double(0, 1) < 0.15) {
        child->chromosome += get_random_double(-1.0, 1.0);
    }
}
