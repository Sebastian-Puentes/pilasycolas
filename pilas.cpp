#include <iostream>
#include <conio.h>

using namespace std;

struct nodo {
    int dato;
    nodo* sig;
};

void agregarNumero(nodo *&, int);
void eliminarComoCola(nodo *&);
void mostrarPila(nodo *);

int main() {
    nodo *pila = nullptr;
    int n1;
    char opcion;

    do {
        cout << "Digite un valor: ";
        cin >> n1;
        agregarNumero(pila, n1);

        cout << "Desea ingresar otro valor?(S/N): ";
        cin >> opcion;
    } while (opcion == 'S' || opcion == 's');
    cout << "Pila antes de eliminar elementos como cola: ";
    mostrarPila(pila);

    do {
        cout << "Desea eliminar un elemento de la pila como si fuera una cola? (S/N): ";
        cin >> opcion;
        if (opcion == 'S' || opcion == 's') {
            eliminarComoCola(pila);
            mostrarPila(pila);
        }
    } while (opcion == 'S' || opcion == 's');

    getch();
    return 0;
}

void agregarNumero(nodo *&pila, int n) {
    nodo *nuevo = new nodo();
    nuevo->dato = n;
    nuevo->sig = pila;
    pila = nuevo;
    cout << "Valor " << n << " agregado correctamente" << endl;
}

void eliminarComoCola(nodo *&pila) {
    if (pila == nullptr) {
        cout << "La pila está vacía, no se puede eliminar ningún elemento." << endl;
        return;
    }

    if (pila->sig == nullptr) {
        delete pila;
        pila = nullptr;
        cout << "Elemento eliminado correctamente." << endl;
    } else {
        nodo *temp = pila;
        while (temp->sig->sig != nullptr) {
            temp = temp->sig;
        }
        nodo *ultimo = temp->sig;
        temp->sig = nullptr;
        delete ultimo;
        cout << "Elemento eliminado correctamente." << endl;
    }
}

void mostrarPila(nodo *pila) {
    nodo *temp = pila;
    while (temp != nullptr) {
        cout << temp->dato << " ";
        temp = temp->sig;
    }
    cout << endl;
}