#pragma once

using namespace System;
using namespace System::ComponentModel;
using namespace System::Collections;
using namespace System::Windows::Forms;
using namespace System::Data;
using namespace System::Drawing;
using namespace MySql::Data::MySqlClient;

ref class GestionBDD {
	MySqlCommand^ commandeSQL;

public:
	String^ valeurBDD;
	MySqlConnection^ connexionSQL;

	GestionBDD();
	Data::DataTable^ chargementBDD();
	void sauvegardeBDD(array<String^> ^valeurs);
	DataTable^ chargerListeCoureur();
	void creation_liaison(      String^ idCourse, String^ idCoureur);
	void suppression_liaison(   String^ idCourse, String^ idCoureur);
	String^ verificationLiaison(int^    idCourse, int^    idCoureur);

	//Renommer GestionBDD, ajouter gestionLiaison, gestionCoureur et gestionCourse
};