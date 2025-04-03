#include "gestion_BDD.h"

GestionBDD::GestionBDD() {
	this->connexionSQL = gcnew MySqlConnection();
	this->commandeSQL = gcnew MySqlCommand();
	try{
		this->connexionSQL->ConnectionString = "datasource = Localhost; port=3306; username=root; password=root; database=chrono_ng";
		this->connexionSQL->Open();
		this->commandeSQL->Connection = this->connexionSQL;
	} catch (Exception^ e) {
		MessageBox::Show("erreur : " + e);
	}
	this->valeurBDD = "";
}

Data::DataTable^ GestionBDD::chargementBDD() {
	DataTable^ chargeurTableau = gcnew DataTable();
	MySqlDataReader^ executeurSQL;
	if (valeurBDD != "assoc") {
		this->commandeSQL->CommandText = "SELECT * FROM " + this->valeurBDD;
	} else {
		commandeSQL->CommandText = "SELECT idCoureur AS id, nomCoureur AS nom, prenomCoureur AS prenom FROM coureur";
	}
	executeurSQL = commandeSQL->ExecuteReader();
	chargeurTableau->Load(executeurSQL);
	executeurSQL->Close();
	return chargeurTableau;
}

void GestionBDD::sauvegardeBDD(array<String^> ^valeurs) {
	MySqlDataReader^ executeurSQL;

	if (this->valeurBDD == "coureur") {
		this->commandeSQL->CommandText = "UPDATE coureur SET nomCoureur = '" + valeurs[1] + "', prenomCoureur = '" + valeurs[2] +
			"', sexeCoureur = '" + valeurs[3] + "', dateNaissance = '" + valeurs[4] + "' WHERE idCoureur = '" + valeurs[0] + "'";
	}
	else if (this->valeurBDD == "course") {
		this->commandeSQL->CommandText = "UPDATE course SET nomCourse = '" + valeurs[1] + "', lieuCourse = '" + valeurs[2] +
			"', distanceCourse = '" + valeurs[3] + "', dateCourse = '" + valeurs[4] + "' WHERE idCourse = '" + valeurs[0] + "'";
	}
	else {
		MessageBox::Show("erreur durant la sauvegarde de la BDD");
	}
	executeurSQL = this->commandeSQL->ExecuteReader();
	executeurSQL->Close();
}

DataTable^ GestionBDD::chargerListeCoureur()
{
	DataTable^ chargeurTableau = gcnew DataTable();
	MySqlDataReader^ executeurSQL;
	commandeSQL->CommandText = "SELECT idCoureur, nomCoureur FROM coureur";
	executeurSQL = commandeSQL->ExecuteReader();
	chargeurTableau->Load(executeurSQL);
	executeurSQL->Close();
	return chargeurTableau;
}

void GestionBDD::creation_liaison(String^ idCoureur, String^ idCourse) {
	array<String^>^ selection = { "dossard", "chrono" };
	for (int i = 0; i < 2; i++) {
		commandeSQL->CommandText = "INSERT INTO " + selection[i]->ToString() + " (idCourse, idCoureur) VALUES ('" + idCourse + "','" + idCoureur + "')";
		this->commandeSQL->ExecuteNonQuery();
	}
}

void GestionBDD::suppression_liaison(String^ idCoureur, String^ idCourse) {
	array<String^>^ selection = { "dossard", "chrono" };
	for (int i = 0; i < 2; i++) {
		commandeSQL->CommandText = "DELETE FROM " + selection[i]->ToString() + " WHERE idCourse = '" + idCourse + "' AND idCoureur = '" + idCoureur + "'";
		this->commandeSQL->ExecuteNonQuery();
	}
}

String^ GestionBDD::verificationLiaison(int^ idCoureur, int^ idCourse) {
	array<String^>^ selection = { "dossard", "chrono" };
	for (int i = 0; i < 2; i++) {
		MySqlDataReader^ executeurSQL;
		DataTable^ chargeurTableau = gcnew DataTable();
		commandeSQL->CommandText = "SELECT * FROM " + selection[i] + " WHERE idCoureur = '" + idCoureur->ToString() + "' AND idCourse = '" + idCourse->ToString() + "'";
		executeurSQL = commandeSQL->ExecuteReader();
		chargeurTableau->Load(executeurSQL);
		try {
			DataRow^ ligne = chargeurTableau->Rows[0];
		} catch(Exception^ e) {
			return "Lier";
		}
	}
	return "Delier";
}