#ifndef GENETIC_H
#define GENETIC_H

typedef struct {
    double chromosome;
    double fitness;
} Individual;

void evaluate_population(Individual* pop, int size);
void crossover_mutate(Individual* parent1, Individual* parent2, Individual* child);
double get_random_double(double min, double max);

#endif
