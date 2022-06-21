/* https://github.com/p-ranav/tabulate */
#include <tabulate/table.hpp>

using namespace tabulate;
using namespace std;
 
Table tower;
int no = 0;
int n;
string blocks[3][64];

char rod[3] = { 'A', 'B', 'C' };

string arrange(string s[]) {
    string arranged;
    for (int i = 0; i < n; i++) {
        arranged += s[i] + '\n';
    }
    return arranged;
}

void move(int x, int from_rod, int to_rod) {
    bool found = false;
    for (int i = 0; i < n; i++) {
        if (blocks[from_rod][i].length() == x) {
            for (int j = n - 1; i >= 0; j--) {
                if (blocks[to_rod][j] == "") {
                    blocks[to_rod][j] = blocks[from_rod][i];
                    break;
                }
            }
            blocks[from_rod][i] = "";
            found = true;
        }
        if (found)
            break;
    }

    tower.add_row({to_string(no), 
            arrange(blocks[0]), 
            arrange(blocks[1]), 
            arrange(blocks[2])});
}

void towerOfHanoi(int n, int from_rod, int aux_rod, int to_rod) {
    if (n == 0) {
        return;
    }

    towerOfHanoi(n - 1, from_rod, to_rod, aux_rod);

    no++;
    cout << no << ". ";
    cout << "Pindahkan cakram " << n << " dari tiang " 
        << rod[from_rod] << " ke tiang " << rod[to_rod] << endl;

    move(n * 2, from_rod, to_rod);

    towerOfHanoi(n - 1, aux_rod, from_rod, to_rod);
}

int main() {
    cout << "Masukkan banyak cakram: ";
    cin >> n;

    cout << endl;
    string block = "==";
    tower.add_row({"No", "A", "B", "C"});
    for (int i = 1; i <= n; i++) {
        for (int j = 0; j < i; j++) {
            blocks[0][i - 1] += block;
        }
    }

    cout << "Langkah-langkah penyelesaian: " << endl;
    cout << no << ". ";
    cout << "Keadaan awal "  << n << " cakram pada tiang A" << endl;

    tower.add_row({to_string(no), 
            arrange(blocks[0]), 
            arrange(blocks[1]), 
            arrange(blocks[2])});

    towerOfHanoi(n, 0, 1, 2);

    for (int i = 0; i < 4; i++) { 
        tower.column(i).format()
            .font_align(FontAlign::center);
    }
    tower.column(0).format()
        .font_color(Color::blue);
    for (int i = 0; i < 4; i++)
        tower[0][i].format()
            .font_color(Color::cyan);

    cout << endl << tower << endl;
}
