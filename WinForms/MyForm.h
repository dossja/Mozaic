#include <Windows.h>
#pragma once

typedef int(_stdcall *MyProc1)(int, int);

namespace WinForms {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for MyForm
	/// </summary>
	public ref class MyForm : public System::Windows::Forms::Form
	{
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
	private: System::Windows::Forms::Button^  BTN_ASM;
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
			this->BTN_ASM = (gcnew System::Windows::Forms::Button());
			this->SuspendLayout();
			// 
			// BTN_ASM
			// 
			this->BTN_ASM->Location = System::Drawing::Point(83, 96);
			this->BTN_ASM->Name = L"BTN_ASM";
			this->BTN_ASM->Size = System::Drawing::Size(131, 55);
			this->BTN_ASM->TabIndex = 0;
			this->BTN_ASM->Text = L"ASM";
			this->BTN_ASM->UseVisualStyleBackColor = true;
			this->BTN_ASM->Click += gcnew System::EventHandler(this, &MyForm::BTN_Click);
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(284, 261);
			this->Controls->Add(this->BTN_ASM);
			this->Name = L"MyForm";
			this->Text = L"MyForm";
			this->ResumeLayout(false);

		}
#pragma endregion
	private: System::Void BTN_Click(System::Object^  sender, System::EventArgs^  e)
	{
		HINSTANCE hInstLibrary = LoadLibrary(L"AsmLib");
		MyProc1 fun;
		if (hInstLibrary)
		{
			//WskaŸnik teraz wskazuje na: rzutowany typ naszego typedef, o adresie z dll'ki pod tym uchwytem, funkcji o nazwie Sum
			fun = (MyProc1)GetProcAddress(hInstLibrary, "MyProc1");

			if (fun)
			{
				int result = fun(7, 3);
				Console::WriteLine(result);
			}



			//Zwalnianie pamiêci po bibliotece
			FreeLibrary(hInstLibrary);
		}
	}
	};
}
