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
﻿