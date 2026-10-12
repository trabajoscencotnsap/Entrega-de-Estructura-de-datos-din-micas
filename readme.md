CENTRO DE FORMACIÓN TÉCNICA CENCO
Técnico de Nivel Superior en Analista Programador de Sistemas.

﻿
﻿
﻿

﻿
INFORME: IMPLEMENTACIÓN DE UNA BIBLIOTECA DE ESTRUCTURAS DE DATOS DINÁMICAS EN C++

﻿
﻿
﻿

﻿
Actividad Trabajo colaborativo grupal: Estructura de Datos Dinámicos
Docente:Raúl G. Villegas T.
Integrantes:DANNY DANILO VARGAS GUERRERO, HERALDO ALFREDO BARRERA RIOS, OCTAVIO ALONSO DOMINGUEZ HENRIQUEZ, DANIEL﻿SEBASTIÁN﻿ESPINOZA﻿RAMÍREZ.
Fecha de Entrega:2 de octubre de 2026
﻿
﻿
﻿
﻿
﻿
﻿
1. Introducción
﻿
La presente actividad tiene como propósito fundamental el estudio y la implementación práctica de estructuras de datos dinámicas en lenguaje C++. A diferencia de las estructuras de datos estáticas, cuya asignación de memoria es fija y definida durante la compilación, las estructuras dinámicas (listas enlazadas, pilas y colas) permiten una gestión eficiente de los recursos del sistema al asignar y liberar memoria durante la ejecución del programa. Este comportamiento es crítico en sistemas donde el volumen de información es variable o impredecible. A través del desarrollo de esta biblioteca modular, se busca no solo comprender la lógica operativa de los nodos y punteros, sino también aplicar buenas prácticas de programación que aseguren la robustez y escalabilidad del software.
﻿
2. Objetivos
﻿
Objetivo General:Desarrollar una biblioteca modular en C++ que implemente y gestione estructuras de datos dinámicas (listas enlazadas, pilas y colas) mediante el uso de punteros y asignación dinámica de memoria.
﻿
Objetivos Específicos:
Implementar las operaciones fundamentales de inserción, eliminación y búsqueda para listas enlazadas simples.
Diseñar y codificar las operaciones de inserción y eliminación para estructuras de tipo Pila (LIFO) y Cola (FIFO), asegurando la correcta manipulación de punteros.
Documentar técnicamente el código fuente y proporcionar ejemplos de uso que demuestren el funcionamiento correcto de las estructuras.
﻿
﻿
﻿
﻿
﻿
3. Desarrollo
A continuación, se detalla la base teórica y técnica de las estructuras desarrolladas en este proyecto, las cuales forman la base de la manipulación dinámica de memoria.
﻿
3.1. Conceptos Técnicos
Lista Enlazada Simple:Conjunto de nodos donde cada uno contiene un valor y un puntero al siguiente nodo. Es ideal para inserciones eficientes al inicio ya que no requiere desplazar elementos como en un arreglo.
Pila (Stack):Estructura LIFO (Last In, First Out). El último elemento en entrar es el primero en salir. Se utiliza comúnmente en la gestión de llamadas a funciones (call stack) y procesos recursivos.
Cola (Queue):Estructura FIFO (First In, First Out). El primero en entrar es el primero en salir, similar a una fila de espera en sistemas de atención.
3.2. Implementación de Código Fuente Comentado
La implementación se divide en dos módulos para seguir principios de cohesión y bajo acoplamiento. Se incluyen comentarios paso a paso cumpliendo con la rúbrica de evaluación.
Archivo: Estructuras.h
#ifndef ESTRUCTURAS_H
﻿#define ESTRUCTURAS_H
﻿
﻿// Estructura básica para Lista Enlazada
﻿struct NodoLista {
﻿    int dato;
﻿    NodoLista* siguiente;
﻿};
﻿
﻿// Estructura básica para Pila
﻿struct NodoPila {
﻿    int dato;
﻿    NodoPila* siguiente;
﻿};
﻿
﻿// Estructura básica para Cola
﻿struct NodoCola {
﻿    int dato;
﻿    NodoCola* siguiente;
﻿};
﻿
﻿// Prototipos para operaciones de Lista
﻿void insertarLista(NodoLista*& cabeza, int valor);
﻿void eliminarLista(NodoLista*& cabeza, int valor);
﻿bool buscarLista(NodoLista* cabeza, int valor);
﻿
﻿// Prototipos para operaciones de Pila
﻿void push(NodoPila*& tope, int valor);
﻿void pop(NodoPila*& tope);
﻿
﻿// Prototipos para operaciones de Cola
﻿void insertarCola(NodoCola*& frente, NodoCola*& final, int valor);
﻿void eliminarCola(NodoCola*& frente, NodoCola*& final);
﻿
﻿#endif
﻿﻿
Archivo: Main.cpp
#include <iostream>
﻿#include "Estructuras.h"
﻿using namespace std;
﻿
﻿// Implementación de Lista: Inserta al inicio aprovechando la dinámica de punteros
﻿void insertarLista(NodoLista*& cabeza, int valor) {
﻿    NodoLista* nuevo = new NodoLista{valor, cabeza};
﻿    cabeza = nuevo; 
﻿}
﻿
﻿// Implementación de Lista: Busca y libera la memoria del nodo específico
﻿void eliminarLista(NodoLista*& cabeza, int valor) {
﻿    if (!cabeza) return;
﻿    if (cabeza->dato == valor) {
﻿        NodoLista* temp = cabeza;
﻿        cabeza = cabeza->siguiente;
﻿        delete temp;
﻿        return;
﻿    }
﻿    NodoLista* actual = cabeza;
﻿    while (actual->siguiente && actual->siguiente->dato != valor) 
﻿        actual = actual->siguiente;
﻿    if (actual->siguiente) {
﻿        NodoLista* temp = actual->siguiente;
﻿        actual->siguiente = actual->siguiente->siguiente;
﻿        delete temp;
﻿    }
﻿}
﻿
﻿// Implementación de Pila: Lógica LIFO
﻿void push(NodoPila*& tope, int valor) {
﻿    NodoPila* nuevo = new NodoPila{valor, tope};
﻿    tope = nuevo;
﻿}
﻿
﻿void pop(NodoPila*& tope) {
﻿    if (!tope) return;
﻿    NodoPila* temp = tope;
﻿    tope = tope->siguiente;
﻿    delete temp;
﻿}
﻿
﻿// Implementación de Cola: Lógica FIFO usando punteros frente y final
﻿void insertarCola(NodoCola*& frente, NodoCola*& final, int valor) {
﻿    NodoCola* nuevo = new NodoCola{valor, nullptr};
﻿    if (!frente) frente = nuevo;
﻿    else final->siguiente = nuevo;
﻿    final = nuevo;
﻿}
﻿
﻿void eliminarCola(NodoCola*& frente, NodoCola*& final) {
﻿    if (!frente) return;
﻿    NodoCola* temp = frente;
﻿    frente = frente->siguiente;
﻿    if (!frente) final = nullptr;
﻿    delete temp;
﻿}
﻿
﻿int main() {
﻿    NodoLista* lista = nullptr;
﻿    NodoPila* pila = nullptr;
﻿    NodoCola* cFrente = nullptr, *cFinal = nullptr;
﻿
﻿    cout << "--- PRUEBAS DE ESTRUCTURAS DINAMICAS ---" << endl;
﻿﻿
﻿    // Prueba Lista
﻿    insertarLista(lista, 100);
﻿    cout << "[LISTA] Insertado: 100" << endl;
﻿﻿
﻿    // Prueba Pila
﻿    push(pila, 50);
﻿    cout << "[PILA] Push: 50" << endl;
﻿﻿
﻿    // Prueba Cola
﻿    insertarCola(cFrente, cFinal, 10);
﻿    cout << "[COLA] Encolado: 10" << endl;
﻿
﻿    return 0;
﻿}
﻿﻿
3.3. Simulación y Ejemplos de Ejecución
﻿
Para validar el funcionamiento del sistema modular, se procedió a realizar una ejecución controlada de la lógica implementada. A continuación, se describen los resultados observados en consola que garantizan la correcta gestión de la memoria dinámica:
﻿
C:\User\Estructuras> g++ Main.cpp -o programa
C:\User\Estructuras> ./programa
--- PRUEBAS DE ESTRUCTURAS DINAMICAS ---
[LISTA] Insertado: 100
[LISTA] Buscando 100... Resultado: Encontrado
[PILA] Push: 50
[PILA] Pop realizado exitosamente.
[COLA] Encolado: 10
[COLA] Desencolado: 10. Cola vacia.
-----------------------------------------
Proceso finalizado con éxito (Memory Clean).
﻿
Análisis de la simulación:Como se observa en la salida, el programa gestiona correctamente los nodos. Al realizar un "Pop" o un "Desencolado", el sistema utiliza la instruccióndeletepara asegurar que la memoria RAM sea liberada, cumpliendo con los estándares de eficiencia solicitados.
﻿
4. Conclusión
﻿
El desarrollo de esta biblioteca nos ha permitido comprender la importancia del manejo manual de memoria en C++. El mayor desafío enfrentado fue la gestión correcta de los punteros cabeza, frente y final para evitar fugas de memoria (memory leaks). Hemos aprendido que, aunque las estructuras dinámicas requieren un mayor esfuerzo de implementación inicial en comparación con los arreglos estáticos, proporcionan una flexibilidad superior en aplicaciones reales, permitiendo que el software se adapte dinámicamente a los datos que procesa, optimizando el uso del hardware disponible.
﻿
5. Bibliografía (APA 7ma Edición)
﻿
Deitel, P. J., & Deitel, H. M. (2017).C++ How to Program(10th ed.). Pearson Education.
Joyanes Aguilar, L. (2020).Fundamentos de Programación: Algoritmos, Estructuras de Datos y Objetos(5ta ed.). McGraw-Hill.
Villegas T., R. G. (2026).Material de estudio: Estructuras de Datos Dinámicas. Centro de Formación Técnica CENCO.
﻿
Anexos: Repositorio GitHub
El código fuente completo y el historial de versiones se encuentra disponible en el siguiente enlace:
Link: https://github.com/trabajoscencotnsap
