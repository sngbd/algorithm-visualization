/* https://github.com/p-ranav/tabulate */
#include <tabulate/table.hpp>
#include <iostream>
#include <stdio.h>

using namespace std;
using namespace tabulate;

int main() {
    int data[100], cari, i, n;

    vector<variant<string, const char *, 
        nonstd::sv_lite::string_view, Table>> elems;
    Table steps;
    int row = 0;

    cout << "Masukkan banyaknya jumlah data: ";
    scanf("%d", &n);
    elems.resize(n);

    printf("Input setiap data integer sebanyak %d:\n", n);

    for (i = 0; i < n; i++){
        cin >> data[i];
        elems[i] = to_string(data[i]);
    }

    cout << "Input data yang ingin dicari: ";
    cin >> cari;

    for (i = 0; i < n; i++) {
        if (data[i] == cari) {
            printf("%d berada di indeks ke %d.\n", cari, i+1);
            steps.add_row(elems);
            steps[row][i].format()
                .font_color(Color::green);
            break;
        }
        else {
            steps.add_row(elems);
            steps[row][i].format()
                .font_color(Color::red);
            row++;
        }
    }
    if (i == n) {
        printf("%d tidak ada.\n", cari);
    }

    cout << "Proses pencarian sebagai berikut:\n";
    cout << steps << endl;

    return 0;
}
