#include "cColectivo.h"

unsigned long int cColectivo::CantidadDeColectivos = 0;

cColectivo::cColectivo() {
	this->CantidadDeColectivos++;
	this->IDColectivo = "";
	this->EstadoOperaativo = true;
	this->SistemaDePagos = new cSistemaDePagos();
	this->ListaPasajeros = new cListaPasajeros(50, false);
}

cColectivo::cColectivo(string IDColectivo,cRecorrido*RecorridoAsignado) {
	this->CantidadDeColectivos++;
	this->IDColectivo = IDColectivo;
	this->EstadoOperaativo = true;
	this->SistemaDePagos = new cSistemaDePagos();
	this->ListaPasajeros = new cListaPasajeros(50, false);
	this->Recorrido = RecorridoAsignado;
}

cColectivo::~cColectivo() {
	delete SistemaDePagos;
	delete ListaPasajeros;
}

cPasajero* cColectivo::BajarPasajeros(string NombreParadaActual) {
	//return pasajero
	return NULL;
}

bool cColectivo::SubirPasajeros(cPasajero* Pasajero) {

	bool EstadoPasajero = SistemaDePagos->GenerarViaje("ParadaActual", Pasajero->GetDestino(), Recorrido->CantidadDeParadasEntreDestinos("ParadaActual", Pasajero->GetDestino()), Pasajero->GetTarjetaPasajero());
	if (EstadoPasajero == true) {
		//agregar pasajero a la lista
		*(ListaPasajeros) + Pasajero;
		//pasajero sube al colectivo
		return true;
	}
	else {
		//pasajero no cumple con el saldo requerido
		//no sube al colectivo
		return false;
	}
}

void cColectivo::Averia() {
	this->EstadoOperaativo = false;
}

string cColectivo::GetIDColectivo() const {
	return IDColectivo;
}

bool cColectivo::GetEstadoOperativo() const {
	return EstadoOperaativo;
}

void cColectivo::SetNuevoRecorrido(cRecorrido* NuevoRecorrido) {
	this->Recorrido = NuevoRecorrido;
}

void cColectivo::operator+(cPasajero* Pasajero) {
	SubirPasajeros(Pasajero);
}

cPasajero* cColectivo::operator-(cPasajero* Pasajero) {
	return BajarPasajeros(Pasajero->GetDestino());

}

string cColectivo::ToStringColectivo() {
	return "ID Colectivo" + IDColectivo;
}

bool cColectivo::operator==(const cColectivo& OtroColectivo) {
	if (IDColectivo == OtroColectivo.GetIDColectivo()) {
		return true;
	}
	else
		return false;
}