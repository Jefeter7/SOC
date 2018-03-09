
#include <string.h>
#pragma once
using namespace System::Runtime::InteropServices;

namespace NiStatus {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for NotesDialog
	/// </summary>
	public ref class NotesDialog : public System::Windows::Forms::Form
	{
	public:
		NotesDialog(void)
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
		~NotesDialog()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::RichTextBox^  richTextBox1;
	private: System::Windows::Forms::Timer^  timer1;
	private: System::ComponentModel::IContainer^  components;
	protected:

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
			System::ComponentModel::ComponentResourceManager^  resources = (gcnew System::ComponentModel::ComponentResourceManager(NotesDialog::typeid));
			this->richTextBox1 = (gcnew System::Windows::Forms::RichTextBox());
			this->timer1 = (gcnew System::Windows::Forms::Timer(this->components));
			this->SuspendLayout();
			// 
			// richTextBox1
			// 
			this->richTextBox1->Dock = System::Windows::Forms::DockStyle::Fill;
			this->richTextBox1->Location = System::Drawing::Point(0, 0);
			this->richTextBox1->Name = L"richTextBox1";
			this->richTextBox1->ScrollBars = System::Windows::Forms::RichTextBoxScrollBars::Vertical;
			this->richTextBox1->Size = System::Drawing::Size(264, 387);
			this->richTextBox1->TabIndex = 0;
			this->richTextBox1->Text = L"Text saves after closing the dialog box.";
			// 
			// timer1
			// 
			this->timer1->Enabled = true;
			this->timer1->Tick += gcnew System::EventHandler(this, &NotesDialog::timer1_Tick);
			// 
			// NotesDialog
			// 
			this->AccessibleRole = System::Windows::Forms::AccessibleRole::Dialog;
			this->AllowDrop = true;
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->AutoValidate = System::Windows::Forms::AutoValidate::EnableAllowFocusChange;
			this->CausesValidation = false;
			this->ClientSize = System::Drawing::Size(264, 387);
			this->Controls->Add(this->richTextBox1);
			this->Icon = (cli::safe_cast<System::Drawing::Icon^>(resources->GetObject(L"$this.Icon")));
			this->Location = System::Drawing::Point(1008, 111);
			this->Name = L"NotesDialog";
			this->StartPosition = System::Windows::Forms::FormStartPosition::Manual;
			this->Text = L"Bath Notes";
			this->FormClosing += gcnew System::Windows::Forms::FormClosingEventHandler(this, &NotesDialog::NotesDialog_FormClosing);
			this->ControlAdded += gcnew System::Windows::Forms::ControlEventHandler(this, &NotesDialog::NotesDialog_ControlAdded);
			this->ResumeLayout(false);

		}
#pragma endregion
	private: System::Void NotesDialog_FormClosing(System::Object^  sender, System::Windows::Forms::FormClosingEventArgs^  e) {
		 

		String ^ temporarynotes = richTextBox1->Text;
		char *temporarystring = (char*)Marshal::StringToHGlobalAnsi(temporarynotes).ToPointer(); //look for using namespace System::Runtime::InteropServices;
		//strcat(hello, temporarystring);
	}
	private: System::Void NotesDialog_ControlAdded(System::Object^  sender, System::Windows::Forms::ControlEventArgs^  e) {
		//richTextBox1 ->Text = System::Convert::ToString(hello);
	}
	private: System::Void timer1_Tick(System::Object^  sender, System::EventArgs^  e) {
		//richTextBox1->Text = System::Convert::ToString(hello);
		timer1->Enabled = false;
		//make file buffered saving and loading
	}
	};
}
