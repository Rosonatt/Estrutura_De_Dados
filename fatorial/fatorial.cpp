#include <iostream>
#include <locale.h>

using namespace std;

int main() {
    setlocale(LC_ALL, "Portuguese");
    int r = 8;
    int fatorial = 1;

    for(int fac = 1; fac <= r; fac++) {
        fatorial *= fac;
    }

    cout << " O fatorial do número " << r << ": " << fatorial << endl;
    return 0;
}
