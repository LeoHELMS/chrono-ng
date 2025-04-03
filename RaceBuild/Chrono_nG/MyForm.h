#pragma once
#include <iostream>
#include <vector>
#include "gestion_BDD.h"

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

private: System::Windows::Forms::Button^  save_and_reload;
private: System::Windows::Forms::Button^  quit;


private: System::Windows::Forms::Button^  gerer_coureurs;
private: System::Windows::Forms::Button^  gerer_courses;
private: System::Windows::Forms::DataGridViewButtonColumn^  liaisonDeliaison;

private: System::Windows::Forms::ComboBox^  comboBox1;
private: System::Windows::Forms::Label^  label1;

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
		this->label1 = (gcnew System::Windows::Forms::Label());
		(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView1))->BeginInit();
		this->SuspendLayout();
		// 
		// dataGridView1
		// 
		this->dataGridView1->AllowDrop = true;
		this->dataGridView1->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
		this->dataGridView1->Columns->AddRange(gcnew cli::array< System::Windows::Forms::DataGridViewColumn^  >(1) { this->liaisonDeliaison });
		this->dataGridView1->ImeMode = System::Windows::Forms::ImeMode::NoControl;
		this->dataGridView1->Location = System::Drawing::Point(26, 173);
		this->dataGridView1->Name = L"dataGridView1";
		this->dataGridView1->Size = System::Drawing::Size(814, 296);
		this->dataGridView1->TabIndex = 0;
		this->dataGridView1->Visible = false;
		this->dataGridView1->CellContentClick += gcnew System::Windows::Forms::DataGridViewCellEventHandler(this, &MyForm::dataGridView1_CellContentClick);
		// 
		// liaisonDeliaison
		// 
		this->liaisonDeliaison->HeaderText = L"Liaison / Deliaison";
		this->liaisonDeliaison->Name = L"liaisonDeliaison";
		this->liaisonDeliaison->ReadOnly = true;
		this->liaisonDeliaison->Visible = false;
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
		// 
		// gerer_coureurs
		// 
		this->gerer_coureurs->Font = (gcnew System::Drawing::Font(L"Georgia", 9.25F, System::Drawing::FontStyle::Bold));
		this->gerer_coureurs->Location = System::Drawing::Point(477, 123);
		this->gerer_coureurs->Name = L"gerer_coureurs";
		this->gerer_coureurs->Size = System::Drawing::Size(169, 32);
		this->gerer_coureurs->TabIndex = 6;
		this->gerer_coureurs->Text = L"gérer les coureurs";
		this->gerer_coureurs->UseVisualStyleBackColor = true;
		this->gerer_coureurs->Click += gcnew System::EventHandler(this, &MyForm::gerer_coureurs_Click);
		// 
		// gerer_courses
		// 
		this->gerer_courses->Font = (gcnew System::Drawing::Font(L"Georgia", 9.25F, System::Drawing::FontStyle::Bold));
		this->gerer_courses->Location = System::Drawing::Point(671, 123);
		this->gerer_courses->Name = L"gerer_courses";
		this->gerer_courses->Size = System::Drawing::Size(169, 32);
		this->gerer_courses->TabIndex = 7;
		this->gerer_courses->Text = L"gérer les courses";
		this->gerer_courses->UseVisualStyleBackColor = true;
		this->gerer_courses->Click += gcnew System::EventHandler(this, &MyForm::gerer_courses_Click);
		// 
		// associer_coureurs_courses
		// 
		this->associer_coureurs_courses->Font = (gcnew System::Drawing::Font(L"Georgia", 9.25F, System::Drawing::FontStyle::Bold));
		this->associer_coureurs_courses->Location = System::Drawing::Point(26, 123);
		this->associer_coureurs_courses->Name = L"associer_coureurs_courses";
		this->associer_coureurs_courses->Size = System::Drawing::Size(280, 32);
		this->associer_coureurs_courses->TabIndex = 0;
		this->associer_coureurs_courses->Text = L"associer des coureurs à une course";
		this->associer_coureurs_courses->UseVisualStyleBackColor = true;
		this->associer_coureurs_courses->Click += gcnew System::EventHandler(this, &MyForm::associer_coureurs_courses_Click);
		// 
		// comboBox1
		// 
		this->comboBox1->Cursor = System::Windows::Forms::Cursors::Arrow;
		this->comboBox1->DropDownStyle = System::Windows::Forms::ComboBoxStyle::DropDownList;
		this->comboBox1->FormattingEnabled = true;
		this->comboBox1->Location = System::Drawing::Point(185, 80);
		this->comboBox1->Name = L"comboBox1";
		this->comboBox1->Size = System::Drawing::Size(121, 24);
		this->comboBox1->TabIndex = 9;
		this->comboBox1->Visible = false;
		this->comboBox1->SelectedIndexChanged += gcnew System::EventHandler(this, &MyForm::comboBox1_SelectedIndexChanged);
		// 
		// label1
		// 
		this->label1->AutoSize = true;
		this->label1->Location = System::Drawing::Point(23, 83);
		this->label1->Name = L"label1";
		this->label1->Size = System::Drawing::Size(139, 16);
		this->label1->TabIndex = 10;
		this->label1->Text = L"sélection de la course";
		this->label1->Visible = false;
		// 
		// MyForm
		// 
		this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
		this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
		this->AutoScroll = true;
		this->BackColor = System::Drawing::SystemColors::ScrollBar;
		this->BackgroundImageLayout = System::Windows::Forms::ImageLayout::None;
		this->ClientSize = System::Drawing::Size(872, 500);
		this->ControlBox = false;
		this->Controls->Add(this->label1);
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
		this->PerformLayout();

	}
#pragma endregion

	private: System::Void MyForm_Load(System::Object^  sender, System::EventArgs^  e) {
		this->dataGridView1->Location = System::Drawing::Point(26, 200);
		this->dataGridView1->Size = System::Drawing::Size(814, 250);
	}

#pragma region Fonctions des boutons
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

	private: System::Void dataGridView1_CellContentClick(System::Object^  sender, System::Windows::Forms::DataGridViewCellEventArgs^  e) {
		if (e->RowIndex > -1 && e->ColumnIndex == 0) {
			if (this->dataGridView1->Rows[e->RowIndex]->Cells[e->ColumnIndex]->Value->ToString() == "Lier") {
				gererLaBDD->creation_liaison(this->dataGridView1->Rows[e->RowIndex]->Cells[e->ColumnIndex + 1]->Value->ToString(), this->comboBox1->SelectedItem->ToString());
				affichage("assoc");  return;
			}
			gererLaBDD->suppression_liaison( this->dataGridView1->Rows[e->RowIndex]->Cells[e->ColumnIndex + 1]->Value->ToString(), this->comboBox1->SelectedItem->ToString());
			actualisationBoutonsLiaison();
		}
	}

	private: System::Void comboBox1_SelectedIndexChanged(System::Object^  sender, System::EventArgs^  e) {
		actualisationBoutonsLiaison();
	}

	private: System::Void associer_coureurs_courses_Click(System::Object^  sender, System::EventArgs^  e) {
		this->dataGridView1->AllowUserToAddRows = false;
		affichage("assoc");
	}

	private: System::Void gerer_coureurs_Click(System::Object^  sender, System::EventArgs^  e) {
		this->dataGridView1->AllowUserToAddRows = true;
		affichage("coureur");	
	}
	private: System::Void gerer_courses_Click(System::Object^  sender, System::EventArgs^  e) {
		this->dataGridView1->AllowUserToAddRows = true;
		affichage("course");
	}
#pragma endregion
#pragma region fonctions

	private: void affichage(String^ valeurBDD) {
		gererLaBDD->valeurBDD = valeurBDD;
		this->dataGridView1->Show();
		if (valeurBDD == "coureur" || valeurBDD == "course") {
			dataGridView1->ReadOnly = false;
			this->dataGridView1->DataSource = gererLaBDD->chargementBDD();
			this->liaisonDeliaison->DisplayIndex = 5;
			this->save_and_reload->Show();
			this->liaisonDeliaison->Visible = false;
			this->comboBox1->Visible = false;
			this->label1->Visible = false;
			return;
		}
		this->save_and_reload->Hide();
		dataGridView1->ReadOnly = true;
		this->liaisonDeliaison->Visible = true;
		this->comboBox1->Visible = true;
		
		this->label1->Visible = true;
		preparation_assoc();
	}

	private: void preparation_assoc() {
		DataTable^ valeurs = gcnew DataTable();
		if (!(valeurs = gererLaBDD->chargementBDD())) {
			MessageBox::Show("cette fonctionnalité n'est pas utilisable sans coureur !");
			return;
		}
		actualisationBoutonsLiaison();
		valeurs = gererLaBDD->chargerListeCoureur();
		comboBox1->Items->Clear();
		DataRow^ coureur;
		int i = 0;
		for each(coureur in valeurs->Rows) {
			comboBox1->Items->Add(coureur["idCoureur"]->ToString());
			i++;
		}
		if (i == 0) {
			MessageBox::Show("cette fonctionnalité n'est pas utilisable sans course !");
			return;
		}
		this->liaisonDeliaison->DisplayIndex = 3;
		this->comboBox1->SelectedIndex = 0;
	}

	private: void actualisationBoutonsLiaison() {
		this->dataGridView1->DataSource = gererLaBDD->chargementBDD();
		int i = 0;
		for each(DataRow^ test in gererLaBDD->chargementBDD()->Rows) {
			dataGridView1->Rows[i]->Cells[0]->Value = gererLaBDD->verificationLiaison(Convert::ToInt32(test["id"]), 1);
			i++;
		}
	}

	private: void sauvegardeBDD() {
		for (int i = 0; i < this->dataGridView1->RowCount - 1; i++) {
			array<String^> ^valeurs = {"", "", "", "", ""};
			for (int j = 0; j < 4; j++) {
				valeurs[j] = getData(i, j+1);
			}
			String^ date = getData(i, 5);
			valeurs[4] = date[6].ToString() + date[7] + date[8] + date[9] + "-" + date[3] + date[4] + "-" + date[0] + date[1];
			gererLaBDD->sauvegardeBDD(valeurs);
		}
	}

	private: String^ getData(int i, int j) {
		return this->dataGridView1->Rows[i]->Cells[j]->Value->ToString();
	}

#pragma endregion
};