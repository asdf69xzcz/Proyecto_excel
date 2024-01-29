#ifndef MATRIZ_H_INCLUDED
#define MATRIZ_H_INCLUDED
#include "LIBRERIAS.h"
class MATRIZ_DIS
{   private:
    static int a;

    public:
        MATRIZ_DIS(int a);
        static void iniciar();
        static void cambiarTam(int a,int b);
        static void teclado(unsigned char tecla, int x, int y);
        static void actualizar();
        static void TodoLosDibujos();
        static void GRAFICOS();
        static void header();
        static void barra_opc();
        static void dib_cuerpo();
        static void MostrarDatos();
        static void cuadroSeleccionado();
        static void ControlMouse(int btn,  int state,  int  x, int  y);

        static void ControlMovMouse(GLsizei x,  GLsizei y);
};

#endif // MATRIZ_H_INCLUDED
