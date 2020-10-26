/**
 * \brief   ui - form installer
 * \author  dhulkifl
 * \contact https://github.com/dhulkifl
 * \version 2020/OCT/20
 * \license BSD 3-Clause "New" or "Revised" License
 */

#include "form_installer.h"

#include "stub.h"

#include "utilities.xor.hpp"

//--------------------------------------------------------------------------------------------------

using namespace loader;

using namespace System;
using namespace System::IO;
using namespace System::Windows::Forms;

//--------------------------------------------------------------------------------------------------

#pragma unmanaged
static auto unhandled_exception = _xor_("Unhandled Exception");
static auto dot_exe = _xor_(".exe");
static auto find_exe = _xor_("Find and Open GenshinImpact.exe");
static auto describe_exe = _xor_("Genshin Impact Game (GenshinImpact.exe)|GenshinImpact.exe");
static auto gid_path = _xor_("GenshinImpact_Data\\");
static auto plugins_path = _xor_("Plugins\\");
static auto stub_dll = _xor_("hid.dll.dll");
static auto extra_path = _xor_("extra\\");

static auto is_right_install_location = _xor_("Please make sure you selected the right GenshinImpact.exe location.");
static auto needs_admin = _xor_("If the directory requires admin access. Restart this as an admin.");

static auto installer = _xor_("Installer");
static auto installed_success = _xor_("Loader Installed!");
static auto installed_extra = _xor_("You can install 'extra' modifications in the following directory:");
static auto installed_failed = _xor_("Install process failed!\n");
static auto installed_running = _xor_("GenshinImpact.exe should not be running when using this installer.");

static auto uninstaller = _xor_("Uninstaller");
static auto uninstall_warning = _xor_("Uninstalling will remove all files within the game's 'extra' folder");
static auto uninstalled_success = _xor_("Loader Uninstalled!");
static auto uninstalled_failed = _xor_("Uninstall process failed!");
static auto uninstalled_running = _xor_("GenshinImpact.exe should not be running when using this uninstaller.");

static auto exit_prompt = _xor_("You can now exit this application.");
static auto padding = _xor_("===================================================================");
static auto about1 = _xor_("[Genshin Impact] \'Extra\' Modifications Loader, Build: Oct 20 2020");
static auto about2 = _xor_("       Genshin Impact Target: HK4E_BUILD_35.45");
static auto about3 = _xor_("       Author: dhulkifl");
static auto about4 = _xor_("       Repository: https://github.com/dhulkifl/genshin-impact.loader");
static auto about5 = _xor_("       License: BSD 3-Clause \'New\' or \'Revised\' License");

//--------------------------------------------------------------------------------------------------

#pragma unmanaged
void lazy_xor(unsigned char* bytes, unsigned long size, unsigned char key)
{
	for (int i = 0; i < size; i++) {
		bytes[i] ^= key;
	}
}

#pragma unmanaged
void decrypt()
{
	lazy_xor(filedata, size, key);
}

//--------------------------------------------------------------------------------------------------

#pragma managed
array<Byte>^ MakeManagedArray(unsigned char* input, int len)
{
	array<Byte>^ result = gcnew array<Byte>(len);
	for (int i = 0; i < len; i++)
	{
		result[i] = input[i];
	}
	return result;
}

#pragma managed
System::Void form_installer::form_installer_Load(System::Object^  sender, System::EventArgs^  e)
{
	btn_install->Enabled = false;
	btn_uninstall->Enabled = false;
	int id = 0;
	try
	{
		list_log->TopIndex = list_log->Items->Add(gcnew String(padding.c_str()));
		list_log->TopIndex = list_log->Items->Add(gcnew String(about1.c_str()));
		list_log->TopIndex = list_log->Items->Add(gcnew String(about2.c_str()));
		list_log->TopIndex = list_log->Items->Add(gcnew String(about3.c_str()));
		list_log->TopIndex = list_log->Items->Add(gcnew String(about4.c_str()));
		list_log->TopIndex = list_log->Items->Add(gcnew String(about5.c_str()));
		list_log->TopIndex = list_log->Items->Add(gcnew String(padding.c_str()));
	}
	catch (Exception^ e)
	{
		MessageBox::Show(e->ToString(), gcnew String(unhandled_exception.c_str()));
	}
}

#pragma managed
System::Void form_installer::btn_browse_gi_exe_Click(System::Object^  sender, System::EventArgs^  e)
{
	try
	{
		OpenFileDialog ^open_gi_exe = gcnew OpenFileDialog();
		open_gi_exe->InitialDirectory = "";
		open_gi_exe->DefaultExt = gcnew String(dot_exe.c_str());
		open_gi_exe->Title = gcnew String(find_exe.c_str());
		open_gi_exe->Filter = gcnew String(describe_exe.c_str());
		open_gi_exe->FilterIndex = 1;
		open_gi_exe->ShowHelp = true;
		open_gi_exe->Multiselect = false;
		open_gi_exe->RestoreDirectory = true;
		if (open_gi_exe->ShowDialog() == System::Windows::Forms::DialogResult::OK)
		{
			txt_gi_exe_path->Text = open_gi_exe->FileName;
			btn_install->Enabled = true;
			btn_uninstall->Enabled = true;
		}
	}
	catch (Exception^ e) 
	{
		MessageBox::Show(e->ToString(), gcnew String(unhandled_exception.c_str()));
	}
}

#pragma managed
String^ form_installer::help_parent(String^ root_file)
{
	try
	{
		auto directory = Path::GetFullPath(root_file);
		directory = Path::GetDirectoryName(directory);
		directory += "\\";
		return directory;
	}
	catch (Exception^ e)
	{
		MessageBox::Show(e->ToString(), gcnew String(unhandled_exception.c_str()));
	}
	return "";
}

#pragma managed
Boolean form_installer::help_setup(String^ filePath, Boolean install_or_uninstall)
{
	int id = 0;
	String^ root = help_parent(filePath);
	String^ plugins = root;
	Boolean status = false;
	if (root != "")
	{
		root += gcnew String(gid_path.c_str());
		if (Directory::Exists(root))
		{
			root += gcnew String(plugins_path.c_str());
			if (Directory::Exists(root))
			{
				String ^ stub = root;
				stub += gcnew String(stub_dll.c_str());
				if (File::Exists(stub))
				{
					try
					{
						File::Delete(stub);
					}
					catch (UnauthorizedAccessException^ e)
					{
						list_log->TopIndex = list_log->Items->Add(gcnew String(needs_admin.c_str()));
						list_log->TopIndex = list_log->Items->Add(e->ToString());
						list_log->TopIndex = list_log->Items->Add(gcnew String(padding.c_str()));
						return false;
					}
					catch (Exception^ e)
					{
						MessageBox::Show(e->ToString(), gcnew String(unhandled_exception.c_str()));
						return false;
					}
				}
				if (install_or_uninstall == true)
				{
					try
					{
						decrypt();
						auto payload = MakeManagedArray(filedata, size);
						File::WriteAllBytes(stub, payload);
					}
					catch (Exception^ e)
					{
						MessageBox::Show(e->ToString(), gcnew String(unhandled_exception.c_str()));
						return false;
					}
				}
				
				plugins += gcnew String(extra_path.c_str());
				if (install_or_uninstall == true)
				{
					if (!Directory::Exists(plugins))
					{
						try
						{
							Directory::CreateDirectory(plugins);
						}
						catch (UnauthorizedAccessException^ e)
						{
							list_log->TopIndex = list_log->Items->Add(gcnew String(needs_admin.c_str()));
							list_log->TopIndex = list_log->Items->Add(e->ToString());
							list_log->TopIndex = list_log->Items->Add(gcnew String(padding.c_str()));
							return false;
						}
						catch (Exception^ e)
						{
							MessageBox::Show(e->ToString(), gcnew String(unhandled_exception.c_str()));
							return false;
						}
					}
					status = true;
				}
				else
				{
					if (Directory::Exists(plugins))
					{
						array<String^>^ files = Directory::GetFiles(plugins);
						for (int i = 0; i<files->Length; i++)
						{
							try
							{
								File::Delete(files[i]);
							}
							catch (UnauthorizedAccessException^ e)
							{
								list_log->TopIndex = list_log->Items->Add(gcnew String(needs_admin.c_str()));
								list_log->TopIndex = list_log->Items->Add(e->ToString());
								list_log->TopIndex = list_log->Items->Add(gcnew String(padding.c_str()));
								return false;
							}
							catch (Exception^ e)
							{
								MessageBox::Show(e->ToString(), gcnew String(unhandled_exception.c_str()));
								return false;
							}
						}
						try
						{
							Directory::Delete(plugins);
						}
						catch (UnauthorizedAccessException^ e)
						{
							list_log->TopIndex = list_log->Items->Add(gcnew String(needs_admin.c_str()));
							list_log->TopIndex = list_log->Items->Add(gcnew String(padding.c_str()));
							MessageBox::Show(e->ToString(), gcnew String(unhandled_exception.c_str()));
							return false;
						}
						catch (Exception^ e)
						{
							MessageBox::Show(e->ToString(), gcnew String(unhandled_exception.c_str()));
							return false;
						}
						
					}
					status = true;
				}

			}
			else
			{
				list_log->TopIndex = list_log->Items->Add(gcnew String(is_right_install_location.c_str()));
				return false;
			}
		}
		else
		{
			list_log->TopIndex = list_log->Items->Add(gcnew String(is_right_install_location.c_str()));
			return false;
		}
	}
	return status;
}

#pragma managed
System::Void form_installer::btn_install_Click(System::Object^  sender, System::EventArgs^  e)
{
	int id = 0;
	if (MessageBox::Show(gcnew String(installed_running.c_str()), gcnew String(installer.c_str())) == System::Windows::Forms::DialogResult::OK)
	{
		if (help_setup(txt_gi_exe_path->Text, true))
		{
			list_log->TopIndex = list_log->Items->Add(gcnew String(installed_success.c_str()));
			list_log->TopIndex = list_log->Items->Add(gcnew String(installed_extra.c_str()));
			String^ extra_loc = help_parent(txt_gi_exe_path->Text);
			extra_loc += gcnew String(extra_path.c_str());
			list_log->TopIndex = list_log->Items->Add(extra_loc);
			list_log->TopIndex = list_log->Items->Add(gcnew String(exit_prompt.c_str()));
			list_log->TopIndex = list_log->Items->Add(gcnew String(padding.c_str()));
		}
		else
		{
			list_log->TopIndex = list_log->Items->Add(gcnew String(installed_failed.c_str()));
			list_log->TopIndex = list_log->Items->Add(gcnew String(padding.c_str()));
		}
	}
}


#pragma managed
System::Void form_installer::btn_uninstall_Click(System::Object^  sender, System::EventArgs^  e)
{
	int id = 0;
	String^ warning_prompt = gcnew String(installed_running.c_str());
	warning_prompt += "\n" + gcnew String(uninstall_warning.c_str());
	
	if (MessageBox::Show(warning_prompt, gcnew String(uninstaller.c_str())) == System::Windows::Forms::DialogResult::OK)
	{
		if (help_setup(txt_gi_exe_path->Text, false))
		{
			id = list_log->Items->Add(gcnew String(uninstalled_success.c_str()));
			id = list_log->Items->Add(gcnew String(exit_prompt.c_str()));
			id = list_log->Items->Add(gcnew String(padding.c_str()));
		}
		else
		{
			id = list_log->Items->Add(gcnew String(uninstalled_failed.c_str()));
			id = list_log->Items->Add(gcnew String(padding.c_str()));
		}
	}
}