#include "LIBRERIAS.h"

int main(int argc, char *args[])
{
    glutInit(&argc, args);
    glutInitDisplayMode(GLUT_RGBA | GLUT_DOUBLE );
    glutInitWindowSize(1300,800);
    glutInitWindowPosition(50,50);
    glutCreateWindow("EXCEL");

    MATRIZ_DIS n1(0);

    n1.iniciar();

    return 0;
}
