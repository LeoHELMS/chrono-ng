#pragma once
using namespace System;
using namespace System::ComponentModel;
using namespace System::Collections;
using namespace System::Windows::Forms;
using namespace System::Data;
using namespace System::Drawing;
using namespace MySql::Data::MySqlClient;

ref class Liaisons {
	MySqlCommand^ commandeSQL;
public:
	void liaisonCoureurCourse(String^ idCourse, String^ idCoureur);
	void deliaisonCoureurCourse(String^ idCourse, String^ idCoureur);
	bool verificationLiaison(String^ idCoureur, String^ idCourse, String^ selection);

private:
	void creation_liaison(String^ idCourse, String^ idCoureur, String ^ selection);
	void suppression_liaison(String^ idCourse, String^ idCoureur, String ^ selection);
};

