#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int print_array(double x[], int len) {
        int k;

        for(k = 0; k < len; k++) {
            printf("x[%d] = %lf\n", k, x[k]);
        }
        return 0;
}

int main(int argc, char *argv[])
{
        int npoints;        
        double *points;
        int k;

        scanf("%d", &npoints); /* npoints получает значение в момент выполнения программы */

        points = (double *)malloc(npoints*sizeof(double));
        /* Выдели память для хранения npoints элементов, каждый размера sizeof(double) */

        if(points == NULL) {
           printf("Произошла ошибка. Запросили слишком много памяти??\n");
           return -1;
        }

        /* Считываем данные с использованием адресной арифметики */
        k = 0;
        while(k < npoints && scanf("%lf", points+k) == 1) {
            k++;
        }

        print_array(points, npoints);

        free(points); /* Освободили память */
        return 0;
}