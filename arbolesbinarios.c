
#include <iostream>
#include <stdlib.h>
#include <conio.h>

using namespace std;

struct arbol
{
    int dato;
    arbol *hijo_izquierdo;
    arbol *hijo_derecho;
    arbol *aux;
};

int cont;

arbol *tree = NULL;

arbol *creararbol(int n, arbol *aux);
void insertararbol(arbol *&tree, int n, arbol *aux);
bool busqueda(arbol *tree, int n);
void imprimirarbol(arbol *tree, int contador);
int altMax(arbol *tree);
int nivelElem(arbol *tree, int n, int cont);
void eliminar (arbol *tree, int n);
void eliminarArbol(arbol *Eliminar);
arbol *minimo (arbol *tree);
void remplazar (arbol *tree, arbol *nuevoNodo);
void destruirArbol (arbol *tree);
void preorden(arbol *tree);
void posorden(arbol *tree);
void entreorden(arbol *tree);

int main()
{
    int opc, opc1, tamm, numb, numero, con=0, pet, num;
      cout << "\t---------------------------" << endl;
      cout << "\t Proyecto Final Matematicas"<< endl;
      cout << "\t---------------------------" << endl;
    do
    {
        cout << "1. Llenar arbol" << endl;
        cout << "2. Buscar un elemento en el arbol" << endl;
        cout << "3. Nivel de un elemento del arbol" << endl;
        cout << "4. Altura de un elemento del arbol" << endl;
        cout << "5. Impresion en Pre-Orden Post-Orden Entre-Orden" << endl;
        cout << "6. Eliminar un elemento del arbol" << endl;
        cout << "7. Impresion grafica del arbol" << endl;
        cout << "8. Salir\n";
        cin >> opc;

        switch(opc)
        {
            case 1:
                {
                    cout << "Llenar arbol" << endl;
                    cout<< "Ingresa el numero de elementos del arbol\n";
                    cin>>tamm;
                    for(int i=0;i<tamm; i++)
                    {
                        cout<< "Ingresa el dato a guardar\n";
                        cin >> numb;
                        insertararbol(tree, numb, NULL);
                    }
                    break;
                }
            case 2:
                {
                    cout << "Buscar un elemento en el arbol" << endl;
                    cout<< "Que numero  se va a buscar\n";
                    cin >> numero;
                    if(busqueda(tree, numero) == true)
                    {
                        cout<< "Elemento encontrado\n";
                    }
                    else
                    {
                        cout << "El elemento no existe en el arbol\n";
                    }
                    break;
                }
            case 3:
                {
                    cout << "Nivel de un elemento del arbol" << endl;
                    cout << "Ingresa el elemento a buscar\n";
                    cin >> num;
                    cout << "El nivel del elemento es: " << nivelElem(tree, num, con) << endl;
                    break;
                }
            case 4:
                {
                    cout << "Altura del arbol es: " << altMax(tree)<< endl;

                    break;
                }
            case 5:
                {
                    cout << "Pre-Orden" << endl;
                    preorden(tree);
                    cout << "Post-Orden" << endl;
                    posorden(tree);
                    cout << "Entre-Orden" << endl;
                    entreorden(tree);

                    break;
                }

            case 6:
                {
                    cout << "Eliminar un elemento del arbol" << endl;
                    cout << "Ingresal el elemento a borrar del arbol\n";
                    cin>>pet;
                    eliminar(tree, pet);
                    cout << "El elemento fue borrado con exito \n";
                    break;
                }
            case 7:
                {
                    cout << "\tImprimesion grafica del arbol\n" << endl;
                    imprimirarbol(tree, con);
                    break;
                }
            case 8:
                {
                    exit(1);
                }
            default:
                cout << "Opcion Incorrecta\n";
        }
        cout<<"Presiona (1) para menu principal (2) para terminar\n";
        cin>>opc1;

    }while(opc1 != 2);

    return 0;
}

arbol *creararbol(int n, arbol *aux)
{
    arbol *nuevo_arbol = new arbol();
    nuevo_arbol->dato = n;
    nuevo_arbol->hijo_izquierdo = NULL;
    nuevo_arbol->hijo_derecho = NULL;
    nuevo_arbol->aux = aux;
    return nuevo_arbol;
}

void insertararbol(arbol *&tree, int n, arbol *aux)
{
    if(tree == NULL)
    {
        arbol *nuevo_arbol = creararbol(n, aux);
        tree = nuevo_arbol;
        cont++;
    }
    else
    {
        int z;
        z = tree->dato;
        if(n<z)
        {
            insertararbol(tree->hijo_izquierdo,n,tree);
        }
        else
        {
            insertararbol(tree->hijo_derecho, n, tree);
        }
    }
}

bool busqueda(arbol *tree, int n)
{
    if(tree == NULL)
    {
        return false;
    }
    else
    {
        if(tree->dato == n)
        {
            return true;
        }
        else
        {
            if(n<tree->dato)
            {
                return busqueda(tree->hijo_izquierdo, n);
            }
            else
            {
                return busqueda(tree->hijo_derecho, n);
            }
        }
    }
}

void imprimirarbol(arbol *tree, int contador)
{
    if(tree ==  NULL)
    {
        return;
    }
    else
    {
        imprimirarbol(tree->hijo_derecho, contador+1);
        for(int i=0;i<contador;i++)
        {
            cout<<"   ";
        }
        cout << tree->dato << endl;
        imprimirarbol(tree->hijo_izquierdo,contador+1);
    }
}

int altMax(arbol *tree){
int aIzq, aDer;
if (tree == NULL){
    return -0;
}
else {
    aIzq = altMax(tree->hijo_izquierdo);
    aDer = altMax(tree->hijo_derecho);
    if (aIzq > aDer){
        return aIzq + 1;
    }
    else {
        return aDer + 1;
    }
}
}

int nivelElem(arbol *tree, int n, int cont)
{
    if (tree == NULL)
    {
        return 0;
    }
    else if (tree->dato == n)
    {
        return cont;
    }
    else if (n< tree->dato)
    {
        cont ++;
        return nivelElem(tree->hijo_izquierdo, n, cont);
    }
    else
    {
        cont ++;
        return nivelElem(tree->hijo_derecho,n,cont);
    }
}

void eliminar (arbol *tree, int n)
{
    if (tree ==NULL)
    {
        return;
    }
    else if (n< tree->dato)
    {
        eliminar(tree->hijo_izquierdo, n);
    }
    else if (n> tree->dato)
    {
        eliminar(tree->hijo_derecho, n);
    }
    else
    {
        eliminarArbol(tree);
    }
}

void eliminarArbol(arbol *Eliminar)
{
    if (Eliminar->hijo_izquierdo && Eliminar->hijo_derecho)
    {
        arbol *menor = minimo(Eliminar->hijo_derecho);
        Eliminar->dato = menor->dato;
        eliminarArbol(menor);
    }
    else
    {
        if (Eliminar->hijo_izquierdo)
        {
            remplazar(Eliminar,Eliminar->hijo_izquierdo);
            destruirArbol(Eliminar);
        }
        else
        {
            if (Eliminar->hijo_derecho)
            {
            remplazar(Eliminar, Eliminar->hijo_derecho);
            destruirArbol(Eliminar);
            }
            else
            {
                remplazar(Eliminar,NULL);
                destruirArbol(Eliminar);
            }
        }
    }
}

arbol *minimo (arbol *tree)
{
    if (tree == NULL)
    {
        return NULL;
    }
    if (tree->hijo_izquierdo)
    {
        return minimo(tree->hijo_izquierdo);
    }
    else
    {
        return tree;
    }
}

void remplazar (arbol *tree, arbol *nuevoNodo)
{
    if (tree->aux)
    {
        if (tree->dato == tree->aux->hijo_izquierdo->dato)
        {
            tree ->aux->hijo_izquierdo = nuevoNodo;
        }
        else
        {
            if (tree->dato == tree->aux->hijo_derecho->dato)
            {
                tree->aux->hijo_derecho = nuevoNodo;
            }
        }
    }
    if (nuevoNodo)
    {
        nuevoNodo->aux = tree->aux;
    }
}

void destruirArbol (arbol *tree)
{
    tree->hijo_izquierdo = NULL;
    tree->hijo_derecho = NULL;

    delete tree;
}
void preorden(arbol *tree)
{
    if(tree == NULL)
    {
        return;
    }
    else
    {
        cout << tree->dato << endl;
        preorden(tree->hijo_izquierdo);
        preorden(tree->hijo_derecho);
    }
}

void posorden(arbol *tree)
{
    if (tree == NULL)
    {
        return;
    }
    else
    {
        posorden(tree->hijo_izquierdo);
        posorden(tree->hijo_derecho);
        cout << tree->dato << endl;
    }
}

void entreorden(arbol *tree)
{
    if (tree == NULL)
    {
        return;
    }
    else
    {
        entreorden(tree->hijo_izquierdo);
        cout << tree->dato << endl;
        entreorden(tree->hijo_derecho);
    }
}