#pragma once
#include <iostream>
#include <vector>
#include "gestion_BDD.h"
#include "liaisons.h"

using namespace System;
using namespace System::ComponentModel;
using namespace System::Collections;
using namespace System::Windows::Forms;
using namespace System::Data;
using namespace System::Drawing;
using namespace MySql::Data::MySqlClient;

/// <summary>
/// Description résumée de MyForm
/// </summary>
public ref class MyForm : public System::Windows::Forms::Form
{
private: 
	GestionBDD^ gererLaBDD;
	Liaisons^ liaisons;
	String^ valeurBDD;
	MySqlConnection^ connexionSQL;
	MySqlCommand^ commandeSQL;
	DataTable^ chargeurTableau;
	MySqlDataAdapter^ sqlData;
	MySqlDataReader^ executeurSQL;

private: System::Windows::Forms::Button^  save_and_reload;
private: System::Windows::Forms::Button^  quit;


private: System::Windows::Forms::Button^  gerer_coureurs;
private: System::Windows::Forms::Button^  gerer_courses;
private: System::Windows::Forms::DataGridViewButtonColumn^  liaisonDeliaison;
private: System::Windows::Forms::ComboBox^  comboBox1;

private: System::Windows::Forms::Button^  associer_coureurs_courses;


public:
	MyForm(void) {
		InitializeComponent();
		gererLaBDD = gcnew GestionBDD();
	}

protected:
	/// <summary>
	/// Nettoyage des ressources utilisées.
	/// </summary>
	~MyForm() {
		if (components) {
			delete components;
		}
	}
private: System::Windows::Forms::DataGridView^  dataGridView1;


protected:


private: System::ComponentModel::IContainer^  components;

private:
	/// <summary>
	/// Variable nécessaire au concepteur.
	/// </summary>

#pragma region Windows Form Designer generated code
	/// <summary>
	/// Méthode requise pour la prise en charge du concepteur - ne modifiez pas
	/// le contenu de cette méthode avec l'éditeur de code.
	/// </summary>
	void InitializeComponent(void)
	{
		this->dataGridView1 = (gcnew System::Windows::Forms::DataGridView());
		this->liaisonDeliaison = (gcnew System::Windows::Forms::DataGridViewButtonColumn());
		this->save_and_reload = (gcnew System::Windows::Forms::Button());
		this->quit = (gcnew System::Windows::Forms::Button());
		this->gerer_coureurs = (gcnew System::Windows::Forms::Button());
		this->gerer_courses = (gcnew System::Windows::Forms::Button());
		this->associer_coureurs_courses = (gcnew System::Windows::Forms::Button());
		this->comboBox1 = (gcnew System::Windows::Forms::ComboBox());
		(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView1))->BeginInit();
		this->SuspendLayout();

#pragma region datagridview
		// 
		// dataGridView1
		//
		this->dataGridView1->AllowDrop = true;
		this->dataGridView1->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
		this->dataGridView1->Columns->AddRange(gcnew cli::array< System::Windows::Forms::DataGridViewColumn^  >(1) { this->liaisonDeliaison });
		this->dataGridView1->ImeMode = System::Windows::Forms::ImeMode::NoControl;
		this->dataGridView1->Location = System::Drawing::Point(26, 145);
		this->dataGridView1->Name = L"dataGridView1";
		this->dataGridView1->Size = System::Drawing::Size(814, 324);
		this->dataGridView1->TabIndex = 0;
		this->dataGridView1->Visible = false;
		this->dataGridView1->CellContentClick += gcnew System::Windows::Forms::DataGridViewCellEventHandler(this, &MyForm::dataGridView1_CellContentClick);
#pragma endregion datagridview
#pragma region liaisondeliaison
		// 
		// liaisonDeliaison
		//
		this->liaisonDeliaison->HeaderText = L"Liaison / Déliaison";
		this->liaisonDeliaison->Name = L"liaisonDeliaison";
		this->liaisonDeliaison->ReadOnly = true;
		this->liaisonDeliaison->Visible = false;
#pragma endregion liaisondeliaison
#pragma region sauvegarde
		// 
		// save_and_reload
		//
		this->save_and_reload->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(192)),
			static_cast<System::Int32>(static_cast<System::Byte>(0)));
		this->save_and_reload->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
		this->save_and_reload->Font = (gcnew System::Drawing::Font(L"Georgia", 9.25F, System::Drawing::FontStyle::Bold));
		this->save_and_reload->Location = System::Drawing::Point(614, 27);
		this->save_and_reload->Name = L"save_and_reload";
		this->save_and_reload->Size = System::Drawing::Size(124, 32);
		this->save_and_reload->TabIndex = 3;
		this->save_and_reload->Text = L"sauvegarder";
		this->save_and_reload->UseVisualStyleBackColor = true;
		this->save_and_reload->Visible = false;
		this->save_and_reload->Click += gcnew System::EventHandler(this, &MyForm::save_and_reload_Click);
#pragma endregion sauvegarde
#pragma region quit
		// 
		// quit
		//
		this->quit->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(210)), static_cast<System::Int32>(static_cast<System::Byte>(30)),
			static_cast<System::Int32>(static_cast<System::Byte>(30)));
		this->quit->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
		this->quit->Font = (gcnew System::Drawing::Font(L"Georgia", 9.25F, System::Drawing::FontStyle::Bold));
		this->quit->ForeColor = System::Drawing::SystemColors::Menu;
		this->quit->Location = System::Drawing::Point(756, 27);
		this->quit->Name = L"quit";
		this->quit->Size = System::Drawing::Size(84, 32);
		this->quit->TabIndex = 4;
		this->quit->Text = L"quitter";
		this->quit->UseVisualStyleBackColor = false;
		this->quit->Click += gcnew System::EventHandler(this, &MyForm::quit_Click);
#pragma endregion quit
#pragma region gestion coureurs
		// 
		// gerer_coureurs
		// 
		this->gerer_coureurs->Font = (gcnew System::Drawing::Font(L"Georgia", 9.25F, System::Drawing::FontStyle::Bold));
		this->gerer_coureurs->Location = System::Drawing::Point(473, 91);
		this->gerer_coureurs->Name = L"gerer_coureurs";
		this->gerer_coureurs->Size = System::Drawing::Size(169, 32);
		this->gerer_coureurs->TabIndex = 6;
		this->gerer_coureurs->Text = L"gérer les coureurs";
		this->gerer_coureurs->UseVisualStyleBackColor = true;
		this->gerer_coureurs->Click += gcnew System::EventHandler(this, &MyForm::gerer_coureurs_Click);
#pragma endregion gestion coureurs
#pragma region gestion courses
		// 
		// gerer_courses
		// 
		this->gerer_courses->Font = (gcnew System::Drawing::Font(L"Georgia", 9.25F, System::Drawing::FontStyle::Bold));
		this->gerer_courses->Location = System::Drawing::Point(671, 91);
		this->gerer_courses->Name = L"gerer_courses";
		this->gerer_courses->Size = System::Drawing::Size(169, 32);
		this->gerer_courses->TabIndex = 7;
		this->gerer_courses->Text = L"gérer les courses";
		this->gerer_courses->UseVisualStyleBackColor = true;
		this->gerer_courses->Click += gcnew System::EventHandler(this, &MyForm::gerer_courses_Click);
#pragma endregion gestion courses
#pragma region associer coureurs courses
		// 
		// associer_coureurs_courses
		// 
		this->associer_coureurs_courses->Font = (gcnew System::Drawing::Font(L"Georgia", 9.25F, System::Drawing::FontStyle::Bold));
		this->associer_coureurs_courses->Location = System::Drawing::Point(26, 27);
		this->associer_coureurs_courses->Name = L"associer_coureurs_courses";
		this->associer_coureurs_courses->Size = System::Drawing::Size(192, 32);
		this->associer_coureurs_courses->TabIndex = 0;
		this->associer_coureurs_courses->Text = L"associer des coureurs";
		this->associer_coureurs_courses->UseVisualStyleBackColor = true;
		this->associer_coureurs_courses->Click += gcnew System::EventHandler(this, &MyForm::associer_coureurs_courses_Click);
#pragma endregion associer coureurs courses
#pragma region selection coureurs
		// 
		// selection_coureurs
		// 
		this->comboBox1->FormattingEnabled = true;
		this->comboBox1->Location = System::Drawing::Point(26, 102);
		this->comboBox1->Name = L"selection_coureurs";
		this->comboBox1->Size = System::Drawing::Size(144, 21);
		this->comboBox1->TabIndex = 8;
		this->comboBox1->SelectedIndexChanged += gcnew System::EventHandler(this, &MyForm::comboBox1_SelectedIndexChanged);
#pragma endregion selection coureurs
#pragma region myform
		// 
		// MyForm
		// 
		this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
		this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
		this->AutoScroll = true;
		this->BackColor = System::Drawing::SystemColors::ScrollBar;
		this->BackgroundImageLayout = System::Windows::Forms::ImageLayout::None;
		this->ClientSize = System::Drawing::Size(872, 500);
		this->ControlBox = false;
		this->Controls->Add(this->comboBox1);
		this->Controls->Add(this->associer_coureurs_courses);
		this->Controls->Add(this->gerer_courses);
		this->Controls->Add(this->gerer_coureurs);
		this->Controls->Add(this->quit);
		this->Controls->Add(this->save_and_reload);
		this->Controls->Add(this->dataGridView1);
		this->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F));
		this->ForeColor = System::Drawing::SystemColors::MenuText;
		this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedDialog;
		this->ImeMode = System::Windows::Forms::ImeMode::Off;
		this->Name = L"MyForm";
		this->ShowIcon = false;
		this->Text = L"phase d\'inscription";
		this->Load += gcnew System::EventHandler(this, &MyForm::MyForm_Load);
		(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView1))->EndInit();
		this->ResumeLayout(false);
#pragma endregion myform
	}
#pragma endregion

	private: System::Void MyForm_Load(System::Object^  sender, System::EventArgs^  e) {
		this->dataGridView1->Location = System::Drawing::Point(26, 200);
		this->dataGridView1->Size = System::Drawing::Size(814, 250);
	}

	private: System::Void save_and_reload_Click(System::Object^  sender, System::EventArgs^  e) {
		this->sauvegardeBDD();
		this->dataGridView1->DataSource = gererLaBDD->chargementBDD(); 
	}

	private: System::Void quit_Click(System::Object^  sender, System::EventArgs^  e) {
		if (!(gererLaBDD->valeurBDD->Empty)) {
			this->sauvegardeBDD();
			gererLaBDD->connexionSQL->Close();
		}
		this->Close();
	}



	private: System::Void associer_coureurs_courses_Click(System::Object^  sender, System::EventArgs^  e) {
		affichage("assoc");
	}

	private: System::Void gerer_coureurs_Click(System::Object^  sender, System::EventArgs^  e) {
		affichage("coureur");	
	}
	private: System::Void gerer_courses_Click(System::Object^  sender, System::EventArgs^  e) {
		affichage("course");
	}


	private: void affichage(String^ valeurBDD) {
		gererLaBDD->valeurBDD = valeurBDD;
		this->dataGridView1->Show();
		if (valeurBDD == "assoc") {
			this->dataGridView1->ReadOnly = true;
			this->save_and_reload->Hide();
			DataTable^ valeurs = gererLaBDD->chargementBDD();
			this->dataGridView1->DataSource = valeurs;
			for each(DataRow^ test in valeurs->Rows) {
				this->dataGridView1->Rows[1]->Cells[0]->Value = liaisons->verificationLiaison(test["id"], ) == 1 ? "lier" : "delier";
				//this->selection_coureurs
			}
			return;
		}
		dataGridView1->ReadOnly = false;
		this->dataGridView1->DataSource = gererLaBDD->chargementBDD();
		this->liaisonDeliaison->DisplayIndex = 5;
		this->save_and_reload->Show();
		this->liaisonDeliaison->Visible = false;
		this->liaisonDeliaison->DisplayIndex = 3;
		this->liaisonDeliaison->Visible = true;
	}

	private: void sauvegardeBDD() {
		for (int i = 0; i < this->dataGridView1->RowCount - 1; i++) {
			array<String^> ^valeurs = {"", "", "", "", ""};
			for (int j = 1; j < 5; j++) {
				valeurs[j] = getData(i, j);
			}
			String^ date = getData(i, 5);
			valeurs[4] = date[6].ToString() + date[7] + date[8] + date[9] + date[5] + date[3] + date[4] + date[2] + date[0] + date[1];
			gererLaBDD->sauvegardeBDD(valeurs);
		}
	}

	private: String^ getData(int i, int j) {
		return this->dataGridView1->Rows[i]->Cells[j]->Value->ToString();
	}

	private: System::Void dataGridView1_CellContentClick(System::Object^  sender, System::Windows::Forms::DataGridViewCellEventArgs^  e) {
		if (e->RowIndex == 3) {
			if (dataGridView1->Rows[e->RowIndex]->Cells[e->ColumnIndex]->Value == "lier") {
				liaisons->liaisonCoureurCourse(dataGridView1->Rows[0]->Cells[e->ColumnIndex]->Value->ToString(), "2");
			} else {
				liaisons->deliaisonCoureurCourse(dataGridView1->Rows[0]->Cells[e->ColumnIndex]->Value->ToString(), "");
			}
		}
	}

	private: System::Void comboBox1_SelectedIndexChanged(System::Object^  sender, System::EventArgs^  e) {
	}
};