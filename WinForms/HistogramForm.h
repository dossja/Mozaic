#pragma once

namespace WinForms {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for HistogramForm
	/// </summary>
	public ref class HistogramForm : public System::Windows::Forms::Form
	{
	public:
		array<int>^ tabColor = gcnew array<int>(256);

		HistogramForm(void)
		{
			InitializeComponent();
		}

		HistogramForm(array<int>^ tab, System::Drawing::Color c)
		{
			InitializeComponent();
			for (int i = 0; i < 256; i++)
			{
				this->tabColor[i] = tab[i];
			}
			this->C_HistogramRGB->PaletteCustomColors = gcnew cli::array< System::Drawing::Color >(1) { c };
			this->C_HistogramRGB->Series[0]->Points->Clear();

			for (int i = 0; i < 256; i++)
			{
				this->C_HistogramRGB->Series[0]->Points->AddXY(i, tabColor[i]);
			}
			//this->label1->Text = text;
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~HistogramForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Button^  BTN_ZamknijOkno;
	private: System::Windows::Forms::DataVisualization::Charting::Chart^  C_HistogramRGB;




	protected:

	protected:

	protected:

	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>
		System::ComponentModel::Container ^components;


#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			System::Windows::Forms::DataVisualization::Charting::ChartArea^  chartArea1 = (gcnew System::Windows::Forms::DataVisualization::Charting::ChartArea());
			System::Windows::Forms::DataVisualization::Charting::Series^  series1 = (gcnew System::Windows::Forms::DataVisualization::Charting::Series());
			this->BTN_ZamknijOkno = (gcnew System::Windows::Forms::Button());
			this->C_HistogramRGB = (gcnew System::Windows::Forms::DataVisualization::Charting::Chart());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->C_HistogramRGB))->BeginInit();
			this->SuspendLayout();
			// 
			// BTN_ZamknijOkno
			// 
			this->BTN_ZamknijOkno->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(0)),
				static_cast<System::Int32>(static_cast<System::Byte>(80)));
			this->BTN_ZamknijOkno->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
			this->BTN_ZamknijOkno->ForeColor = System::Drawing::Color::Silver;
			this->BTN_ZamknijOkno->Location = System::Drawing::Point(450, 558);
			this->BTN_ZamknijOkno->Name = L"BTN_ZamknijOkno";
			this->BTN_ZamknijOkno->Size = System::Drawing::Size(128, 44);
			this->BTN_ZamknijOkno->TabIndex = 0;
			this->BTN_ZamknijOkno->Text = L"Zamknij";
			this->BTN_ZamknijOkno->UseVisualStyleBackColor = false;
			this->BTN_ZamknijOkno->Click += gcnew System::EventHandler(this, &HistogramForm::BTN_ZamknijOkno_Click);
			// 
			// C_HistogramRGB
			// 
			this->C_HistogramRGB->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(0)),
				static_cast<System::Int32>(static_cast<System::Byte>(8)));
			this->C_HistogramRGB->BorderlineColor = System::Drawing::Color::Transparent;
			chartArea1->AxisX->IsMarginVisible = false;
			chartArea1->AxisX->LabelStyle->ForeColor = System::Drawing::Color::White;
			chartArea1->AxisX->LineColor = System::Drawing::Color::White;
			chartArea1->AxisX->MajorGrid->LineColor = System::Drawing::Color::White;
			chartArea1->AxisX->MajorTickMark->LineColor = System::Drawing::Color::White;
			chartArea1->AxisY->LabelStyle->ForeColor = System::Drawing::Color::White;
			chartArea1->AxisY->LineColor = System::Drawing::Color::White;
			chartArea1->AxisY->MajorGrid->LineColor = System::Drawing::Color::White;
			chartArea1->AxisY->MajorTickMark->LineColor = System::Drawing::Color::White;
			chartArea1->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(64)), static_cast<System::Int32>(static_cast<System::Byte>(64)),
				static_cast<System::Int32>(static_cast<System::Byte>(64)));
			chartArea1->Name = L"ChartArea1";
			this->C_HistogramRGB->ChartAreas->Add(chartArea1);
			this->C_HistogramRGB->Location = System::Drawing::Point(12, 12);
			this->C_HistogramRGB->Name = L"C_HistogramRGB";
			this->C_HistogramRGB->Palette = System::Windows::Forms::DataVisualization::Charting::ChartColorPalette::None;
			this->C_HistogramRGB->PaletteCustomColors = gcnew cli::array< System::Drawing::Color >(3) {
				System::Drawing::Color::Red, System::Drawing::Color::Green,
					System::Drawing::Color::Blue
			};
			series1->ChartArea = L"ChartArea1";
			series1->ChartType = System::Windows::Forms::DataVisualization::Charting::SeriesChartType::SplineArea;
			series1->Name = L"Color";
			this->C_HistogramRGB->Series->Add(series1);
			this->C_HistogramRGB->Size = System::Drawing::Size(562, 562);
			this->C_HistogramRGB->TabIndex = 9;
			this->C_HistogramRGB->Click += gcnew System::EventHandler(this, &HistogramForm::C_HistogramRGB_Click);
			// 
			// HistogramForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(0)),
				static_cast<System::Int32>(static_cast<System::Byte>(8)));
			this->BackgroundImageLayout = System::Windows::Forms::ImageLayout::None;
			this->ClientSize = System::Drawing::Size(622, 622);
			this->Controls->Add(this->BTN_ZamknijOkno);
			this->Controls->Add(this->C_HistogramRGB);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::None;
			this->Name = L"HistogramForm";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"HistogramForm";
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->C_HistogramRGB))->EndInit();
			this->ResumeLayout(false);

		}
#pragma endregion
	private: System::Void BTN_ZamknijOkno_Click(System::Object^  sender, System::EventArgs^  e) {
		HistogramForm::Close();
	}
	private: System::Void C_HistogramRGB_Click(System::Object^  sender, System::EventArgs^  e) {
	}
};
}
