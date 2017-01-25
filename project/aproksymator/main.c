#include <stdio.h>
#include <stdlib.h>
#include "points.h"
#include "splines.h"

int main(int argc, char ** argv) {
    points_t points;
    spline_t *spline;
    points.n = 0;
    char * fname = argc > 1 ? argv[1] : "points.pt";
    FILE * fpoints = fopen(fname, "r");
    int nbase = argc >  2 ? atoi(argv[2]) : 4;
    char * fname_dense = argc > 3 ? argv[3] : "points_dense.pt";
    FILE * fpoints_dense = fopen(fname_dense, "w");

    if (fpoints == NULL) {
        printf("Nie mogę otworzyć pliku z punktami: %s\n", fname);
        return 3;
    }

    if (fpoints_dense == NULL) {
        printf("Nie mogę otworzyć pliku z wynikowymi punktami aproksymacji: %s\n", fname_dense);
        return 4;
    }

    if (read_points_failed(fpoints, &points)) {
        printf("Błąd podczas wczytywania punktów z pliku %s\n", fname);
        return 1;
    }
    fclose(fpoints);

    /** Tutaj liczymy współczynniki aproksymacji funkcjami sklejanymi. Wszelkie dane do obliczenia
     * wartości funkcji sklejanej dla jakiegoś punktu znajdują się w strukturze spline.*/
    if ((spline = splines_approximate(&points, nbase)) != NULL) {
        double a = points_min_x(&points);
        double b = points_max_x(&points);
        int npoints = 100;
        points_t *points_dense;

        if ((points_dense = points_linspace(a, b, npoints)) != NULL) {
            int i;

            /** Główna część programu wyznaczająca wartość funkcji sklejanej dla zadanego wektora punktów x */
            for (i = 0; i < points_dense->n; i++) {
                points_dense->y[i] = splines_eval(spline, points_dense->x[i]);
                fprintf(fpoints_dense, "%lf %lf\n", points_dense->x[i], points_dense->y[i]);
            }

        } else
            printf("Błąd podczas generacji %d równoodległych punktów w przedziale <%lf, %lf>.\n", npoints,a,b);

        fclose(fpoints_dense);
        free_spline(spline);
    } else {
        printf("Błąd podczas wyznaczania współczynników funkcji sklejanych.\n");
        return 2;
    }

    return 0;
}


