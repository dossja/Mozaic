#include "MyForm.h"

using namespace System;
using namespace System::Windows::Forms;

[STAThreadAttribute]		// Ustawienie okienka WindowsForms jako aplikacji jednowątkowej

int main(array<String^>^ argv)
{
	// Ustawienie wyglądu okien z Windows 10 (w moim przypadku), przed utworzeniem jakichkolwiek okien
	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false);

	// Tworzenie okna głównego i uruchomienie go
	WinForms::MyForm form;
	Application::Run(%form);

	return 0;
}