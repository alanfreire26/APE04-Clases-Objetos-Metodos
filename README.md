# APE04-Clases-Objetos-Metodos
# 🎓 APE04 – Clases, Objetos y Métodos

**Asignatura:** Algoritmos y Lógica de Programación  
**Carrera:** Software  
**Universidad:** Universidad Técnica de Ambato  
**Docente:** Ing. José Rubén Caiza, Mg.  
**Ciclo:** Enero 2026 – Julio 2026  
**Estudiante:** Apellidos y Nombres  

---

## 📋 Descripción del Proyecto

Sistema básico de control de estudiantes y calificaciones desarrollado como parte de la guía práctica **SW-AyLP-APE-04**. El programa permite registrar información de estudiantes de la asignatura Algoritmos y Lógica de Programación, aplicando los principios de la **Programación Orientada a Objetos (POO)** mediante clases, objetos y métodos.

El sistema fue implementado en dos lenguajes de programación:
- **C++** – archivo único `main.cpp`
- **Java** – dos archivos: `Estudiante.java` y `Main.java`

---

## 🎯 Funcionalidades

- Registrar mínimo **5 estudiantes** con sus datos personales.
- Ingresar **3 notas** por estudiante (validadas en el rango 0 – 10).
- Calcular automáticamente el **promedio**.
- Determinar el **estado académico**: `APROBADO` (promedio ≥ 7.00) o `REPROBADO`.
- Mostrar el **listado completo** de estudiantes en formato tabular.
- Mostrar el **resumen** con el total de aprobados y reprobados.

---

## 🧱 Diseño de la Clase Estudiante

| Elemento | Detalle |
|---|---|
| **Atributos (privados)** | `cedula`, `nombre`, `apellido`, `nota1`, `nota2`, `nota3`, `promedio`, `estado` |
| **Constructor** | Recibe los 6 datos base y calcula promedio y estado automáticamente |
| **Getters** | `getCedula()`, `getNombre()`, `getApellido()`, `getNota1/2/3()`, `getPromedio()`, `getEstado()` |
| **Setters** | `setNota1/2/3()` – actualizan promedio y estado al cambiar una nota |
| **`calcularPromedio()`** | `promedio = (nota1 + nota2 + nota3) / 3.0` |
| **`determinarEstado()`** | `APROBADO` si promedio ≥ 7.00, de lo contrario `REPROBADO` |
| **`mostrarInfo()`** | Imprime todos los datos del estudiante con formato tabular |

---



*Universidad Técnica de Ambato – Facultad de Ingeniería en Sistemas, Electrónica e Industrial*
