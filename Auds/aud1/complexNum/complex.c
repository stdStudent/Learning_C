#include <stdio.h>
#include<stdlib.h>
#include <math.h>

double moduleComplex(int real, int img)
{
    return (double)sqrt(abs(real)*abs(real) + abs(img)*abs(img));
}

void compareComplex(int n)
{
    int* real = (int*)malloc(n*sizeof(int));
    int* img  = (int*)malloc(n*sizeof(int));

    double max = 0;
    int maxR, maxI;

    for(int i = 0; i < n; i++) {
        scanf("%d %d", &real[i], &img[i]);
        if (moduleComplex(real[i], img[i]) > max) {
            max = moduleComplex(real[i], img[i]);
            maxR = real[i]; maxI = img[i];
        }
    }

    puts("");
    for (int i = 0; i < n; ++i)
        if (img[i] >= 0)
            printf("%d + %di\n", real[i], img[i]);
        else
            printf("%d - %di\n", real[i], -img[i]);

    free(real); free(img);
    if (maxI < 0)
        printf("Max: %d - %di", maxR, -maxI);
    else
        printf("Max: %d + %di", maxR, maxI);


}
