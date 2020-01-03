#include "MyForm.h"

using namespace System;
using namespace System::Windows::Forms;

[STAThreadAttribute]		// Ustawienie okienka WindowsForms jako aplikacji jednow¹tkowej

int main(array<String^>^ argv)
{
	// Ustawienie wygl¹du okien z Windows 10 (w moim przypadku), przed utworzeniem jakichkolwiek okien
	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false);

	// Tworzenie okna g³ównego i uruchomienie go
	WinForms::MyForm form;
	Application::Run(%form);

	return 0;
}