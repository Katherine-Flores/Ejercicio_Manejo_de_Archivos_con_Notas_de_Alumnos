#include <iostream>
#include <fstream>
#include <filesystem>
#include <string>
#include <windows.h>

using namespace std;

int main() {
    int opc;
    cout << "Bienvenido al Programa para Calcular la Nota Final de Alumnos" << endl;
    do {
        cout << "Elija una opcion a realizar" << endl;
        cout << "[1] Crear Archivos con la Notas Finales" << endl;
        cout << "[2] Enlistar Archivos de un Directorio" << endl;
        cout << "[3] Mostrar Detalles de Archivos en un Directorio" << endl;
        cout << "[0] Salir" << endl;
        switch (opc) {
            case 1:
                break;
            case 2:
                break;
            case 3:
                break;
            case 0:
                cout << "Gracias por Utilizar el Programa" << endl;
                break;
            default:
                cout << "Opcion incorrecta, vuelva a intentarlo" << endl;
                break;
        }
    } while (opc != 0);
    return 0;
}
