#include "../Estructura/jugador.h"
#include "../Estructura/continente.h"
#include "../Estructura/tarjeta.h"
#include "../Estructura/territorio.h"
#include <iostream>
#include <list>
#include <fstream>

using namespace std;
void Guardar(const Jugador &jugador, const list<Continente> &continentes, const list<Territorio> &territorios, const list<Tarjeta> &tarjetasGlobales);

int main() {

    // Crear una lista de continentes
    list<Continente> continentes;

    Continente americaDelNorte(1, "América del Norte", 9);
    Continente europa(2, "Europa", 7);

    continentes.push_back(americaDelNorte);
    continentes.push_back(europa);

    list<Territorio> territorios;

    Territorio alaska(1,1, "Alaska", 1);
    Territorio alberta(2,2, "Alberta", 1);
    Territorio americaCen(3,3, "América Central", 1);
    Territorio estadosUnidosOri(4,4, "Estados Unidos Orientales", 1);
    Territorio groenlandia(5,5, "Groenlandia", 1);
    Territorio territorioNoroc(6,6, "Territorio Noroccidental", 1);
    Territorio ontario(7,7, "Ontario", 1);
    Territorio quebec(8,8, "Quebec", 1);
    Territorio estadosUnidosOc(9,9, "Estados Unidos Occidentales", 1);

    // Continente: Europa

    Territorio granBretana(10,1, "Gran Bretaña", 2);
    Territorio islandia(11,2, "Islandia", 2);
    Territorio europaDelNorte(12,3, "Europa del Norte", 2);
    Territorio escandinavia(13,4, "Escandinavia", 2);
    Territorio europaDelSur(14,5, "Europa del Sur", 2);
    Territorio ucrania(15,6, "Ucrania", 2);
    Territorio europaOc(16,7, "Europa Occidental", 2);

    list<string> TAalaska = {"Territorio Noroccidental","Alberta","Kamchatka"};
    list<string> TAalberta = {"Territorio Noroccidental", "Ontario"};
    list<string> TAamericaC = {"Estados Unidos Occidentales", "Estados Unidos Orientales","Venezuela"};
    list<string> TAestadosUOr = {"América Central", "Estados Unidos Occidentales","Ontario","Quebec"};
    list<string> TAgroenlandia = {"Territorio Noroccidental","Ontario","Quebec","Islandia"};
    list<string> TAteritorioNO = {"Alaska","Alberta","Ontario","Groenlandia"};
    list<string> TAontario = {"Territorio Noroccidental","Alberta","Estados Unidos Occidentales","Estados Unidos Orientales","Quebec","Groenlandia"};
    list<string> TAquebec = {"Ontario","Estados Unidos Orientales","Groenlandia"};
    list<string> TAestadosUOc = {"Alberta","Ontario","Estados Unidos Orientales","América Central"};

    list<string> TAgranB ={"Islandia","Europa del Norte","Escandinavia","Europa Occidental"};
    list<string> TAislandia ={"Gran Bretaña","Escandinavia","Groenlandia"};
    list<string> TAeuropaN ={"Gran Bretaña","Escandinavia","Europa del Sur","Ucrania","Europa Occidental"};
    list<string> TAescandinavia ={"Gran Bretaña","Islandia","Europa del Norte","Ucrania"};
    list<string> TAeuropaS ={"Europa del Norte","Ucrania", "Europa Occidental","Medio Oriente","Egipto","África del Norte"};
    list<string> TAucrania ={"Europa del Norte", "Escandinavia","Europa del Sur","Afghanistán","Medio Oriente","Ural"};
    list<string> TAeuropaOc ={"Gran Bretaña", "Europa del Norte","Europa del Sur","África del Norte"};

    //territorio Norte Americano//
    alaska.setUnidadesDeEjercitoTerritorio(10);
    alaska.setTerritoriosAlrededor(TAalaska);

    alberta.setUnidadesDeEjercitoTerritorio(10);
    alberta.setTerritoriosAlrededor(TAalberta);

    americaCen.setUnidadesDeEjercitoTerritorio(10);
    americaCen.setTerritoriosAlrededor(TAamericaC);

    estadosUnidosOri.setUnidadesDeEjercitoTerritorio(10);
    estadosUnidosOri.setTerritoriosAlrededor(TAestadosUOr);

    groenlandia.setUnidadesDeEjercitoTerritorio(10);
    groenlandia.setTerritoriosAlrededor(TAgroenlandia);

    territorioNoroc.setUnidadesDeEjercitoTerritorio(10);
    territorioNoroc.setTerritoriosAlrededor(TAteritorioNO);

    ontario.setUnidadesDeEjercitoTerritorio(10);
    ontario.setTerritoriosAlrededor(TAontario);

    quebec.setUnidadesDeEjercitoTerritorio(10);
    quebec.setTerritoriosAlrededor(TAquebec);

    estadosUnidosOc.setUnidadesDeEjercitoTerritorio(10);
    estadosUnidosOc.setTerritoriosAlrededor(TAestadosUOc);

// Territorios de Europa
    granBretana.setUnidadesDeEjercitoTerritorio(10);
    granBretana.setTerritoriosAlrededor(TAgranB);

    islandia.setUnidadesDeEjercitoTerritorio(10);
    islandia.setTerritoriosAlrededor(TAislandia);

    europaDelNorte.setUnidadesDeEjercitoTerritorio(10);
    europaDelNorte.setTerritoriosAlrededor(TAeuropaN);

    escandinavia.setUnidadesDeEjercitoTerritorio(10);
    escandinavia.setTerritoriosAlrededor(TAescandinavia);

    europaDelSur.setUnidadesDeEjercitoTerritorio(10);
    europaDelSur.setTerritoriosAlrededor(TAeuropaS);

    ucrania.setUnidadesDeEjercitoTerritorio(10);
    ucrania.setTerritoriosAlrededor(TAucrania);

    europaOc.setUnidadesDeEjercitoTerritorio(10);
    europaOc.setTerritoriosAlrededor(TAeuropaOc);

    territorios.push_back(alaska);
    territorios.push_back(alberta);
    territorios.push_back(americaCen);
    territorios.push_back(estadosUnidosOri);
    territorios.push_back(groenlandia);
    territorios.push_back(territorioNoroc);
    territorios.push_back(ontario);
    territorios.push_back(quebec);
    territorios.push_back(estadosUnidosOc);
    territorios.push_back(granBretana);
    territorios.push_back(islandia);
    territorios.push_back(europaDelNorte);
    territorios.push_back(escandinavia);
    territorios.push_back(europaDelSur);
    territorios.push_back(ucrania);
    territorios.push_back(europaOc);

    // Crear una lista de tarjetas (debes definir esta lista según tu implementación)
    list<Tarjeta> lista_tarjetas;

    // América del Norte
    Tarjeta tarjeta1(1,"TR",27, "Soldier");
    Tarjeta tarjeta2(2, "TR", 1, "Canon");
    Tarjeta tarjeta3(3, "TR", 2, "Canon");
    Tarjeta tarjeta4(4, "TR", 10, "Soldier");
    Tarjeta tarjeta5(5, "TR", 11, "Soldier");
    Tarjeta tarjeta6(6, "TR", 9, "Soldier");
    Tarjeta tarjeta7(7, "TR", 28, "Canon");
    Tarjeta tarjeta8(8, "TR", 24, "Canon");
    Tarjeta tarjeta9(9, "TR", 23, "Soldier");
    Tarjeta tarjeta10(10, "TR", 40, "Horse");
    Tarjeta tarjeta11(11, "TR", 4, "Canon");
    Tarjeta tarjeta12(12, "TR", 25, "Horse");
    Tarjeta tarjeta13(13, "TR", 18, "Soldier");
    Tarjeta tarjeta14(14, "TR", 5, "Horse");
    Tarjeta tarjeta15(15, "TR", 19, "Horse");
    Tarjeta tarjeta16(16, "TR", 29, "Horse");

    lista_tarjetas.push_back(tarjeta1);
    lista_tarjetas.push_back(tarjeta2);
    lista_tarjetas.push_back(tarjeta3);
    lista_tarjetas.push_back(tarjeta4);
    lista_tarjetas.push_back(tarjeta5);
    lista_tarjetas.push_back(tarjeta6);
    lista_tarjetas.push_back(tarjeta7);
    lista_tarjetas.push_back(tarjeta8);
    lista_tarjetas.push_back(tarjeta9);
    lista_tarjetas.push_back(tarjeta10);
    lista_tarjetas.push_back(tarjeta11);
    lista_tarjetas.push_back(tarjeta12);
    lista_tarjetas.push_back(tarjeta13);
    lista_tarjetas.push_back(tarjeta14);
    lista_tarjetas.push_back(tarjeta15);
    lista_tarjetas.push_back(tarjeta16);

    int tarjetas_global = 2 ;

    list<Territorio> territorios_jugador;
    territorios_jugador.push_back(alaska);
    territorios_jugador.push_back(alberta);
    territorios_jugador.push_back(americaCen);
    territorios_jugador.push_back(estadosUnidosOri);
    territorios_jugador.push_back(groenlandia);
    territorios_jugador.push_back(territorioNoroc);
    territorios_jugador.push_back(ontario);
    territorios_jugador.push_back(quebec);
    territorios_jugador.push_back(estadosUnidosOc);
    territorios_jugador.push_back(granBretana);
    territorios_jugador.push_back(islandia);
    territorios_jugador.push_back(europaDelNorte);
    territorios_jugador.push_back(escandinavia);

    list<Tarjeta> tarjetas_jugador;

    tarjetas_jugador.push_back(tarjeta1);
    tarjetas_jugador.push_back(tarjeta2);
    tarjetas_jugador.push_back(tarjeta3);
    tarjetas_jugador.push_back(tarjeta4);
    tarjetas_jugador.push_back(tarjeta5);

    // Crear una instancia de Jugador
    Jugador jugador("NombreDelJugador", "ColorDelJugador", 1);  // Puedes cambiar los valores según tus necesidades
    jugador.setTerritoriosJugador(territorios_jugador);
    jugador.setTarjetasJugador(tarjetas_jugador);

    cout<<"llamando funciones jugador"<<"\n";

    jugador.fortificar(continentes, tarjetas_global);
    jugador.mover();

    Guardar(jugador, continentes, territorios, lista_tarjetas);
    return 0;
}

void Guardar(const Jugador &jugador, const list<Continente> &continentes, const list<Territorio> &territorios, const list<Tarjeta> &tarjetasGlobales) {
                                        //JUGADOR//
    ofstream archivo_guardar("/home/jose/Probar/Estructuras1/Juego/partida_guardada.txt");
    if (archivo_guardar.is_open()) {
        archivo_guardar << "Nombre del jugador: " << jugador.getNombreJugador() << endl;
        archivo_guardar << "Color del jugador: " << jugador.getColorJugador() << endl;
        archivo_guardar << "ID del jugador: " << jugador.getIdJugador() << endl;

        archivo_guardar << "Territorios del jugador:" << endl;
        for (const Territorio &territorio : jugador.getTerritoriosJugador()) {
            archivo_guardar << "Nombre: " << territorio.getNombreTerritorio() << ", Unidades: " << territorio.getUnidadesDeEjercitoTerritorio() << endl;
        }

        archivo_guardar << "Tarjetas del jugador:" << endl;
        for (const Tarjeta &tarjeta : jugador.getTarjetasJugador()) {
            archivo_guardar << "ID: " << tarjeta.getIdTarjeta() << ", Tipo: " << tarjeta.getTipo() << ", Territorio: " << tarjeta.getKeyTerritorio() << endl;
        }
        archivo_guardar << "Tarjetas Global"  <<endl;

        archivo_guardar.close();
        cout << "Datos del jugador guardados exitosamente en 'partida_guardada.txt'." << endl;
    } else {
        cout << "No se pudo abrir el archivo para guardar los datos del jugador." << endl;
    }

                                            //Continentes//

    ofstream archivo_continentes("/home/jose/Probar/Estructuras1/Juego/continentes_guardados.txt");
    if (archivo_continentes.is_open()) {
        archivo_continentes << "id_continente" <<";"<<"Nombre continente" <<endl;
        for (const Continente &continente : continentes) {
            archivo_continentes << continente.getIdContienente() <<";" << continente.getNombreContinente() <<endl;
        }
        archivo_continentes.close();
        cout << "Datos de continentes guardados exitosamente en 'continentes_guardados.txt'." << endl;
    } else {
        cout << "No se pudo abrir el archivo para guardar los datos de continentes." << endl;
    }

                                            //Territorios//
    ofstream archivo_territorios("/home/jose/Probar/Estructuras1/Juego/territorios_guardados.txt");
    if (archivo_territorios.is_open()) {
        archivo_territorios << "key_territorio" << ";"<< "id_continente" << "id_territorio"<<";" <<"Descripcion"<<endl;
        for (const Territorio &territorio : territorios) {
            archivo_territorios << territorio.getKeyTerritorio() <<";" << territorio.getIdContinente() << ";" << territorio.getIdTerritorio() << ";" << territorio.getNombreTerritorio() << endl;
        }
        archivo_territorios.close();
        cout << "Datos de territorios guardados exitosamente en 'territorios_guardados.txt'." << endl;
    } else {
        cout << "No se pudo abrir el archivo para guardar los datos de territorios." << endl;
    }

                                                //Tarjetas//
    ofstream archivo_tarjetas_globales("/home/jose/Probar/Estructuras1/Juego/tarjetas_globales_guardadas.txt");
    if (archivo_tarjetas_globales.is_open()) {
        archivo_tarjetas_globales << "id_tarjeta" <<";"<<"Tipo_tarjeta"<<";"<<"Ket_territorio"<<";"<<"Figura"<< endl;
        for (const Tarjeta &tarjeta : tarjetasGlobales) {
            archivo_tarjetas_globales << tarjeta.getIdTarjeta()<<";" << tarjeta.getTipo()<<";" << tarjeta.getKeyTerritorio()<<";"<< tarjeta.getDibujo()<< endl;
        }
        archivo_tarjetas_globales.close();
        cout << "Datos de tarjetas globales guardados exitosamente en 'tarjetas_globales_guardadas.txt'." << endl;
    } else {
        cout << "No se pudo abrir el archivo para guardar los datos de tarjetas globales." << endl;
    }
}
