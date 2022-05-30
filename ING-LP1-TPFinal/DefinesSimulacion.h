#pragma once
#include <iostream>
#include <string>

#include"cListaColectivos.h"

#include"cColectivoAcordeon.h"
#include"cColectivoAutonomo.h"
#include"cColectivoSinAire.h"

using namespace std;

const unsigned int CantidadTotalParadas = 28;

const string CodigoRecorridos[] = { "A","B","C" };

const string NombreRecorridos[] = { 
	"Barracas - San Idrio",
	"Barracas de Belgrano - Rincon de Milberg",
	"Barracas de Belgrano - Estacion Terminal de Omnibus de Escobar"
};

const float TotalKilometrosRecorrido[] = { 31, (float) 27.2, (float) 49.7 };

const unsigned int CantidadTotalParadasRecorridoA = 12;

const unsigned int ParadasRecorridoA[] = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11 };

const unsigned int CantidadTotalParadasRecorridoB = 11;

const unsigned int ParadasRecorridoB[] = { 5, 6, 12, 13, 14, 15, 16, 17, 18, 19, 20 };

const unsigned int CantidadTotalParadasRecorridoC = 16;

const unsigned int ParadasRecorridoC[] = { 5, 6, 12, 13, 14, 15, 16, 17, 18, 21, 22, 23, 24, 25, 26, 27 };

const string ParadasDireccion[] = { 
	"Pedro de Lujan y Santa Maria del Buen Aire",
	"Av. Suarez y Gral Hornos",
	"Pte. Suarez y Av Hipolito Yrigoyen",
	"Junin y Av Las Heras",
	"Aav Santa Fe y Godoy Cruz",
	"Virrey Vertriz y Sucre",
	"Av Cabildo y Av Congreso",
	"Est. Transferencia Vicente Lopez",
	"Estacion Bartolome Mitre",
	"Av Santa Fe y Gral Alvear",
	"Av Centenario y Gral M.Belgrano",
	"Primera Junta y Av Tiscornia",
	"Av Cabildo y Av Gral Paz",
	"Au Panamericana y Laprida",
	"Au Panamericana y Manuel Ugarte",
	"Au Panamericana y Tomas Edison",
	"Au Panamericana y Av Marquez",
	"Au Panamericana y Uruguay",
	"Acceso Norte y Ruta Nacional 197",
	"Liniers y Santa Maria de las Conchas",
	"Ruta Provincial 27 y Ugarte",
	"Liniers y Ruta Provincial 24",
	"Ruta Provincial 24 y Boulogne Sur Mer",
	"Constituyrntes y Cervantes",
	"Barrio Mutual",
	"Av Gral J.D Peron y Av Benavidez",
	"Au Panamericana y VillaNueva",
	"Terminal Escobar"
};

#pragma region Inicializacion de los recorridos y paradas

	/// <summary>
	/// Genera paradas y las agrega a la Lista Global Paradas 
	/// </summary>
	/// <param name="ListaGlobalParadas"></param>
void GenerarParadas(cListaParadas* ListaGlobalParadas);

	/// <summary>
	/// Agrega las Paradas a los recorridos
	/// </summary>
	/// <param name="RecorridoA"></param>
	/// <param name="RecorridoB"></param>
	/// <param name="RecorridoC"></param>
	/// <param name="ListaGlobalParadas"></param>
void AgregarParadasRecorrido(cRecorrido* RecorridoA, cRecorrido* RecorridoB, cRecorrido* RecorridoC, cListaParadas* ListaGlobalPardas);

#pragma endregion

#pragma region Inicializacion de los Colectivos

	/// <summary>
	/// Genera colectivos y los agrega a la lista global de colectivos
	/// </summary>
	/// <param name="RecorridoA"></param>
void GenerarColectivos(cListaColectivos* ListaGlobalColectivos);

#pragma endregion

#pragma region Simulacion

	/// <summary>
	/// Actualizacion de objetos
	/// </summary>
	/// <param name="ListaGlobalColectivos"></param>
	/// <param name="ListaGlobalPardas"></param>
void ActualizarObjetos(cListaColectivos* ListaGlobalColectivos, cListaParadas* ListaGlobalParadas);

	/// <summary>
	/// Actualiza todos los colectivos (avanzan en su recorrido)
	/// </summary>
	/// <param name="ListaGlobalColectivos"></param>
void ActualizarColectivos(cListaColectivos* ListaGlobalColectivos);

	/// <summary>
	/// Actualiza todos los paradas (agrega nuevas personas a las mismas)
	/// </summary>
	/// <param name="ListaGlobalPardas"></param>
void ActualizarParadas(cListaParadas* ListaGlobalParadas);

	/// <summary>
	/// Actualiza los GPS de todos los colectivos
	/// </summary>
	/// <param name="ListaGlobalColectivos"></param>
void ActualizarColectivosGPS(cListaColectivos* ListaGlobalColectivos);

#pragma endregion