#include <Windows.h>

#pragma once

typedef int(_stdcall *Mozaika)(unsigned char* tab, int ilosc);

#include "HistogramForm.h"

namespace WinForms {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace System::Threading;
	using namespace System::Diagnostics;
	using namespace std;

	/// <summary>
	/// Summary for MyForm
	/// </summary>
	public ref class MyForm : public System::Windows::Forms::Form
	{
	public:
		Bitmap^ bitmapa;				//Bitmapa wejœciowa
		Bitmap^ bitmapaPoPrzejsciach;	//Bitmapa wejœciowa po przekszta³ceniach

		Stopwatch timer;				//Timer u¿ywany do obliczania czasu wykonywania operacji (stoper)

		//Tablice u¿ywane do tworzenia histogramów
		array<int>^ tabRED = gcnew array<int>(256);
		array<int>^ tabGREEN = gcnew array<int>(256);
		array<int>^ tabBLUE = gcnew array<int>(256);

	private: System::Windows::Forms::Label^  L_InfoHistogram;
	private: System::Windows::Forms::Button^  BTN_ZapiszPlik;
	private: System::Windows::Forms::Label^  L_CzasPracyHistogramy;
	private: System::Windows::Forms::Label^  L_CzasPracyCpp;
	private: System::Windows::Forms::Label^  L_CzasPracyASM;
	private: System::Windows::Forms::Label^  L_CzasHistogramów;
	private: System::Windows::Forms::Label^  L_CzasCpp;
	private: System::Windows::Forms::Label^  L_CzasASM;

	private: System::Windows::Forms::Button^  BTN_WygenerujHistogramy;
	public:

		MyForm(void)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~MyForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::OpenFileDialog^  OtwarciePliku;
	private: System::Windows::Forms::Button^  BTN_OtworzPlik;

	private: System::Windows::Forms::GroupBox^  G_InfoPlik;
	private: System::Windows::Forms::Label^  L_InfoPlikStan;
	private: System::Windows::Forms::Label^  L_InfoPlikWymiary;



	private: System::Windows::Forms::PictureBox^  B_PrzedEdycja;
	private: System::Windows::Forms::PictureBox^  B_PoEdycji;

	private: System::Windows::Forms::SaveFileDialog^  ZapisaniePliku;
	private: System::Windows::Forms::Button^  BTN_ZamknijProgram;
	private: System::Windows::Forms::Button^  BTN_RestartProgramu;

	private: System::Windows::Forms::Button^  BTN_UruchomCpp;
	private: System::Windows::Forms::Button^  BTN_UruchomAsm;

	private: System::Windows::Forms::Label^  L_WymiaryPiksela;
	private: System::Windows::Forms::GroupBox^  G_PrzedEdycja;
	private: System::Windows::Forms::GroupBox^  G_PoEdycji;
	private: System::Windows::Forms::Label^  L_WybranyJezyk;
	private: System::Windows::Forms::ComboBox^  DDL_WymiaryPiksela;
	private: System::Windows::Forms::GroupBox^  G_Histogramy;
	private: System::Windows::Forms::Button^  BTN_HistogramNiebieski;
	private: System::Windows::Forms::Button^  BTN_HistogramZielony;
	private: System::Windows::Forms::Label^  L_HistogramNiebieski;
	private: System::Windows::Forms::Label^  L_HistogramZielony;
	private: System::Windows::Forms::Label^  L_HistogramCzerwony;
	private: System::Windows::Forms::Button^  BTN_HistogramCzerwony;

	private: System::Windows::Forms::GroupBox^  G_CzasPracy;






	protected:

	protected:

	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			this->OtwarciePliku = (gcnew System::Windows::Forms::OpenFileDialog());
			this->BTN_OtworzPlik = (gcnew System::Windows::Forms::Button());
			this->ZapisaniePliku = (gcnew System::Windows::Forms::SaveFileDialog());
			this->BTN_ZamknijProgram = (gcnew System::Windows::Forms::Button());
			this->G_InfoPlik = (gcnew System::Windows::Forms::GroupBox());
			this->L_InfoHistogram = (gcnew System::Windows::Forms::Label());
			this->L_InfoPlikWymiary = (gcnew System::Windows::Forms::Label());
			this->L_InfoPlikStan = (gcnew System::Windows::Forms::Label());
			this->B_PrzedEdycja = (gcnew System::Windows::Forms::PictureBox());
			this->B_PoEdycji = (gcnew System::Windows::Forms::PictureBox());
			this->BTN_RestartProgramu = (gcnew System::Windows::Forms::Button());
			this->BTN_UruchomCpp = (gcnew System::Windows::Forms::Button());
			this->BTN_UruchomAsm = (gcnew System::Windows::Forms::Button());
			this->L_WymiaryPiksela = (gcnew System::Windows::Forms::Label());
			this->G_PrzedEdycja = (gcnew System::Windows::Forms::GroupBox());
			this->G_PoEdycji = (gcnew System::Windows::Forms::GroupBox());
			this->L_WybranyJezyk = (gcnew System::Windows::Forms::Label());
			this->DDL_WymiaryPiksela = (gcnew System::Windows::Forms::ComboBox());
			this->G_Histogramy = (gcnew System::Windows::Forms::GroupBox());
			this->BTN_HistogramNiebieski = (gcnew System::Windows::Forms::Button());
			this->BTN_HistogramZielony = (gcnew System::Windows::Forms::Button());
			this->L_HistogramNiebieski = (gcnew System::Windows::Forms::Label());
			this->L_HistogramZielony = (gcnew System::Windows::Forms::Label());
			this->L_HistogramCzerwony = (gcnew System::Windows::Forms::Label());
			this->BTN_HistogramCzerwony = (gcnew System::Windows::Forms::Button());
			this->G_CzasPracy = (gcnew System::Windows::Forms::GroupBox());
			this->L_CzasPracyHistogramy = (gcnew System::Windows::Forms::Label());
			this->L_CzasPracyCpp = (gcnew System::Windows::Forms::Label());
			this->L_CzasPracyASM = (gcnew System::Windows::Forms::Label());
			this->L_CzasHistogramów = (gcnew System::Windows::Forms::Label());
			this->L_CzasCpp = (gcnew System::Windows::Forms::Label());
			this->L_CzasASM = (gcnew System::Windows::Forms::Label());
			this->BTN_WygenerujHistogramy = (gcnew System::Windows::Forms::Button());
			this->BTN_ZapiszPlik = (gcnew System::Windows::Forms::Button());
			this->G_InfoPlik->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->B_PrzedEdycja))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->B_PoEdycji))->BeginInit();
			this->G_PrzedEdycja->SuspendLayout();
			this->G_PoEdycji->SuspendLayout();
			this->G_Histogramy->SuspendLayout();
			this->G_CzasPracy->SuspendLayout();
			this->SuspendLayout();
			// 
			// OtwarciePliku
			// 
			this->OtwarciePliku->Filter = L"Bitmapy (#.bmp)|*.bmp|Wszystkie typy (#.*)|*.*";
			this->OtwarciePliku->InitialDirectory = L"C:\\Desktop";
			// 
			// BTN_OtworzPlik
			// 
			this->BTN_OtworzPlik->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(0)),
				static_cast<System::Int32>(static_cast<System::Byte>(80)));
			this->BTN_OtworzPlik->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
			this->BTN_OtworzPlik->ForeColor = System::Drawing::Color::Silver;
			this->BTN_OtworzPlik->Location = System::Drawing::Point(74, 16);
			this->BTN_OtworzPlik->Margin = System::Windows::Forms::Padding(2);
			this->BTN_OtworzPlik->Name = L"BTN_OtworzPlik";
			this->BTN_OtworzPlik->Size = System::Drawing::Size(96, 36);
			this->BTN_OtworzPlik->TabIndex = 0;
			this->BTN_OtworzPlik->Text = L"Otwórz plik";
			this->BTN_OtworzPlik->UseVisualStyleBackColor = false;
			this->BTN_OtworzPlik->Click += gcnew System::EventHandler(this, &MyForm::BTN_OtworzPlik_Click);
			// 
			// ZapisaniePliku
			// 
			this->ZapisaniePliku->Filter = L"Bitmapa (*.bmp)|*.bmp";
			this->ZapisaniePliku->InitialDirectory = L"C:\\Desktop";
			// 
			// BTN_ZamknijProgram
			// 
			this->BTN_ZamknijProgram->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)),
				static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(80)));
			this->BTN_ZamknijProgram->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
			this->BTN_ZamknijProgram->ForeColor = System::Drawing::Color::Silver;
			this->BTN_ZamknijProgram->Location = System::Drawing::Point(1060, 595);
			this->BTN_ZamknijProgram->Margin = System::Windows::Forms::Padding(2);
			this->BTN_ZamknijProgram->Name = L"BTN_ZamknijProgram";
			this->BTN_ZamknijProgram->Size = System::Drawing::Size(96, 36);
			this->BTN_ZamknijProgram->TabIndex = 8;
			this->BTN_ZamknijProgram->Text = L"Zamknij";
			this->BTN_ZamknijProgram->UseVisualStyleBackColor = false;
			this->BTN_ZamknijProgram->Click += gcnew System::EventHandler(this, &MyForm::BTN_ZamknijProgram_Click);
			// 
			// G_InfoPlik
			// 
			this->G_InfoPlik->Controls->Add(this->L_InfoHistogram);
			this->G_InfoPlik->Controls->Add(this->L_InfoPlikWymiary);
			this->G_InfoPlik->Controls->Add(this->L_InfoPlikStan);
			this->G_InfoPlik->ForeColor = System::Drawing::Color::Silver;
			this->G_InfoPlik->Location = System::Drawing::Point(14, 59);
			this->G_InfoPlik->Margin = System::Windows::Forms::Padding(2);
			this->G_InfoPlik->Name = L"G_InfoPlik";
			this->G_InfoPlik->Padding = System::Windows::Forms::Padding(2);
			this->G_InfoPlik->Size = System::Drawing::Size(223, 103);
			this->G_InfoPlik->TabIndex = 5;
			this->G_InfoPlik->TabStop = false;
			this->G_InfoPlik->Text = L"Informacje:";
			// 
			// L_InfoHistogram
			// 
			this->L_InfoHistogram->AutoSize = true;
			this->L_InfoHistogram->ForeColor = System::Drawing::Color::LightGray;
			this->L_InfoHistogram->Location = System::Drawing::Point(17, 70);
			this->L_InfoHistogram->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->L_InfoHistogram->Name = L"L_InfoHistogram";
			this->L_InfoHistogram->Size = System::Drawing::Size(146, 13);
			this->L_InfoHistogram->TabIndex = 5;
			this->L_InfoHistogram->Text = L"Histogram do wygenerowania";
			// 
			// L_InfoPlikWymiary
			// 
			this->L_InfoPlikWymiary->AutoSize = true;
			this->L_InfoPlikWymiary->ForeColor = System::Drawing::Color::LightGray;
			this->L_InfoPlikWymiary->Location = System::Drawing::Point(17, 45);
			this->L_InfoPlikWymiary->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->L_InfoPlikWymiary->Name = L"L_InfoPlikWymiary";
			this->L_InfoPlikWymiary->Size = System::Drawing::Size(146, 13);
			this->L_InfoPlikWymiary->TabIndex = 0;
			this->L_InfoPlikWymiary->Text = L"Wymiary za³adowanego pliku";
			// 
			// L_InfoPlikStan
			// 
			this->L_InfoPlikStan->AutoSize = true;
			this->L_InfoPlikStan->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.5F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(238)));
			this->L_InfoPlikStan->ForeColor = System::Drawing::Color::LightGray;
			this->L_InfoPlikStan->Location = System::Drawing::Point(17, 20);
			this->L_InfoPlikStan->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->L_InfoPlikStan->Name = L"L_InfoPlikStan";
			this->L_InfoPlikStan->Size = System::Drawing::Size(121, 15);
			this->L_InfoPlikStan->TabIndex = 4;
			this->L_InfoPlikStan->Text = L"Stan ³adowania pliku";
			// 
			// B_PrzedEdycja
			// 
			this->B_PrzedEdycja->Dock = System::Windows::Forms::DockStyle::Fill;
			this->B_PrzedEdycja->Location = System::Drawing::Point(2, 15);
			this->B_PrzedEdycja->Margin = System::Windows::Forms::Padding(2);
			this->B_PrzedEdycja->Name = L"B_PrzedEdycja";
			this->B_PrzedEdycja->Size = System::Drawing::Size(416, 483);
			this->B_PrzedEdycja->SizeMode = System::Windows::Forms::PictureBoxSizeMode::Zoom;
			this->B_PrzedEdycja->TabIndex = 6;
			this->B_PrzedEdycja->TabStop = false;
			// 
			// B_PoEdycji
			// 
			this->B_PoEdycji->Dock = System::Windows::Forms::DockStyle::Fill;
			this->B_PoEdycji->Location = System::Drawing::Point(2, 15);
			this->B_PoEdycji->Margin = System::Windows::Forms::Padding(2);
			this->B_PoEdycji->Name = L"B_PoEdycji";
			this->B_PoEdycji->Size = System::Drawing::Size(416, 483);
			this->B_PoEdycji->SizeMode = System::Windows::Forms::PictureBoxSizeMode::Zoom;
			this->B_PoEdycji->TabIndex = 7;
			this->B_PoEdycji->TabStop = false;
			// 
			// BTN_RestartProgramu
			// 
			this->BTN_RestartProgramu->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)),
				static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(80)));
			this->BTN_RestartProgramu->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
			this->BTN_RestartProgramu->ForeColor = System::Drawing::Color::Silver;
			this->BTN_RestartProgramu->Location = System::Drawing::Point(947, 595);
			this->BTN_RestartProgramu->Margin = System::Windows::Forms::Padding(2);
			this->BTN_RestartProgramu->Name = L"BTN_RestartProgramu";
			this->BTN_RestartProgramu->Size = System::Drawing::Size(96, 36);
			this->BTN_RestartProgramu->TabIndex = 9;
			this->BTN_RestartProgramu->Text = L"Restart";
			this->BTN_RestartProgramu->UseVisualStyleBackColor = false;
			this->BTN_RestartProgramu->Click += gcnew System::EventHandler(this, &MyForm::BTN_RestartProgramu_Click);
			// 
			// BTN_UruchomCpp
			// 
			this->BTN_UruchomCpp->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(0)),
				static_cast<System::Int32>(static_cast<System::Byte>(80)));
			this->BTN_UruchomCpp->BackgroundImageLayout = System::Windows::Forms::ImageLayout::None;
			this->BTN_UruchomCpp->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
			this->BTN_UruchomCpp->ForeColor = System::Drawing::Color::Silver;
			this->BTN_UruchomCpp->Location = System::Drawing::Point(598, 595);
			this->BTN_UruchomCpp->Margin = System::Windows::Forms::Padding(2);
			this->BTN_UruchomCpp->Name = L"BTN_UruchomCpp";
			this->BTN_UruchomCpp->Size = System::Drawing::Size(96, 36);
			this->BTN_UruchomCpp->TabIndex = 10;
			this->BTN_UruchomCpp->Text = L"C++";
			this->BTN_UruchomCpp->UseVisualStyleBackColor = false;
			this->BTN_UruchomCpp->Click += gcnew System::EventHandler(this, &MyForm::BTN_UruchomCpp_Click);
			// 
			// BTN_UruchomAsm
			// 
			this->BTN_UruchomAsm->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(0)),
				static_cast<System::Int32>(static_cast<System::Byte>(80)));
			this->BTN_UruchomAsm->BackgroundImageLayout = System::Windows::Forms::ImageLayout::None;
			this->BTN_UruchomAsm->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
			this->BTN_UruchomAsm->ForeColor = System::Drawing::Color::Silver;
			this->BTN_UruchomAsm->Location = System::Drawing::Point(484, 595);
			this->BTN_UruchomAsm->Margin = System::Windows::Forms::Padding(2);
			this->BTN_UruchomAsm->Name = L"BTN_UruchomAsm";
			this->BTN_UruchomAsm->Size = System::Drawing::Size(96, 36);
			this->BTN_UruchomAsm->TabIndex = 11;
			this->BTN_UruchomAsm->Text = L"Asm";
			this->BTN_UruchomAsm->UseVisualStyleBackColor = false;
			this->BTN_UruchomAsm->Click += gcnew System::EventHandler(this, &MyForm::BTN_UruchomAsm_Click);
			// 
			// L_WymiaryPiksela
			// 
			this->L_WymiaryPiksela->AutoSize = true;
			this->L_WymiaryPiksela->ForeColor = System::Drawing::Color::Silver;
			this->L_WymiaryPiksela->Location = System::Drawing::Point(34, 196);
			this->L_WymiaryPiksela->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->L_WymiaryPiksela->Name = L"L_WymiaryPiksela";
			this->L_WymiaryPiksela->Size = System::Drawing::Size(86, 13);
			this->L_WymiaryPiksela->TabIndex = 13;
			this->L_WymiaryPiksela->Text = L"Wymiary piksela:";
			// 
			// G_PrzedEdycja
			// 
			this->G_PrzedEdycja->Controls->Add(this->B_PrzedEdycja);
			this->G_PrzedEdycja->ForeColor = System::Drawing::Color::Silver;
			this->G_PrzedEdycja->Location = System::Drawing::Point(274, 59);
			this->G_PrzedEdycja->Margin = System::Windows::Forms::Padding(2);
			this->G_PrzedEdycja->Name = L"G_PrzedEdycja";
			this->G_PrzedEdycja->Padding = System::Windows::Forms::Padding(2);
			this->G_PrzedEdycja->Size = System::Drawing::Size(420, 500);
			this->G_PrzedEdycja->TabIndex = 14;
			this->G_PrzedEdycja->TabStop = false;
			this->G_PrzedEdycja->Text = L"Przed edycj¹";
			// 
			// G_PoEdycji
			// 
			this->G_PoEdycji->Controls->Add(this->B_PoEdycji);
			this->G_PoEdycji->ForeColor = System::Drawing::Color::Silver;
			this->G_PoEdycji->Location = System::Drawing::Point(736, 59);
			this->G_PoEdycji->Margin = System::Windows::Forms::Padding(2);
			this->G_PoEdycji->Name = L"G_PoEdycji";
			this->G_PoEdycji->Padding = System::Windows::Forms::Padding(2);
			this->G_PoEdycji->Size = System::Drawing::Size(420, 500);
			this->G_PoEdycji->TabIndex = 15;
			this->G_PoEdycji->TabStop = false;
			this->G_PoEdycji->Text = L"Po edycji";
			// 
			// L_WybranyJezyk
			// 
			this->L_WybranyJezyk->AutoSize = true;
			this->L_WybranyJezyk->ForeColor = System::Drawing::Color::Silver;
			this->L_WybranyJezyk->Location = System::Drawing::Point(384, 595);
			this->L_WybranyJezyk->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->L_WybranyJezyk->Name = L"L_WybranyJezyk";
			this->L_WybranyJezyk->Size = System::Drawing::Size(79, 13);
			this->L_WybranyJezyk->TabIndex = 16;
			this->L_WybranyJezyk->Text = L"Wybrany jêzyk:";
			// 
			// DDL_WymiaryPiksela
			// 
			this->DDL_WymiaryPiksela->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)),
				static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(80)));
			this->DDL_WymiaryPiksela->DisplayMember = L"1x1";
			this->DDL_WymiaryPiksela->DropDownStyle = System::Windows::Forms::ComboBoxStyle::DropDownList;
			this->DDL_WymiaryPiksela->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
			this->DDL_WymiaryPiksela->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10.8F, System::Drawing::FontStyle::Regular,
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(238)));
			this->DDL_WymiaryPiksela->ForeColor = System::Drawing::Color::LightGray;
			this->DDL_WymiaryPiksela->FormattingEnabled = true;
			this->DDL_WymiaryPiksela->Items->AddRange(gcnew cli::array< System::Object^  >(25) {
				L"1x1", L"2x2", L"3x3", L"4x4", L"5x5",
					L"6x6", L"7x7", L"8x8", L"9x9", L"10x10", L"11x11", L"12x12", L"13x13", L"14x14", L"15x15", L"16x16", L"17x17", L"18x18", L"19x19",
					L"20x20", L"50x50", L"100x100", L"150x150", L"200x200", L"250x250"
			});
			this->DDL_WymiaryPiksela->SelectedIndex = 0;
			this->DDL_WymiaryPiksela->Location = System::Drawing::Point(144, 196);
			this->DDL_WymiaryPiksela->Margin = System::Windows::Forms::Padding(2);
			this->DDL_WymiaryPiksela->Name = L"DDL_WymiaryPiksela";
			this->DDL_WymiaryPiksela->Size = System::Drawing::Size(78, 25);
			this->DDL_WymiaryPiksela->TabIndex = 17;
			// 
			// G_Histogramy
			// 
			this->G_Histogramy->Controls->Add(this->BTN_HistogramNiebieski);
			this->G_Histogramy->Controls->Add(this->BTN_HistogramZielony);
			this->G_Histogramy->Controls->Add(this->L_HistogramNiebieski);
			this->G_Histogramy->Controls->Add(this->L_HistogramZielony);
			this->G_Histogramy->Controls->Add(this->L_HistogramCzerwony);
			this->G_Histogramy->Controls->Add(this->BTN_HistogramCzerwony);
			this->G_Histogramy->ForeColor = System::Drawing::Color::Silver;
			this->G_Histogramy->Location = System::Drawing::Point(17, 428);
			this->G_Histogramy->Margin = System::Windows::Forms::Padding(2);
			this->G_Histogramy->Name = L"G_Histogramy";
			this->G_Histogramy->Padding = System::Windows::Forms::Padding(2);
			this->G_Histogramy->Size = System::Drawing::Size(223, 131);
			this->G_Histogramy->TabIndex = 18;
			this->G_Histogramy->TabStop = false;
			this->G_Histogramy->Text = L"Histogram do podgl¹du:";
			// 
			// BTN_HistogramNiebieski
			// 
			this->BTN_HistogramNiebieski->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)),
				static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(192)));
			this->BTN_HistogramNiebieski->Cursor = System::Windows::Forms::Cursors::Hand;
			this->BTN_HistogramNiebieski->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
			this->BTN_HistogramNiebieski->ForeColor = System::Drawing::Color::LightGray;
			this->BTN_HistogramNiebieski->Location = System::Drawing::Point(130, 95);
			this->BTN_HistogramNiebieski->Margin = System::Windows::Forms::Padding(2);
			this->BTN_HistogramNiebieski->Name = L"BTN_HistogramNiebieski";
			this->BTN_HistogramNiebieski->Size = System::Drawing::Size(75, 24);
			this->BTN_HistogramNiebieski->TabIndex = 18;
			this->BTN_HistogramNiebieski->Text = L"Podgl¹d";
			this->BTN_HistogramNiebieski->UseVisualStyleBackColor = false;
			this->BTN_HistogramNiebieski->Click += gcnew System::EventHandler(this, &MyForm::BTN_HistogramNiebieski_Click);
			// 
			// BTN_HistogramZielony
			// 
			this->BTN_HistogramZielony->BackColor = System::Drawing::Color::Green;
			this->BTN_HistogramZielony->Cursor = System::Windows::Forms::Cursors::Hand;
			this->BTN_HistogramZielony->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
			this->BTN_HistogramZielony->ForeColor = System::Drawing::Color::LightGray;
			this->BTN_HistogramZielony->Location = System::Drawing::Point(130, 56);
			this->BTN_HistogramZielony->Margin = System::Windows::Forms::Padding(2);
			this->BTN_HistogramZielony->Name = L"BTN_HistogramZielony";
			this->BTN_HistogramZielony->Size = System::Drawing::Size(75, 24);
			this->BTN_HistogramZielony->TabIndex = 17;
			this->BTN_HistogramZielony->Text = L"Podgl¹d";
			this->BTN_HistogramZielony->UseVisualStyleBackColor = false;
			this->BTN_HistogramZielony->Click += gcnew System::EventHandler(this, &MyForm::BTN_HistogramZielony_Click);
			// 
			// L_HistogramNiebieski
			// 
			this->L_HistogramNiebieski->AutoSize = true;
			this->L_HistogramNiebieski->ForeColor = System::Drawing::Color::Silver;
			this->L_HistogramNiebieski->Location = System::Drawing::Point(17, 101);
			this->L_HistogramNiebieski->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->L_HistogramNiebieski->Name = L"L_HistogramNiebieski";
			this->L_HistogramNiebieski->Size = System::Drawing::Size(69, 13);
			this->L_HistogramNiebieski->TabIndex = 16;
			this->L_HistogramNiebieski->Text = L"Niebieski (B):";
			// 
			// L_HistogramZielony
			// 
			this->L_HistogramZielony->AutoSize = true;
			this->L_HistogramZielony->ForeColor = System::Drawing::Color::Silver;
			this->L_HistogramZielony->Location = System::Drawing::Point(17, 62);
			this->L_HistogramZielony->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->L_HistogramZielony->Name = L"L_HistogramZielony";
			this->L_HistogramZielony->Size = System::Drawing::Size(61, 13);
			this->L_HistogramZielony->TabIndex = 15;
			this->L_HistogramZielony->Text = L"Zielony (G):";
			// 
			// L_HistogramCzerwony
			// 
			this->L_HistogramCzerwony->AutoSize = true;
			this->L_HistogramCzerwony->ForeColor = System::Drawing::Color::Silver;
			this->L_HistogramCzerwony->Location = System::Drawing::Point(17, 23);
			this->L_HistogramCzerwony->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->L_HistogramCzerwony->Name = L"L_HistogramCzerwony";
			this->L_HistogramCzerwony->Size = System::Drawing::Size(73, 13);
			this->L_HistogramCzerwony->TabIndex = 14;
			this->L_HistogramCzerwony->Text = L"Czerwony (R):";
			// 
			// BTN_HistogramCzerwony
			// 
			this->BTN_HistogramCzerwony->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(192)),
				static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(0)));
			this->BTN_HistogramCzerwony->Cursor = System::Windows::Forms::Cursors::Hand;
			this->BTN_HistogramCzerwony->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
			this->BTN_HistogramCzerwony->ForeColor = System::Drawing::Color::LightGray;
			this->BTN_HistogramCzerwony->Location = System::Drawing::Point(130, 17);
			this->BTN_HistogramCzerwony->Margin = System::Windows::Forms::Padding(2);
			this->BTN_HistogramCzerwony->Name = L"BTN_HistogramCzerwony";
			this->BTN_HistogramCzerwony->Size = System::Drawing::Size(75, 24);
			this->BTN_HistogramCzerwony->TabIndex = 1;
			this->BTN_HistogramCzerwony->Text = L"Podgl¹d";
			this->BTN_HistogramCzerwony->UseVisualStyleBackColor = false;
			this->BTN_HistogramCzerwony->Click += gcnew System::EventHandler(this, &MyForm::BTN_HistogramCzerwony_Click);
			// 
			// G_CzasPracy
			// 
			this->G_CzasPracy->Controls->Add(this->L_CzasPracyHistogramy);
			this->G_CzasPracy->Controls->Add(this->L_CzasPracyCpp);
			this->G_CzasPracy->Controls->Add(this->L_CzasPracyASM);
			this->G_CzasPracy->Controls->Add(this->L_CzasHistogramów);
			this->G_CzasPracy->Controls->Add(this->L_CzasCpp);
			this->G_CzasPracy->Controls->Add(this->L_CzasASM);
			this->G_CzasPracy->ForeColor = System::Drawing::Color::Silver;
			this->G_CzasPracy->Location = System::Drawing::Point(17, 254);
			this->G_CzasPracy->Margin = System::Windows::Forms::Padding(2);
			this->G_CzasPracy->Name = L"G_CzasPracy";
			this->G_CzasPracy->Padding = System::Windows::Forms::Padding(2);
			this->G_CzasPracy->Size = System::Drawing::Size(223, 94);
			this->G_CzasPracy->TabIndex = 19;
			this->G_CzasPracy->TabStop = false;
			this->G_CzasPracy->Text = L"Czas pracy:";
			// 
			// L_CzasPracyHistogramy
			// 
			this->L_CzasPracyHistogramy->AutoSize = true;
			this->L_CzasPracyHistogramy->Location = System::Drawing::Point(89, 67);
			this->L_CzasPracyHistogramy->Name = L"L_CzasPracyHistogramy";
			this->L_CzasPracyHistogramy->Size = System::Drawing::Size(0, 13);
			this->L_CzasPracyHistogramy->TabIndex = 5;
			// 
			// L_CzasPracyCpp
			// 
			this->L_CzasPracyCpp->AutoSize = true;
			this->L_CzasPracyCpp->Location = System::Drawing::Point(89, 43);
			this->L_CzasPracyCpp->Name = L"L_CzasPracyCpp";
			this->L_CzasPracyCpp->Size = System::Drawing::Size(0, 13);
			this->L_CzasPracyCpp->TabIndex = 4;
			// 
			// L_CzasPracyASM
			// 
			this->L_CzasPracyASM->AutoSize = true;
			this->L_CzasPracyASM->Location = System::Drawing::Point(89, 19);
			this->L_CzasPracyASM->Name = L"L_CzasPracyASM";
			this->L_CzasPracyASM->Size = System::Drawing::Size(0, 13);
			this->L_CzasPracyASM->TabIndex = 3;
			// 
			// L_CzasHistogramów
			// 
			this->L_CzasHistogramów->AutoSize = true;
			this->L_CzasHistogramów->Location = System::Drawing::Point(17, 68);
			this->L_CzasHistogramów->Name = L"L_CzasHistogramów";
			this->L_CzasHistogramów->Size = System::Drawing::Size(62, 13);
			this->L_CzasHistogramów->TabIndex = 2;
			this->L_CzasHistogramów->Text = L"Histogramy:";
			// 
			// L_CzasCpp
			// 
			this->L_CzasCpp->AutoSize = true;
			this->L_CzasCpp->Location = System::Drawing::Point(17, 44);
			this->L_CzasCpp->Name = L"L_CzasCpp";
			this->L_CzasCpp->Size = System::Drawing::Size(29, 13);
			this->L_CzasCpp->TabIndex = 1;
			this->L_CzasCpp->Text = L"C++:";
			// 
			// L_CzasASM
			// 
			this->L_CzasASM->AutoSize = true;
			this->L_CzasASM->Location = System::Drawing::Point(17, 20);
			this->L_CzasASM->Name = L"L_CzasASM";
			this->L_CzasASM->Size = System::Drawing::Size(53, 13);
			this->L_CzasASM->TabIndex = 0;
			this->L_CzasASM->Text = L"Asembler:";
			// 
			// BTN_WygenerujHistogramy
			// 
			this->BTN_WygenerujHistogramy->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)),
				static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(80)));
			this->BTN_WygenerujHistogramy->Cursor = System::Windows::Forms::Cursors::Hand;
			this->BTN_WygenerujHistogramy->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
			this->BTN_WygenerujHistogramy->ForeColor = System::Drawing::Color::Silver;
			this->BTN_WygenerujHistogramy->Location = System::Drawing::Point(57, 379);
			this->BTN_WygenerujHistogramy->Margin = System::Windows::Forms::Padding(2);
			this->BTN_WygenerujHistogramy->Name = L"BTN_WygenerujHistogramy";
			this->BTN_WygenerujHistogramy->Size = System::Drawing::Size(146, 24);
			this->BTN_WygenerujHistogramy->TabIndex = 20;
			this->BTN_WygenerujHistogramy->Text = L"Wygeneruj histogramy";
			this->BTN_WygenerujHistogramy->UseVisualStyleBackColor = false;
			this->BTN_WygenerujHistogramy->Click += gcnew System::EventHandler(this, &MyForm::BTN_WygenerujHistogramy_Click);
			// 
			// BTN_ZapiszPlik
			// 
			this->BTN_ZapiszPlik->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(0)),
				static_cast<System::Int32>(static_cast<System::Byte>(80)));
			this->BTN_ZapiszPlik->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
			this->BTN_ZapiszPlik->ForeColor = System::Drawing::Color::Silver;
			this->BTN_ZapiszPlik->Location = System::Drawing::Point(1060, 16);
			this->BTN_ZapiszPlik->Margin = System::Windows::Forms::Padding(2);
			this->BTN_ZapiszPlik->Name = L"BTN_ZapiszPlik";
			this->BTN_ZapiszPlik->Size = System::Drawing::Size(96, 36);
			this->BTN_ZapiszPlik->TabIndex = 21;
			this->BTN_ZapiszPlik->Text = L"Zapisz";
			this->BTN_ZapiszPlik->UseVisualStyleBackColor = false;
			this->BTN_ZapiszPlik->Click += gcnew System::EventHandler(this, &MyForm::BTN_ZapiszPlik_Click);
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(0)),
				static_cast<System::Int32>(static_cast<System::Byte>(8)));
			this->ClientSize = System::Drawing::Size(1190, 663);
			this->Controls->Add(this->BTN_ZapiszPlik);
			this->Controls->Add(this->BTN_WygenerujHistogramy);
			this->Controls->Add(this->G_CzasPracy);
			this->Controls->Add(this->G_Histogramy);
			this->Controls->Add(this->DDL_WymiaryPiksela);
			this->Controls->Add(this->L_WybranyJezyk);
			this->Controls->Add(this->L_WymiaryPiksela);
			this->Controls->Add(this->BTN_UruchomAsm);
			this->Controls->Add(this->BTN_UruchomCpp);
			this->Controls->Add(this->BTN_RestartProgramu);
			this->Controls->Add(this->BTN_ZamknijProgram);
			this->Controls->Add(this->G_InfoPlik);
			this->Controls->Add(this->BTN_OtworzPlik);
			this->Controls->Add(this->G_PrzedEdycja);
			this->Controls->Add(this->G_PoEdycji);
			this->ForeColor = System::Drawing::Color::DarkRed;
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::None;
			this->Margin = System::Windows::Forms::Padding(2);
			this->Name = L"MyForm";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"WinForms";
			this->Load += gcnew System::EventHandler(this, &MyForm::MyForm_Load);
			this->G_InfoPlik->ResumeLayout(false);
			this->G_InfoPlik->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->B_PrzedEdycja))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->B_PoEdycji))->EndInit();
			this->G_PrzedEdycja->ResumeLayout(false);
			this->G_PoEdycji->ResumeLayout(false);
			this->G_Histogramy->ResumeLayout(false);
			this->G_Histogramy->PerformLayout();
			this->G_CzasPracy->ResumeLayout(false);
			this->G_CzasPracy->PerformLayout();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	
	private: System::Void BTN_OtworzPlik_Click(System::Object^ sender, System::EventArgs^ e)
	{
		L_InfoPlikStan->Text = L"Analiza pliku";
		
		L_CzasPracyCpp->Text = L"";
		L_CzasPracyASM->Text = L"";
		L_CzasPracyHistogramy->Text = L"";

		L_InfoPlikStan->Text = L"Wczytywanie...";
		if (OtwarciePliku->ShowDialog() == System::Windows::Forms::DialogResult::OK)
		{
			L_InfoPlikStan->Text = L"Wczytywanie.";

			try
			{
				OtwarciePliku->OpenFile();
				bitmapa = (Bitmap^)Image::FromFile(OtwarciePliku->FileName);
				B_PrzedEdycja->Image = bitmapa;
				L_InfoPlikStan->Text = L"Zakoñczono ³adowanie bitmapy.";

				L_InfoPlikWymiary->Text = L"Wymiary bitmapy: " + bitmapa->Size.Width + L" x " + bitmapa->Size.Height;

				bitmapaPoPrzejsciach = bitmapa;
				B_PoEdycji->Image = bitmapaPoPrzejsciach;
			}

			catch(...)
			{
				System::Windows::Forms::MessageBox::Show(L"Nie mo¿na otworzyæ pliku.", L"Error!");
				L_InfoPlikStan->Text = L"Wybierz ponownie inny plik.";
			}
		}

	}

	private: System::Void BTN_ZamknijProgram_Click(System::Object^  sender, System::EventArgs^  e) 
	{
		System::Windows::Forms::MessageBox::Show(L"Program zostanie zamkniêty!", L"Program");	//Wyœwietlanie okienka z komunikatem i ok
		Application::Exit();
	}

	private: System::Void BTN_RestartProgramu_Click(System::Object^  sender, System::EventArgs^  e) 
	{
		System::Windows::Forms::MessageBox::Show(L"Program zostanie odœwie¿ony!", L"Program");
		Application::Restart();
	}

	private: System::Void BTN_UruchomCpp_Click(System::Object^  sender, System::EventArgs^  e) 
	{	
		bitmapaPoPrzejsciach = bitmapa;
		B_PoEdycji->Image = bitmapaPoPrzejsciach;
		try
		{
			L_CzasPracyCpp->Text = L"W trakcie...";

			int num = DDL_WymiaryPiksela->SelectedIndex;
			int kwadrat = (num + 1);

			//Dla indeksów do 19, wartoœæ kwadratu to numer indeksu + 1
			//Dla indeksów od 20 do 24, wartoœæ ta zale¿y od tego switch
			switch (num)
			{
			case 20:
				kwadrat = 50;
				break;
			case 21:
				kwadrat = 100;
				break;
			case 22:
				kwadrat = 150;
				break;
			case 23:
				kwadrat = 200;
				break;
			case 24:
				kwadrat = 250;
				break;
			}

				//Zerowanie stopera i ponowne jego uruchomienie
			timer.Reset();
			timer.Start();

			System::Windows::Forms::MessageBox::Show(L"Uruchomiono program w jêzyku C++!", L"Jêzyk programu");
		
				//Jednym z za³o¿eñ projektu jest nieedystowanie pikseli, które nie tworz¹ jednego z pe³nych kwadratów,
				// w celu niesprawdzania tego warunku, w tym miejscu obliczany jest wymiar obrazu zawieraj¹cego same kwadraty
				// w zwi¹zku z tym obliczenia nie dotycz¹ niepe³nych kwadratów
			int wysokosc = bitmapaPoPrzejsciach->Height - (bitmapaPoPrzejsciach->Height % kwadrat);
			int szerokosc = bitmapaPoPrzejsciach->Width - (bitmapaPoPrzejsciach->Width % kwadrat);

				//Uruchomienie wszystkich funkcji Cpp
			for (int j = 0; j < wysokosc; j = (j + kwadrat))
			{
				for (int i = 0; i < szerokosc; i = (i + kwadrat))
				{
					int sR = 0, sG = 0, sB = 0;
					Color pikselKolor;

					//Dodawanie wartoœci RGB w pikselach tworz¹cych kwadraty
					for (int tJ = j; tJ < j + kwadrat; tJ++)
					{
						for (int tI = i; tI < i + kwadrat; tI++)
						{
							pikselKolor = bitmapaPoPrzejsciach->GetPixel(tI, tJ);
							sR += pikselKolor.R;
							sG += pikselKolor.G;
							sB += pikselKolor.B;
						}
					}

					//Obliczanie œrednich wartoœci poszczególnych elementów koloru RGB
					sR = sR / (kwadrat * kwadrat);
					sG = sG / (kwadrat * kwadrat);
					sB = sB / (kwadrat * kwadrat);

					//Ustawianie kolorów zedytowanych pikseli
					for (int tJ = j; tJ < j + kwadrat; tJ++)
					{
						for (int tI = i; tI < i + kwadrat; tI++)
						{
							pikselKolor.FromArgb(sR, sG, sB);

							bitmapaPoPrzejsciach->SetPixel(tI, tJ, pikselKolor);
						}
					}
				}
			}

			//Wczytywanie zedytowaniej bitmapy
			B_PoEdycji->Image = bitmapaPoPrzejsciach;

			//Zatrzymanie stopera, odczyt jego wartoœci i wpisanie do labela
			timer.Stop();
			TimeSpan czas = timer.Elapsed;
			String ^format = "{0:00}:{1:00}:{2:00}.{3:00}";
			String ^czasTrwania = System::String::Format(format, czas.Hours, czas.Minutes, czas.Seconds, czas.Milliseconds / 10);
			L_CzasPracyCpp->Text = czasTrwania;
		}

		catch (...)
		{
			System::Windows::Forms::MessageBox::Show(L"W celu przekszta³cenia pliku nale¿y go najpierw otworzyæ.", L"Error!");
			L_CzasPracyCpp->Text = L"Error!";
		}
	}

	private: System::Void BTN_UruchomAsm_Click(System::Object^  sender, System::EventArgs^  e)
	{			
		bitmapaPoPrzejsciach = bitmapa;
		B_PoEdycji->Image = bitmapaPoPrzejsciach;
		System::Windows::Forms::MessageBox::Show(L"Uruchomiono program w jêzyku Asemblera!", L"Jêzyk programu");

		//Dynamiczne ³adowanie biblioteki Asm
		try
		{
			L_CzasPracyASM->Text = L"W trakcie...";

			HINSTANCE hInstLibrary = LoadLibrary(L"AsmLib");
			Mozaika mozaika;

			//WskaŸnik teraz wskazuje na: rzutowany typ naszego typedef, o adresie z dll'ki pod tym uchwytem, funkcji o nazwie Mozaika
			mozaika = (Mozaika)GetProcAddress(hInstLibrary, "Mozaika");

			int num = DDL_WymiaryPiksela->SelectedIndex;
			int kwadrat = (num + 1);

			//Dla indeksów do 19, wartoœæ kwadratu to numer indeksu + 1
			//Dla indeksów od 20 do 24, wartoœæ ta zale¿y od tego switch
			switch (num)
			{
			case 20:
				kwadrat = 50;
				break;
			case 21:
				kwadrat = 100;
				break;
			case 22:
				kwadrat = 150;
				break;
			case 23:
				kwadrat = 200;
				break;
			case 24:
				kwadrat = 250;
				break;
			}

			//Tworzenie zmiennej z liczb¹ pikseli w kwadracie, ¿eby ograniczyæ liczbê ponownego wymna¿ania
			int ilosc = kwadrat * kwadrat;

			//Uruchamianie stopera
			timer.Reset();
			timer.Start();

				//Jednym z za³o¿eñ projektu jest nieedystowanie pikseli, które nie tworz¹ jednego z pe³nych kwadratów,
				// w celu niesprawdzania tego warunku, w tym miejscu obliczany jest wymiar obrazu zawieraj¹cego same kwadraty
				// w zwi¹zku z tym obliczenia nie dotycz¹ niepe³nych kwadratów
			int wysokosc = bitmapaPoPrzejsciach->Height - (bitmapaPoPrzejsciach->Height % kwadrat);
			int szerokosc = bitmapaPoPrzejsciach->Width - (bitmapaPoPrzejsciach->Width % kwadrat);

			//Uruchomienie wszystkich funkcji Cpp i ASM
			for (int j = 0; j < wysokosc; j = (j + kwadrat))
			{
				for (int i = 0; i < szerokosc; i = (i + kwadrat))
				{
					int inkrementacja = 0;

					unsigned char* tRED = new unsigned char[ilosc];
					unsigned char* tGREEN = new unsigned char[ilosc];
					unsigned char* tBLUE = new unsigned char[ilosc];

					Color pikselKolor;

					for (int tJ = j; tJ < j + kwadrat; tJ++)
					{
						for (int tI = i; tI < i + kwadrat; tI++)
						{
							pikselKolor = bitmapaPoPrzejsciach->GetPixel(tI, tJ);

							//Przepisywanie wartoœci pikseli do tablicy char
							tRED[inkrementacja] = pikselKolor.R;
							tGREEN[inkrementacja] = pikselKolor.G;
							tBLUE[inkrementacja] = pikselKolor.G;

							inkrementacja++;
						}
					}

					//Zmienne przechowywuj¹ce wartoœci adresów tablic poszczególnych czêœci koloru, do przekazania do funkcji ASM
					unsigned char* tREDaddress = &(tRED[0]);
					unsigned char* tGREENaddress = &(tGREEN[0]);
					unsigned char* tBLUEaddress = &(tBLUE[0]);

					//Wywo³anie funkcji dla poszczególnych tablic
					mozaika(tREDaddress, ilosc);
					mozaika(tGREENaddress, ilosc);
					mozaika(tBLUEaddress, ilosc);

					for (int tJ = j; tJ < j + kwadrat; tJ++)
					{
						for (int tI = i; tI < i + kwadrat; tI++)
						{
							pikselKolor.FromArgb((tRED[0]/ilosc), (tGREEN[0]/ilosc), (tBLUE[0]/ilosc));

							bitmapaPoPrzejsciach->SetPixel(tI, tJ, pikselKolor);
						}
					}
				}
			}

			B_PoEdycji->Image = bitmapaPoPrzejsciach;

			//Zwalnianie pamiêci po bibliotece
			FreeLibrary(hInstLibrary);

			//Odczyt czasu pracy i zapis do labela
			timer.Stop();
			TimeSpan czas = timer.Elapsed;
			String ^format = "{0:00}:{1:00}:{2:00}.{3:00}";
			String ^czasTrwania = System::String::Format(format, czas.Hours, czas.Minutes, czas.Seconds, (czas.Milliseconds / 10));
			L_CzasPracyASM->Text = czasTrwania;
		}

		catch (...)
		{
			System::Windows::Forms::MessageBox::Show(L"B³¹d przy ³adowaniu biblioteki asemblerowej!", L"Error!");
			L_CzasPracyASM->Text = L"Error!";
		}
	}

		//Otwieranie nowego forma z histogramem koloru czerwonego
	private: System::Void BTN_HistogramCzerwony_Click(System::Object^  sender, System::EventArgs^  e)
	{
		WinForms::HistogramForm form(tabRED, System::Drawing::Color::Red);
		form.ShowDialog();
		this->Show();
	}

		//Otwieranie nowego forma z histogramem koloru zielonego
	private: System::Void BTN_HistogramZielony_Click(System::Object^  sender, System::EventArgs^  e) 
	{
		WinForms::HistogramForm form(tabGREEN, System::Drawing::Color::Green);
		form.ShowDialog();
		this->Show();
	}

		//Otwieranie nowego forma z histogramem koloru niebieskiego
	private: System::Void BTN_HistogramNiebieski_Click(System::Object^  sender, System::EventArgs^  e) 
	{
		WinForms::HistogramForm form(tabBLUE, System::Drawing::Color::Blue);
		form.ShowDialog();
		this->Show();
	}

	private: System::Void MyForm_Load(System::Object^  sender, System::EventArgs^  e)
	{

	}

	private: System::Void BTN_WygenerujHistogramy_Click(System::Object^  sender, System::EventArgs^  e)
	{
		this->L_InfoHistogram->Text = L"Tworzenie histogramów";
		try
		{
			L_CzasPracyHistogramy->Text = L"W trakcie...";
			
			//Uruchamianie stopera
			timer.Reset();
			timer.Start();

			this->bitmapaPoPrzejsciach = bitmapa;

			for (int i = 0; i < 256; i++)
			{
				//Zerowanie tablic dla histogramów
				tabRED[i] = 0; tabGREEN[i] = 0; tabBLUE[i] = 0;
			}

			int iRED, iGREEN, iBLUE;
			Color pikselKolor;

			for (int i = 0; i < bitmapaPoPrzejsciach->Size.Width; i++)
			{
				for (int j = 0; j < bitmapaPoPrzejsciach->Size.Height; j++)
				{
					//Pobieranie wartoœci RGB pikseli
					pikselKolor = bitmapaPoPrzejsciach->GetPixel(i, j);

					//Zapis tych wartoœci do zmiennych
					iRED = pikselKolor.R; iGREEN = pikselKolor.G; iBLUE = pikselKolor.B;

					//Inkrementacja wartoœci tablic
					(tabRED[iRED])++; (tabGREEN[iGREEN])++; (tabBLUE[iBLUE])++;
				}
			}

			//Zatrzymanie stopera i zapis wyniku do labela
			timer.Stop();
			TimeSpan czas = timer.Elapsed;
			String ^format = "{0:00}:{1:00}:{2:00}.{3:00}";
			String ^czasTrwania = System::String::Format(format, czas.Hours, czas.Minutes, czas.Seconds, (czas.Milliseconds / 10));
			L_CzasPracyHistogramy->Text = czasTrwania;
		}

		catch (...)
		{
			System::Windows::Forms::MessageBox::Show(L"Nie mo¿na utworzyæ histogramów pliku.", L"Error!");
			L_InfoPlikStan->Text = L"Wybierz ponownie inny plik.";
			L_CzasPracyHistogramy->Text = L"Error!";
		}

		this->L_InfoHistogram->Text = L"Utworzono histogramy.";
	}

	private: System::Void BTN_ZapiszPlik_Click(System::Object^  sender, System::EventArgs^  e)
	{
		if (ZapisaniePliku->ShowDialog() == System::Windows::Forms::DialogResult::OK)
		{
			System::Windows::Forms::MessageBox::Show(L"Zapisano plik wynikowy!");
			try
			{
				if (ZapisaniePliku->FileName != "")
					bitmapaPoPrzejsciach->Save(ZapisaniePliku->FileName);
			}

			catch (...)
			{
				System::Windows::Forms::MessageBox::Show(L"B³¹d przy zapisie pliku!", L"Error!");
			}
		}
	}
};
}

