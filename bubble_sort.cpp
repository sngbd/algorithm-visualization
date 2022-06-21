/* https://github.com/p-ranav/tabulate */
#include <tabulate/table.hpp>
#include <stdio.h>

using namespace tabulate;
using namespace std;

vector<variant<string, const char *, 
    nonstd::sv_lite::string_view, Table>> elems;

Table steps;
int row = 0;

void swapElems(int i, int j) {
    swap(elems[i], elems[j]);
    steps.add_row(elems);
    steps[row - 1][i].format()
        .font_color(Color::red);
    steps[row - 1][j].format()
        .font_color(Color::red);
}

void bubbleSort(int arr[], int n) {
    int i, j, tmp;
    for (i = 0; i < n; i++) {
        for (j = 0; j < n-i-1; j++) {
            if (arr[j] > arr[j+1]) {
                row++;
                swapElems(j, j+1);
                tmp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = tmp;
            }
        }
    }
}

int main() {
    int n, i, j;
    printf("Masukkan banyak elemen: ");
    scanf("%d", &n);
    elems.resize(n);
    int array[n];

    printf("Masukkan nilai: \n");

    for (i = 0; i < n; i++) {
        scanf("%d", &array[i]);
        elems[i] = to_string(array[i]);
    }

    steps.add_row(elems);
    bubbleSort(array, n);

    printf("Hasil pengurutan sebagai berikut:\n");

    for (i = 0; i < n; i++) {
        printf("%d ", array[i]);
    }

    printf("\n");

    printf("Proses pengurutan sebagai berikut:\n");
    steps.row(row).format()
        .font_color(Color::green);
    cout << steps << endl;
}
