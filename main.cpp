#include <iostream>
#include <fstream>
#include <filesystem>
#include <string>
#include <windows.h>

void crearArchivos(int cantidad);
void listarArchivosDeDirectorio();
int contarArchivosDeDirectorio();
void mostrarDetalles();

using namespace std;

int main() {
    int opc;
    cout << "Bienvenido al Programa para Calcular la Nota Final de Alumnos" << endl;
    do {
        cout << "------------------------------------------------------------------------" << endl;
        cout << "Elija una opcion a realizar" << endl;
        cout << "[1] Crear Archivos con las Notas Finales" << endl;
        cout << "[2] Enlistar Archivos de un Directorio" << endl;
        cout << "[3] Mostrar Detalles de Archivos en un Directorio" << endl;
        cout << "[0] Salir" << endl;
        cin >> opc;
        switch (opc) {
            case 1:
                int cantidad;
                cout << "Ingrese el numero de alumnos del curso" << endl;
                cin >> cantidad;
                crearArchivos(cantidad);
                break;
            case 2:
                cout << "Se encontraron " << contarArchivosDeDirectorio() << " archivos en el Directorio" << endl;
                cout << "Los Archivos encontrados en el Directorio son los siguierntes:";
                listarArchivosDeDirectorio();
                break;
            case 3:
                mostrarDetalles();
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

void crearArchivos(int cantidad){
    string nombreArchivo = "Nota_Alumno";
    char nom[150];
    float notaFinal, n1, n2, n3, n4;
    float valorPrimerosBimestres = 0.2;
    float valorUltimoBimestre = 0.4;

    for (int i = 0; i < cantidad; ++i) {
        ofstream file;
        file.open("C:/Users/kathe/Desktop/progra/" + nombreArchivo + to_string(i) + ".txt");
        cout << "\nIngrese el nombre del Alumno: "; cin.ignore(); cin.getline(nom,150);
        cout << "\nIngrese la Nota del Primer Bimestre: "; cin >> n1;
        cout << "\nIngrese la Nota del Segundo Bimestre: "; cin >> n2;
        cout << "\nIngrese la Nota del Tercer Bimestre: "; cin >> n3;
        cout << "\nIngrese la Nota del Cuarto Bimestre: "; cin >> n4;
        notaFinal = (n1*valorPrimerosBimestres) + (n2*valorPrimerosBimestres) + (n3*valorPrimerosBimestres) + (n4*valorUltimoBimestre);

        file << "Alumno: " << nom << endl;
        file << "Nota del Primer Bimestres: " << n1 << " (Equivale al 20% de la Nota Final)" << endl;
        file << "Nota del Segundo Bimestres: " << n2 << " (Equivale al 20% de la Nota Final)" << endl;
        file << "Nota del Tercer Bimestres: " << n3 << " (Equivale al 20% de la Nota Final)" << endl;
        file << "Nota del Cuarto Bimestres: " << n4 << " (Equivale al 40% de la Nota Final)" << endl;
        file << "Nota Final del Alumno: " << notaFinal << endl;
        file.close();
        cout << "------------------------------------------------------------------------" << endl;
    }
    cout << cantidad << " Archivos creados con Exito" << endl;
}

void listarArchivosDeDirectorio() {
    WIN32_FIND_DATA findFileData;
    HANDLE hFind;

    hFind = FindFirstFile("C:/Users/kathe/Desktop/progra/*", &findFileData);

    if (hFind == INVALID_HANDLE_VALUE) {
        cout << "Ruta Incorrecta" << endl;
    } else {
        cout << findFileData.cFileName << endl;
        while (FindNextFile(hFind, &findFileData) != 0) {
            cout << findFileData.cFileName << endl;
        }
    }
}

int contarArchivosDeDirectorio(){
    WIN32_FIND_DATA findFileData;
    HANDLE          hFind;
    int cantidadDeArchivos=0;
    hFind = FindFirstFile("C:/Users/kathe/Desktop/progra/*", &findFileData);

    if (hFind == INVALID_HANDLE_VALUE){
        cout << "Ruta incorrecta" << endl;
    }else{
        while (FindNextFile(hFind, &findFileData)!=0){
            cantidadDeArchivos=cantidadDeArchivos+1;
        }
    }
    return cantidadDeArchivos-1;
}

void mostrarDetalles(){
    filesystem::directory_iterator directoryIterator("C:/Users/kathe/Desktop/progra");
    for(const auto& entry: directoryIterator){
        if (!filesystem::is_directory(entry.status())){
            cout << "------------------------------------------------------------------------" << endl;
            cout << "Nombre de Archivo: " << entry.path().filename() << endl;
            cout << "Extension: " << entry.path().extension() << endl;
            cout << "Peso: " << file_size(entry.path()) << " bytes" << endl;
        }
    }
}