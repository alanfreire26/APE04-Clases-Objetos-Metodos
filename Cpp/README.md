# ⚙️ Sistema de Control de Estudiantes – C++

Implementación en **C++** del sistema de control de estudiantes y calificaciones, desarrollado para la guía práctica APE04 aplicando los principios de la **Programación Orientada a Objetos**.

---

## 📂 Archivos

| Archivo | Descripción |
|---|---|
| `main.cpp` | Contiene la clase `Estudiante` completa y la función `main` en un solo archivo |

---

## 🧱 Clase `Estudiante`

### Atributos (privados)

```cpp
private:
    string cedula, nombre, apellido;
    double nota1, nota2, nota3, promedio;
    string estado;
```

### Constructor

```cpp
Estudiante(string ced, string nom, string ape,
           double n1, double n2, double n3);
```

Al crear el objeto se invocan automáticamente `calcularPromedio()` y `determinarEstado()`, asegurando coherencia interna desde el primer momento.

### Métodos Principales

| Método | Tipo | Descripción |
|---|---|---|
| `getCedula()` | Getter | Retorna la cédula |
| `getNombre()` | Getter | Retorna el nombre |
| `getApellido()` | Getter | Retorna el apellido |
| `getPromedio()` | Getter | Retorna el promedio calculado |
| `getEstado()` | Getter | Retorna `"APROBADO"` o `"REPROBADO"` |
| `setNota1/2/3(double n)` | Setter | Asigna la nota y recalcula promedio y estado |
| `calcularPromedio()` | Lógica | `promedio = (nota1 + nota2 + nota3) / 3.0` |
| `determinarEstado()` | Lógica | `APROBADO` si promedio ≥ 7.00 |
| `mostrarInfo()` | Salida | Imprime todos los datos con `setw` e `iomanip` |

### Función auxiliar

```cpp
double leerNota(const string& msg);
```

Solicita y valida que la nota ingresada esté en el rango [0, 10]. Si el valor es inválido, muestra un mensaje de error y repite la solicitud.

---

## ⚙️ Requisitos del Sistema

| Elemento | Especificación |
|---|---|
| Lenguaje | C++ (estándar C++11 o superior) |
| Compilador | GCC 10+ / MinGW (Windows) |
| IDE recomendado | Visual Studio Code + extensión C/C++ |
| Sistema Operativo | Windows / Linux / macOS |

---

## 🚀 Cómo Compilar y Ejecutar

### 1. Abrir una terminal en la carpeta `Cpp/`

```bash
cd Cpp
```

### 2. Compilar el programa

```bash
g++ -o sistema main.cpp
```

> En Windows con MinGW:
> ```bash
> g++ -o sistema.exe main.cpp
> ```

### 3. Ejecutar el programa

```bash
./sistema
```
> En Windows:
> ```bash
> sistema.exe
> ```

---

## 🖥️ Ejemplo de Ejecución

```
=== SISTEMA DE CONTROL DE ESTUDIANTES ===
Asignatura: Algoritmos y Logica de Programacion
--------------------------------------------------

-- Estudiante 1 --
Cedula   : 1804001111
Nombre   : Ana
Apellido : Torres
Nota 1   : 9.0
Nota 2   : 8.5
Nota 3   : 8.0

-- Estudiante 2 --
Cedula   : 1804002222
Nombre   : Luis
Apellido : Mora
Nota 1   : 6.0
Nota 2   : 5.5
Nota 3   : 7.0

[... 3 estudiantes más ...]

=== LISTADO COMPLETO ===
Cedula        Nombre       Apellido     N1     N2     N3    Promedio  Estado
-------------------------------------------------------------------
1804001111    Ana          Torres       9.00   8.50   8.00   8.50  APROBADO
1804002222    Luis         Mora         6.00   5.50   7.00   6.17  REPROBADO
1804003333    María        León         8.00   9.00   7.50   8.17  APROBADO
1804004444    Carlos       Vega         4.50   5.00   6.00   5.17  REPROBADO
1804005555    Sofía        Cruz         7.00   8.00   9.50   8.17  APROBADO

--- Resumen ---
Total aprobados : 3
Total reprobados: 2
```

---

## 🔒 Validación de Notas

Si se ingresa un valor fuera del rango permitido, el programa lo rechaza y vuelve a pedir el dato:

```
Nota 1   : -3
  ! Nota invalida. Ingrese un valor entre 0 y 10.
Nota 1   : 12
  ! Nota invalida. Ingrese un valor entre 0 y 10.
Nota 1   : 8.5
```

---

## 🧹 Gestión de Memoria

Los objetos `Estudiante` se crean dinámicamente con `new` en el heap y se liberan al final del programa con `delete` para evitar fugas de memoria:

```cpp
Estudiante* est[TAM];
// ... creación de objetos ...
for (int i = 0; i < TAM; i++) delete est[i];
```

---

## 💡 Conceptos de POO Aplicados

| Concepto | Aplicación en el código |
|---|---|
| **Encapsulamiento** | Atributos declarados en `private`; acceso controlado por getters/setters |
| **Abstracción** | La clase modela un estudiante real con sus datos y comportamiento |
| **Métodos** | Responsabilidades separadas: calcular, determinar estado, mostrar |
| **Objetos** | Se instancian con `new Estudiante(...)` y se accede vía puntero |
| **Memoria dinámica** | Uso de `new` / `delete` para gestión manual del heap |
