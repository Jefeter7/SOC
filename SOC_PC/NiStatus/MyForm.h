/*
*****NOTES*****
**For the proper functioning, few requirements must be met:
**1)
**2)
**©2018 Patrick Jefeter Körmendy

*/

#pragma managed
#pragma once
#include "rs232.h"
#include <iostream>
#include <stdlib.h>
#include <math.h>
#include "NotesDialog.h" 
#include <string.h>
//#include "GlobalVariables.h"

//Global Variables
//
//gonna get variables
unsigned int temperature=1, uv=1;
float pH = 1;
unsigned char Tbuf[10] = { 0 }; //variable used in TransmitData()
//managed native correcttions


//
//Conversion Factors
float pHgiven, pHinit, pHavg=0;
float UVinit, ConcGiven, SolVol, PlateArea,RA;
const float ROcorr = 8.908 / 7.81; //for whole and melted stuff//not important so far


//
//to display variables
float dispTemp, disppH, dispthickness; //temperature, pH and deposit thickness to display
float dispgperl, dispperc, dispphosph,RAdisp;   //gram per liter, percentage and phosphorus content display	
uint8_t	status, comerror,filerror;				//Status and error codes
double	GlobalCounter, ProgramCounter;
INT32 DataDeleter = 1;
char pHdepPhosph;

//state variables
bool IsPhGraph, IsInitialized;
char IsToReceive;





using namespace System::Runtime::InteropServices;

extern "C" {
	int TransmitData();
	void ConvertDispData();
	int StatusLoop();
	void ExportData();
	void ExportTo(char *target_file);
}

namespace NiStatus {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Windows::Forms::DataVisualization;
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
	private: System::Windows::Forms::Timer^  timer1;
	private: System::Windows::Forms::Label^  label1;
	private: System::Windows::Forms::Label^  label2;
	private: System::Windows::Forms::Label^  label3;
	private: System::Windows::Forms::MenuStrip^  menuStrip1;
	private: System::Windows::Forms::ToolStripMenuItem^  fileToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  openToolStripMenuItem;


	private: System::Windows::Forms::ToolStripMenuItem^  exitToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  editToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  notesToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  helpToolStripMenuItem;
	private: System::Windows::Forms::ToolStripSeparator^  toolStripSeparator1;
	private: System::Windows::Forms::ToolStripMenuItem^  advancedControlsToolStripMenuItem;
	private: System::Windows::Forms::Label^  label4;
	private: System::Windows::Forms::Label^  label5;
	private: System::Windows::Forms::Label^  label6;
	private: System::Windows::Forms::Button^  button1;

	private: System::Windows::Forms::Button^  button3;
	private: System::Windows::Forms::StatusStrip^  statusStrip1;
	private: System::Windows::Forms::ToolStripStatusLabel^  toolStripStatusLabel1;
	private: System::Windows::Forms::Label^  label7;

	private: System::Windows::Forms::Label^  label9;
	private: System::Windows::Forms::Label^  label8;
	private: System::Windows::Forms::Label^  label10;
	private: System::Windows::Forms::Label^  label11;
	private: System::Windows::Forms::Label^  label12;
	private: System::Windows::Forms::Label^  label13;
	private: System::Windows::Forms::Label^  label14;
	private: System::Windows::Forms::Label^  label15;




	private: System::Windows::Forms::Label^  label20;
	private: System::Windows::Forms::Label^  label21;




	private: System::Windows::Forms::MaskedTextBox^  maskedTextBox2;
	private: System::Windows::Forms::Label^  label22;
	private: System::Windows::Forms::Label^  label23;
	private: System::Windows::Forms::MaskedTextBox^  maskedTextBox3;
	private: System::Windows::Forms::Label^  label24;

	private: System::Windows::Forms::ContextMenuStrip^  contextMenuStrip1;
	private: System::Windows::Forms::ToolStripMenuItem^  toolStripMenuItem1;
	private: System::Windows::Forms::ToolStripMenuItem^  toolStripMenuItem2;


	private: System::Windows::Forms::Label^  label27;



	private: System::Windows::Forms::Button^  buttonUV;

	private: System::Windows::Forms::MaskedTextBox^  maskedTextBox5;

	private: System::Windows::Forms::ToolStripStatusLabel^  toolStripStatusLabel3;
	private: System::Windows::Forms::MaskedTextBox^  maskedTextBox6;


	private: System::Windows::Forms::Label^  label29;
	private: System::Windows::Forms::Label^  label30;
	private: System::Windows::Forms::Label^  label31;
	private: System::Windows::Forms::Label^  label32;
	private: System::Windows::Forms::Button^  button2;
	private: System::Windows::Forms::Label^  label33;
	private: System::Windows::Forms::Label^  label34;
	public: System::Windows::Forms::DataVisualization::Charting::Chart^  chart1;
	private:

	private: System::Windows::Forms::ToolStripMenuItem^  exportToolStripMenuItem;
	private: System::Windows::Forms::SaveFileDialog^  saveFileDialog1;
	private: System::Windows::Forms::Button^  button4;
	private: System::Windows::Forms::CheckBox^  checkBox1;
	protected: System::Windows::Forms::ComboBox^  comboBox1;

	protected:

	private: System::Windows::Forms::Label^  label16;
protected: System::Windows::Forms::ComboBox^  comboBox2;
private:
protected: System::Windows::Forms::ComboBox^  comboBox3;
private: System::Windows::Forms::MaskedTextBox^  maskedTextBox1;
protected:
private: System::Windows::Forms::Label^  label17;
private: System::Windows::Forms::MaskedTextBox^  maskedTextBox4;
private: System::Windows::Forms::Label^  label18;
private: System::Windows::Forms::ToolTip^  toolTip1;

private: System::Windows::Forms::Label^  label25;
private: System::Windows::Forms::Label^  label26;
private: System::Windows::Forms::Button^  button5;

	private:






	protected:
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
			System::ComponentModel::ComponentResourceManager^  resources = (gcnew System::ComponentModel::ComponentResourceManager(MyForm::typeid));
			System::Windows::Forms::DataVisualization::Charting::ChartArea^  chartArea2 = (gcnew System::Windows::Forms::DataVisualization::Charting::ChartArea());
			System::Windows::Forms::DataVisualization::Charting::Series^  series3 = (gcnew System::Windows::Forms::DataVisualization::Charting::Series());
			System::Windows::Forms::DataVisualization::Charting::Series^  series4 = (gcnew System::Windows::Forms::DataVisualization::Charting::Series());
			this->timer1 = (gcnew System::Windows::Forms::Timer(this->components));
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->menuStrip1 = (gcnew System::Windows::Forms::MenuStrip());
			this->fileToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->openToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->exportToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->toolStripSeparator1 = (gcnew System::Windows::Forms::ToolStripSeparator());
			this->exitToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->editToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->notesToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->advancedControlsToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->helpToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->label6 = (gcnew System::Windows::Forms::Label());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->button3 = (gcnew System::Windows::Forms::Button());
			this->statusStrip1 = (gcnew System::Windows::Forms::StatusStrip());
			this->toolStripStatusLabel1 = (gcnew System::Windows::Forms::ToolStripStatusLabel());
			this->toolStripStatusLabel3 = (gcnew System::Windows::Forms::ToolStripStatusLabel());
			this->label7 = (gcnew System::Windows::Forms::Label());
			this->label9 = (gcnew System::Windows::Forms::Label());
			this->label8 = (gcnew System::Windows::Forms::Label());
			this->label10 = (gcnew System::Windows::Forms::Label());
			this->label11 = (gcnew System::Windows::Forms::Label());
			this->label12 = (gcnew System::Windows::Forms::Label());
			this->label13 = (gcnew System::Windows::Forms::Label());
			this->label14 = (gcnew System::Windows::Forms::Label());
			this->label15 = (gcnew System::Windows::Forms::Label());
			this->label20 = (gcnew System::Windows::Forms::Label());
			this->label21 = (gcnew System::Windows::Forms::Label());
			this->maskedTextBox2 = (gcnew System::Windows::Forms::MaskedTextBox());
			this->label22 = (gcnew System::Windows::Forms::Label());
			this->label23 = (gcnew System::Windows::Forms::Label());
			this->maskedTextBox3 = (gcnew System::Windows::Forms::MaskedTextBox());
			this->label24 = (gcnew System::Windows::Forms::Label());
			this->contextMenuStrip1 = (gcnew System::Windows::Forms::ContextMenuStrip(this->components));
			this->toolStripMenuItem1 = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->toolStripMenuItem2 = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->label27 = (gcnew System::Windows::Forms::Label());
			this->chart1 = (gcnew System::Windows::Forms::DataVisualization::Charting::Chart());
			this->buttonUV = (gcnew System::Windows::Forms::Button());
			this->maskedTextBox5 = (gcnew System::Windows::Forms::MaskedTextBox());
			this->maskedTextBox6 = (gcnew System::Windows::Forms::MaskedTextBox());
			this->label29 = (gcnew System::Windows::Forms::Label());
			this->label30 = (gcnew System::Windows::Forms::Label());
			this->label31 = (gcnew System::Windows::Forms::Label());
			this->label32 = (gcnew System::Windows::Forms::Label());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->label33 = (gcnew System::Windows::Forms::Label());
			this->label34 = (gcnew System::Windows::Forms::Label());
			this->saveFileDialog1 = (gcnew System::Windows::Forms::SaveFileDialog());
			this->button4 = (gcnew System::Windows::Forms::Button());
			this->checkBox1 = (gcnew System::Windows::Forms::CheckBox());
			this->comboBox1 = (gcnew System::Windows::Forms::ComboBox());
			this->label16 = (gcnew System::Windows::Forms::Label());
			this->comboBox2 = (gcnew System::Windows::Forms::ComboBox());
			this->comboBox3 = (gcnew System::Windows::Forms::ComboBox());
			this->maskedTextBox1 = (gcnew System::Windows::Forms::MaskedTextBox());
			this->label17 = (gcnew System::Windows::Forms::Label());
			this->maskedTextBox4 = (gcnew System::Windows::Forms::MaskedTextBox());
			this->label18 = (gcnew System::Windows::Forms::Label());
			this->toolTip1 = (gcnew System::Windows::Forms::ToolTip(this->components));
			this->label25 = (gcnew System::Windows::Forms::Label());
			this->label26 = (gcnew System::Windows::Forms::Label());
			this->button5 = (gcnew System::Windows::Forms::Button());
			this->menuStrip1->SuspendLayout();
			this->statusStrip1->SuspendLayout();
			this->contextMenuStrip1->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->chart1))->BeginInit();
			this->SuspendLayout();
			// 
			// timer1
			// 
			this->timer1->Enabled = true;
			this->timer1->Interval = 500;
			this->timer1->Tick += gcnew System::EventHandler(this, &MyForm::timer1_Tick);
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"Segoe UI Emoji", 62));
			this->label1->Location = System::Drawing::Point(631, 355);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(137, 111);
			this->label1->TabIndex = 0;
			this->label1->Text = L"85";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Font = (gcnew System::Drawing::Font(L"Segoe UI Emoji", 62));
			this->label2->Location = System::Drawing::Point(455, 355);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(155, 111);
			this->label2->TabIndex = 1;
			this->label2->Text = L"7.0";
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Font = (gcnew System::Drawing::Font(L"Segoe UI Emoji", 48));
			this->label3->Location = System::Drawing::Point(111, 376);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(300, 85);
			this->label3->TabIndex = 2;
			this->label3->Text = L"0.278 um";
			// 
			// menuStrip1
			// 
			this->menuStrip1->BackColor = System::Drawing::Color::White;
			this->menuStrip1->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(3) {
				this->fileToolStripMenuItem,
					this->editToolStripMenuItem, this->helpToolStripMenuItem
			});
			this->menuStrip1->Location = System::Drawing::Point(0, 0);
			this->menuStrip1->Name = L"menuStrip1";
			this->menuStrip1->Size = System::Drawing::Size(939, 24);
			this->menuStrip1->TabIndex = 3;
			this->menuStrip1->Text = L"menuStrip1";
			this->menuStrip1->ItemClicked += gcnew System::Windows::Forms::ToolStripItemClickedEventHandler(this, &MyForm::menuStrip1_ItemClicked);
			// 
			// fileToolStripMenuItem
			// 
			this->fileToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(4) {
				this->openToolStripMenuItem,
					this->exportToolStripMenuItem, this->toolStripSeparator1, this->exitToolStripMenuItem
			});
			this->fileToolStripMenuItem->Name = L"fileToolStripMenuItem";
			this->fileToolStripMenuItem->Size = System::Drawing::Size(37, 20);
			this->fileToolStripMenuItem->Text = L"File";
			// 
			// openToolStripMenuItem
			// 
			this->openToolStripMenuItem->Name = L"openToolStripMenuItem";
			this->openToolStripMenuItem->Size = System::Drawing::Size(107, 22);
			this->openToolStripMenuItem->Text = L"Open";
			// 
			// exportToolStripMenuItem
			// 
			this->exportToolStripMenuItem->Name = L"exportToolStripMenuItem";
			this->exportToolStripMenuItem->Size = System::Drawing::Size(107, 22);
			this->exportToolStripMenuItem->Text = L"Export";
			this->exportToolStripMenuItem->Click += gcnew System::EventHandler(this, &MyForm::exportToolStripMenuItem_Click);
			// 
			// toolStripSeparator1
			// 
			this->toolStripSeparator1->BackColor = System::Drawing::SystemColors::ControlDarkDark;
			this->toolStripSeparator1->ForeColor = System::Drawing::SystemColors::ControlDarkDark;
			this->toolStripSeparator1->Name = L"toolStripSeparator1";
			this->toolStripSeparator1->Size = System::Drawing::Size(104, 6);
			// 
			// exitToolStripMenuItem
			// 
			this->exitToolStripMenuItem->Name = L"exitToolStripMenuItem";
			this->exitToolStripMenuItem->Size = System::Drawing::Size(107, 22);
			this->exitToolStripMenuItem->Text = L"Exit";
			this->exitToolStripMenuItem->Click += gcnew System::EventHandler(this, &MyForm::exitToolStripMenuItem_Click);
			// 
			// editToolStripMenuItem
			// 
			this->editToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(2) {
				this->notesToolStripMenuItem,
					this->advancedControlsToolStripMenuItem
			});
			this->editToolStripMenuItem->Name = L"editToolStripMenuItem";
			this->editToolStripMenuItem->Size = System::Drawing::Size(39, 20);
			this->editToolStripMenuItem->Text = L"Edit";
			// 
			// notesToolStripMenuItem
			// 
			this->notesToolStripMenuItem->Name = L"notesToolStripMenuItem";
			this->notesToolStripMenuItem->Size = System::Drawing::Size(175, 22);
			this->notesToolStripMenuItem->Text = L"Notes";
			this->notesToolStripMenuItem->Click += gcnew System::EventHandler(this, &MyForm::notesToolStripMenuItem_Click);
			// 
			// advancedControlsToolStripMenuItem
			// 
			this->advancedControlsToolStripMenuItem->Name = L"advancedControlsToolStripMenuItem";
			this->advancedControlsToolStripMenuItem->Size = System::Drawing::Size(175, 22);
			this->advancedControlsToolStripMenuItem->Text = L"Advanced Controls";
			// 
			// helpToolStripMenuItem
			// 
			this->helpToolStripMenuItem->Name = L"helpToolStripMenuItem";
			this->helpToolStripMenuItem->Size = System::Drawing::Size(44, 20);
			this->helpToolStripMenuItem->Text = L"Help";
			this->helpToolStripMenuItem->Click += gcnew System::EventHandler(this, &MyForm::helpToolStripMenuItem_Click);
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Font = (gcnew System::Drawing::Font(L"Segoe UI Emoji", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label4->Location = System::Drawing::Point(28, 35);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(149, 21);
			this->label4->TabIndex = 4;
			this->label4->Text = L"Bath Characteristics:";
			// 
			// label5
			// 
			this->label5->AutoSize = true;
			this->label5->Font = (gcnew System::Drawing::Font(L"Segoe UI Emoji", 20));
			this->label5->Location = System::Drawing::Point(740, 376);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(42, 36);
			this->label5->TabIndex = 5;
			this->label5->Text = L"°C";
			// 
			// label6
			// 
			this->label6->AutoSize = true;
			this->label6->Font = (gcnew System::Drawing::Font(L"Segoe UI Emoji", 20));
			this->label6->Location = System::Drawing::Point(584, 376);
			this->label6->Name = L"label6";
			this->label6->Size = System::Drawing::Size(50, 36);
			this->label6->TabIndex = 6;
			this->label6->Text = L"pH";
			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point(162, 466);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(50, 23);
			this->button1->TabIndex = 7;
			this->button1->Text = L"Pause";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &MyForm::button1_Click);
			// 
			// button3
			// 
			this->button3->Location = System::Drawing::Point(106, 466);
			this->button3->Name = L"button3";
			this->button3->Size = System::Drawing::Size(50, 23);
			this->button3->TabIndex = 9;
			this->button3->Text = L"Start";
			this->button3->UseVisualStyleBackColor = true;
			this->button3->Click += gcnew System::EventHandler(this, &MyForm::button3_Click);
			// 
			// statusStrip1
			// 
			this->statusStrip1->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(2) {
				this->toolStripStatusLabel1,
					this->toolStripStatusLabel3
			});
			this->statusStrip1->Location = System::Drawing::Point(0, 494);
			this->statusStrip1->Name = L"statusStrip1";
			this->statusStrip1->Size = System::Drawing::Size(939, 22);
			this->statusStrip1->TabIndex = 10;
			this->statusStrip1->Text = L"statusStrip1";
			// 
			// toolStripStatusLabel1
			// 
			this->toolStripStatusLabel1->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"toolStripStatusLabel1.Image")));
			this->toolStripStatusLabel1->Name = L"toolStripStatusLabel1";
			this->toolStripStatusLabel1->Size = System::Drawing::Size(59, 17);
			this->toolStripStatusLabel1->Text = L"Offline";
			// 
			// toolStripStatusLabel3
			// 
			this->toolStripStatusLabel3->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"toolStripStatusLabel3.Image")));
			this->toolStripStatusLabel3->Name = L"toolStripStatusLabel3";
			this->toolStripStatusLabel3->Size = System::Drawing::Size(114, 17);
			this->toolStripStatusLabel3->Text = L"UV Not Initialized";
			// 
			// label7
			// 
			this->label7->AutoSize = true;
			this->label7->Font = (gcnew System::Drawing::Font(L"Segoe UI Emoji", 15.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label7->Location = System::Drawing::Point(810, 379);
			this->label7->Name = L"label7";
			this->label7->Size = System::Drawing::Size(65, 28);
			this->label7->TabIndex = 11;
			this->label7->Text = L"20 g/l";
			// 
			// label9
			// 
			this->label9->AutoSize = true;
			this->label9->Font = (gcnew System::Drawing::Font(L"Segoe UI Emoji", 15.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label9->Location = System::Drawing::Point(812, 415);
			this->label9->Name = L"label9";
			this->label9->Size = System::Drawing::Size(57, 28);
			this->label9->TabIndex = 13;
			this->label9->Text = L"96 %";
			// 
			// label8
			// 
			this->label8->AutoSize = true;
			this->label8->Font = (gcnew System::Drawing::Font(L"Segoe UI Emoji", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label8->Location = System::Drawing::Point(123, 376);
			this->label8->Name = L"label8";
			this->label8->Size = System::Drawing::Size(172, 17);
			this->label8->TabIndex = 14;
			this->label8->Text = L"Expected Deposit Thickness:";
			// 
			// label10
			// 
			this->label10->AutoSize = true;
			this->label10->Font = (gcnew System::Drawing::Font(L"Segoe UI Emoji", 20.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label10->Location = System::Drawing::Point(21, 412);
			this->label10->Name = L"label10";
			this->label10->Size = System::Drawing::Size(59, 36);
			this->label10->TabIndex = 15;
			this->label10->Text = L"3 %";
			// 
			// label11
			// 
			this->label11->AutoSize = true;
			this->label11->Location = System::Drawing::Point(24, 378);
			this->label11->Name = L"label11";
			this->label11->Size = System::Drawing::Size(69, 15);
			this->label11->TabIndex = 16;
			this->label11->Text = L"Phosphorus";
			// 
			// label12
			// 
			this->label12->AutoSize = true;
			this->label12->Location = System::Drawing::Point(24, 392);
			this->label12->Name = L"label12";
			this->label12->Size = System::Drawing::Size(52, 15);
			this->label12->TabIndex = 17;
			this->label12->Text = L"Content:";
			// 
			// label13
			// 
			this->label13->AutoSize = true;
			this->label13->Font = (gcnew System::Drawing::Font(L"Segoe UI Emoji", 10.25F));
			this->label13->Location = System::Drawing::Point(28, 73);
			this->label13->Name = L"label13";
			this->label13->Size = System::Drawing::Size(105, 19);
			this->label13->TabIndex = 18;
			this->label13->Text = L"Nickel Sulphate:";
			// 
			// label14
			// 
			this->label14->AutoSize = true;
			this->label14->Font = (gcnew System::Drawing::Font(L"Segoe UI Emoji", 10.25F));
			this->label14->Location = System::Drawing::Point(28, 95);
			this->label14->Name = L"label14";
			this->label14->Size = System::Drawing::Size(156, 19);
			this->label14->TabIndex = 19;
			this->label14->Text = L"Sodium Hypophosphite:";
			// 
			// label15
			// 
			this->label15->AutoSize = true;
			this->label15->Font = (gcnew System::Drawing::Font(L"Segoe UI Emoji", 10.25F));
			this->label15->Location = System::Drawing::Point(29, 119);
			this->label15->Name = L"label15";
			this->label15->Size = System::Drawing::Size(68, 19);
			this->label15->TabIndex = 20;
			this->label15->Text = L"Additives:";
			// 
			// label20
			// 
			this->label20->AutoSize = true;
			this->label20->Font = (gcnew System::Drawing::Font(L"Segoe UI Emoji", 10.25F));
			this->label20->Location = System::Drawing::Point(28, 198);
			this->label20->Name = L"label20";
			this->label20->Size = System::Drawing::Size(62, 19);
			this->label20->TabIndex = 25;
			this->label20->Text = L"Solution:";
			// 
			// label21
			// 
			this->label21->AutoSize = true;
			this->label21->Font = (gcnew System::Drawing::Font(L"Segoe UI Emoji", 10.25F));
			this->label21->Location = System::Drawing::Point(155, 198);
			this->label21->Name = L"label21";
			this->label21->Size = System::Drawing::Size(89, 19);
			this->label21->TabIndex = 26;
			this->label21->Text = L"Plate surface:";
			// 
			// maskedTextBox2
			// 
			this->maskedTextBox2->BeepOnError = true;
			this->maskedTextBox2->Location = System::Drawing::Point(214, 92);
			this->maskedTextBox2->Mask = L"00";
			this->maskedTextBox2->Name = L"maskedTextBox2";
			this->maskedTextBox2->Size = System::Drawing::Size(17, 22);
			this->maskedTextBox2->TabIndex = 30;
			this->maskedTextBox2->Text = L"23";
			// 
			// label22
			// 
			this->label22->AutoSize = true;
			this->label22->Font = (gcnew System::Drawing::Font(L"Segoe UI Emoji", 10.25F));
			this->label22->Location = System::Drawing::Point(245, 67);
			this->label22->Name = L"label22";
			this->label22->Size = System::Drawing::Size(25, 19);
			this->label22->TabIndex = 31;
			this->label22->Text = L"g/l";
			// 
			// label23
			// 
			this->label23->AutoSize = true;
			this->label23->Font = (gcnew System::Drawing::Font(L"Segoe UI Emoji", 10.25F));
			this->label23->Location = System::Drawing::Point(245, 92);
			this->label23->Name = L"label23";
			this->label23->Size = System::Drawing::Size(25, 19);
			this->label23->TabIndex = 32;
			this->label23->Text = L"g/l";
			// 
			// maskedTextBox3
			// 
			this->maskedTextBox3->BeepOnError = true;
			this->maskedTextBox3->Location = System::Drawing::Point(249, 197);
			this->maskedTextBox3->Mask = L" 000";
			this->maskedTextBox3->Name = L"maskedTextBox3";
			this->maskedTextBox3->Size = System::Drawing::Size(28, 22);
			this->maskedTextBox3->TabIndex = 33;
			// 
			// label24
			// 
			this->label24->AutoSize = true;
			this->label24->Font = (gcnew System::Drawing::Font(L"Segoe UI Emoji", 10.25F));
			this->label24->Location = System::Drawing::Point(283, 198);
			this->label24->Name = L"label24";
			this->label24->Size = System::Drawing::Size(45, 19);
			this->label24->TabIndex = 34;
			this->label24->Text = L"cm^2";
			// 
			// contextMenuStrip1
			// 
			this->contextMenuStrip1->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(2) {
				this->toolStripMenuItem1,
					this->toolStripMenuItem2
			});
			this->contextMenuStrip1->Name = L"contextMenuStrip1";
			this->contextMenuStrip1->Size = System::Drawing::Size(130, 48);
			// 
			// toolStripMenuItem1
			// 
			this->toolStripMenuItem1->Name = L"toolStripMenuItem1";
			this->toolStripMenuItem1->Size = System::Drawing::Size(129, 22);
			this->toolStripMenuItem1->Text = L"Shift Left";
			this->toolStripMenuItem1->ToolTipText = L"Shifts timeline 1/10 left.";
			// 
			// toolStripMenuItem2
			// 
			this->toolStripMenuItem2->CheckOnClick = true;
			this->toolStripMenuItem2->Name = L"toolStripMenuItem2";
			this->toolStripMenuItem2->Size = System::Drawing::Size(129, 22);
			this->toolStripMenuItem2->Text = L"Shift Right";
			this->toolStripMenuItem2->ToolTipText = L"Shifts timeline 1/10 right.";
			// 
			// label27
			// 
			this->label27->AutoSize = true;
			this->label27->Location = System::Drawing::Point(647, 350);
			this->label27->Name = L"label27";
			this->label27->Size = System::Drawing::Size(44, 15);
			this->label27->TabIndex = 37;
			this->label27->Text = L"label27";
			// 
			// chart1
			// 
			this->chart1->BackColor = System::Drawing::Color::Transparent;
			this->chart1->BorderlineColor = System::Drawing::Color::Transparent;
			chartArea2->AxisY->Enabled = System::Windows::Forms::DataVisualization::Charting::AxisEnabled::True;
			chartArea2->AxisY->Title = L"Temperature";
			chartArea2->AxisY->TitleFont = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Regular,
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(238)));
			chartArea2->AxisY2->Enabled = System::Windows::Forms::DataVisualization::Charting::AxisEnabled::True;
			chartArea2->AxisY2->InterlacedColor = System::Drawing::Color::Red;
			chartArea2->AxisY2->IntervalAutoMode = System::Windows::Forms::DataVisualization::Charting::IntervalAutoMode::VariableCount;
			chartArea2->AxisY2->IntervalOffsetType = System::Windows::Forms::DataVisualization::Charting::DateTimeIntervalType::Number;
			chartArea2->AxisY2->IntervalType = System::Windows::Forms::DataVisualization::Charting::DateTimeIntervalType::Number;
			chartArea2->AxisY2->LineColor = System::Drawing::Color::DarkRed;
			chartArea2->AxisY2->Title = L"pH";
			chartArea2->Name = L"Shared Area";
			this->chart1->ChartAreas->Add(chartArea2);
			this->chart1->Location = System::Drawing::Point(333, 27);
			this->chart1->Name = L"chart1";
			series3->ChartArea = L"Shared Area";
			series3->ChartType = System::Windows::Forms::DataVisualization::Charting::SeriesChartType::Line;
			series3->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(238)));
			series3->Legend = L"Legend1";
			series3->Name = L"dat";
			series4->ChartArea = L"Shared Area";
			series4->ChartType = System::Windows::Forms::DataVisualization::Charting::SeriesChartType::Line;
			series4->Color = System::Drawing::Color::Red;
			series4->Legend = L"Legend1";
			series4->Name = L"dat2";
			series4->YAxisType = System::Windows::Forms::DataVisualization::Charting::AxisType::Secondary;
			this->chart1->Series->Add(series3);
			this->chart1->Series->Add(series4);
			this->chart1->Size = System::Drawing::Size(608, 325);
			this->chart1->TabIndex = 39;
			this->chart1->Text = L"chart1";
			// 
			// buttonUV
			// 
			this->buttonUV->Location = System::Drawing::Point(12, 466);
			this->buttonUV->Name = L"buttonUV";
			this->buttonUV->Size = System::Drawing::Size(88, 23);
			this->buttonUV->TabIndex = 40;
			this->buttonUV->Text = L"Initialize UV";
			this->buttonUV->UseVisualStyleBackColor = true;
			this->buttonUV->Click += gcnew System::EventHandler(this, &MyForm::button5_Click);
			// 
			// maskedTextBox5
			// 
			this->maskedTextBox5->BeepOnError = true;
			this->maskedTextBox5->Location = System::Drawing::Point(214, 70);
			this->maskedTextBox5->Mask = L"00";
			this->maskedTextBox5->Name = L"maskedTextBox5";
			this->maskedTextBox5->Size = System::Drawing::Size(17, 22);
			this->maskedTextBox5->TabIndex = 42;
			// 
			// maskedTextBox6
			// 
			this->maskedTextBox6->BeepOnError = true;
			this->maskedTextBox6->Location = System::Drawing::Point(96, 197);
			this->maskedTextBox6->Mask = L"000";
			this->maskedTextBox6->Name = L"maskedTextBox6";
			this->maskedTextBox6->Size = System::Drawing::Size(23, 22);
			this->maskedTextBox6->TabIndex = 43;
			this->maskedTextBox6->Text = L"200";
			// 
			// label29
			// 
			this->label29->AutoSize = true;
			this->label29->Font = (gcnew System::Drawing::Font(L"Segoe UI Emoji", 10.25F));
			this->label29->Location = System::Drawing::Point(210, 67);
			this->label29->Name = L"label29";
			this->label29->Size = System::Drawing::Size(0, 19);
			this->label29->TabIndex = 46;
			// 
			// label30
			// 
			this->label30->AutoSize = true;
			this->label30->Font = (gcnew System::Drawing::Font(L"Segoe UI Emoji", 10.25F));
			this->label30->Location = System::Drawing::Point(98, 222);
			this->label30->Name = L"label30";
			this->label30->Size = System::Drawing::Size(0, 19);
			this->label30->TabIndex = 47;
			// 
			// label31
			// 
			this->label31->AutoSize = true;
			this->label31->Font = (gcnew System::Drawing::Font(L"Segoe UI Emoji", 10.25F));
			this->label31->Location = System::Drawing::Point(40, 269);
			this->label31->Name = L"label31";
			this->label31->Size = System::Drawing::Size(80, 19);
			this->label31->TabIndex = 48;
			this->label31->Text = L"Water Loss:";
			// 
			// label32
			// 
			this->label32->AutoSize = true;
			this->label32->Font = (gcnew System::Drawing::Font(L"Segoe UI Emoji", 18.25F));
			this->label32->Location = System::Drawing::Point(47, 288);
			this->label32->Name = L"label32";
			this->label32->Size = System::Drawing::Size(63, 33);
			this->label32->TabIndex = 49;
			this->label32->Text = L"0 ml";
			// 
			// button2
			// 
			this->button2->Cursor = System::Windows::Forms::Cursors::Help;
			this->button2->Enabled = false;
			this->button2->Location = System::Drawing::Point(26, 324);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(94, 28);
			this->button2->TabIndex = 50;
			this->button2->Text = L"Replenished";
			this->button2->UseVisualStyleBackColor = true;
			// 
			// label33
			// 
			this->label33->AutoSize = true;
			this->label33->Font = (gcnew System::Drawing::Font(L"Segoe UI Emoji", 26.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label33->Location = System::Drawing::Point(279, 274);
			this->label33->Name = L"label33";
			this->label33->Size = System::Drawing::Size(77, 47);
			this->label33->TabIndex = 51;
			this->label33->Text = L"858";
			// 
			// label34
			// 
			this->label34->AutoSize = true;
			this->label34->Font = (gcnew System::Drawing::Font(L"Segoe UI Emoji", 10.25F));
			this->label34->Location = System::Drawing::Point(204, 296);
			this->label34->Name = L"label34";
			this->label34->Size = System::Drawing::Size(82, 19);
			this->label34->TabIndex = 52;
			this->label34->Text = L"UV Voltage:";
			// 
			// saveFileDialog1
			// 
			this->saveFileDialog1->DefaultExt = L"xls";
			this->saveFileDialog1->FileName = L"L";
			this->saveFileDialog1->Title = L"Export Measured Data";
			// 
			// button4
			// 
			this->button4->Location = System::Drawing::Point(707, 468);
			this->button4->Name = L"button4";
			this->button4->Size = System::Drawing::Size(75, 23);
			this->button4->TabIndex = 53;
			this->button4->Text = L"Update pH";
			this->button4->UseVisualStyleBackColor = true;
			this->button4->Click += gcnew System::EventHandler(this, &MyForm::button4_Click_1);
			// 
			// checkBox1
			// 
			this->checkBox1->AutoSize = true;
			this->checkBox1->Location = System::Drawing::Point(788, 471);
			this->checkBox1->Name = L"checkBox1";
			this->checkBox1->Size = System::Drawing::Size(103, 19);
			this->checkBox1->TabIndex = 54;
			this->checkBox1->Text = L"Keep Updating";
			this->checkBox1->UseVisualStyleBackColor = true;
			// 
			// comboBox1
			// 
			this->comboBox1->AllowDrop = true;
			this->comboBox1->AutoCompleteCustomSource->AddRange(gcnew cli::array< System::String^  >(3) {
				L"Nickel #1", L"Copper #1",
					L"custom..."
			});
			this->comboBox1->AutoCompleteSource = System::Windows::Forms::AutoCompleteSource::ListItems;
			this->comboBox1->Cursor = System::Windows::Forms::Cursors::Hand;
			this->comboBox1->FormattingEnabled = true;
			this->comboBox1->Items->AddRange(gcnew cli::array< System::Object^  >(3) { L"Nickel #1", L"Copper #1", L"custom..." });
			this->comboBox1->Location = System::Drawing::Point(179, 35);
			this->comboBox1->Name = L"comboBox1";
			this->comboBox1->Size = System::Drawing::Size(121, 23);
			this->comboBox1->TabIndex = 55;
			this->comboBox1->Text = L"choose one...";
			this->comboBox1->SelectedIndexChanged += gcnew System::EventHandler(this, &MyForm::comboBox1_SelectedIndexChanged);
			// 
			// label16
			// 
			this->label16->AutoSize = true;
			this->label16->Font = (gcnew System::Drawing::Font(L"Segoe UI Emoji", 8.25F));
			this->label16->Location = System::Drawing::Point(123, 201);
			this->label16->Name = L"label16";
			this->label16->Size = System::Drawing::Size(19, 15);
			this->label16->TabIndex = 58;
			this->label16->Text = L"ml";
			// 
			// comboBox2
			// 
			this->comboBox2->AllowDrop = true;
			this->comboBox2->AutoCompleteCustomSource->AddRange(gcnew cli::array< System::String^  >(3) {
				L"Nickel #1", L"Copper #1",
					L"custom..."
			});
			this->comboBox2->AutoCompleteSource = System::Windows::Forms::AutoCompleteSource::ListItems;
			this->comboBox2->Cursor = System::Windows::Forms::Cursors::Hand;
			this->comboBox2->FormattingEnabled = true;
			this->comboBox2->Items->AddRange(gcnew cli::array< System::Object^  >(4) {
				L"Sodium Acetate", L"Ammonia", L"Rochelle Salt",
					L"Sodium Pyrophosphate"
			});
			this->comboBox2->Location = System::Drawing::Point(104, 118);
			this->comboBox2->Name = L"comboBox2";
			this->comboBox2->Size = System::Drawing::Size(198, 23);
			this->comboBox2->TabIndex = 59;
			this->comboBox2->Text = L"Complexing agent/Buffer";
			// 
			// comboBox3
			// 
			this->comboBox3->AllowDrop = true;
			this->comboBox3->AutoCompleteCustomSource->AddRange(gcnew cli::array< System::String^  >(3) {
				L"Nickel #1", L"Copper #1",
					L"custom..."
			});
			this->comboBox3->AutoCompleteSource = System::Windows::Forms::AutoCompleteSource::ListItems;
			this->comboBox3->Cursor = System::Windows::Forms::Cursors::Hand;
			this->comboBox3->FormattingEnabled = true;
			this->comboBox3->Items->AddRange(gcnew cli::array< System::Object^  >(2) { L"Lead (II) Chloride", L"Maleic Acid" });
			this->comboBox3->Location = System::Drawing::Point(104, 145);
			this->comboBox3->Name = L"comboBox3";
			this->comboBox3->Size = System::Drawing::Size(198, 23);
			this->comboBox3->TabIndex = 60;
			this->comboBox3->Text = L"Stabilizer";
			// 
			// maskedTextBox1
			// 
			this->maskedTextBox1->BeepOnError = true;
			this->maskedTextBox1->Location = System::Drawing::Point(305, 118);
			this->maskedTextBox1->Mask = L"00";
			this->maskedTextBox1->Name = L"maskedTextBox1";
			this->maskedTextBox1->Size = System::Drawing::Size(17, 22);
			this->maskedTextBox1->TabIndex = 61;
			// 
			// label17
			// 
			this->label17->AutoSize = true;
			this->label17->Font = (gcnew System::Drawing::Font(L"Segoe UI Emoji", 10.25F));
			this->label17->Location = System::Drawing::Point(322, 119);
			this->label17->Name = L"label17";
			this->label17->Size = System::Drawing::Size(25, 19);
			this->label17->TabIndex = 62;
			this->label17->Text = L"g/l";
			// 
			// maskedTextBox4
			// 
			this->maskedTextBox4->BeepOnError = true;
			this->maskedTextBox4->Location = System::Drawing::Point(305, 145);
			this->maskedTextBox4->Mask = L"00";
			this->maskedTextBox4->Name = L"maskedTextBox4";
			this->maskedTextBox4->Size = System::Drawing::Size(17, 22);
			this->maskedTextBox4->TabIndex = 63;
			// 
			// label18
			// 
			this->label18->AutoSize = true;
			this->label18->Font = (gcnew System::Drawing::Font(L"Segoe UI Emoji", 10.25F));
			this->label18->Location = System::Drawing::Point(322, 145);
			this->label18->Name = L"label18";
			this->label18->Size = System::Drawing::Size(37, 19);
			this->label18->TabIndex = 64;
			this->label18->Text = L"ppm";
			// 
			// toolTip1
			// 
			this->toolTip1->OwnerDraw = true;
			this->toolTip1->ShowAlways = true;
			this->toolTip1->ToolTipIcon = System::Windows::Forms::ToolTipIcon::Warning;
			this->toolTip1->ToolTipTitle = L"This property is Incorrect for your Bath";
			// 
			// label25
			// 
			this->label25->AutoSize = true;
			this->label25->Enabled = false;
			this->label25->Font = (gcnew System::Drawing::Font(L"Segoe UI Emoji", 6.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label25->Location = System::Drawing::Point(816, 407);
			this->label25->Name = L"label25";
			this->label25->Size = System::Drawing::Size(49, 12);
			this->label25->TabIndex = 68;
			this->label25->Text = L"RA = 27 g/l";
			this->label25->Visible = false;
			// 
			// label26
			// 
			this->label26->AutoSize = true;
			this->label26->Font = (gcnew System::Drawing::Font(L"Segoe UI Emoji", 14.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label26->Location = System::Drawing::Point(203, 270);
			this->label26->Name = L"label26";
			this->label26->Size = System::Drawing::Size(54, 26);
			this->label26->TabIndex = 69;
			this->label26->Text = L"Bath:";
			// 
			// button5
			// 
			this->button5->Enabled = false;
			this->button5->Location = System::Drawing::Point(156, 271);
			this->button5->Name = L"button5";
			this->button5->Size = System::Drawing::Size(49, 45);
			this->button5->TabIndex = 70;
			this->button5->Text = L"Refill";
			this->button5->UseVisualStyleBackColor = true;
			this->button5->Click += gcnew System::EventHandler(this, &MyForm::button5_Click_1);
			// 
			// MyForm
			// 
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Inherit;
			this->AutoSize = true;
			this->BackColor = System::Drawing::Color::Snow;
			this->ClientSize = System::Drawing::Size(939, 516);
			this->Controls->Add(this->button5);
			this->Controls->Add(this->label26);
			this->Controls->Add(this->label25);
			this->Controls->Add(this->label18);
			this->Controls->Add(this->maskedTextBox4);
			this->Controls->Add(this->label17);
			this->Controls->Add(this->maskedTextBox1);
			this->Controls->Add(this->comboBox3);
			this->Controls->Add(this->comboBox2);
			this->Controls->Add(this->label16);
			this->Controls->Add(this->comboBox1);
			this->Controls->Add(this->checkBox1);
			this->Controls->Add(this->button4);
			this->Controls->Add(this->label34);
			this->Controls->Add(this->label33);
			this->Controls->Add(this->button2);
			this->Controls->Add(this->label32);
			this->Controls->Add(this->label31);
			this->Controls->Add(this->label30);
			this->Controls->Add(this->label29);
			this->Controls->Add(this->maskedTextBox6);
			this->Controls->Add(this->maskedTextBox5);
			this->Controls->Add(this->buttonUV);
			this->Controls->Add(this->chart1);
			this->Controls->Add(this->label27);
			this->Controls->Add(this->label24);
			this->Controls->Add(this->maskedTextBox3);
			this->Controls->Add(this->label23);
			this->Controls->Add(this->label22);
			this->Controls->Add(this->maskedTextBox2);
			this->Controls->Add(this->label21);
			this->Controls->Add(this->label20);
			this->Controls->Add(this->label15);
			this->Controls->Add(this->label14);
			this->Controls->Add(this->label13);
			this->Controls->Add(this->label12);
			this->Controls->Add(this->label11);
			this->Controls->Add(this->label10);
			this->Controls->Add(this->label8);
			this->Controls->Add(this->label9);
			this->Controls->Add(this->label7);
			this->Controls->Add(this->statusStrip1);
			this->Controls->Add(this->button3);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->label6);
			this->Controls->Add(this->label5);
			this->Controls->Add(this->label4);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->menuStrip1);
			this->Cursor = System::Windows::Forms::Cursors::Default;
			this->Font = (gcnew System::Drawing::Font(L"Segoe UI Emoji", 8.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->ForeColor = System::Drawing::SystemColors::ControlDarkDark;
			this->Icon = (cli::safe_cast<System::Drawing::Icon^>(resources->GetObject(L"$this.Icon")));
			this->Location = System::Drawing::Point(65, 110);
			this->MainMenuStrip = this->menuStrip1;
			this->Name = L"MyForm";
			this->StartPosition = System::Windows::Forms::FormStartPosition::Manual;
			this->Text = L"Autocatalytic Plating Interface";
			this->FormClosing += gcnew System::Windows::Forms::FormClosingEventHandler(this, &MyForm::MyForm_FormClosing);
			this->menuStrip1->ResumeLayout(false);
			this->menuStrip1->PerformLayout();
			this->statusStrip1->ResumeLayout(false);
			this->statusStrip1->PerformLayout();
			this->contextMenuStrip1->ResumeLayout(false);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->chart1))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}

		//************************************************************************************************************************************************************
		//************************************************************************************************************************************************************
		//************************************************************************************************************************************************************
		//************************************************************************************************************************************************************
		//************************************************************************************************************************************************************
		//************************************************************************************************************************************************************
	private: System::Void timer1_Tick(System::Object^  sender, System::EventArgs^  e)  //runs each 200ms
	{
		ProgramCounter++;
		label1:
		if (StatusLoop() == 1)
		{
			GlobalCounter++;
			TransmitData();
			if (comerror == 1)
			{
				timer1->Enabled = false;
				while (MessageBox::Show("Couldn't open ComPort. Check connections and try again.", "Connection Error", MessageBoxButtons::OK, MessageBoxIcon::Warning) != System::Windows::Forms::DialogResult::OK);
				GlobalCounter--;
				status = 0;
				timer1->Enabled = true;
				goto label1;
			}
			 
			ConvertDispData();
			
			label33->Text = System::Convert::ToString(uv);										//UV RAW
			label1->Text = System::Convert::ToString(dispTemp);									//temperature DISP
	/*x*/	label27->Text = System::Convert::ToString(temperature);								//ANY TEST VARIABLE GOES HERE 
			if(pHavg < 7 && pHavg > 4)
				label10->Text = System::Convert::ToString(dispphosph) + " %";//phosphorus content
			else {
				if (pHdepPhosph == 1 ) //STUPIDEST WAY TO DISPLAY THIS, AINT GONNA GET PAID FOR THIS SO WHY TO THINK TOO MUCH?
					label10->Text = System::Convert::ToString("LP");
				if(pHdepPhosph == 2)
					label10->Text = System::Convert::ToString("MP");
				if(pHdepPhosph == 3)
					label10->Text = System::Convert::ToString("HP");
			}
				
			if (checkBox1->Checked == TRUE)														//pH DISP
			{
				label2->Text = System::Convert::ToString(disppH);
				if (disppH > 10)
					label2->Location = Point(415, 355);
				else
					label2->Location = Point(455, 355); //CONFIGURE THIS
				IsPhGraph = TRUE;
			}
			label9->Text = System::Convert::ToString(dispperc) + " %";							//percentage DISP
			label7->Text = System::Convert::ToString(dispgperl) + "g/l";						//concentration DISP
			label3->Text = System::Convert::ToString(dispthickness) + " um";					//thickness DISP
			label25->Text = System::Convert::ToString(RAdisp) + "g/l";
			//EXPERIMENTAL DATA
		/*	
			
		*/	
			if ((int)GlobalCounter % 2 == 0 && GlobalCounter != 0)
			{
				this->chart1->Series["dat"]->Points->AddXY((int)(GlobalCounter / 2), dispTemp);//, dispTemp);  //graph temp
				if (IsPhGraph == TRUE)
				{
					this->chart1->Series["dat2"]->Points->AddXY((int)(GlobalCounter / 2), disppH); //graph pH
				}
				
				if ((int)(GlobalCounter / 2) % 600 == 0)											//starts removing after 600 writtings
				{
					this->chart1->Series["dat"]->Points->Clear();
					this->chart1->Series["dat2"]->Points->Clear();
					
					//this->chart1->Series["dat"]->Points->RemoveAt(DataDeleter);
					//DataDeleter = DataDeleter + 1;
					//This is the graph reset part, DataBindXY and RemoveAt functions should be used instead of clear, that neverthless doesnt work because of unidentified error in config files
				}
			}
			
			/*label2->Text = System::Convert::ToString((float)pH / 22.571);*/
			
		}
		ExportData();
		
		if (filerror == 1)
			MessageBox::Show("Couldn't open File.", "File Open Error", MessageBoxButtons::OK, MessageBoxIcon::Warning);
		 IsPhGraph = FALSE; //end 
	}
		//************************************************************************************************************************************************************
		 //************************************************************************************************************************************************************
     	//************************************************************************************************************************************************************
		//************************************************************************************************************************************************************
		//************************************************************************************************************************************************************
		 //************************************************************************************************************************************************************
		//************************************************************************************************************************************************************
		//************************************************************************************************************************************************************
		//************************************************************************************************************************************************************
		//************************************************************************************************************************************************************


private: System::Void exitToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) { //************************//
		 if (MessageBox::Show("Do you really want to exit? \n You might want to export the data..", "Closure", MessageBoxButtons::YesNo, MessageBoxIcon::Question) == System::Windows::Forms::DialogResult::Yes)
			 Application::Exit();
	}
	//Controls
	//Buttons
private: System::Void button3_Click(System::Object^  sender, System::EventArgs^  e) {				//************************//	//Start Button
	if (IsInitialized == FALSE)
		if (MessageBox::Show("Spectrometer must be initialized before executing the program. Do you want to continue without initialization?", "Initialization Error", MessageBoxButtons::YesNo, MessageBoxIcon::Exclamation) == System::Windows::Forms::DialogResult::No)
			goto skip;
	status = 1; //code for start
	this->maskedTextBox5->Enabled = FALSE;
	this->maskedTextBox2->Enabled = FALSE;
	this->maskedTextBox3->Enabled = FALSE;
	this->maskedTextBox6->Enabled = FALSE;
	this->maskedTextBox1->Enabled = FALSE;
	this->maskedTextBox4->Enabled = FALSE;
	this->comboBox2->Enabled = FALSE;
	this->comboBox3->Enabled = FALSE;
	skip:;
}
private: System::Void button1_Click(System::Object^  sender, System::EventArgs^  e) {				//************************////Pause Button
	status = 2; //code for pause
}

private: System::Void menuStrip1_ItemClicked(System::Object^  sender, System::Windows::Forms::ToolStripItemClickedEventArgs^  e) {  //Open Existing data&&&&&&&&&&
}

		 //PROBABLY DOESNT EXIST
private: System::Void button4_Click(System::Object^  sender, System::EventArgs^  e) {				//************************////Initializes data for pH
	
	//char *temporarystringtwo = (char*)Marshal::StringToHGlobalAnsi(temporarytwo).ToPointer(); //look for using namespace System::Runtime::InteropServices;
	

	if (RS232_OpenComport(3, 38400, "8N1"))//open comport: n; baudrate n; 8N1- 8bits, no parity, 1 stopbit, write error if occur
		MessageBox::Show("Couldn't open ComPort", "Connection Error", MessageBoxButtons::OK, MessageBoxIcon::Warning); //warn user of not initialization

	

	RS232_SendByte(3, 'X'); //sends byte X to obtain the pH data
		for (double i = 0; i < 1200000; i++) //waits for response and loads data
		{
			if (RS232_PollComport(3, Tbuf, 10))
			{
				Tbuf[3] = (Tbuf[3] << 1) >> 1; //correctment
				pHinit = (float)(((unsigned int)Tbuf[2]) | (((unsigned int)Tbuf[3]) << 8)); //pH
				
				MessageBox::Show("pH initialized", "Success", MessageBoxButtons::OK, MessageBoxIcon::Information);

				RS232_CloseComport(3);
				break;
			}
				

		}

}
private: System::Void MyForm_FormClosing(System::Object^  sender, System::Windows::Forms::FormClosingEventArgs^  e) {	//************************//
	if (MessageBox::Show("Do you really want to exit? \n You might want to export the data..", "Closure", MessageBoxButtons::YesNo, MessageBoxIcon::Question) == System::Windows::Forms::DialogResult::Yes)
		Application::Exit();
	else
		e->Cancel = true;

}
private: System::Void button5_Click(System::Object^  sender, System::EventArgs^  e) {									//************************//

	String ^ temporaryone = maskedTextBox5->Text; //concentration
	char *temporarystring = (char*)Marshal::StringToHGlobalAnsi(temporaryone).ToPointer();//this translates string to char array //look for using namespace System::Runtime::InteropServices;
	label29->Text = temporaryone;
	String ^ temporaryone1 = maskedTextBox6->Text; //solution volume
	char *temporarystring1 = (char*)Marshal::StringToHGlobalAnsi(temporaryone1).ToPointer();
	String ^ temporaryone2 = maskedTextBox3->Text; //plate area
	char *temporarystring2 = (char*)Marshal::StringToHGlobalAnsi(temporaryone2).ToPointer();
	String ^ temporaryone3 = maskedTextBox2->Text; //reducing agent concentration
	char *temporarystring3 = (char*)Marshal::StringToHGlobalAnsi(temporaryone3).ToPointer();

	

	if (RS232_OpenComport(3, 38400, "8N1"))//open comport: n; baudrate n; 8N1- 8bits, no parity, 1 stopbit, write error if occur
		MessageBox::Show("Couldn't open ComPort", "Connection Error", MessageBoxButtons::OK, MessageBoxIcon::Information); //warn user of not initialization



	RS232_SendByte(3, 'X'); //sends byte X to obtain the pH data
	for (double i = 0; i < 1200000; i++) //waits for response and loads data
	{
		if (RS232_PollComport(3, Tbuf, 10))
		{
			Tbuf[6] = (Tbuf[6] &0b11); //correctment
			UVinit = ((unsigned int)Tbuf[5]) | (((unsigned int)Tbuf[6]) << 8);
			
			ConcGiven = (float)atoi(temporarystring);
			SolVol = (float)atoi(temporarystring1);
			PlateArea = (float)atoi(temporarystring2);
			RA = atoi(temporarystring3);
			if ((SolVol == 0) || (ConcGiven == 0) || (PlateArea == 0))
			{
				MessageBox::Show("Please initialize values for Volume, UV and area correctly.", "Initialization Error", MessageBoxButtons::OK, MessageBoxIcon::Warning);
				break;
			}

			toolStripStatusLabel3->Text = "UV Initialized";
			maskedTextBox5->Enabled = false;
			maskedTextBox6->Enabled = false;
			maskedTextBox3->Enabled = false;
			maskedTextBox2->Enabled = false;
			//label30->Text = System::Convert::ToString(SolVol * 10) + " ml";
			MessageBox::Show("UV initialized", "Success", MessageBoxButtons::OK, MessageBoxIcon::Warning);
			RS232_CloseComport(3);
			IsInitialized = TRUE;
			break;
		}


	}
	
}
private: System::Void notesToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {

	NotesDialog^ ND = gcnew NotesDialog();
	ND->ShowDialog();

}
private: System::Void exportToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {
	saveFileDialog1->ShowDialog();
	String ^ temporaryonesave = saveFileDialog1->FileName; //solution volume
	char *temporarystringsave = (char*)Marshal::StringToHGlobalAnsi(temporaryonesave).ToPointer();

	if(temporarystringsave[0] != 'L')
			ExportTo(temporarystringsave);

}
private: System::Void button4_Click_1(System::Object^  sender, System::EventArgs^  e) {
	label2->Text = System::Convert::ToString(disppH);
	IsPhGraph = TRUE;
}
private: System::Void comboBox1_SelectedIndexChanged(System::Object^  sender, System::EventArgs^  e) {

	String ^ temporarys = comboBox1->Text; //
	char *temporarystring = (char*)Marshal::StringToHGlobalAnsi(temporarys).ToPointer();//this translates string to char array

	if (strcmp(temporarystring, "Nickel #1") == 0)
	{
		MessageBox::Show("Yeaaah", "Yeaah", MessageBoxButtons::OK, MessageBoxIcon::Warning);
		this->label13->Text= System::Convert::ToString("Nickel Sulphate •5H2O:");
		this->label14->Text = System::Convert::ToString("Sodium Hypophosphite:");
		this->comboBox1->Enabled = FALSE;
	}
	else {
		if (strcmp(temporarystring, "Copper #1") == 0)
		{
			//stuff to happen for nickel, lock combobox1
		}
		else {
			if (strcmp(temporarystring, "custom...") == 0)
			{
				//stuff to happen for nickel, lock combobox1
			}
			else
				MessageBox::Show("The input is invalid. Choose from the above.", "Invalid Input", MessageBoxButtons::OK, MessageBoxIcon::Warning);
		}
	}
}
private: System::Void helpToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {
	system("help.txt"); //open help //system() is function for executing cmd commands
}
private: System::Void button5_Click_1(System::Object^  sender, System::EventArgs^  e) {
	//comming in further releases
}
};
}
//FILE 2****************************************************************************************
#pragma endregion


int TransmitData() //returns 2 error codes or 0 if fine: 1==cant open poll,2 cant send,3==not received 
{

	//RS232section
	if (RS232_OpenComport(3, 38400, "8N1"))
		comerror = 1;
	else comerror = 0;//open comport: n; baudrate n; 8N1- 8bits, no parity, 1 stopbit, write error if occur
		
	
	RS232_SendByte(3, 'X');					//RS232_cputs(3, "X");

	for (double i = 0; i < 1200000; i++)
	{
		if (RS232_PollComport(3, Tbuf, 10))
		{
			break;
		}
	}

	Tbuf[1] = (Tbuf[1] & 0b11);     //correctment process
	temperature = ((unsigned int)Tbuf[0]) | (((unsigned int)Tbuf[1] &0b11) << 8); //temperature, same correctment cuz it looks good

	Tbuf[3] = (Tbuf[3] & 0b11);     //correctment
	pH = ((unsigned int)Tbuf[2]) | (((unsigned int)Tbuf[3]) << 8); //pH
	/**/
	/**/
	if (Tbuf[4] == 1)
		IsToReceive = 1;
	else
		IsToReceive = 0;
	Tbuf[6] = (Tbuf[6] & 0b11); //correctment
	uv = ((unsigned int)Tbuf[5]) | (((unsigned int)Tbuf[6]) << 8);
	/**/
	/**/
	if (Tbuf[4]==1)
	{
		Tbuf[6] = (Tbuf[6] & 0b11); //correctment
		uv = ((unsigned int)Tbuf[5]) | (((unsigned int)Tbuf[6]) << 8);  //concentration
	}


	RS232_CloseComport(3);

	return 0;
}//281

void ConvertDispData()//add errors to out of range data
{
	float tperc;
	//
	//BASIC
	disppH = ((float) (int)((-0.0208696 * (pH - 1023) + 1.8087 ) * 10)) /10;  //where form of y = mx + b is empirically y = 0.02608696x + 1.8087 and x is 
	if (temperature > 494)													//for temperature greater than 48 degs C
		dispTemp = int(-0.08219178*temperature + 82.9);//21/134
	else																	//for temperature more than 48 degs C		unused://!manuálne zvýši faktor! additional factor must be set by / 19.8 = 794 | 54 = 430 this seems to be correct for linear scope y = -34.2/364*x+94.401
		dispTemp = int(-0.1567*temperature + 114+1);
	if (dispTemp > 70 && dispTemp<80)
		disppH = disppH + 0.3;
	else {
		if (dispTemp > 50 && dispTemp < 70)
			disppH = disppH + 0.2;
		else {
			if (dispTemp > 80 && dispTemp < 85)
				disppH = disppH + 0.4;
			if (dispTemp > 85)
				disppH = disppH + 0.5;
			}
		}
	//
	//Advanced Here it gets messy /////271
	if (IsToReceive) {
		 
		dispperc = (int)((float)(-0.370370*uv + 132.22211)/ ((float)(-0.370370*UVinit + 132.22211)) * 100);			//INITIALIZE THE VALUE EXPERIMENTALLY ONLY THISS
		tperc = (float)(-0.370370*uv + 132.22211) / (float)(-0.370370*UVinit + 132.22211) * 100;
																													//Correcting statement
		dispgperl = ((int)(ConcGiven * (tperc / 100)));				//

		//RAdisp = int(RA /(dispperc/100 * 1.27)); //for each 1 gram of NiSO4(hexahydrate) deposited, 1.2137 grams of Sodium Hypophosphite(monohydrate) are consumed
						//other reducing agents are not supported yet, new version, new me
		dispthickness = (int)((((ConcGiven - dispgperl)/1000) * SolVol) / (8.908 * PlateArea) * 10000);//is cm without *10000 to, Should work if the percentage is geven correctly 
	}														//very inacurate SolVol in ml, conc in g
	//phosphorus content

	if (pHavg == 0)
		pHavg = disppH;
	else
	{
		pHavg = (pHavg + disppH) / 2;				//average pH so far
		if (pHavg < 4)								//if pH value is in non-measurable region, display expected deposit properties
			pHdepPhosph = 1;//HP					THE STUPIDEST WAY TO DO THIS, THO IT WORKS
		else {
			if (pHavg < 7)
				dispphosph = 0;		
			//The definite pH function
			else {
				if (pHavg < 9.4)					//further approximate
					pHdepPhosph = 2; //MP
				else
					pHdepPhosph = 3;//LP
			}
		}
		
	}
}

int StatusLoop()
{
	
	return status;
}

void ExportData()
{
	//
	//first time run
	if ((int)ProgramCounter == 1)
	{
		FILE *fprim = fopen("BasicQuantities.xls", "w");
		
		if (fprim == NULL)
			filerror = 1;
		else
			filerror = 0;

		fprintf(fprim, "1/2Time\tT(°C)\t\tpH\t\tUV\n");
		fclose(fprim);
	}
	//
	//real writting
	if (StatusLoop() == 1)
	{
		FILE *fdat = fopen("BasicQuantities.xls", "a");
		fprintf(fdat, "%lf\t\t%f\t\t%f\t\t%d\n",(INT32)GlobalCounter, dispTemp, disppH, uv);
		fclose(fdat);
	}
}

void ExportTo(char *target_file)
{
	char ch;
	FILE *source = fopen("BasicQuantities.xls", "r");
	FILE *target = fopen(target_file, "w");
	if (target_file[0] == NULL);
	else {
		while ((ch = fgetc(source)) != EOF)
			fputc(ch, target);
	}
	fclose(source);
	fclose(target);
	

}

