/**
 * \brief   loader
 * \author  dhulkifl
 * \contact https://github.com/dhulkifl
 * \version 2020/OCT/20
 * \license BSD 3-Clause "New" or "Revised" License
 */

#include "form_installer.h"

#include <Windows.h>

//--------------------------------------------------------------------------------------------------

using namespace loader;

using namespace System;
using namespace System::Windows::Forms;

//--------------------------------------------------------------------------------------------------

#pragma managed
[STAThread]
int start()
{
	Application::EnableVisualStyles();
	Application::Run(gcnew form_installer());
	return 0;
}

//--------------------------------------------------------------------------------------------------

#pragma unmanaged
INT WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, PSTR lpCmdLine, INT nCmdShow)
{
	return start();
}