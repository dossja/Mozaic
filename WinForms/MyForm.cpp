#include "MyForm.h"

using namespace System;
using namespace System::Windows::Forms;

[STAThreadAttribute]		// Ustawienie okienka WindowsForms jako aplikacji jednow�tkowej

int main(array<String^>^ argv)
{
	// Ustawienie wygl�du okien z Windows 10 (w moim przypadku), przed utworzeniem jakichkolwiek okien
	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false);

	// Tworzenie okna g��wnego i uruchomienie go
	WinForms::MyForm form;
	Application::Run(%form);

	return 0;
}