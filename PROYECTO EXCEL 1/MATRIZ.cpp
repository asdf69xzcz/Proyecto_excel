#include "LIBRERIAS.h"
#include <iostream>
using namespace std;

double fps = 60.f;
double mausX=3,mausY=3;
double psy;
int a=0;

char columna='A';
int columna_entero=1;
int fila=1;

string fil_col="";
string cuadro_pri="";
string cad_principal="";

vector<pair<int,pair<int,int> > > tuplas;

bool cuadro_pri_cmp=false;
bool fil_col_cmp=false;
bool aceptar= false;
bool cancelar = false;
bool cuadro=false;


Matriz* mat = new Matriz();

MATRIZ_DIS::MATRIZ_DIS(int a)
{
    glutDisplayFunc(GRAFICOS);
    glutIdleFunc(actualizar);
    glutKeyboardFunc(teclado);
    glutMouseFunc(ControlMouse);
    glutMotionFunc(ControlMovMouse);
    glutReshapeFunc(cambiarTam);
    glutKeyboardFunc(teclado);
    glutMainLoop();
}
void MATRIZ_DIS::iniciar()
{   gluOrtho2D(1300, 0, 800, 0);
    glMatrixMode(GL_PROJECTION);
    glLineWidth(1);
}
void MATRIZ_DIS::cambiarTam(int a,int b)
{   if (b == 0)
        b = 1;
    double razon = (double) (1000 * 1.0 )/(b);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glViewport(0, 0, 1300, b);
    gluPerspective(45,razon,1,100);
    glMatrixMode(GL_MODELVIEW);
}
void MATRIZ_DIS::teclado(unsigned char tecla, int x, int y)
{
    if(tecla==' ')
    {
    }
    else
    {
        cad_principal+=tecla;
       // cout<< cad_principal << endl;
    }
}
void MATRIZ_DIS::actualizar()
{   static double tiempo_transcurrido = 0;
    static double creando_asteroides = 0;

    if((glutGet(GLUT_ELAPSED_TIME) > (double) tiempo_transcurrido + 1.f/fps))
    {   if(glutGet(GLUT_ELAPSED_TIME) > (double) creando_asteroides + 1000.0f)
        {
             creando_asteroides = glutGet(GLUT_ELAPSED_TIME);

        }

        tiempo_transcurrido = glutGet(GLUT_ELAPSED_TIME);
        glutPostRedisplay();
    }
}
void MATRIZ_DIS::TodoLosDibujos()
{


    //A1.torre(0.0 , 0.0 , 0.0 , 0.0 );
//PlaySound(TEXT("musica"), NULL, SND_FILENAME | SND_ASYNC);


   // N1.divNave(px1,py1);
   // N1.divNave(px2,py1);


}
void MATRIZ_DIS::GRAFICOS()
{
    glClear(GL_COLOR_BUFFER_BIT| GL_DEPTH_BUFFER_BIT);
    glPushMatrix();
    glClearColor(0.9, 0.9f, 0.9f,1);
    gluLookAt(	0.0f, 0.0f, 5.50f,
                0.0f, 0.0f,  0.0f,
                0.0f, 1.0f,  0.0f);

    header();
    barra_opc();
    dib_cuerpo();
    TodoLosDibujos();
    if(cuadro)
        cuadroSeleccionado();
    MostrarDatos();
    glPopMatrix();

    glutSwapBuffers();
}
void MATRIZ_DIS::header(){
    glColor3f(0.2, 0.5, 0.2);

    glBegin(GL_POLYGON);// cabezera principal
        glVertex2f(-3.f,2.9f);
        glVertex2f(3.f,2.9f);
        glVertex2f(3.f,2.08f);
        glVertex2f(-3.f,2.08f);
    glEnd();
    glColor3f(1., 1., 1.);
    glRasterPos2f(-2.66,2.15);
    string ii = "Excel";
    for (int k = 0; k < ii.size() ; k++)
    {   glutBitmapCharacter(GLUT_BITMAP_HELVETICA_12, ii[k]);
    }




}
void MATRIZ_DIS::barra_opc(){

    glColor3f(0.96, 0.96, 0.96);
    glBegin(GL_POLYGON);// cuadro de fonde de barra opc
        glVertex2f(-3.f,2.07f);
        glVertex2f(3.f,2.07f);
        glVertex2f(3.f,1.45f);
        glVertex2f(-3.f,1.45f);
        glVertex2f(-3.f,2.07f);
    glEnd();

    glColor3f(0., 0., 0.);
    glRasterPos2f(-2.8,1.99);
    string ii = "Archivo      Inicio      Insertar      Disposicion de pagina      Formula      Datos      Revisar      Vista      Ayuda";
    for (int k = 0; k < ii.size() ; k++)
    {   glutBitmapCharacter(GLUT_BITMAP_HELVETICA_12, ii[k]);
    }


    glColor3f(1., 1., 1.);
    glBegin(GL_POLYGON);// cuadro de fonde de barra opc COLOR BLANCO
        glVertex2f(-2.8f,1.95f);
        glVertex2f(2.8f,1.95f);
        glVertex2f(2.8f,1.486f);
        glVertex2f(-2.8f,1.486f);
        glVertex2f(-2.8f,1.95f);
    glEnd();

    /////#############BARRA DE LINEAS EN EL BARRA DE  OPC
    glColor3f(0.7, 0.7, 0.7);
    glBegin(GL_LINE_STRIP);
        glVertex2f(-2.4,1.93);
        glVertex2f(-2.4,1.49);
    glEnd();
    glBegin(GL_LINE_STRIP);
        glVertex2f(-1.4,1.93);
        glVertex2f(-1.4,1.49);
    glEnd();
    glBegin(GL_LINE_STRIP);
        glVertex2f(-0.7,1.9);
        glVertex2f(-0.7,1.63);
    glEnd();

    glBegin(GL_LINE_STRIP);
        glVertex2f(0.,1.93);
        glVertex2f(0.,1.49);
    glEnd();

    glBegin(GL_LINE_STRIP);
        glVertex2f(0.65,1.93);
        glVertex2f(0.65,1.49);
    glEnd();
    glBegin(GL_LINE_STRIP);
        glVertex2f(1.55,1.93);
        glVertex2f(1.55,1.49);
    glEnd();
    glBegin(GL_LINE_STRIP);
        glVertex2f(2.3,1.93);
        glVertex2f(2.3,1.49);
    glEnd();

    glColor3f(0., 0., 0.);
    glRasterPos2f(-2.8,1.52);
    ii = "      Portapapeles                                     Fuente                                                                               Alineacion                                                                 Numero                                                 Estilo                                                      Celda                                       Edicion";
    for (int k = 0; k < ii.size() ; k++)
    {   glutBitmapCharacter(GLUT_BITMAP_HELVETICA_10, ii[k]);
    }

    glColor3f(1., 1., 1.);
    glBegin(GL_POLYGON);// CUADRO DONDE DICE EN QUE FILA Y COLUMNA ESTA
        glVertex2f(-2.8,1.38);
        glVertex2f(-2.4,1.38);
        glVertex2f(-2.4,1.255);
        glVertex2f(-2.8,1.255);
        glVertex2f(-2.8,1.38);
    glEnd();
    glColor3f(0.7, 0.7, 0.7);
    glBegin(GL_LINE_STRIP);
        glVertex2f(-2.8,1.38);
        glVertex2f(-2.4,1.38);
        glVertex2f(-2.4,1.255);
        glVertex2f(-2.8,1.255);
        glVertex2f(-2.8,1.38);
    glEnd();
    glColor3f(0., 0., 0.);
    glRasterPos2f(-2.75,1.29);
        stringstream ssb;
        ssb << fila;
        string iii = columna+ssb.str();
        for (int k = 0; k < iii.size() ; k++)
        {   glutBitmapCharacter(GLUT_BITMAP_HELVETICA_12, iii[k]);
        }


    glColor3f(1., 1., 1.);
    glBegin(GL_POLYGON);// CUADRO DONDE ESTA X, ASPA, FUNCION
        glVertex2f(-2.3,1.38);
        glVertex2f(-1.8,1.38);
        glVertex2f(-1.8,1.255);
        glVertex2f(-2.3,1.255);
        glVertex2f(-2.3,1.38);
    glEnd();
    glColor3f(0.7, 0.7, 0.7);
    glBegin(GL_LINE_STRIP);
        glVertex2f(-2.3,1.38);
        glVertex2f(-1.8,1.38);
        glVertex2f(-1.8,1.255);
        glVertex2f(-2.3,1.255);
        glVertex2f(-2.3,1.38);
    glEnd();
    glColor3f(0., 0., 0.);
    glRasterPos2f(-2.28,1.29);

        ii = "  X       ->     F(x) ";
        for (int k = 0; k < ii.size() ; k++)
        {   glutBitmapCharacter(GLUT_BITMAP_HELVETICA_12, ii[k]);
        }


    glColor3f(1., 1., 1.);
    glBegin(GL_POLYGON);// CUADRO DE LA BARRA PRINCIPAL
        glVertex2f(-1.77,1.38);
        glVertex2f(2.8,1.38);
        glVertex2f(2.8,1.255);
        glVertex2f(-1.77,1.255);
        glVertex2f(-1.77,1.38);
    glEnd();
    glColor3f(0.7, 0.7, 0.7);
    glBegin(GL_LINE_STRIP);
        glVertex2f(-1.77,1.38);
        glVertex2f(2.8,1.38);
        glVertex2f(2.8,1.255);
        glVertex2f(-1.77,1.255);
        glVertex2f(-1.77,1.38);
    glEnd();
    glColor3f(0., 0., 0.);
    glRasterPos2f(-1.75,1.29);
        string iiii = cad_principal;
        for (int k = 0; k < iiii.size() ; k++)
        {   glutBitmapCharacter(GLUT_BITMAP_HELVETICA_12, iiii[k]);
        }

}
void MATRIZ_DIS::dib_cuerpo(){

    glColor3f(1.0, 1.0, 1.0); // CUADRO DE FONDO BLANCO
    glBegin(GL_POLYGON);
        glVertex2f(-2.7f,1.1f);
        glVertex2f(3.f,1.1f);
        glVertex2f(3.f,-3.f);
        glVertex2f(-2.7f,-3.f);
    glEnd();

    glColor3f(0.7, 0.7, 0.7);
    double pp;
    for(int i=0;i<26;i++){ // LINEAS HORIZONTALES
        pp = double(i*0.133);
        glBegin(GL_LINE_STRIP);
            glVertex2f(-2.82,(1.111)-pp);
            glVertex2f(2.8,(1.111)-pp);
        glEnd();
    }

    ////////###########################################################
    for(int i=0;i<19;i++){ // LINEAS VERTICALES
        pp = double(i*0.305);
        glBegin(GL_LINE_STRIP);
            glVertex2f(-2.7+pp,1.2);
            glVertex2f(-2.7+pp,-2.22);
        glEnd();
    }
    double x1=-2.8;
    double y1=1.0;
    glColor3f(0., 0., 0.);
    for(int i=1;i<=24;i++){ // NUMEROS LATERALES DE LAS FILAS
         if(i<=9)x1=-2.785;
         else x1=-2.8;
         glRasterPos2f(x1,y1);
            int bb=i;
            stringstream ssb;
            ssb << bb;

            string ii = ssb.str();
            for (int k = 0; k < ii.size() ; k++)
            {   glutBitmapCharacter(GLUT_BITMAP_HELVETICA_12, ii[k]);
            }
        y1=y1-0.133;
    }
    x1=-2.57;
    y1=1.13;


    for(int i=0;i<18;i++){ // LETRAS SUPERIORES DE LAS COLUMNAS
        glRasterPos2f(x1,y1);
        char ii = 'A'+i;
        glutBitmapCharacter(GLUT_BITMAP_HELVETICA_12, ii);

        x1= x1+0.305;
    }
}
void MATRIZ_DIS::cuadroSeleccionado(){
    double kx = 0.004203;
    double ky = 0.005903;

    double posX = kx * mausX;
    double posY = ky * mausY;

    double nx =  -2.700;
    double ny =  1.111;
    int nnnx=-1;
    int nnny=-1;
    for(int i=0;i<25;i++)
    {   if( ((ny-(i*0.133))>posY && ny-((i+1)*0.133)<posY) ){
            nnny=i;
        }
        ny-=0.002;
    }
    for(int i=0;i<19;i++){
        if(nx+(i*0.305)<posX && nx+((i+1)*0.305)>posX ){
            nnnx=i;
        }
        nx-=0.012;
    }

    nnnx--;
    columna_entero = nnnx;
    columna = 'A'+nnnx;
    fila = nnny+1;

    glColor3f(0.2, 0.5, 0.2);
    glLineWidth(3);
    double aaaaX = (nnnx*0.305);
    double aaaaY = (nnny*0.133);
    glBegin(GL_LINE_STRIP);

        glVertex2f((-2.7f)+aaaaX,(1.111f)-aaaaY);
        glVertex2f((-2.395f)+aaaaX,(1.111f)-aaaaY);
        glVertex2f((-2.395f)+aaaaX,(0.978f)-aaaaY);
        glVertex2f((-2.7f)+aaaaX,(0.978f)-aaaaY);
        glVertex2f((-2.7f)+aaaaX,(1.111f)-aaaaY);

    glEnd();
    glLineWidth(1);
    glColor3f(0., 0., 0.);
}
void MATRIZ_DIS::MostrarDatos(){
    int filaaa,columnaaa,datooo;

    for(int i=0;i<tuplas.size();i++){
        filaaa= tuplas[i].first;
        columnaaa = tuplas[i].second.first;
        datooo = tuplas[i].second.second;


        double aaaaX = (columnaaa*0.305);
        double aaaaY = (filaaa*0.133);
        glRasterPos2f((-2.59f)+aaaaX,(1.151f)-aaaaY);

        stringstream dat;
        dat << datooo;
        string ii = dat.str();
        glColor3f(0., 0., 0.);
        for (int k = 0; k < ii.size() ; k++)
        {   glutBitmapCharacter(GLUT_BITMAP_HELVETICA_12, ii[k]);
        }
        glColor3f(0., 0., 0.);
    }
}
void MATRIZ_DIS::ControlMouse(int btn,  int state,  int  x, int  y)
{
    if ((state == GLUT_DOWN) &&(btn== GLUT_LEFT_BUTTON))
    {   fil_col_cmp = false;
        btn = true;

        double mausXX = (double) x-600;
        double mausYY = (double) 400-y;

      //  cout<< "averX "<< mausX <<endl;
      // cout<< "avery "<< mausY <<endl;
        cuadro=true;

        double kx = 0.004203;
        double ky = 0.005903;

        double psx = kx * mausXX;
        double psy = ky * mausYY;

        if(psy<1.262){
            mausX = (double) x-600;
            mausY =  (double) 400-y;
        }

        //cout << "xxxx "<<psx <<"  yyyy "<<psy<<endl;


        if((-2.46<psx && -2.1>psx)&&( 1.43 > psy && 1.33 < psy )){
            fil_col_cmp = true;
        }
        else if((-1.99<psx && -1.85>psx)&&( 1.43 > psy && 1.33 < psy )){
            cancelar = true;
            cad_principal = "";
            ////////////// ya solo queda borrar esa nodo;
        }
        else if((-1.848<psx && -1.68>psx)&&( 1.42 > psy && 1.33 < psy )){
            aceptar = true;
            cout<< "fila "<< fila << " columna "<< columna << endl;
            if(isdigit(cad_principal[0])){
                int nn = atoi(cad_principal.c_str());

                mat->insertar(fila,columna_entero,nn);
                tuplas = mat->mostrar();
            }
            cad_principal = "";

            /////////// INSERTAMOS
        }

    }
    glutPostRedisplay();
}

void MATRIZ_DIS::ControlMovMouse(GLsizei x,  GLsizei y)
{
    cout<<"POSICION DE MOUSE EN COORDENADAS \n";

   // cout<< "averX "<< x<<endl;
  //  cout<< "avery "<< y<<endl;
}
