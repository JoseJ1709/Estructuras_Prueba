/*
  Estructura de Datos - Proyecto de clase
- Jose Andres Jaramillo- Juan Camilo Gomez
  Universidad Javeriana - Tercer periodo 2023
*/

#include "jugador.h"
#include <iostream>
#include <string>
#include "continente.h"
#include "tarjeta.h"
#include <list>

using namespace std;

Jugador::Jugador(){}
Jugador::Jugador(string n, string c, int id) {
  nombre_jugador = n;
  color_jugador = c;
  id_jugador = id;
}

int calcularUnidadesFortificar(int tarjetas_global) {
    int unidades_a_sumar = 0;

    if (tarjetas_global > 7) {
        tarjetas_global = 7;
    }

    switch (tarjetas_global) {
        case 1:
            unidades_a_sumar = 4;
            break;
        case 2:
            unidades_a_sumar = 6;
            break;
        case 3:
            unidades_a_sumar = 8;
            break;
        case 4:
            unidades_a_sumar = 10;
            break;
        case 5:
            unidades_a_sumar = 12;
            break;
        case 6:
            unidades_a_sumar = 15;
            break;
        case 7:
            for (int j = 1; j <= 6; ++j) {
                unidades_a_sumar += 5;
            }
            break;
        default:
            break;
    }

    return unidades_a_sumar;
}

void Jugador::fortificar(list<Continente> continentes,  int tarjetas_global ) {
    int opcion= 0;
    int unidades_fortifciar = territorios_jugador.size() / 3;
    string tipos_tarjeta[4] = {"Soldier", "Horse", "Canon", "comodin"};
    int contador[4] = {0, 0, 0, 0};
    int sum;
    bool ver = false;
    bool Comb1 = false;
    bool Comb2 = false;
    bool Comb3 = false;
    cout << "fortificando" << "\n";

                                //-----verificacion de otras unidades------ //
                                        //verificaion de Tarjetas//

    //mirar cuantas tarjetas de que tipo tengo - clasificas //

    for (const Tarjeta tarjeta: tarjetas_jugador) {
        for (int i = 0; i < 4; i++) {
            if (tarjeta.getDibujo() == tipos_tarjeta[i]) {
                contador[i]++;
                break;
            }
        }
    }

    // imprimir # de cartas que tiene el usuario //

    cout<<"----Revisando tarjetas de jugador----"<<"\n";
    cout<<""<< "\n";
    for (int i = 0; i <3 ; ++i) {
        if(contador[i] > 0){
            cout<< "Tienes " << contador[i] << " tarjetas de " << tipos_tarjeta[i]<<"\n";
        }
    }

    //revisar que combinaciones tiene //


    //revisar si tiene tres cartas del mismo dibujo //
    for (int i = 0; i < 2; ++i) {
        if(contador[i] >= 3){
            cout<<"tienes una combinacion de 3 cartas del mismo dibujo"<< "\n";
            Comb1 = true;
        }
    }
    //revisar si tiene tres cartas de distito dibujo //

    if(contador[0] >=1 &&contador[1] >=1 && contador[2] >=1){
        cout<<"tienes una combinacion de 3 cartas del mismo dibujo"<< "\n";
        Comb2 = true;
    }
    //revisar si tiene dos cartas de distinto dibujo y un comodin //

    if (contador[3] >= 1 && ((contador[0] >= 1 && (contador[1] >= 1 || contador[2] >= 1)) || (contador[1] >= 1 && (contador[0] >= 1 || contador[2] >= 1)) || (contador[2] >= 1 && (contador[0] >= 1 || contador[1] >= 1)))) {
        cout << "Tienes una combinación de dos cartas de distinto dibujo y un comodín" << endl;
        Comb3 = true;
    }

    if (Comb1 == true || Comb2 == true || Comb3 == true) {
        do {
            cout << "Escoge una ocpion segun tus combinaciones"<< "\n";
            cout << "'1' tres cartas con mismo dibujo " << "\n";
            cout << "'2' tres cartas con distinto dibujo " << "\n";
            cout << "'3' dos cartas con distinto dibujo y un comodin" << "\n";
            cout << "'4' no quiero intercambiar tarjetas"<< "\n";
            cin >> opcion;
            //verificar que pueda realizar la opcion escogida || si si, borras lo pedido en la opcion //
            //tres cartas con el mismo dibujo //
            if (opcion == 1) {
                for (int i = 0; i < 3; ++i) {
                    if (contador[i] >= 3) {
                        cout << "Intercambiando tarjetas por unidades" << "\n";
                        //borrar trio de tarjetas //
                        bool intercambio_completado = false;
                        int este = 0;
                        for (int i = 0; i < 2; ++i) {
                            este = contador[i];
                            if (este >= 3) {
                                este = i;
                                break;
                            }
                        }
                        //ya sabemos el tipo de tarjeta que vamos a borrar ahora vamos a buscar en el usuario ese tipo y mirar si esa tarjeta la tiene
                        for (auto it = tarjetas_jugador.begin(); it != tarjetas_jugador.end();) {
                            int i;
                            //encontramos una tarjeta del mismo tipo //
                            if ((*it).getDibujo() == tipos_tarjeta[este]) {
                                // Verificar si el jugador tiene el territorio de la tarjeta.
                                for (const Territorio territorio: territorios_jugador) {
                                    if ((*it).getKeyTerritorio() == territorio.getKeyTerritorio()) {
                                        unidades_fortifciar += 2;
                                        cout<<"Tienes el mismo terriotorio de la tarjeta" <<"\n";
                                    }
                                }
                                // Borrar la tarjeta y obtener el siguiente iterador.
                                it = tarjetas_jugador.erase(it);
                                i++;
                                // Comprobar si hemos encontrado suficientes tarjetas coincidentes.
                                if (i >= 3) {
                                    int unidades_sumar = calcularUnidadesFortificar(tarjetas_global);
                                    unidades_fortifciar += unidades_sumar;
                                    cout<< "se sumaron " << unidades_sumar<<" unidades";
                                    tarjetas_global++;
                                    ver = true;
                                    cout << "unidades intercambiadas con exito" << "\n";
                                    opcion = 4;
                                    break;
                                }
                            }
                        }
                    }
                }
            }
            if (opcion == 2) {
                // las 3 tarjetas distintas //
                if (contador[0] > 0 && contador[1] > 0 && contador[2] > 0) {
                    cout << "Intercambiando tarjetas por unidades" << "\n";
                    //borrar una tarjeta de cada tipo
                    bool intercambio_completado = false;

                    for (int i = 0; i < 2; ++i) {
                        //ya sabemos el tipo de tarjeta que vamos a borrar ahora vamos a buscar en el usuario ese tipo y mirar si esa tarjeta la tiene
                        for (auto it = tarjetas_jugador.begin(); it != tarjetas_jugador.end();) {
                            int i;
                            //encontramos una tarjeta del mismo tipo //
                            if ((*it).getDibujo() == tipos_tarjeta[i]) {
                                string nomTerr;
                                // Verificar si el jugador tiene el territorio de la tarjeta.
                                for (const Territorio territorio: territorios_jugador) {

                                    if ((*it).getKeyTerritorio() == territorio.getKeyTerritorio()) {
                                        unidades_fortifciar += 2;
                                        cout<<"Tienes el mismo terriotorio de la tarjeta" <<"\n";
                                    }
                                }
                                // Borrar la tarjeta y obtener el siguiente iterador.
                                it = tarjetas_jugador.erase(it);

                                break; // Salir del bucle ya que hemos borrado una
                            }
                        }
                    }
                    int unidades_sumar = calcularUnidadesFortificar(tarjetas_global);
                    unidades_fortifciar += unidades_sumar;
                    cout<< "se sumaron " << unidades_sumar<<" unidades";
                    tarjetas_global++;
                    ver = true;
                    opcion = 4;
                    cout << "unidades intercambiadas con exito" << "\n";
                    break;
                }
            }
            if (opcion == 3) {
                //dos tarjetas distintas y un comodin
                if ((contador[0] > 1 && contador[1] > 1) || (contador[0] > 1 && contador[2] > 1) ||(contador[1] > 1 && contador[2] > 1) && contador[3] > 0) {
                    cout << "Intercambiando tarjetas por unidades" << "\n";
                    //borrar 2 tarjetas de distinto tipo //
                    int t = 0;
                    for (int i = 0; i < 2; ++i) {
                        //ya sabemos el tipo de tarjeta que vamos a borrar ahora vamos a buscar en el usuario ese tipo y mirar si esa tarjeta la tiene
                        for (auto it = tarjetas_jugador.begin(); it != tarjetas_jugador.end();) {
                            int i;
                            //encontramos una tarjeta del mismo tipo //
                            if ((*it).getDibujo() == tipos_tarjeta[i]) {
                                // Verificar si el jugador tiene el territorio de la tarjeta.
                                for (const Territorio territorio: territorios_jugador) {
                                    if ((*it).getKeyTerritorio() == territorio.getKeyTerritorio()) {
                                        unidades_fortifciar += 2;
                                        cout<<"Tienes el mismo terriotorio de la tarjeta" <<"\n";
                                    }
                                }
                                // Borrar la tarjeta y obtener el siguiente iterador.
                                it = tarjetas_jugador.erase(it);
                                t++;
                                break; // Salir del bucle ya que hemos borrado una
                            }
                        }
                        if (t >= 2) {
                            int unidades_sumar = calcularUnidadesFortificar(tarjetas_global);
                            unidades_fortifciar += unidades_sumar;
                            cout<< "se sumaron " << unidades_sumar<<" unidades";
                            tarjetas_global++;
                            ver = true;
                            opcion = 4;
                            cout << "unidades intercambiadas con exito" << "\n";
                            break;
                        }
                    }
                }
            }
            if (opcion != 4 && opcion != 3 && opcion != 2 && opcion != 1) {
                cout << "opcion erronea, intente otra vez" << "\n";
            }
        } while (opcion != 4);
    } else{
        cout<<"no tienes combinaciones de tarjetas"<< "\n";
    }

                                                //verificacion de continentes//

    int territoriosXcontinente[6] ={0,0,0,0,0,0};
    bool territoriocupado = false;
    string nombreTerritorio;
    int unidadesAñadir;
    bool esValido = false;

    cout<<"----Revisando territorios de jugador----"<<"\n";
    cout<<""<< "\n";

    // Iterar sobre la lista de territorios del jugador para mirar cuantos territorios de un continente tiene
    for (Territorio territorio : territorios_jugador) {
        int continente = territorio.getIdContinente();
        switch (continente) {
            case 1 : //americaN//
                territoriosXcontinente[0]++;
                break;
            case 2 : //Europa//
                territoriosXcontinente[1]++;
                break;
            case 3 : //Asia//
                territoriosXcontinente[2]++;
                break;
            case 4 : //africa//
                territoriosXcontinente[3]++;
                break;
            case 5 : //americaS//
                territoriosXcontinente[4]++;
                break;
            case 6 : //australia//
                territoriosXcontinente[5]++;
                break;
        default:
            break;
        }
    }
    //mirar si el tamaño del continente[1] es igual que el numero de la lista del jugador en [1] que deberia ser 9

    for (const Continente continente : continentes ) {
        for (int i = 0; i < 5; i++) {
            if (territoriosXcontinente[i] == continente.getNumContinente()) {
                switch (continente.getNumContinente()) {
                    case 9 : //americaN//
                        unidades_fortifciar += 5;
                        territoriocupado = true;
                        cout << "Territorio America Norte ocupado.  +5 unidades"<<"\n";
                        break;
                    case 7 : //Europa//
                        territoriocupado = true;
                        unidades_fortifciar += 5;
                        cout << "Territorio Europa ocupado. +5 unidades"<<"\n";
                        break;
                    case 12 : //Asia//
                        territoriocupado = true;
                        unidades_fortifciar += 7;
                        cout << "Territorio Asia ocupado. +7 unidades"<<"\n";
                        break;
                    case 6 : //africa//
                        territoriocupado = true;
                        unidades_fortifciar += 3;
                        cout << "Territorio Africa ocupado. +3 unidades"<<"\n";
                        break;
                    case 4 : //americaS - australia//
                        territoriocupado = true;
                        unidades_fortifciar += 2;
                        break;
                }
            }
        }
    }
    if (territoriocupado = false){
        cout << "no tiene ningun continente ocupado "<<"\n";
    }
    cout<<""<< "\n";

                                                //-----seleccionar territorios al cual añadir----//
    //mostrar territorios //
    cout << "Territorios de " << nombre_jugador << ":" <<"\n";
    for (Territorio territorio : territorios_jugador) {
        cout << " - " << territorio.getNombreTerritorio() << " tiene :" << territorio.getUnidadesDeEjercitoTerritorio() << " unidades" <<"\n";
    }

    //seleccionar y añaidir unidades a territorios //
    do {
        cout << "Usted tiene : " << unidades_fortifciar << " unidades para fortificar sus territorios" << endl;
        cin.ignore();
        do {
            cout << "Dame el nombre del territorio al que quieres fortificar" << endl;
            getline(cin, nombreTerritorio);

            for (Territorio &territorio : territorios_jugador) {
                if (territorio.getNombreTerritorio() == nombreTerritorio) {
                    esValido = true;
                    break;
                }
            }

            if (!esValido) {
                cout << "Nombre de territorio no válido. Intente nuevamente." << endl;
            }
        } while (!esValido);

        do {
            cout << "Dame la cantidad de unidades que le quieres añadir" << endl;
            cin >> unidadesAñadir;
            if (unidadesAñadir <= unidades_fortifciar) {
                for (Territorio &territorio : territorios_jugador) {
                    if (nombreTerritorio == territorio.getNombreTerritorio()) {
                        territorio.setUnidadesDeEjercitoTerritorio(territorio.getUnidadesDeEjercitoTerritorio() + unidadesAñadir);
                        unidades_fortifciar -= unidadesAñadir;
                        cout << "Fortificación exitosa. " << territorio.getNombreTerritorio() << " ahora tiene " << territorio.getUnidadesDeEjercitoTerritorio() << " unidades." << endl;
                        break;
                    }
                }
            }
            if (!esValido) {
                cout << "Cantidad de unidades inválida. Intente nuevamente." << endl;
            }
        } while (!esValido);
    } while (unidades_fortifciar > 0);
    cout << "Fortificación terminada" << endl;
    cout<<""<< "\n";
}

void Jugador::mover() {
    cout<<"moviendo"<< "\n";
    cout<<"" << "\n";

    bool Valido = false;
    bool Valido2 = false;
    bool Valido3 = false;
    bool adyacente = true;
    string territorio_obtener;
    string territorio_poner;
    int unidades_mover;
    int suma =0 ;
    int tamaño = territorios_jugador.size();

    for (Territorio territorio: territorios_jugador) {
        suma = suma + territorio.getUnidadesDeEjercitoTerritorio();
    }
    if(suma>tamaño){

        cout << "Territorios disponibles:" << "\n";
        for (Territorio it: this->getTerritoriosJugador()) {
            cout << it.getNombreTerritorio() << " : " << it.getUnidadesDeEjercitoTerritorio() << "unidades" << "\n";
        }

        cin.ignore();
        do {
            cout << "selecciona desde donde quieres mover unidades" << "\n";
            getline(cin, territorio_obtener);
            for (auto it = territorios_jugador.begin(); it != territorios_jugador.end(); ++it) {
                Territorio& territorio = *it; // Utilizamos una referencia a través del iterador
                if (territorio.getNombreTerritorio() == territorio_obtener) {
                    do {
                        cout << "dime cuantas unidades de " << territorio.getUnidadesDeEjercitoTerritorio()
                             << " quieres mover" << "\n";
                        cin >> unidades_mover;

                        if (unidades_mover >= territorio.getUnidadesDeEjercitoTerritorio()) {
                            cout << "unidades no aceptadas, intenta otra vez" << "\n";
                            Valido = false;
                        } else {
                            Valido = true;
                            territorio.setUnidadesDeEjercitoTerritorio(territorio.getUnidadesDeEjercitoTerritorio() - unidades_mover);
                            cout << "unidades de " << territorio.getNombreTerritorio() << " son " << territorio.getUnidadesDeEjercitoTerritorio() << "\n";
                        }
                    } while (!Valido);
                }
            }
            if (!Valido){
                cout<<"territorio no encontrado" << "\n";
            }
        } while (!Valido);
        cin.ignore();
        do {
            cout << "Seleccione territorio al que desea mover unidades" << "\n";
            getline(cin, territorio_poner);

            //verificamos que tenemos ese territorio //
            for (Territorio territorio: territorios_jugador) {
                if (territorio.getNombreTerritorio() == territorio_poner) {
                    Valido2 = true;
                    cout << "Territorio valido"<< "\n";
                }
            }
            if (Valido2 == true) {
                cout << "revisando si es adyacente "<< "\n";
                for (Territorio territorio: territorios_jugador) {
                    if (territorio.getNombreTerritorio() == territorio_obtener) {
                        for (string adyacente: territorio.getTerritoriosAlrededor()) {
                            if (adyacente == territorio_poner) {
                                for (Territorio &territorio: territorios_jugador) {
                                    if (territorio_poner == territorio.getNombreTerritorio()) {
                                        territorio.setUnidadesDeEjercitoTerritorio(territorio.getUnidadesDeEjercitoTerritorio() + unidades_mover);
                                        cout<<"territorio adyacente"<< "\n";
                                        Valido3 = true;
                                        return;
                                    }
                                }
                            }
                        }
                    }
                }
            }
            if (!Valido2){
                cout<<"no se encontro el territorio"<< "\n";
            }
            if(!Valido3){
                cout<<"el territorio no es adyacente"<< "\n";
            }
        } while (!Valido3);
    } else{
        cout<<"no puedes mover unidades"<< "\n";
        return;
    }

}

const string &Jugador::getNombreJugador() const {
    return nombre_jugador;
}

void Jugador::setNombreJugador(const string &nombreJugador) {
    nombre_jugador = nombreJugador;
}

const int &Jugador::getIdJugador() const {
    return id_jugador;
}

void Jugador::setIdJugador(const int &idJugador) {
    id_jugador = idJugador;
}

const string &Jugador::getColorJugador() const {
    return color_jugador;
}

void Jugador::setColorJugador(const string &colorJugador) {
    color_jugador = colorJugador;
}

const list<Tarjeta> &Jugador::getTarjetasJugador() const {
    return tarjetas_jugador;
}

void Jugador::setTarjetasJugador(const list<Tarjeta> &tarjetasJugador) {
    tarjetas_jugador = tarjetasJugador;
}

const list<Territorio> &Jugador::getTerritoriosJugador() const {
    return territorios_jugador;
}

void Jugador::setTerritoriosJugador( list<Territorio> &territoriosJugador) {
    territorios_jugador = territoriosJugador;
}
