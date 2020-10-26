#pragma once

namespace loader {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for form_installer
	/// </summary>
	public ref class form_installer : public System::Windows::Forms::Form
	{
	public:
		form_installer(void)
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
		~form_installer()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Button^  btn_browse_gi_exe;

	protected:

	protected:

	private: System::Windows::Forms::TextBox^  txt_gi_exe_path;
	private: System::Windows::Forms::Button^  btn_install;
	private: System::Windows::Forms::ToolTip^  tips_buttons;



	private: System::Windows::Forms::Button^  btn_uninstall;

	private: System::Windows::Forms::PictureBox^  pic_meme;
	private: System::Windows::Forms::ListBox^  list_log;


	private: System::ComponentModel::IContainer^  components;

	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>


#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			this->components = (gcnew System::ComponentModel::Container());
			System::ComponentModel::ComponentResourceManager^  resources = (gcnew System::ComponentModel::ComponentResourceManager(form_installer::typeid));
			this->btn_browse_gi_exe = (gcnew System::Windows::Forms::Button());
			this->txt_gi_exe_path = (gcnew System::Windows::Forms::TextBox());
			this->btn_install = (gcnew System::Windows::Forms::Button());
			this->btn_uninstall = (gcnew System::Windows::Forms::Button());
			this->pic_meme = (gcnew System::Windows::Forms::PictureBox());
			this->tips_buttons = (gcnew System::Windows::Forms::ToolTip(this->components));
			this->list_log = (gcnew System::Windows::Forms::ListBox());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pic_meme))->BeginInit();
			this->SuspendLayout();
			//
			// btn_browse_gi_exe
			//
			this->btn_browse_gi_exe->Location = System::Drawing::Point(522, 12);
			this->btn_browse_gi_exe->MaximumSize = System::Drawing::Size(33, 20);
			this->btn_browse_gi_exe->MinimumSize = System::Drawing::Size(33, 20);
			this->btn_browse_gi_exe->Name = L"btn_browse_gi_exe";
			this->btn_browse_gi_exe->Size = System::Drawing::Size(33, 20);
			this->btn_browse_gi_exe->TabIndex = 0;
			this->btn_browse_gi_exe->Text = L"....";
			this->tips_buttons->SetToolTip(this->btn_browse_gi_exe, L"Find the file GenshinImpact.exe");
			this->btn_browse_gi_exe->UseVisualStyleBackColor = true;
			this->btn_browse_gi_exe->Click += gcnew System::EventHandler(this, &form_installer::btn_browse_gi_exe_Click);
			//
			// txt_gi_exe_path
			//
			this->txt_gi_exe_path->Location = System::Drawing::Point(12, 12);
			this->txt_gi_exe_path->Name = L"txt_gi_exe_path";
			this->txt_gi_exe_path->ReadOnly = true;
			this->txt_gi_exe_path->Size = System::Drawing::Size(504, 20);
			this->txt_gi_exe_path->TabIndex = 1;
			//
			// btn_install
			//
			this->btn_install->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"btn_install.Image")));
			this->btn_install->Location = System::Drawing::Point(522, 56);
			this->btn_install->MaximumSize = System::Drawing::Size(33, 27);
			this->btn_install->MinimumSize = System::Drawing::Size(33, 27);
			this->btn_install->Name = L"btn_install";
			this->btn_install->Size = System::Drawing::Size(33, 27);
			this->btn_install->TabIndex = 3;
			this->tips_buttons->SetToolTip(this->btn_install, L"Install");
			this->btn_install->UseVisualStyleBackColor = true;
			this->btn_install->Click += gcnew System::EventHandler(this, &form_installer::btn_install_Click);
			//
			// btn_uninstall
			//
			this->btn_uninstall->BackgroundImageLayout = System::Windows::Forms::ImageLayout::None;
			this->btn_uninstall->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"btn_uninstall.Image")));
			this->btn_uninstall->Location = System::Drawing::Point(522, 106);
			this->btn_uninstall->MaximumSize = System::Drawing::Size(33, 27);
			this->btn_uninstall->MinimumSize = System::Drawing::Size(33, 27);
			this->btn_uninstall->Name = L"btn_uninstall";
			this->btn_uninstall->Size = System::Drawing::Size(33, 27);
			this->btn_uninstall->TabIndex = 4;
			this->tips_buttons->SetToolTip(this->btn_uninstall, L"Uninstall");
			this->btn_uninstall->UseVisualStyleBackColor = true;
			this->btn_uninstall->Click += gcnew System::EventHandler(this, &form_installer::btn_uninstall_Click);
			//
			// pic_meme
			//
			this->pic_meme->BackgroundImageLayout = System::Windows::Forms::ImageLayout::None;
			this->pic_meme->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pic_meme.Image")));
			this->pic_meme->Location = System::Drawing::Point(8, 40);
			this->pic_meme->MaximumSize = System::Drawing::Size(83, 93);
			this->pic_meme->MinimumSize = System::Drawing::Size(83, 93);
			this->pic_meme->Name = L"pic_meme";
			this->pic_meme->Size = System::Drawing::Size(83, 93);
			this->pic_meme->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
			this->pic_meme->TabIndex = 5;
			this->pic_meme->TabStop = false;
			//
			// list_log
			//
			this->list_log->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->list_log->FormattingEnabled = true;
			this->list_log->Location = System::Drawing::Point(91, 40);
			this->list_log->MaximumSize = System::Drawing::Size(425, 93);
			this->list_log->MinimumSize = System::Drawing::Size(425, 93);
			this->list_log->Name = L"list_log";
			this->list_log->ScrollAlwaysVisible = true;
			this->list_log->Size = System::Drawing::Size(425, 93);
			this->list_log->TabIndex = 6;
			//
			// form_installer
			//
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(563, 145);
			this->Controls->Add(this->list_log);
			this->Controls->Add(this->pic_meme);
			this->Controls->Add(this->btn_uninstall);
			this->Controls->Add(this->btn_install);
			this->Controls->Add(this->txt_gi_exe_path);
			this->Controls->Add(this->btn_browse_gi_exe);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedSingle;
			this->MaximizeBox = false;
			this->MaximumSize = System::Drawing::Size(579, 180);
			this->MinimizeBox = false;
			this->MinimumSize = System::Drawing::Size(579, 180);
			this->Name = L"form_installer";
			this->ShowIcon = false;
			this->ShowInTaskbar = false;
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterParent;
			this->Text = L"Genshin Impact - Loader";
			this->TopMost = true;
			this->Load += gcnew System::EventHandler(this, &form_installer::form_installer_Load);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pic_meme))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
		//
		//
	private: Boolean help_setup(String^ filePath, Boolean install_or_uninstall);
	private: String^ help_parent(String^ root_file);
	private: System::Void btn_browse_gi_exe_Click(System::Object^  sender, System::EventArgs^  e);
	private: System::Void btn_install_Click(System::Object^  sender, System::EventArgs^  e);
	private: System::Void btn_uninstall_Click(System::Object^  sender, System::EventArgs^  e);
	private: System::Void form_installer_Load(System::Object^  sender, System::EventArgs^  e);

};
}
