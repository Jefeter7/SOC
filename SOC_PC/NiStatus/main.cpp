#include "MyForm.h"
#include "rs232.h"


using namespace System;
using namespace System::Windows::Forms;
[STAThread]
void main(array<String^>^ args)
{
	
	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false);
	NiStatus::MyForm form;
	Application::Run(%form);
}

/*void extfun()
{
	
}*/