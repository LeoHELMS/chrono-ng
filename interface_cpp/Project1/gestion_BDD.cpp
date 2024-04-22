#include "gestion_BDD.h"
#include "liaisons.h"

GestionBDD::GestionBDD() {
	this->connexionSQL = gcnew MySqlConnection();
	this->commandeSQL = gcnew MySqlCommand();
	try{
		this->connexionSQL->ConnectionString = "datasource = Localhost; port=3307; username=root; password=root; database=projet_chrono_ng";
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
	DataTable^ chargeurTableau = gcnew DataTable();
	MySqlDataReader^ executeurSQL;
	this->commandeSQL->CommandText = "SELECT * FROM " + this->valeurBDD;
	executeurSQL = this->commandeSQL->ExecuteReader();
	chargeurTableau->Load(executeurSQL);
	executeurSQL->Close();



	if (this->valeurBDD == "coureur") {
		this->commandeSQL->CommandText = "select * from " + this->valeurBDD;
	}



	if (this->valeurBDD == "coureur") {
		this->commandeSQL->CommandText = "UPDATE coureur SET nomCoureur = '" + valeurs[1] + "', prenomCoureur = '" + valeurs[2] +
			"', sexeCoureur = '" + valeurs[3] + "', date_naissance = '" + valeurs[4] + "' WHERE idCoureur = '" + valeurs[0] + "'";
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