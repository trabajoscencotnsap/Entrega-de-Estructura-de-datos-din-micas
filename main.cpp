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