#ifndef PHYSICS_H
#define PHYSICS_H

#include <math.h>
#include <stdlib.h>

// Ecuación de Rango de Radar con factor LPI
// Retorna la potencia de la señal recibida
double calcular_potencia_recibida(double distancia_km, double rcs_objetivo, int modo_lpi) {
    double p_transmision = modo_lpi ? 1000.0 : 15000.0; // En LPI usamos menos potencia para no ser vistos
    double ganancia = 10000.0;
    double lambda = 0.03; // Banda X
    double distancia_m = distancia_km * 1000.0;

    // Ecuación del Radar: Pr = (Pt * G^2 * L^2 * sigma) / ((4*pi)^3 * R^4)
    double numerador = p_transmision * pow(ganancia, 2) * pow(lambda, 2) * rcs_objetivo;
    double denominador = pow(4 * M_PI, 3) * pow(distancia_m, 4);
    
    return numerador / denominador;
}

// Probabilidad: Añadir ruido Gaussiano a la señal
double añadir_ruido(double señal_pura) {
    // Simulamos ruido de fondo (Entropía)
    double ruido = ((double)rand() / RAND_MAX) * 1e-15; 
    return señal_pura + ruido;
}

#endif