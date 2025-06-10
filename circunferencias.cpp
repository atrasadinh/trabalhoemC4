#include <stdio.h>
#include <math.h>

int main() {
    double x_c, y_c;
    int n;

    printf("Digite as coordenadas do ponto C (x y): ");
    scanf("%lf %lf", &x_c, &y_c);

    do {
        printf("Digite o numero de pontos na sequencia: ");
        scanf("%d", &n);
        if (n < 1) {
            printf("Valor incorreto, tente novamente\n");
        }
    } while (n < 1);

    double raios[n];
    int count = 0;

    printf("Digite a sequencia de %d pontos (x y): \n", n);
    for (int i = 0; i < n; i++) {
        double x, y;
        scanf("%lf %lf", &x, &y);

        double raio = sqrt((x - x_c) * (x - x_c) + (y - y_c) * (y - y_c));

        int existe = 0;
        for (int j = 0; j < count; j++) {
            if (fabs(raios[j] - raio) < 1e-6) {  
                existe = 1;
                break;
            }
        }

        if (!existe) {
            raios[count++] = raio;
        }
    }

    for (int i = 0; i < count; i++) {
        printf("%.6lf\n", raios[i]);
    }
}