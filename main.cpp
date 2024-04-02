#include <iostream>
#include <sstream>
#include "clases/Grupos.h"
#include <string>
#include "estructuras/TablaHash.h"


using namespace std;
void menuPrincipal() {
    cout << "****** CODE & BUGS ******" << endl;
    cout << "1. Ingrese el comando" << endl;
    cout << "2. Graficas" << endl;
    cout << "3. Exportacion de contactos" << endl;
    cout << "4. Reportes" << endl;
    cout << "5. Salir" << endl;
    cout << "Ingrese la opcion deseada: ";
}

void submenuGraficas() {
    cout << "****** GRAFICAS ******" << endl;
    cout << "1. Estado actual de la estructura completa." << endl;
    cout << "2. Estado actual de cada una de las estructuras por separado mostrara solo 1 grupo." << endl;
    cout << "3. Estado de visualizacion de todos los datos contenidos." << endl;
    cout << "5. Regresar" << endl;
    cout << "Ingrese la opcion deseada: ";
}

void limpiarPantalla() {
    cout << "\n\n\n\n\n\n\n\n\n\n";
}

template <typename T>
void verificacionCreacion(std::string &comando, TablaHash<T> &tablaHash){
    std::istringstream iss(comando);
    limpiarPantalla();
    std::string add, newgroup, nameGroup, fields, attributes;
    iss >> add >> newgroup >> nameGroup >> fields;
    if (add == "ADD" && newgroup == "NEW-GROUP" && fields == "FIELDS" ){
        Grupos* grupo = new Grupos();
        grupo->setNombreGrupo(nameGroup);
        cout << "Grupo creado con exito " << attributes << endl;
        cout << "El nombre del grupo es: " <<  grupo->getNombreGrupo() << endl;
        std::getline(iss, attributes, ';');
        attributes.erase(0, 2);
        attributes.erase(attributes.size() - 1);
        std::istringstream iss2(attributes);
        std::string attribute;
        while (std::getline(iss2, attribute, ',')) {
            std::istringstream iss3(attribute);
            std::string key, value;
            iss3 >> key >> value;
            grupo->group[key] = value;
        }
        for (const auto& pair : grupo->group) {
            cout << pair.first << ": " << pair.second << endl;
        }
        tablaHash.insertGroup(grupo);
        tablaHash.mostrarTabla();
    } else {
        cout << "El comando no es valido" << endl;
    }
}

void verificacionInsercion(string comando){
    cout << "Andamos en la verificacion de insercion" << endl;
}

void busquedaContactos(string comando){
    cout << "Andamos en la busqueda de contactos" << endl;
}

template <typename T>
void creaGrupoContactos(TablaHash<T> tablaHash){
    std::string comando;
    cout << "****** INGRESE EL COMANDO CORRECTAMENTE ******\n";
    std::getline(std::cin.ignore(), comando); //ACA PEDIMOS EL COMANDO
    istringstream iss(comando);//Dividimos el comando
    std::string add, newgroup;//Segun el add y newgroup podemos saber que tipo de comando es
    iss >> add >> newgroup;
    if(add == "ADD" && newgroup == "NEW-GROUP"){
        //Aqui se verifica si el agregar comando es correcto
        verificacionCreacion(comando, tablaHash);
    } else if(add == "ADD" && newgroup == "CONTACT"){
        verificacionInsercion(comando);
    } else if(add == "FIND"){
        busquedaContactos(comando);
    } else {
        cout << "Comando no valido" << endl;
    }
}

int main() {
    TablaHash<Grupos*> tablaHash;
    int seleccion = 0;
    menuPrincipal();
    cin >> seleccion;
    do {
        switch (seleccion) {
            case 1:
                limpiarPantalla();
                creaGrupoContactos(tablaHash);
                break;
            case 2:
                limpiarPantalla();
                submenuGraficas();
                break;
        }
        menuPrincipal();
        cin >> seleccion;
    } while (seleccion != 5);
    return 0;
}
