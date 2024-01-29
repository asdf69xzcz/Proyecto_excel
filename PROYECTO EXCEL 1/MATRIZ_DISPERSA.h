#ifndef MATRIZ_DISPERSA_H_INCLUDED
#define MATRIZ_DISPERSA_H_INCLUDED

#include "LIBRERIAS.h"

class NodoCol {
public:
    int columna;
    int dato;
    NodoCol* sig;

    NodoCol(int c, int d) : columna(c), dato(d), sig(NULL) {}
    NodoCol(int c, int d, NodoCol* s) : columna(c), dato(d), sig(s) {}

    void mostrar() {
        cout << columna << " " << dato << endl;
    }
};

class ListaCol {
public:
    NodoCol* iniCol;

    ListaCol() : iniCol(NULL) {}

    NodoCol* buscar(int columna) {
        for (NodoCol* tmp = iniCol; tmp != NULL; tmp = tmp->sig) {
            if (tmp->columna == columna) {
                cout << "Col=";
                tmp->mostrar();
                return tmp;
            }
        }
        return NULL;
    }

    void insertar(int columna, int dato) {
        if (buscar(columna) != NULL) {
            return;
        }

        if (iniCol == NULL) {
            iniCol = new NodoCol(columna, dato);
        } else {
            int pos = 0;
            NodoCol* tmp = iniCol;
            NodoCol* tmp2 = iniCol;
            bool flag = false;

            for (; tmp && tmp->columna <= columna; pos++) {
                if (tmp->columna == columna) {
                    return;
                }

                if (!tmp->sig) {
                    flag = true;
                    break;
                }

                tmp2 = tmp;
                tmp = tmp->sig;
            }

            if (pos == 0 && !flag) {
                iniCol = new NodoCol(columna, dato, iniCol);
            } else if (flag) {
                tmp->sig = new NodoCol(columna, dato);
            } else {
                tmp2->sig = new NodoCol(columna, dato, tmp2->sig);
            }
        }
    }

    void mostrar() {
        for (NodoCol* tmp = iniCol; tmp != NULL; tmp = tmp->sig) {
            tmp->mostrar();
        }
    }
};

class NodoFila {
public:
    int fila;
    NodoFila* sig;
    ListaCol* columnas;

    NodoFila(int f) : fila(f), sig(NULL), columnas(new ListaCol()) {}
    NodoFila(int f, NodoFila* s) : fila(f), sig(s), columnas(new ListaCol()) {}

    void mostrar() {
        cout << fila << endl;
    }
};

class ListaFila {
public:
    NodoFila* iniFila;

    ListaFila() : iniFila(NULL) {}

    void insertarPos(int pos, int fila) {
        if (iniFila == NULL) {
            iniFila = new NodoFila(fila);
        } else {
            if (pos == 0) {
                iniFila = new NodoFila(fila, iniFila);
            } else {
                int i;
                NodoFila* tmp;
                for (tmp = iniFila, i = 0; i < pos - 1 && tmp; i++, tmp = tmp->sig)
                    ;
                if (tmp) {
                    tmp->sig = new NodoFila(fila, tmp->sig);
                }
            }
        }
    }

    NodoFila* buscar(int fila) {
        for (NodoFila* tmp = iniFila; tmp != NULL; tmp = tmp->sig) {
            if (tmp->fila == fila)
                return tmp;
        }
        return NULL;
    }

    void insertar(int fila) {
        if (buscar(fila) != NULL) {
            return;
        }

        if (iniFila == NULL) {
            iniFila = new NodoFila(fila);
        } else {
            int pos = 0;
            NodoFila* tmp = iniFila;
            NodoFila* tmp2 = iniFila;
            bool flag = false;

            for (; tmp && tmp->fila <= fila; pos++) {
                if (tmp->fila == fila) {
                    return;
                }

                if (!tmp->sig) {
                    flag = true;
                    break;
                }

                tmp2 = tmp;
                tmp = tmp->sig;
            }

            if (pos == 0 && !flag) {
                iniFila = new NodoFila(fila, iniFila);
            } else if (flag) {
                tmp->sig = new NodoFila(fila, tmp->sig);
            } else {
                tmp2->sig = new NodoFila(fila, tmp2->sig);
            }
        }
    }

    void mostrar() {
        for (NodoFila* tmp = iniFila; tmp != NULL; tmp = tmp->sig) {
            tmp->mostrar();
        }
    }
};

class Matriz {
public:
    ListaFila* filas;

    Matriz() : filas(new ListaFila()) {}

    void insertar(int fila, int columna, int dato) {
        NodoFila* tmp = filas->buscar(fila);

        if (tmp == NULL) {
            filas->insertar(fila);
            tmp = filas->buscar(fila);
        }

        if (tmp->columnas->buscar(columna) == NULL) {
            tmp->columnas->insertar(columna, dato);
        } else {
            tmp->columnas->buscar(columna)->dato = dato;
        }
    }

    vector<pair<int,pair<int,int > > > mostrar() {
        NodoFila* tmp;
        NodoCol* tmp2;
        vector<pair<int,pair<int,int> > >  tuplas;

        for (tmp = filas->iniFila; tmp != NULL; tmp = tmp->sig) {
            for (tmp2 = tmp->columnas->iniCol; tmp2 != NULL; tmp2 = tmp2->sig) {
                //tuplas.push_back(make_pair(tmp->fila, make_pair(tmp->columnas, tmp2->dato)));
                tuplas.push_back(pair<int, pair<int, int> >(tmp->fila, pair<int, int>(tmp2->columna, tmp2->dato)));

                // tuplas[i].first = tmp->fila;
                // tuplas[i].second.first = tmp->columnas;
                // tuplas[i].second.second = tmp2->dato;
                cout << " fila-> " << tmp->fila << "";
                cout << " columna-> " << tmp2->columna << " dato = " << tmp2->dato << endl;

            }
          //  cout << endl;
        }
        return tuplas;
    }
    NodoCol* buscarDato(int fila, int columna) {
        NodoFila* tmpFila = filas->buscar(fila);
        if (tmpFila != NULL) {
            NodoCol* tmpCol = tmpFila->columnas->buscar(columna);
            return tmpCol;
        }
        return NULL;
    }
};
#endif // MATRIZ_DISPERSA_H_INCLUDED
