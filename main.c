#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "genetic.h"

int main() {
    srand(time(NULL));
    printf("🧬 Initializing GenetX Optimization Array Engines...\n\n");

    int pop_size = 4;
    Individual population[4];

    // Seed Random Chromosome Configurations
    for (int i = 0; i < pop_size; i++) {
        population[i].chromosome = get_random_double(0.0, 15.0);
    }

    evaluate_population(population, pop_size);
    printf("📊 Gen 0 Initial State Alpha: Chromosome[0]=%.3f | Fitness=%.3f\n", 
            population[0].chromosome, population[0].fitness);

    // Evolve single child iteration loop demo
    Individual next_generation_child;
    crossover_mutate(&population[0], &population[1], &next_generation_child);
    
    Individual structural_wrapper[1] = {next_generation_child};
    evaluate_population(structural_wrapper, 1);

    printf("✨ Gen 1 Evolved Offspring:  Chromosome=%.3f    | Optimized Fitness=%.3f\n", 
            structural_wrapper[0].chromosome, structural_wrapper[0].fitness);

    return 0;
}
