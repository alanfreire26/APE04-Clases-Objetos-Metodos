#include <iostream>
#include <string>
#include <iomanip>
using namespace std;
 
// Clase Estudiante con atributos privados, constructor,
// metodos get/set, calculo de promedio y estado
class Estudiante {
private:
    string cedula, nombre, apellido;
    double nota1, nota2, nota3, promedio;
    string estado;
 
public:
    // Constructor: inicializa atributos y calcula promedio/estado
    Estudiante(string ced, string nom, string ape,
               double n1, double n2, double n3) {
        cedula = ced; nombre = nom; apellido = ape;
        nota1 = n1;  nota2 = n2;  nota3 = n3;
        calcularPromedio();
        determinarEstado();
    }
 
    // Getters
    string getCedula()   { return cedula; }
    string getNombre()   { return nombre; }
    string getApellido() { return apellido; }
    double getPromedio() { return promedio; }
    string getEstado()   { return estado; }
 
    // Setters con recalculo automatico
    void setNota1(double n){ nota1=n; calcularPromedio(); determinarEstado(); }
    void setNota2(double n){ nota2=n; calcularPromedio(); determinarEstado(); }
    void setNota3(double n){ nota3=n; calcularPromedio(); determinarEstado(); }
 
    // Calcula el promedio de las tres notas
    void calcularPromedio() {
        promedio = (nota1 + nota2 + nota3) / 3.0;
    }
 
    // Aprueba si promedio >= 7.00
    void determinarEstado() {
        estado = (promedio >= 7.0) ? "APROBADO" : "REPROBADO";
    }
 
    // Muestra la informacion del estudiante formateada
    void mostrarInfo() {
        cout << left
             << setw(13) << cedula
             << setw(12) << nombre
             << setw(12) << apellido
             << setw(7)  << fixed << setprecision(2) << nota1
             << setw(7)  << nota2
             << setw(7)  << nota3
             << setw(9)  << promedio
             << estado   << endl;
    }
};
 
// Valida que la nota este en rango [0, 10]
double leerNota(const string& msg) {
    double n;
    do {
        cout << msg; cin >> n;
        if (n < 0 || n > 10)
            cout << "  ! Nota invalida. Ingrese un valor entre 0 y 10." << endl;
    } while (n < 0 || n > 10);
    return n;
}
 
int main() {
    const int TAM = 5;
    Estudiante* est[TAM];
 
    cout << "=== SISTEMA DE CONTROL DE ESTUDIANTES ===" << endl;
    cout << "Asignatura: Algoritmos y Logica de Programacion" << endl;
    cout << string(50, '-') << endl << endl;
 
    for (int i = 0; i < TAM; i++) {
        string ced, nom, ape;
        cout << "-- Estudiante " << (i+1) << " --" << endl;
        cout << "Cedula   : "; cin >> ced;
        cout << "Nombre   : "; cin >> nom;
        cout << "Apellido : "; cin >> ape;
        double n1 = leerNota("Nota 1   : ");
        double n2 = leerNota("Nota 2   : ");
        double n3 = leerNota("Nota 3   : ");
        est[i] = new Estudiante(ced, nom, ape, n1, n2, n3);
        cout << endl;
    }
 
    // Encabezado del listado
    cout << "\n=== LISTADO COMPLETO ===" << endl;
    cout << left
         << setw(13) << "Cedula"
         << setw(12) << "Nombre"
         << setw(12) << "Apellido"
         << setw(7)  << "N1"
         << setw(7)  << "N2"
         << setw(7)  << "N3"
         << setw(9)  << "Promedio"
         << "Estado"  << endl;
    cout << string(67, '-') << endl;
 
    int aprobados = 0, reprobados = 0;
    for (int i = 0; i < TAM; i++) {
        est[i]->mostrarInfo();
        if (est[i]->getEstado() == "APROBADO") aprobados++;
        else reprobados++;
        delete est[i]; // Liberar memoria
    }
 
    cout << "\n--- Resumen ---" << endl;
    cout << "Total aprobados : " << aprobados  << endl;
    cout << "Total reprobados: " << reprobados << endl;
    return 0;
}
