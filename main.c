#include <stdio.h>
#include <termios.h>
#include <fcntl.h>
#include <unistd.h>
#include "physics.h"

// Función para leer teclado sin bloquear el programa (Ingeniería de Sistemas)
int kbhit(void) {
    struct termios oldt, newt;
    int ch, oldf;
    tcgetattr(STDIN_FILENO, &oldt);
    newt = oldt;
    newt.c_lflag &= ~(ICANON | ECHO);
    tcsetattr(STDIN_FILENO, TCSANOW, &newt);
    oldf = fcntl(STDIN_FILENO, F_GETFL, 0);
    fcntl(STDIN_FILENO, F_SETFL, oldf | O_NONBLOCK);
    ch = getchar();
    tcsetattr(STDIN_FILENO, TCSANOW, &oldt);
    fcntl(STDIN_FILENO, F_SETFL, oldf);
    if(ch != EOF) { ungetc(ch, stdin); return 1; }
    return 0;
}

int main() {
    double distancia_enemigo = 250.0; // km
    double rcs_rafale = 0.1;          // m2 (Furtivo)
    int modo_lpi = 1;                 // Empezamos en sigilo
    char tecla;

    printf("\033[2J\033[H"); // Limpiar consola

    while(distancia_enemigo > 0) {
        // 1. Lógica de Entrada (Interrupciones simuladas)
        if(kbhit()) {
            tecla = getchar();
            if(tecla == 'f') modo_lpi = !modo_lpi; // 'f' para máxima potencia
        }

        // 2. Lógica de Procesamiento (Física y Probabilidad)
        double señal = calcular_potencia_recibida(distancia_enemigo, rcs_rafale, modo_lpi);
        señal = añadir_ruido(señal);
        
        // Umbral de detección (Sensibilidad del Sh121)
        double umbral = 1e-18; 

        // 3. Interfaz de Usuario (Dashboard de Combate)
        printf("\033[H"); // Reset cursor
        printf("--- SISTEMA CIBERNÉTICO Sh121 (Controlador Glushkov) ---\n");
        printf("MODO RADAR: %s | POTENCIA: %s\n", 
                modo_lpi ? "\033[32mSIGILO (LPI)\033[0m" : "\033[31mCOMBATE (FULL)\033[0m",
                modo_lpi ? "BAJA" : "ALTA");
        printf("DISTANCIA OBJETIVO: %.2f km\n", distancia_enemigo);
        
        if(señal > umbral) {
            printf("DETECCIÓN: [\033[31m LOCK ON \033[0m] Señal: %.2e\n", señal);
        } else {
            printf("DETECCIÓN: [ BUSCANDO ] Señal: %.2e (Bajo el ruido)\n", señal);
        }
        printf("------------------------------------------------------\n");
        printf("Presiona 'f' para cambiar modo | Ctrl+C para abortar\n");

        distancia_enemigo -= 0.5; // El enemigo se acerca
        usleep(100000); // Ciclo de 100ms (Frecuencia de actualización)
    }

    return 0;
}