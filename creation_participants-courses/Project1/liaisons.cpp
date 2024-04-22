#include "liaisons.h"

void Liaisons::liaisonCoureurCourse(String^ idCourse, String^ idCoureur)
{
	creation_liaison(idCourse, idCoureur, "chrono");
	creation_liaison(idCourse, idCoureur, "dossard");
}

void Liaisons::deliaisonCoureurCourse(String^ idCourse, String^ idCoureur)
{
	suppression_liaison(idCourse, idCoureur, "chrono");
	suppression_liaison(idCourse, idCoureur, "dossard");
}

void Liaisons::creation_liaison(String^ idCourse, String^ idCoureur, String^ selection) {
	this->commandeSQL->CommandText = "INSERT INTO " + selection + " ('idCourse', 'idCoureur') VALUES ('" + idCourse + "','" + idCoureur + "')";
}

void Liaisons::suppression_liaison(String^ idCourse, String^ idCoureur, String^ selection) {
	this->commandeSQL->CommandText = "DELETE " + selection + " WHERE idCourse = '" + idCourse + " AND idCoureur = '" + idCoureur + "'";
}

bool Liaisons::verificationLiaison(String^ idCoureur, String^ idCourse, String^ selection) {
	this->commandeSQL->CommandText = "SELECT * FROM " + selection + " WHERE idCoureur = '" + idCoureur + "' AND idCourse = '" + idCourse + "'";
	if (this->commandeSQL->ExecuteReader()) {
		return true;
	}
	return false;
}