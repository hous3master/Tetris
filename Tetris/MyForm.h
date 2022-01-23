#pragma once
#include "Grid.h"
namespace Tetris {

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
			objGame = new Grid();
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
	private: System::Windows::Forms::Timer^ timer1;
	protected:
	private: System::ComponentModel::IContainer^ components;
	private: System::Windows::Forms::Label^ scorelabel;
	private: System::Windows::Forms::Label^ next_tetraminolabel;
	private: System::Windows::Forms::Button^ button1;
	private: System::Windows::Forms::Button^ button2;
	private: System::Windows::Forms::Button^ button3;
	private: System::Windows::Forms::ComboBox^ comboBox1;


	private:
		Grid* objGame;
	private: System::Windows::Forms::Label^ label1;

		   Color Game_Color;


#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			this->components = (gcnew System::ComponentModel::Container());
			this->timer1 = (gcnew System::Windows::Forms::Timer(this->components));
			this->scorelabel = (gcnew System::Windows::Forms::Label());
			this->next_tetraminolabel = (gcnew System::Windows::Forms::Label());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->button3 = (gcnew System::Windows::Forms::Button());
			this->comboBox1 = (gcnew System::Windows::Forms::ComboBox());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->SuspendLayout();
			// 
			// timer1
			// 
			this->timer1->Interval = 300;
			this->timer1->Tick += gcnew System::EventHandler(this, &MyForm::timer1_Tick);
			// 
			// scorelabel
			// 
			this->scorelabel->BackColor = System::Drawing::Color::Gold;
			this->scorelabel->Enabled = false;
			this->scorelabel->Font = (gcnew System::Drawing::Font(L"Arial Rounded MT Bold", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->scorelabel->Location = System::Drawing::Point(632, 366);
			this->scorelabel->Name = L"scorelabel";
			this->scorelabel->Size = System::Drawing::Size(138, 97);
			this->scorelabel->TabIndex = 0;
			this->scorelabel->Text = L"SCORE:\r\n#####";
			this->scorelabel->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			this->scorelabel->UseCompatibleTextRendering = true;
			this->scorelabel->Visible = false;
			// 
			// next_tetraminolabel
			// 
			this->next_tetraminolabel->BackColor = System::Drawing::Color::Gold;
			this->next_tetraminolabel->Enabled = false;
			this->next_tetraminolabel->Font = (gcnew System::Drawing::Font(L"Arial Rounded MT Bold", 9, System::Drawing::FontStyle::Regular,
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			this->next_tetraminolabel->Location = System::Drawing::Point(632, 46);
			this->next_tetraminolabel->Name = L"next_tetraminolabel";
			this->next_tetraminolabel->Size = System::Drawing::Size(138, 43);
			this->next_tetraminolabel->TabIndex = 1;
			this->next_tetraminolabel->Text = L"Next tetramino:";
			this->next_tetraminolabel->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			this->next_tetraminolabel->UseCompatibleTextRendering = true;
			this->next_tetraminolabel->Visible = false;
			// 
			// button1
			// 
			this->button1->BackColor = System::Drawing::Color::Gold;
			this->button1->Font = (gcnew System::Drawing::Font(L"Arial Rounded MT Bold", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->button1->Location = System::Drawing::Point(230, 145);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(267, 57);
			this->button1->TabIndex = 2;
			this->button1->Text = L"Play";
			this->button1->UseVisualStyleBackColor = false;
			this->button1->Click += gcnew System::EventHandler(this, &MyForm::button1_Click);
			// 
			// button2
			// 
			this->button2->BackColor = System::Drawing::SystemColors::Highlight;
			this->button2->Font = (gcnew System::Drawing::Font(L"Arial Rounded MT Bold", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->button2->Location = System::Drawing::Point(230, 243);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(267, 57);
			this->button2->TabIndex = 3;
			this->button2->Text = L"BG Options";
			this->button2->UseVisualStyleBackColor = false;
			this->button2->Click += gcnew System::EventHandler(this, &MyForm::button2_Click);
			// 
			// button3
			// 
			this->button3->BackColor = System::Drawing::SystemColors::ControlDark;
			this->button3->Font = (gcnew System::Drawing::Font(L"Arial Rounded MT Bold", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->button3->Location = System::Drawing::Point(288, 500);
			this->button3->Name = L"button3";
			this->button3->Size = System::Drawing::Size(156, 57);
			this->button3->TabIndex = 4;
			this->button3->Text = L"Quit";
			this->button3->UseVisualStyleBackColor = false;
			this->button3->Click += gcnew System::EventHandler(this, &MyForm::button3_Click);
			// 
			// comboBox1
			// 
			this->comboBox1->BackColor = System::Drawing::SystemColors::GradientActiveCaption;
			this->comboBox1->DropDownStyle = System::Windows::Forms::ComboBoxStyle::DropDownList;
			this->comboBox1->Enabled = false;
			this->comboBox1->FormattingEnabled = true;
			this->comboBox1->ItemHeight = 16;
			this->comboBox1->Items->AddRange(gcnew cli::array< System::Object^  >(5) {
				L"White", L"Light Gray", L"Red", L"Dark Green",
					L"Gold"
			});
			this->comboBox1->Location = System::Drawing::Point(230, 306);
			this->comboBox1->Name = L"comboBox1";
			this->comboBox1->Size = System::Drawing::Size(267, 24);
			this->comboBox1->TabIndex = 6;
			this->comboBox1->Visible = false;
			this->comboBox1->SelectedIndexChanged += gcnew System::EventHandler(this, &MyForm::comboBox1_SelectedIndexChanged);
			// 
			// label1
			// 
			this->label1->BackColor = System::Drawing::Color::PaleTurquoise;
			this->label1->Font = (gcnew System::Drawing::Font(L"Arial", 10.2F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label1->Location = System::Drawing::Point(145, 354);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(443, 125);
			this->label1->TabIndex = 7;
			this->label1->Text = L"-Move tetraminos with KEY ARROWS(LEFT / RIGHT)\r\n-Rotate tetraminos with SPACE\r\n-M"
				L"ake tetraminos fall faster with DOWN KEY";
			this->label1->TextAlign = System::Drawing::ContentAlignment::MiddleLeft;
			this->label1->UseCompatibleTextRendering = true;
			// 
			// MyForm
			// 
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::None;
			this->BackColor = System::Drawing::SystemColors::AppWorkspace;
			this->ClientSize = System::Drawing::Size(782, 600);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->comboBox1);
			this->Controls->Add(this->button3);
			this->Controls->Add(this->button2);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->next_tetraminolabel);
			this->Controls->Add(this->scorelabel);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedSingle;
			this->MaximumSize = System::Drawing::Size(800, 800);
			this->MinimumSize = System::Drawing::Size(600, 600);
			this->Name = L"MyForm";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"Tetris";
			this->KeyDown += gcnew System::Windows::Forms::KeyEventHandler(this, &MyForm::MyForm_KeyDown);
			this->ResumeLayout(false);

		}
#pragma endregion
	private: System::Void timer1_Tick(System::Object^ sender, System::EventArgs^ e) {
		
		//BACKGROUND, BUFFER AND CONFIG
		Graphics^ g = CreateGraphics();
		BufferedGraphicsContext^ space = BufferedGraphicsManager::Current;
		BufferedGraphics^ bf = space->Allocate(g, ClientRectangle);
		if (comboBox1->SelectedIndex.Equals(-1)) Game_Color = Color::White;
		bf->Graphics->Clear(Game_Color);

		//EXECUTION
		if (objGame->Time_Acceleration())
			timer1->Interval = 30;
		else
			timer1->Interval = 300;
		if (objGame->Top_Row_Is_Occupied()) {
			button3->Visible = true;
			button3->Enabled = true;
			timer1->Enabled = false;
		}
			
		objGame->Insert_Tetramino();
		objGame->Set_Tetramino();
		objGame->Clean_Last_Row();
		objGame->Draw_Tetramino(bf->Graphics);

		objGame->Draw_Visuals(bf->Graphics);
		scorelabel->Text = objGame->Return_Points();

		bf->Render(g);
		delete bf, space, g;
	}
	private: System::Void MyForm_KeyDown(System::Object^ sender, System::Windows::Forms::KeyEventArgs^ e) {
		if (e->KeyCode == Keys::Space) objGame->Rotate_Tetramino();
		if (e->KeyCode == Keys::Right) objGame->Translate_Tetramino(direction::right);
		if (e->KeyCode == Keys::Left) objGame->Translate_Tetramino(direction::left);
		if (e->KeyCode == Keys::Down) objGame->Press_Key_Down();
	}
	private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e) {
		scorelabel->Visible = true;
		scorelabel->Enabled = true;
		next_tetraminolabel->Visible = true;
		next_tetraminolabel->Enabled = true;

		button1->Visible = false;
		button1->Enabled = false;
		button2->Visible = false;
		button2->Enabled = false;
		button3->Visible = false;
		button3->Enabled = false;
		label1->Visible = false;
		label1->Enabled = false;

		comboBox1->Visible = false;
		comboBox1->Enabled = false;

		timer1->Enabled = true;
	}
private: System::Void label1_Click(System::Object^ sender, System::EventArgs^ e) {
}
private: System::Void button2_Click(System::Object^ sender, System::EventArgs^ e) {
	comboBox1->Visible = true;
	comboBox1->Enabled = true;
}
private: System::Void comboBox1_SelectedIndexChanged(System::Object^ sender, System::EventArgs^ e) {
	if (comboBox1->SelectedIndex.Equals(1)) Game_Color = Color::LightGray;
	else if (comboBox1->SelectedIndex.Equals(2)) Game_Color = Color::Red;
	else if (comboBox1->SelectedIndex.Equals(3)) Game_Color = Color::DarkGreen;
	else if (comboBox1->SelectedIndex.Equals(4)) Game_Color = Color::Gold;
	else Game_Color = Color::White;
}
private: System::Void button3_Click(System::Object^ sender, System::EventArgs^ e) {
	Close();
}
}; 

}
