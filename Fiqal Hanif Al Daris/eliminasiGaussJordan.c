#include <stdio.h>
#define size 5

int i, j, k;
void gaussJordan(double arr[size][size], int ordo){
    double pembagi, v[size];

    printf("\t[Matriks A | B]\n");
    printMatrix(arr, ordo);
  
    for(i = 0; i < ordo; i++){
        pembagi = arr[i][i];

        for(k = i; k < ordo + 1; k++){
            arr[i][k] /= pembagi;
        }

        for(j = i + 1; j < ordo + 1; j++){
            v[i] = arr[j][i];

            for(k = i; k < ordo + 1; k++){
                arr[j][k] = arr[j][k] - v[i] * arr[i][k];
            }
        }
    }

    for(i = 1; i < ordo; i++){
        for(j = 1; j < i + 1; j++){
            v[j] = arr[j - 1][i];
            for(k = i; k < ordo + 1; k++){
                arr[j - 1][k] -= v[j] * arr[i][k];
            }
        }
    }

    printf("\n\t[Matriks Identitas]\n");
    printMatrix(arr, ordo);
}

void printMatrix(double arr[size][size], int ordo){
    for (i = 0; i < ordo; i++){
        printf("|");
        for (j = 0; j < ordo; j++){
            printf("%.3f   ", arr[i][j]);

            if (j == ordo - 1){
                printf("\t|   %.3lf", arr[i][j + 1]);
            }
        }
        printf("|\n");
    }
}

int main(){
    double arr[size][size];
    int ordo;


    printf("\n\n============= SOLUSI PERSAMAAN SISTEM LINEAR METODE GAUSS JORDAN ========================\n");
    printf("\nPress any key to continue.\n");
    getchar();

    printf("\nMasukkan Ordo Matriks : ");
    scanf("%d", &ordo);

    if(ordo < 2){
        printf("\nBentuk Matriks Minimal 2x2");
        return 0; 
    }

    printf("\n[Terkonfirmasi Matriks Ordo %dx%d]\n\n", ordo, ordo);

    for(i = 0; i < ordo; i++) {
        printf("Input Matriks Baris ke-%d\n", (i + 1));

        printf("Matriks A\n");
        for(j = 0; j < ordo; j++){
            printf("[%d][%d] = ", (i+1), (j+1));
            scanf("%lf", &arr[i][j]);

            if(j == ordo - 1){
                printf("Matriks B\n");
                printf("[%d][%d] = ", (i+1), (j+1));
                scanf("%lf", &arr[i][j + 1]);
            }
        }
        printf("\n");
    }

    gaussJordan(arr, ordo);

    for(i = 0; i < ordo; i++){
        printf("\nX%d = %.3lf", (i + 1), arr[i][ordo]);
    }
    return 0;
}
