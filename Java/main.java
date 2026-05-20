package Java;

import java.util.Scanner;

public class main {
    // Valida que la nota este en el rango [0, 10]
    static double leerNota(Scanner sc, String msg) {
        double n;
        do {
            System.out.print(msg);
            n = sc.nextDouble();
            if (n < 0 || n > 10)
                System.out.println("  ! Nota invalida. Ingrese un valor entre 0 y 10.");
        } while (n < 0 || n > 10);
        return n;
    }
 
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        final int TAM = 5;
        Estudiantes[] lista = new Estudiante[TAM];
 
        System.out.println("=== SISTEMA DE CONTROL DE ESTUDIANTES ===");
        System.out.println("Asignatura: Algoritmos y Logica de Programacion");
        System.out.println("-".repeat(50) + "\n");
 
        for (int i = 0; i < TAM; i++) {
            System.out.println("-- Estudiante " + (i + 1) + " --");
            System.out.print("Cedula   : "); String ced = sc.next();
            System.out.print("Nombre   : "); String nom = sc.next();
            System.out.print("Apellido : "); String ape = sc.next();
            double n1 = leerNota(sc, "Nota 1   : ");
            double n2 = leerNota(sc, "Nota 2   : ");
            double n3 = leerNota(sc, "Nota 3   : ");
            lista[i] = new Estudiante(ced, nom, ape, n1, n2, n3);
            System.out.println();
        }
 
        System.out.println("\n=== LISTADO COMPLETO ===");
        System.out.printf("%-13s %-12s %-12s %5s %5s %5s %7s  %s%n",
            "Cedula","Nombre","Apellido","N1","N2","N3","Promedio","Estado");
        System.out.println("-".repeat(69));
 
        int aprobados = 0, reprobados = 0;
        for (Estudiante e : lista) {
            e.mostrarInfo();
            if (e.getEstado().equals("APROBADO")) aprobados++;
            else reprobados++;
        }
 
        System.out.println("\n--- Resumen ---");
        System.out.println("Total aprobados : " + aprobados);
        System.out.println("Total reprobados: " + reprobados);
        sc.close();
    }
}

    
}   
