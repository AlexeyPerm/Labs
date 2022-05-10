#pragma once
#include "fact.h"

namespace Project3 {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Сводка для MyForm
	/// </summary>
	public ref class MyForm : public System::Windows::Forms::Form {
	public:
		MyForm(void) {
			InitializeComponent();
			//
			//TODO: добавьте код конструктора
			//
		}

	protected:
		/// <summary>
		/// Освободить все используемые ресурсы.
		/// </summary>
		~MyForm() {
			if (components) {
				delete components;
			}
		}
	private: System::Windows::Forms::Button^ I;
	protected:

	private: System::Windows::Forms::Button^ V;
	protected:

	private: System::Windows::Forms::Button^ X;

	private: System::Windows::Forms::Button^ button4;
	private: System::Windows::Forms::Button^ button5;
	private: System::Windows::Forms::Button^ button6;
	private: System::Windows::Forms::Button^ button7;
	private: System::Windows::Forms::Button^ button8;
	private: System::Windows::Forms::Button^ button9;
	private: System::Windows::Forms::Button^ button10;
	private: System::Windows::Forms::Button^ button11;
	private: System::Windows::Forms::Button^ button12;
	private: System::Windows::Forms::Button^ button13;
	private: System::Windows::Forms::Button^ button14;
	private: System::Windows::Forms::Button^ button15;
	private: System::Windows::Forms::Button^ result;

	private: System::Windows::Forms::TextBox^ textBox1;
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::Button^ button1;


	private: System::Windows::Forms::TextBox^ num1;
	private: System::Windows::Forms::TextBox^ num2;





	protected:

	private:
		/// <summary>
		/// Обязательная переменная конструктора.
		/// </summary>
		System::ComponentModel::Container^ components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Требуемый метод для поддержки конструктора — не изменяйте 
		/// содержимое этого метода с помощью редактора кода.
		/// </summary>
		void InitializeComponent(void) {
			this->I = (gcnew System::Windows::Forms::Button());
			this->V = (gcnew System::Windows::Forms::Button());
			this->X = (gcnew System::Windows::Forms::Button());
			this->button4 = (gcnew System::Windows::Forms::Button());
			this->button5 = (gcnew System::Windows::Forms::Button());
			this->button6 = (gcnew System::Windows::Forms::Button());
			this->button7 = (gcnew System::Windows::Forms::Button());
			this->button8 = (gcnew System::Windows::Forms::Button());
			this->button9 = (gcnew System::Windows::Forms::Button());
			this->button10 = (gcnew System::Windows::Forms::Button());
			this->button11 = (gcnew System::Windows::Forms::Button());
			this->button12 = (gcnew System::Windows::Forms::Button());
			this->button13 = (gcnew System::Windows::Forms::Button());
			this->button14 = (gcnew System::Windows::Forms::Button());
			this->button15 = (gcnew System::Windows::Forms::Button());
			this->result = (gcnew System::Windows::Forms::Button());
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->num1 = (gcnew System::Windows::Forms::TextBox());
			this->num2 = (gcnew System::Windows::Forms::TextBox());
			this->SuspendLayout();
			// 
			// I
			// 
			this->I->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 15.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->I->Location = System::Drawing::Point(12, 107);
			this->I->Name = L"I";
			this->I->Size = System::Drawing::Size(36, 31);
			this->I->TabIndex = 1;
			this->I->Text = L"I";
			this->I->UseVisualStyleBackColor = true;
			this->I->Click += gcnew System::EventHandler(this, &MyForm::I_Click);
			// 
			// V
			// 
			this->V->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 15.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->V->Location = System::Drawing::Point(65, 107);
			this->V->Name = L"V";
			this->V->Size = System::Drawing::Size(36, 31);
			this->V->TabIndex = 2;
			this->V->Text = L"V";
			this->V->UseVisualStyleBackColor = true;
			this->V->Click += gcnew System::EventHandler(this, &MyForm::button1_Click);
			// 
			// X
			// 
			this->X->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 15.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->X->Location = System::Drawing::Point(123, 107);
			this->X->Name = L"X";
			this->X->Size = System::Drawing::Size(36, 31);
			this->X->TabIndex = 3;
			this->X->Text = L"X";
			this->X->UseVisualStyleBackColor = true;
			this->X->Click += gcnew System::EventHandler(this, &MyForm::button3_Click);
			// 
			// button4
			// 
			this->button4->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->button4->Location = System::Drawing::Point(178, 107);
			this->button4->Name = L"button4";
			this->button4->Size = System::Drawing::Size(36, 31);
			this->button4->TabIndex = 4;
			this->button4->Text = L"<-\r\n";
			this->button4->UseVisualStyleBackColor = true;
			// 
			// button5
			// 
			this->button5->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 15.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->button5->Location = System::Drawing::Point(236, 107);
			this->button5->Name = L"button5";
			this->button5->Size = System::Drawing::Size(36, 31);
			this->button5->TabIndex = 5;
			this->button5->Text = L"+";
			this->button5->UseVisualStyleBackColor = true;
			// 
			// button6
			// 
			this->button6->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 15.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->button6->Location = System::Drawing::Point(236, 162);
			this->button6->Name = L"button6";
			this->button6->Size = System::Drawing::Size(36, 31);
			this->button6->TabIndex = 10;
			this->button6->Text = L"-";
			this->button6->UseVisualStyleBackColor = true;
			// 
			// button7
			// 
			this->button7->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 15.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->button7->Location = System::Drawing::Point(178, 162);
			this->button7->Name = L"button7";
			this->button7->Size = System::Drawing::Size(36, 31);
			this->button7->TabIndex = 9;
			this->button7->Text = L"M";
			this->button7->UseVisualStyleBackColor = true;
			// 
			// button8
			// 
			this->button8->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 15.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->button8->Location = System::Drawing::Point(123, 162);
			this->button8->Name = L"button8";
			this->button8->Size = System::Drawing::Size(36, 31);
			this->button8->TabIndex = 8;
			this->button8->Text = L"D";
			this->button8->UseVisualStyleBackColor = true;
			// 
			// button9
			// 
			this->button9->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 15.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->button9->Location = System::Drawing::Point(65, 162);
			this->button9->Name = L"button9";
			this->button9->Size = System::Drawing::Size(36, 31);
			this->button9->TabIndex = 7;
			this->button9->Text = L"C";
			this->button9->UseVisualStyleBackColor = true;
			// 
			// button10
			// 
			this->button10->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 15.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->button10->Location = System::Drawing::Point(12, 162);
			this->button10->Name = L"button10";
			this->button10->Size = System::Drawing::Size(36, 31);
			this->button10->TabIndex = 6;
			this->button10->Text = L"L";
			this->button10->UseVisualStyleBackColor = true;
			// 
			// button11
			// 
			this->button11->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 15.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->button11->Location = System::Drawing::Point(236, 219);
			this->button11->Name = L"button11";
			this->button11->Size = System::Drawing::Size(36, 31);
			this->button11->TabIndex = 15;
			this->button11->Text = L"*";
			this->button11->UseVisualStyleBackColor = true;
			// 
			// button12
			// 
			this->button12->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 15.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->button12->Location = System::Drawing::Point(178, 219);
			this->button12->Name = L"button12";
			this->button12->Size = System::Drawing::Size(36, 31);
			this->button12->TabIndex = 14;
			this->button12->Text = L"/";
			this->button12->UseVisualStyleBackColor = true;
			// 
			// button13
			// 
			this->button13->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 15.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->button13->Location = System::Drawing::Point(123, 219);
			this->button13->Name = L"button13";
			this->button13->Size = System::Drawing::Size(36, 31);
			this->button13->TabIndex = 13;
			this->button13->Text = L"%";
			this->button13->UseVisualStyleBackColor = true;
			// 
			// button14
			// 
			this->button14->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 15.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->button14->Location = System::Drawing::Point(65, 219);
			this->button14->Name = L"button14";
			this->button14->Size = System::Drawing::Size(36, 31);
			this->button14->TabIndex = 12;
			this->button14->Text = L"C";
			this->button14->UseVisualStyleBackColor = true;
			// 
			// button15
			// 
			this->button15->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 15.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->button15->Location = System::Drawing::Point(12, 219);
			this->button15->Name = L"button15";
			this->button15->Size = System::Drawing::Size(36, 31);
			this->button15->TabIndex = 11;
			this->button15->Text = L"©";
			this->button15->UseVisualStyleBackColor = true;
			// 
			// result
			// 
			this->result->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 27.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->result->Location = System::Drawing::Point(236, 32);
			this->result->Name = L"result";
			this->result->Size = System::Drawing::Size(52, 47);
			this->result->TabIndex = 16;
			this->result->Text = L"=";
			this->result->UseVisualStyleBackColor = true;
			// 
			// textBox1
			// 
			this->textBox1->Location = System::Drawing::Point(24, 32);
			this->textBox1->Multiline = true;
			this->textBox1->Name = L"textBox1";
			this->textBox1->Size = System::Drawing::Size(190, 47);
			this->textBox1->TabIndex = 17;
			this->textBox1->TextChanged += gcnew System::EventHandler(this, &MyForm::textBox1_TextChanged);
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label1->Location = System::Drawing::Point(40, 287);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(175, 20);
			this->label1->TabIndex = 18;
			this->label1->Text = L"Введите целое число";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label2->Location = System::Drawing::Point(40, 350);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(61, 20);
			this->label2->TabIndex = 19;
			this->label2->Text = L"Ответ:";
			// 
			// button1
			// 
			this->button1->FlatStyle = System::Windows::Forms::FlatStyle::System;
			this->button1->Location = System::Drawing::Point(156, 396);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(194, 30);
			this->button1->TabIndex = 21;
			this->button1->Text = L"Вычислить факториал";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &MyForm::button2_Click);
			// 
			// num1
			// 
			this->num1->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->num1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 15.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->num1->Location = System::Drawing::Point(272, 271);
			this->num1->Multiline = true;
			this->num1->Name = L"num1";
			this->num1->Size = System::Drawing::Size(171, 36);
			this->num1->TabIndex = 22;
			// 
			// num2
			// 
			this->num2->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->num2->Location = System::Drawing::Point(272, 327);
			this->num2->Multiline = true;
			this->num2->Name = L"num2";
			this->num2->Size = System::Drawing::Size(171, 43);
			this->num2->TabIndex = 23;
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(551, 469);
			this->Controls->Add(this->num2);
			this->Controls->Add(this->num1);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->textBox1);
			this->Controls->Add(this->result);
			this->Controls->Add(this->button11);
			this->Controls->Add(this->button12);
			this->Controls->Add(this->button13);
			this->Controls->Add(this->button14);
			this->Controls->Add(this->button15);
			this->Controls->Add(this->button6);
			this->Controls->Add(this->button7);
			this->Controls->Add(this->button8);
			this->Controls->Add(this->button9);
			this->Controls->Add(this->button10);
			this->Controls->Add(this->button5);
			this->Controls->Add(this->button4);
			this->Controls->Add(this->X);
			this->Controls->Add(this->V);
			this->Controls->Add(this->I);
			this->MaximizeBox = false;
			this->Name = L"MyForm";
			this->Text = L"Факториал";
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void button3_Click(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void I_Click(System::Object^ sender, System::EventArgs^ e) {

	}
	private: System::Void textBox1_TextChanged(System::Object^ sender, System::EventArgs^ e) {

	}
	private: System::Void button2_Click(System::Object^ sender, System::EventArgs^ e) {
		int number = System::Convert::ToDouble(num1->Text);
		double factor = fact(number);
		num2->Text = System::Convert::ToString(factor);
	}
private: System::Void label3_Click(System::Object^ sender, System::EventArgs^ e) {
}
};
}
