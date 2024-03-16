#pragma once
#include<Windows.h>
#include"Admin.h"
using namespace std;

void Welcome(Admin* admin, Student* student);
void Administrator(Admin* admin, Student* student);
void Edit_Admin_Data(Admin* admin, Student* student);
void Admin_Work(Admin* admin, Student* student);

///////////

void Work_with_Students(Admin* admin, Student* student);
void show_all_students_stat(Admin* admin);
void choose_current_student(Admin* admin, Student* student);
void show_reg_data_current_student(list <Student*>::iterator it, Admin* admin, Student* student);
void show_rez_test_current_student(list <Student*>::iterator it, Admin* admin, Student* Student);
void add_fake_rezult(list <Student*>::iterator it, Admin* admin, Student* student);
void Print_all_students_fio();
void Print_selected_question_with_answers(Question* selected_question, Rezult_of_Test* rezult);

///////////

void Work_with_Tests(Admin* admin, Student* student);
void work_with_sections(Admin* admin, Student* student);
void work_with_subsections(Admin* admin, Student* student);
void work_with_tests(Admin* admin, Student* student);
Test* choose_test(Admin* admin, Student* student);
void Print_all_sections();
Subsection* Print_all_subsections(list <Section*>::iterator& section, Admin* admin, Student* student);
void Print_all_tests(Admin* admin, Student* student);
Test* Print_all_tests_in_subsection(Subsection* position, Admin* admin, Student* student);
void Add_tests_and_change_tests(Admin* admin, Student* student);
void change_current_test(Admin* admin, vector<Test*>& temp_tests, Student* student);
void change_questions_in_test(Test* current_test, Admin* admin, vector<Test*>& temp_tests);
void change_selected_questions_in_test(Test* current_test, Admin* admin, vector<Test*>& temp_tests, int num_of_quest);
void add_test(Test* current_test, Admin* admin, vector<Test*>& temp_tests, Student* student);
void add_question_in_test(Test* current_test, Admin* admin, vector<Test*>& temp_tests);
void set_fake_answers(Admin* admin, Rezult_of_Test* fake_rezult, Test* selected_test);


///////////

void User(Admin* admin, Student* student);
void User_info(Admin* admin, Student* student);
void show_current_student_stat(Admin* admin, Student* current_stud);
void take_the_test(Admin* admin, Student* current_stud, Test*& waiting_test);

///////////


int main()
{
	setlocale(0, "");
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	Admin* admin = new Admin;
	Student* student = new Student;

	Welcome(admin, student);

	delete admin;
	delete student;
	return 0;
}
void Welcome(Admin* admin, Student* student)
{
	int choice;
	do
	{
		cout << "Добро пожаловать! Выберите режим работы: \n"
			<< "1. Администратор\n" << "2. Тестируемый\n" << "3. Выход\n";
		cin >> choice;
		system("cls");
		switch (choice)
		{
		case 1:
			Administrator(admin,student);
			break;
		case 2:
			User(admin,student);
			break;
		case 3:
			exit(0);
		default:
			break;
		}
	} while (choice != 3);
}
void Administrator(Admin* admin, Student* student)
{
	int choice;
	string login;
	string password;
	if (admin->Get_Admin_is_admin() == false)
	{
		do
		{
			cout << "1. Регистрация администратора в системе\n"
				<< "2. Назад в главное меню\n";
			cin >> choice;
			system("cls");
			switch (choice)
			{
			case 1:
				admin->Registration();
				system("cls");
				Admin_Work(admin, student);
				break;
			default:
				break;
			}
		} while (choice != 2);
	}
	if (admin->Get_Admin_is_admin() == true)
	{
		do
		{

			cout << "1. Пройти аутентификацию (введите логин и пароль)\n"
				<< "2. В главное меню\n"<< "3. Выход из программы\n";
			cin >> choice;
			system("cls");
			switch (choice)
			{
			case 1:
				do
				{
					cout << "Введите логин: \n";
					cin >> login;
					cout << "Введите пароль: \n";
					cin >> password;
				} while (admin->Enter(login, password) == false);
				system("cls");
				Admin_Work(admin,student);
				break;
			case 2:
				Welcome(admin,student);
				break;
			case 3:
				exit(0);
				break;
			default:
				break;
			}
		} while (choice != 3);
	}
}
void Admin_Work(Admin* admin, Student* student)
{
	int choice;
	do
	{
		cout << "1. Работа со студентами\n"
			<< "2. Работа с тестами\n"
			<< "3. Редактировать данные админа\n"
			<< "4. Выход из системы\n";
		cin >> choice;
		system("cls");
		switch (choice)
		{
		case 1:
			Work_with_Students(admin,student);
			break;
		case 2:
			Work_with_Tests(admin, student);
			break;
		case 3:
			Edit_Admin_Data(admin,student);
			break;
		case 4:
			system("cls");
			Administrator(admin,student);
			break;
		default:
			break;
		}
	} while (choice < 1 || choice > 4);
}
void Edit_Admin_Data(Admin* admin, Student* student)
{
	int choice;
	string tmp;
	do
	{
		cout << "Данные администратора: " << endl;
		cout << "1. ФИО: " << admin->Get_Admin_fio() << "\n2. Адрес: " << admin->Get_Admin_adress()
			<< "\n3. Номер телефона: " << admin->Get_Admin_phone_number() << "\n"
			<< "4. Логин: " << admin->Get_Admin_Decode_login() << "\n" << "5. Пароль: " << admin->Get_Admin_Decode_password() << "\n6. Назад";
		cout << "\nЧто будем редактировать?\n";
		cin >> choice;
		system("cls");
		switch (choice)
		{

		case 1:
			cout << "Введите ФИО:\n";
			cin.ignore(256, '\n');
			getline(cin, tmp);
			admin->Set_Admin_name(tmp);
			system("cls");
			Edit_Admin_Data(admin,student);
			break;
		case 2:
			cout << "Введите адрес:\n";
			cin.ignore(256, '\n');
			getline(cin, tmp);
			admin->Set_Admin_adress(tmp);
			system("cls");
			Edit_Admin_Data(admin,student);
			break;
		case 3:
			cout << "Введите номер телефона:\n";
			cin.ignore(256, '\n');
			getline(cin, tmp);
			admin->Set_Admin_phonenumber(tmp);
			system("cls");
			Edit_Admin_Data(admin,student);
			break;
		case 4:
			cout << "Введите логин:\n";
			cin.ignore(256, '\n');
			getline(cin, tmp);
			admin->Set_Admin_login(tmp);
			system("cls");
			Edit_Admin_Data(admin,student);
			break;
		case 5:
			cout << "Введите пароль:\n";
			cin.ignore(256, '\n');
			getline(cin, tmp);
			admin->Set_Admin_password(tmp);
			system("cls");
			Edit_Admin_Data(admin,student);
		case 6:
			system("cls");
			Admin_Work(admin, student);
		default:
			break;
		}
	} while (choice < 1 || choice > 6);
}

////////////////

void Work_with_Students(Admin* admin, Student* student)
{
	int choice;
	int tmp;
	main:
	do
	{
		Print_all_students_fio();
		cout << "1. Посмотреть статистику по всем студентам\n"
			<< "2. Выгрузить статистику и инфо по всем студентам в файл\n"
			<< "3. Добавить студента\n" << "4. Удалить студента\n"
			<< "\t\t\tИЛИ\n" << "5. Выбрать конкретного студента\n" << "6. Назад\n";
		cin >> choice;
		system("cls");
		switch (choice)
		{
		case 1:
			try
			{
				show_all_students_stat(admin);
			}
			catch (const char* ex)
			{
				cout << ex << "\n\n\n\n";
				Sleep(1000);
				system("cls");
				goto main;
			}
			Work_with_Students(admin, student);
			break;
		case 2:
			try
			{
				admin->Exp_to_file_All_Students_Stat();
				Sleep(1000);
				system("cls");
			}
			catch (const char* ex)
			{
				cout << ex << "\n\n\n\n";
				goto main;
			}
			catch (...)
			{
				cout << "Неверный выбор! Введите значение снова\n";
				goto main;
			}
			Work_with_Students(admin, student);
			break;
		case 3:
			admin->Add_Student();
			system("cls");
			Work_with_Students(admin, student);
			break;
		case 4:
			try
			{
				if (All_Students.empty())
				{
					cout << "List IS EMPTY!!!";
					goto main;
				}
				Print_all_students_fio();
				cout << "Выберите студета: \n";
				cin >> tmp;
				admin->Del_Student(tmp);
				system("cls");
				Work_with_Students(admin, student);
			}
			catch (const char* ex)
			{
				cout << ex << "\n\n\n\n";
				goto main;
			}
			catch (...)
			{
				cout << "Неверный выбор! Введите значение снова\n";
				goto main;
			}
			break;
		case 5:
			try
			{
				system("cls");
				choose_current_student(admin,student);
			}
			catch (const char* ex)
			{
				cout << ex << "\n\n\n\n";
				goto main;
			}
			break;
		case 6:
			system("cls");
			Admin_Work(admin, student);
			break;
		default:
			break;
		}
	} while (choice < 1 || choice > 6);

}
void show_all_students_stat(Admin* admin)
{
	system("cls");
	list <Student*>::const_iterator it = All_Students.begin();

	if (All_Students.empty()) throw "List is EMPTY!!!";
	
	for (int i = 0; it != All_Students.end(); ++it, ++i)
	{
		Student* current_student = (*it);
		
		cout << i + 1 << ". " << (*it)->Get_Stud_FIO() << endl;
		
		cout << "Количество сданных тестов: " << admin->Get_All_Passed_Tests(current_student) << endl;
		cout << "Количество не сданных тестов: " << admin->Get_All_Failed_Tests(current_student) << endl;
		cout << "Количество тестов, ожидающих завершение: " << admin->Get_All_Waiting_Tests(current_student) << endl;
		for (size_t j = 0; j < (*it)->Get_Stud_Rez().size(); ++j)
		{

			if (!(*it)->Get_Stud_Rez()[j]->Get_Question_and_Answers().empty())
			{
				cout << "\tРаздел: " << (*it)->Get_Stud_Rez()[j]->Get_Current_Test()->Get_Name_of_Section() << endl;
				cout << "\tПодраздел: " << (*it)->Get_Stud_Rez()[j]->Get_Current_Test()->Get_Name_of_Subsection() << endl;
				cout << "\tНазвание теста: " << (*it)->Get_Stud_Rez()[j]->Get_Current_Test()->Get_Name_of_Test() << endl;
				cout << "\tКоличество правильных ответов: " << (*it)->Get_Stud_Rez()[j]->Get_Quant_of_Right_Answers() << endl;
				cout << "\tРезультат: " << (*it)->Get_Stud_Rez()[j]->Get_Rezult_Message() << endl;
				cout << "\tОценка: " << (*it)->Get_Stud_Rez()[j]->Get_Score() << endl;
				if ((*it)->Get_Stud_Rez()[j]->Get_Current_Test()->Get_Mark_is_Finished())
					cout << "\tТест завершен." << endl;
				else
					cout << "\tТест не завершен." << endl;
			}
			else
				cout << "\t" << "Student doesn`t have rezults!!!\n" << std::endl;
		}
	}
	cout << "\n\n";
	system("pause");
	system("cls");
	
}
void choose_current_student(Admin* admin, Student* student)
{
	size_t ch1;
	size_t ch2;
	if (All_Students.empty()) 
		throw "List is EMPTY!!!";
	
	do
	{
		Print_all_students_fio();
		cout << (All_Students.size() + 1) << ". Назад\n\n";
		cout << "Выберите номер студента в списке: \n";
		cin >> ch1;

		if (ch1 == (All_Students.size() + 1))
		{
			system("cls");
			Work_with_Students(admin, student);
		}
		system("cls");
	} while ((ch1-1) < 0 || (ch1-1) > All_Students.size());
	
	list <Student*>::iterator it = All_Students.begin();
	advance(it, (ch1 - 1));
	do
	{
		cout << (*it)->Get_Stud_FIO() << "\n\n";
		cout << "1. Посмотреть регистрационные данные студента\n"
			<< "2. Поcмотреть результаты тестирования\n" << "3. Назад\n";
		cin >> ch2;
		system("cls");
		switch (ch2)
		{
		case 1:
			try
			{
				show_reg_data_current_student(it, admin, student);
			}
			catch (const exception& ex)
			{
				cout << ex.what();
			}
			break;
		case 2:
			show_rez_test_current_student(it, admin, student);
			break;
		case 3:
			system("cls");
			Work_with_Students(admin,student);
			break;
		default:
			break;
		}
	} while (ch2 < 1 || ch2 > 3);


}
void show_reg_data_current_student(list <Student*>::iterator it, Admin* admin, Student* student)
{
	int choice;
	string tmp;

	size_t id_student = admin->Set_Account_find_student(it);
	vector <AccountsInfo*>::iterator itu = Users.begin();
	advance(itu, id_student);
	
	cout << "ФИО: " << (*it)->Get_Stud_FIO() << "\nДомашний адрес: " << (*it)->Get_Stud_HomAddr()
		<< "\nТелефон: " << (*it)->Get_Stud_Pnumber() << "\nЛогин: " << admin->Decode_login((*itu)->Get_AccInfo_logs_and_pass().first)
		<< "\nПароль: " << admin->Decode_password((*itu)->Get_AccInfo_logs_and_pass().second) << "\n\n";
again:
	do
	{
		cout << "1. Изменить ФИО\n" << "2. Изменить домашний адрес\n" << "3. Изменить телефон\n"
			<< "4. Изменить логин\n" << "5. Изменить пароль\n" << "6. Назад\n";
		cin >> choice;
		system("cls");
		switch (choice)
		{
		case 1:
			cout << "Введите ФИО: \n";
			cin.ignore(256, '\n');
			getline(cin, tmp);
			system("cls");
			admin->Set_Student_fio((*it), tmp);
			show_reg_data_current_student(it, admin, student);
			break;
		case 2:
			cout << "Введите домашний адрес: \n";
			cin.ignore(256, '\n');
			getline(cin, tmp);
			system("cls");
			admin->Set_Student_adress((*it), tmp);
			show_reg_data_current_student(it, admin, student);
			break;
		case 3:
			cout << "Введите телефон: \n";
			cin.ignore(256, '\n');
			getline(cin, tmp);
			system("cls");
			admin->Set_Student_phone_number((*it), tmp);
			show_reg_data_current_student(it, admin, student);
			break;
		case 4:
		
			try
			{
				cout << "Введите логин: \n";
				cin.ignore(256, '\n');
				getline(cin, tmp);
				system("cls");
				admin->Set_Account_login(itu, tmp);
				show_reg_data_current_student(it, admin, student);
			}
			catch (const char* ex)
			{
				cout << ex << "\n\n\n\n";
				goto again;
			}
			break;
		case 5:
			cout << "Введите пароль: \n";
			cin.ignore(256, '\n');
			getline(cin, tmp);
			system("cls");
			admin->Set_Account_password(itu, tmp);
			show_reg_data_current_student(it, admin,student);
			break;
		case 6:
			system("cls");
			choose_current_student(admin,student);
			break;
		default:
			break;
		}
	} while (choice < 1 || choice > 6);
}
void show_rez_test_current_student(list <Student*>::iterator it, Admin* admin, Student* student)
{
	size_t ch1;
	int ch2;
	bool tmp_rez;
	string tmp_msg;
	size_t tmp;

	if ((*it)->Get_Stud_Rez()[0]->Get_Current_Test() == nullptr)
	{
		int choice;
		main:
		do
		{
			cout << "Student doesn`t have rezults!!!\n\n";
			cout << "1. Добавить липовый результат\n"
				 << "2. Назад\n";
			cin >> choice;
			system("cls");
			switch (choice)
			{
			case 1:
				try
				{
					add_fake_rezult(it, admin, student);
				}
				catch (const char* ex)
				{
					cout << ex << "\n\n\n\n";
					goto main;
				}
				break;
			case 2:
				system("cls");
				choose_current_student(admin, student);
				break;
			default:
				break;
			}
		} while (choice < 1 || choice > 2);
	}
	
	cout << (*it)->Get_Stud_FIO() << "\n\nРезультаты: \n";
	for (size_t i = 0; i < (*it)->Get_Stud_Rez().size(); ++i)
	{
		cout << i + 1 << ". Название теста: " << (*it)->Get_Stud_Rez()[i]->Get_Current_Test()->Get_Name_of_Test() << "\n" << "\tКоличество вопросов : " <<
			(*it)->Get_Stud_Rez()[i]->Get_Current_Test()->Get_Quant_of_Questions() << "\n" << "\tКоличество правильных ответов: " <<
			(*it)->Get_Stud_Rez()[i]->Get_Quant_of_Right_Answers() << "\n" << "\tВаша оценка: " << (*it)->Get_Stud_Rez()[i]->Get_Score()
			<< "\n" << "\tВаш результат: " << (*it)->Get_Stud_Rez()[i]->Get_Rezult_Message() << "\n\n\n";
	}
	do
	{
		do
		{
			cout << "Выберите тест из списка:\n" << "(0. Назад)\n";
			cin >> ch1;
			if (ch1 == 0)
			{
				system("cls");
				choose_current_student(admin,student);
			}
			
		} while ((ch1 - 1) < 0 || (ch1 - 1) > (*it)->Get_Stud_Rez().size());
		
		Test* cur_test = (*it)->Get_Stud_Rez()[ch1 - 1]->Get_Current_Test();
		system("cls");
		do
		{
			cout << "1. Изменить количество правильных ответов\n" << "2. Изменить оценку\n" << "3. Изменить результат\n"
				<< "4. Назад\n";
			cin >> ch2;
			system("cls");
			switch (ch2)
			{
			case 1:
				cout << "Введите количество правильных ответов: \n";
				cin >> tmp;
				admin->Set_Rezults_quant_of_Rig_Answ((*it)->Get_Stud_Rez()[ch1 - 1], tmp);
				system("cls");
				show_rez_test_current_student(it, admin, student);
				break;
			case 2:
				cout << "Введите оценку: \n";
				cin >> tmp;
				admin->Set_Rezults_score((*it)->Get_Stud_Rez()[ch1 - 1], tmp);
				system("cls");
				show_rez_test_current_student(it, admin, student);
				break;
			case 3:
				cout << "Введите сообщение о результате: \n";
				cin.ignore(256, '\n');
				getline(cin, tmp_msg);
				system("cls");
				admin->Set_Rezults_messg_rezult((*it)->Get_Stud_Rez()[ch1 - 1], tmp_msg);
				cout << "Введите флаг результа СДАЛ = 1, НЕСДАЛ = 0: \n";
				cin >> tmp_rez;
				admin->Set_Rezults_flag_rezult((*it)->Get_Stud_Rez()[ch1 - 1], tmp_rez);
				system("cls");
				show_rez_test_current_student(it, admin, student);
				break;
			case 4:
				system("cls");
				show_rez_test_current_student(it, admin, student);
				break;
			default:
				break;
			}
		} while (ch2 < 1 || ch2 > 4);
	} while ((ch1 - 1) < 0 || (ch1 - 1) > (*it)->Get_Stud_Rez().size());
}
void add_fake_rezult(list <Student*>::iterator it, Admin* admin, Student* student)
{
	Test* selected_test;
	Rezult_of_Test* fake_rezult = new Rezult_of_Test;
	int choice;
	do
	{
		if (All_Tests.empty())
		{
			delete fake_rezult;
			throw "List Is EMPTY!!!\tДобавьте хотя бы 1 тест в БД Тестов!";
		}
		do
		{
			cout << "1. Добавить тест из списка к липовому результату\n"
				 << "2. Назад\n";
			cin >> choice;
		} while (choice < 1 || choice > 2);
		switch (choice)
		{
		case 1:
			selected_test = choose_test(admin, student);
			admin->Set_Rezults_current_test(fake_rezult, selected_test);
			set_fake_answers(admin, fake_rezult, selected_test);
			admin->Set_Rezults_quant_of_Rig_Answ(fake_rezult, selected_test->Get_Quant_of_Questions());
			fake_rezult->Calculate_Score(selected_test, fake_rezult);
			admin->Set_Rezults_flag_rezult(fake_rezult, true);
			admin->Set_Rezults_add_rezult(fake_rezult, (*it));

			system("cls");
			show_rez_test_current_student(it, admin, student);
			break;
		case 2:
			system("cls");
			choose_current_student(admin, student);
			break;
		default:
			break;
		}
	} while (true);
}
Test* choose_test(Admin* admin, Student* student)
{
	list <Section*>::const_iterator it = All_Tests.begin();
	size_t choice;
	int ch_test;
	for (int i = 0; it != All_Tests.end(); ++it, ++i)
	{
		cout << "Разделы: \n";
		cout << i + 1 << ". " << (*it)->Get_Name_of_Section() << endl;
	}
	cout << "\nВыберите раздел: \n";
	cin >> choice;
	it = All_Tests.begin();
	advance(it, (choice - 1));
	for (size_t i = 0; i < (*it)->Get_Subsections().size(); ++i)
	{
		cout << "Подразделы: \n";
		cout << i + 1 << ". " << (*it)->Get_Subsections()[i]->Get_Name_of_Subsection() << endl;
		
	}
	cout << "\nВыберите подраздел: \n";
	cin >> choice;
	
	for (size_t i = 0; i < (*it)->Get_Subsections()[choice - 1]->Get_Tests().size(); ++i)
	{
		cout << "Тесты: \n";
		cout << i + 1 << ". " << (*it)->Get_Subsections()[choice - 1]->Get_Tests()[i]->Get_Name_of_Test() << endl;
	}
	cout << "\nВыберите тест: \n";
	cin >> ch_test;
	Test* selected_test = (*it)->Get_Subsections()[choice - 1]->Get_Tests()[ch_test - 1];
	return selected_test;
}
void Print_all_students_fio()
{
	if (!All_Students.empty())
		cout << "\t\tСтуденты:\n";
	std::list <Student*>::const_iterator it = All_Students.begin();
	int i = 0;
	for (; it != All_Students.end(); ++it)
	{
		std::cout << i + 1 << ". " << (*it)->Get_Stud_FIO() << std::endl;
		++i;
	}
	cout << "\n\n\n";
}
void Print_selected_question_with_answers(Question* selected_question, Rezult_of_Test* rezult)
{
	std::pair<size_t, size_t> correct_and_stud_answers;

	std::map <Question*, std::pair<size_t, size_t>>::const_iterator it = rezult->Get_Question_and_Answers().begin();
	for (; it != rezult->Get_Question_and_Answers().end(); ++it)
	{
		if ((*it).first == selected_question)
		{
			correct_and_stud_answers.first = (*it).second.first;
			correct_and_stud_answers.second = (*it).second.second;
		}
		else
		{
			throw "Студент не оветил ни на один вопрос!!!";
		}
	}

	cout << selected_question->Get_Name_of_Question() << "\n";
	for (size_t i = 0; i < selected_question->Get_Options().size(); ++i)
	{
		cout << "\t" << i + 1 << ". " << selected_question->Get_Options()[i] << "\n";
		cout << "\tПравильный ответ: " << correct_and_stud_answers.first;
		cout << "\tОтвет студента: " << correct_and_stud_answers.second;
	}
}

////////////////

void Work_with_Tests(Admin* admin, Student* student)
{
	
	int choice;
	do
	{
		cout << "1. Просмотр разделов\n"
			 << "2. Просмотр подразделов в разделе\n"
			 << "3. Просмотр тестов\n"
			 << "4. Назад\n";
		cin >> choice;
		system("cls");
		switch (choice)
		{
		case 1:
			work_with_sections(admin,student);
			break;
		case 2:
			work_with_subsections(admin,student);
			break;
		case 3:
			work_with_tests(admin,student);
			break;
		case 4:
			Admin_Work(admin, student);
			system("cls");
			break;
		default:
			break;
		}
		} while (choice < 1 || choice > 4);
}
void work_with_sections(Admin* admin, Student* student)
{
	int choice;
	int num;
	string tmp;
	list <Section*>::iterator section = All_Tests.begin();
	system("cls");
	main:
	do
	{
		Print_all_sections();

		cout << "1. Изменить имя раздела\n"
			 << "2. Удалить раздел\n"
			 << "3. Добавить раздел\n"
			 << "4. Выгрузить разделы в файл\n"
			 << "5. Назад\n";
		cin >> choice;
		system("cls");
		switch (choice)
		{
		case 1:
			if (All_Tests.empty())
			{
				system("cls");
				cout << "List IS EMPTY!!!";
				goto main;
			}
			system("cls");
			Print_all_sections();
			cout << "Введите номер раздела: \n";
			cin >> num;
			advance(section, (num - 1));

			cout << "Введите название раздела: \n";
			cin.ignore(256, '\n');
			getline(cin, tmp);
			system("cls");
			admin->Set_Section_name((*section), tmp);
			work_with_sections(admin,student);
			break;
		case 2:
			try
			{
				if (All_Tests.empty())
				{
					system("cls");
					cout << "List IS EMPTY!!!";
					goto main;
				}
				Print_all_sections();
				cout << "Выберите номер раздела: \n";
				cin >> num;
				admin->Del_Section(num);
				system("cls");
				work_with_sections(admin,student);
			}
			catch (const char* ex)
			{
				cout << ex << "\n\n\n\n";
				goto main;
			}
			catch (...)
			{
				cout << "Неверный выбор! Введите значение снова\n";
				goto main;
			}
			break;
		case 3:
			cout << "Введите название раздела: \n";
			cin.ignore(256, '\n');
			getline(cin, tmp);
			system("cls");
			admin->Add_Section_empty(tmp);
			system("cls");
			Work_with_Tests(admin, student);
			break;
		case 4:
			try
			{
				admin->Exp_to_file_All_Sections();
				Sleep(1000);
				system("cls");
				work_with_sections(admin, student);
			}
			catch (const char* ex)
			{
				cout << ex;
				goto main;
			}
			catch (...)
			{
				cout << "Неверный выбор! Введите значение снова\n";
				goto main;
			}
			break;
		case 5:
			system("cls");
			Work_with_Tests(admin,student);
			break;
		default:
			break;
		}
	} while (choice < 1 || choice > 5);
}
void work_with_subsections(Admin* admin, Student* student)
{
	int choice;
	size_t num;
	string tmp;
	system("cls");
	list <Section*>::iterator section = All_Tests.begin();
	Print_all_subsections(section, admin, student);
main:
	do
	{
		
		cout << "\nПодразделы: \n";
		for (size_t i = 0; i < (*section)->Get_Subsections().size(); ++i)
		{
			cout<<i+1<<". " << (*section)->Get_Subsections()[i]->Get_Name_of_Subsection() << endl;
		}
		cout << "\n\n\n";

		cout << "1. Изменить имя подраздела\n"
			 << "2. Удалить подраздел\n"
			 << "3. Добавить подраздел\n"
			 << "4. Выгрузить подразделы в файл\n"
			 << "5. Назад\n";
		cin >> choice;
		switch (choice)
		{
		case 1:
			if ((*section)->Get_Subsections().empty())
			{
				system("cls");
				cout << "List IS EMPTY!!!\n\n";
				cout <<"Раздел: " << (*section)->Get_Name_of_Section() << endl;
				goto main;
			}
			else
			{
				do
				{
					cout << "Введите --номер!-- подраздела: \n";
					cin >> num;
				} while (num < 1 || num >(*section)->Get_Subsections().size());
				Subsection* subsection = (*section)->Get_Subsections()[num - 1];

				cout << "Введите название подраздела: \n";
				cin.ignore(256, '\n');
				getline(cin, tmp);
				system("cls");
				admin->Set_Subsection_name(subsection, tmp);
				goto main;
			}
			break;
		case 2:
			again:
			try
			{
				if ((*section)->Get_Subsections().empty())
				{
					system("cls");
					cout << "List IS EMPTY!!!\n\n";
					cout << "Раздел: " << (*section)->Get_Name_of_Section() << endl;
					goto main;
				}
				cout << "Выберите номер подраздела: \n";
				cin >> num;
				admin->Del_Subsection((*section),num);
				system("cls");
				goto main;
			}
			catch (const char* ex)
			{
				cout << ex << "\n\n\n\n";
				goto main;
			}
			catch (...)
			{
				cout << "Неверный выбор! Введите значение снова\n";
				goto again;
			}
			break;
		case 3:
			cout << "Введите название подраздела: \n";
			cin.ignore(256, '\n');
			getline(cin, tmp);
			system("cls");
			admin->Add_Subsection_empty((*section), tmp);
			system("cls");
			goto main;
			break;
		case 4:
			system("cls");
			try
			{
				admin->Exp_to_file_All_Subsections();
				Sleep(1000);
				system("cls");
				goto main;
			}
			catch (const char* ex)
			{
				cout << ex;
				cout << "Раздел: " << (*section)->Get_Name_of_Section() << endl;
				goto main;
			}
			catch (...)
			{
				cout << "Неверный выбор! Введите значение снова\n";
				goto main;
			}
			break;
		case 5:
			system("cls");
			Work_with_Tests(admin, student);
			break;
		default:
			break;
		}
	} while (choice < 1 || choice > 5);
}
void work_with_tests(Admin* admin, Student* student)
{
	int choice;
	list <Section*>::iterator section = All_Tests.begin();
	Subsection* subsection = nullptr;
	Test* test = nullptr;
	string tmp;
	system("cls");

main:
	do
	{
		cout << "1. Просмотр всех тестов в системе\n"
			 << "2. Просмотр тестов по категориям\n"
			 << "3. Добавление и изменение тестов\n"
			 << "4. Назад\n";
		cin >> choice;

		switch (choice)
		{
		case 1:
			Print_all_tests(admin, student);
			goto main;
			break;
		case 2:
			subsection = Print_all_subsections(section,admin,student);
			test = Print_all_tests_in_subsection(subsection, admin, student);
			break;
		case 3:
			Add_tests_and_change_tests(admin, student);
		case 4:
			system("cls");
			Work_with_Tests(admin, student);
			break;
		default:
			break;
		}
	} while (choice < 1 || choice > 4);
}
void Print_all_sections()
{
	if (All_Tests.empty()) cout << "List Is EMPTY!!\n\n";
	
	else
	{
		list <Section*>::const_iterator it = All_Tests.begin();

		cout << "Разделы: \n";
		for (int i = 0; it != All_Tests.end(); ++it, ++i)
		{
			cout << i + 1 << ". " << (*it)->Get_Name_of_Section() << endl;
		}
		cout << "\n\n---------------------\n";
	}
}
Subsection* Print_all_subsections(list <Section*>::iterator& section, Admin* admin, Student* student)
{
	int choice;
	list <Section*>::const_iterator it = All_Tests.begin();
	if (All_Tests.empty()) 
	{
		cout << "List Is EMPTY!!  Добавьте сначала раздел!\n";
		Sleep(1000);
		system("cls");
		Work_with_Tests(admin, student);
	}
	
	Print_all_sections();

	cout << "Выберите номер раздела: \n";
	cin >> choice;
	advance(it, (choice - 1));
	advance(section, (choice - 1));
	if ((*it)->Get_Subsections().empty()) cout << "List Is EMPTY!!";
	else
	{
		cout << "Подразделы: \n";
		for (size_t i = 0; i < (*it)->Get_Subsections().size(); ++i)
		{
			cout << i + 1 << ". " << (*it)->Get_Subsections()[i]->Get_Name_of_Subsection() << endl;
		}
		cout << "\n\n---------------------\n";
		cout << "\nВыберите номер подраздела: \n";
		cin >> choice;
		system("cls");
		return (*it)->Get_Subsections()[choice - 1];
	}
}
void Print_all_tests(Admin* admin, Student* student)
{
	list <Section*>::const_iterator it = All_Tests.begin();
	system("cls");
	if (All_Tests.empty())
	{
		system("cls");
		cout << "В системе ни одного теста!!\n";
		Sleep(1000);
		system("cls");
	}
	else
	{
		cout << "РАЗДЕЛЫ: \n\n";
		for (int i = 0 ; it != All_Tests.end(); ++it, ++i)
		{
			
			cout << (*it)->Get_Name_of_Section() << endl;
			if ((*it)->Get_Subsections().empty())
			{
				cout << "Раздел пустой!!!\n\n\n";
				continue;
			}
			else
			{
				for (size_t i = 0; i < (*it)->Get_Subsections().size(); ++i)
				{
					cout << "\tПодраздел: \n";
					cout << "\t    " << (*it)->Get_Subsections()[i]->Get_Name_of_Subsection() << endl;
					if ((*it)->Get_Subsections()[i]->Get_Tests().empty())
					{
						cout << "\t\tТесты в подразделе отсутствуют!!!\n\n\n";
						continue;
					}
					else
					{
						for (size_t j = 0; j < (*it)->Get_Subsections()[i]->Get_Tests().size(); ++j)
						{
							cout << "\t\tТесты: \n";
							cout << "\t\t" << i + 1 << ". " << (*it)->Get_Subsections()[i]->Get_Tests()[j]->Get_Name_of_Test() << endl;
						}
					}
				}
			}
			
		}
	}
	system("pause");
	system("cls");
}
Test* Print_all_tests_in_subsection(Subsection* subsection, Admin* admin, Student* student)
{
	int choice;
	Test* selected_test;

	if (subsection == NULL)
	{
		system("cls");
		cout << "\tНЕТ ТЕСТОВ В РАЗДЕЛЕ!!";
		Sleep(1000);
		work_with_tests(admin, student);
	}
	else
	{
		if (subsection->Get_Tests().empty())
		{
			system("cls");
			cout << "\tНЕТ ТЕСТОВ В РАЗДЕЛЕ!!";
			Sleep(1000);
			work_with_tests(admin, student);
		}
		else
		{
			cout << "Тесты: \n";
			for (size_t i = 0; i < subsection->Get_Tests().size(); ++i)
			{
				cout << i + 1 << ". " << subsection->Get_Tests()[i]->Get_Name_of_Test() << endl;
			}
			cout << "\nВыберите номер теста: \n";
			cin >> choice;
			selected_test = subsection->Get_Tests()[choice - 1];
			return selected_test;
		}
	}
}
void Add_tests_and_change_tests(Admin* admin, Student* student)
{
	vector<Test*> temp_tests;
	list <Section*>::const_iterator it = All_Tests.begin();
	Test* current_test = nullptr;
	size_t choice;
	size_t num;
	system("cls");
	if (!All_Tests.empty())
	{
		for (size_t i = 0; it != All_Tests.end(); ++it, ++i)
		{
			if (!(*it)->Get_Subsections().empty())
			{
				for (size_t j = 0; j < (*it)->Get_Subsections()[i]->Get_Tests().size(); ++j)
				{
					if (!(*it)->Get_Subsections()[i]->Get_Tests().empty())
					{
						for (size_t k = 0; k < (*it)->Get_Subsections()[i]->Get_Tests().size(); ++k)
						{
							temp_tests.push_back((*it)->Get_Subsections()[i]->Get_Tests()[k]);
						
						}
					}
				}
			}
		}
	}
main:
	cout << "Список всех тестов в системе: \n";
	for (size_t i = 0; i < temp_tests.size(); i++)
	{
		cout << i + 1 << ". " << "Раздел: " << temp_tests[i]->Get_Name_of_Section() << endl;
		cout << "   Подраздел: " << temp_tests[i]->Get_Name_of_Subsection() << endl;
		cout << "\tНазвание теста: " << temp_tests[i]->Get_Name_of_Test() << endl;
	}
	cout << "------------------\n\n";
	do
	{
		cout << "1. Добавить тест\n"
			 << "2. Изменить тест\n"
			 << "3. Удалить тест\n"
			 << "4. Выгрузить тест в файл\n"
			 << "5. Назад\n";
		cin >> choice;
	
			switch (choice)
			{
			case 1:
				add_test(current_test, admin, temp_tests, student);
				break;
			case 2:
				if (temp_tests.empty())
				{
					system("cls");
					cout << "Сначала добавьте хотя бы 1 тест!!!\n";
					Sleep(1000);
					Add_tests_and_change_tests(admin, student);
				}
				else
					change_current_test(admin, temp_tests,student);
				break;
			case 3:
			again:
				if (temp_tests.empty())
				{
					system("cls");
					cout << "Сначала добавьте хотя бы 1 тест!!!\n";
					Sleep(1000);
					Add_tests_and_change_tests(admin, student);
				}
				try
				{
					cout << "Введите номер теста из списка\n";
					cin >> num;
					admin->Del_Test(temp_tests[num - 1], num);
					Add_tests_and_change_tests(admin, student);
				}
				catch (const exception& ex)
				{
					cout << ex.what();
					goto again;
				}
				break;
			case 4:
				if (temp_tests.empty())
				{
					system("cls");
					cout << "Сначала добавьте хотя бы 1 тест!!!\n";
					Sleep(1000);
					Add_tests_and_change_tests(admin, student);
				}
				try
				{
					cout << "Введите номер теста из списка\n";
					cin >> num;
					admin->Exp_to_file_Selected_Test(temp_tests[num - 1]);
					Sleep(1000);
					system("cls");
				}
				catch (const char* ex)
				{
					cout << ex << "\n\n\n\n";
					goto main;
				}
				catch (...)
				{
					cout << "Неверный выбор! Введите значение снова\n";
					goto main;
				}
				Add_tests_and_change_tests(admin, student);
				break;
			case 5:
				system("cls");
				work_with_tests(admin, student);
				break;
			default:
				break;
			}
	} while (choice < 1 || choice > 5);

}
void change_current_test(Admin* admin, vector<Test*>& temp_tests,Student* student)
{
	size_t choice;
	string tmp;
	Test* current_test = nullptr;
	system("cls");
	cout << "Список всех тестов в системе: \n";
	for (size_t i = 0; i < temp_tests.size(); i++)
	{
		cout <<i+1<<". "<< "Раздел: " << temp_tests[i]->Get_Name_of_Section() << endl;
		cout << "   Подраздел: " << temp_tests[i]->Get_Name_of_Subsection() << endl;
		cout << "\tНазвание теста: " << temp_tests[i]->Get_Name_of_Test() << endl;
	}
	cout << "------------------\n\n";
	cout << "Выберите тест из списка: \n";
	cin >> choice;
	current_test = temp_tests[choice - 1];
	do
	{
		cout << "\n\n1. Изменить имя теста\n"
			 << "2. Изменить вопросы в тесте\n"
			 << "3. Назад\n";
		cin >> choice;

		switch (choice)
		{
		case 1:
			cout << "Введите имя теста: \n";
			cin.ignore(256, '\n');
			getline(cin, tmp);
			system("cls");
			admin->Set_Test_name(current_test, tmp);
			change_current_test(admin, temp_tests,student);
			break;
		case 2:
			system("cls");
			change_questions_in_test(current_test, admin, temp_tests);
			change_current_test(admin, temp_tests,student);
			break;
		case 3:
			Add_tests_and_change_tests(admin, student);
			break;
		default:
			break;
		}
	} while (choice < 1 || choice > 5);
}
void change_questions_in_test(Test* current_test, Admin* admin, vector<Test*>& temp_tests)
{
	int choice;
	int num_of_quest;
	Student* student = nullptr;
	cout << "Название теста: " << current_test->Get_Name_of_Test() << endl;
	for (size_t i = 0; i < current_test->Get_Questions().size(); ++i)
	{
		cout <<"Вопрос № " << i + 1 << ". " << current_test->Get_Questions()[i]->Get_Name_of_Question() << endl;

		for (size_t j = 0; j < current_test->Get_Questions()[i]->Get_Options().size(); j++)
		{

			cout << j + 1 << ". " << current_test->Get_Questions()[i]->Get_Options()[j] << endl;
		}
		cout << "\n";
	}
	
	do
	{
		cout << "\n\n1. Изменить вопрос\n"
			 << "2. Добавить вопрос\n"
			 << "3. Удалить вопрос\n"
			 << "4. Назад\n";
		cin >> choice;

		switch (choice)
		{
		case 1:
			if (current_test->Get_Questions().empty())
			{
				system("cls");
				cout << "\tНЕТ ВОПРОСОВ В ТЕСТЕ!!\tДобавьте хотя бы 1 вопрос";
				Sleep(1000);
				change_questions_in_test(current_test, admin, temp_tests);
			}
			else
			{
				cout << "\n Введите номер вопроса: \n";
				cin >> num_of_quest;
				change_selected_questions_in_test(current_test, admin, temp_tests, num_of_quest);
			}
			break;
		case 2:
			add_question_in_test(current_test, admin, temp_tests);
			change_questions_in_test(current_test, admin, temp_tests);
			break;
		case 3:
		again:
			try
			{
				cout << "\n Введите номер вопроса: \n";
				cin >> num_of_quest;
				admin->Del_Question(current_test, num_of_quest);
				change_questions_in_test(current_test, admin, temp_tests);
			}
			catch (const exception& ex)
			{
				cout << ex.what();
				goto again;
			}
			break;
		case 4:
			system("cls");
			change_current_test(admin, temp_tests,student);
			break;
		default:
			break;
		}
	} while (choice < 1 || choice > 4);
}
void change_selected_questions_in_test(Test* current_test, Admin* admin, vector<Test*>& temp_tests, int num_of_quest)
{
	int choice;
	string tmp;
	int num;
	system("cls");

	cout << current_test->Get_Questions()[num_of_quest - 1]->Get_Name_of_Question() << endl;
	for (size_t i = 0; i < current_test->Get_Questions()[num_of_quest - 1]->Get_Options().size(); ++i)
	{
		cout<<i+1<<". "<<current_test->Get_Questions()[num_of_quest - 1]->Get_Options()[i] << endl;
	}
	cout << "Правильный ответ: " << current_test->Get_Questions()[num_of_quest - 1]->Get_Correct_of_Question();
main:
	do
	{
		cout << "\n\n1. Изменить имя вопроса\n"
			<< "2. Добавить вариант ответа в вопросе\n"
			<< "3. Изменить название варианта ответа в вопросе\n"
			<< "4. Изменить номер правильного ответа в вопросе\n"
			<< "5. Удалить вариант ответа в вопросе\n"
			<< "6. Добавить вариант ответа в вопрос\n"
			<< "7. Назад\n";
		cin >> choice;
		switch (choice)
		{
		case 1:
			cout << "Введите название вопроса: \n";
			cin.ignore(256, '\n');
			getline(cin, tmp);
			system("cls");
			admin->Set_Question_name(current_test->Get_Questions()[num_of_quest - 1], tmp);
			change_selected_questions_in_test(current_test, admin, temp_tests, num_of_quest);
			break;
		case 2:
			try
			{
				cout << "Введите вариант ответа: \n";
				cin.ignore(256, '\n');
				getline(cin, tmp);
				system("cls");
				admin->Add_Question_option(current_test->Get_Questions()[num_of_quest - 1], tmp);
				change_selected_questions_in_test(current_test, admin, temp_tests, num_of_quest);
			}
			catch (const exception& ex)
			{
				cout << ex.what();
				goto main;
			}
			break;
		case 3:
			if (current_test->Get_Questions()[num_of_quest - 1]->Get_Options().empty())
			{
				system("cls");
				cout << "\tНЕТ ВАРИАНТОВ ОТВЕТОВ В ТЕСТЕ!!\tДобавьте хотя бы 1 вариант";
				Sleep(1000);
				change_selected_questions_in_test(current_test, admin, temp_tests, num_of_quest);
			}
			else
			{
				cout << "Введите номер варианта ответа: \n";
				cin >> num;
				cout << "Введите название варианта ответа: \n";
				cin.ignore(256, '\n');
				getline(cin, tmp);
				system("cls");
				admin->Set_Question_option(current_test->Get_Questions()[num_of_quest - 1], num, tmp);
				change_selected_questions_in_test(current_test, admin, temp_tests, num_of_quest);
			}
			break;
		case 4:
			cout << "Введите номер правильного ответа: \n";
			cin >> num;
			admin->Set_Question_correct_answer(current_test->Get_Questions()[num_of_quest - 1], num);
			change_selected_questions_in_test(current_test, admin, temp_tests, num_of_quest);
			break;
		case 5:
			cout << "Введите номер варианта на удаление: \n";
			cin >> num;
			try
			{
				admin->Del_Question_option(current_test->Get_Questions()[num_of_quest - 1], num);
				change_selected_questions_in_test(current_test, admin, temp_tests, num_of_quest);
			}
			catch (const exception& ex)
			{
				cout << ex.what();
				goto main;
			}
			break;
		case 6:
			cout << "Введите вариант ответа: \n";
			cin.ignore(256, '\n');
			getline(cin, tmp);
			system("cls");
			admin->Add_Question_option(current_test->Get_Questions()[num_of_quest - 1], tmp);
			change_selected_questions_in_test(current_test, admin, temp_tests, num_of_quest);
			break;
		case 7:
			system("cls");
			change_questions_in_test(current_test, admin, temp_tests);
			break;
		default:
			break;
		}
	} while (choice <1 || choice > 7);
}
void add_test(Test* current_test, Admin* admin, vector<Test*>& temp_tests, Student* student)
{
	system("cls");
	list <Section*>::iterator section = All_Tests.begin();
	Subsection* current_subsection = nullptr;
	Test* new_test = new Test;
	string tmp;
	size_t num;
	int quant;
	if (All_Tests.empty())
	{
		cout << "Создаем новый раздел!\n";
		cout << "Введите название раздела: \n";	
		if (char(cin.peek()) == '\n')
			cin.ignore();
		getline(cin, tmp);
		system("cls");
		admin->Set_Test_name_section(new_test, tmp);
		admin->Add_Section_empty(tmp);
		section = All_Tests.begin();
	}
	else
	{
		Print_all_sections();
		cout << "Выберите номер раздела для добавления теста из списка:\n";
		cin >> num;
		advance(section, (num - 1));
		admin->Set_Test_name_section(new_test, (*section)->Get_Name_of_Section());
	}
	if ((*section)->Get_Subsections().empty())
	{
		cout << "Создаем новый подраздел!\n";
		cout << "Введите название подраздела: \n";
		if (char(cin.peek()) == '\n')
			cin.ignore();
		getline(cin, tmp);
		system("cls");
		admin->Set_Test_name_subsection(new_test, tmp);
		admin->Add_Subsection_empty((*section), tmp);
		current_subsection = (*section)->Get_Subsections().back();
	}
	else
	{
		cout << "Подразделы: \n";
		for (size_t i = 0; i < (*section)->Get_Subsections().size(); ++i)
		{
			cout << i + 1 << ". " << (*section)->Get_Subsections()[i]->Get_Name_of_Subsection() << endl;
		}
		cout << "\n\n---------------------\n";
		cout << "\nВыберите номер подраздела: \n";
		cin >> num;
		current_subsection = (*section)->Get_Subsections()[num - 1];
		admin->Set_Test_name_subsection(new_test, current_subsection->Get_Name_of_Subsection());
	}

	cout << "Введите название теста: \n";
	if (char(cin.peek()) == '\n')
		cin.ignore();
	getline(cin, tmp);
	admin->Set_Test_name(new_test, tmp);

	cout << "Введите количество вопросов в тесте: \n";
	cin >> quant;
	admin->Set_Test_quant_of_questions(new_test, quant);
	admin->Set_Test_is_finished(new_test, true);

	for (int i = 0; i < quant; ++i)
	{
		add_question_in_test(new_test, admin, temp_tests);
	}
	admin->Add_Test(new_test, current_subsection);
	system("cls");
	Add_tests_and_change_tests(admin, student);
}
void add_question_in_test(Test* new_test, Admin* admin, vector<Test*>& temp_tests)
{
	system("cls");
	Question* new_quest = new Question;
	string tmp;
	size_t num;
	int quant;

	cout << "Введите название вопроса: \n";
	if (char(cin.peek()) == '\n')
		cin.ignore();
	getline(cin, tmp);
	admin->Set_Question_name(new_quest, tmp);
	
	bool exit = false;
	int count_options = 1;
	int choice;
	while (exit != true)
	{
		std::cout << "Введите " << count_options << " й вариант ответа: " << std::endl;
		if (char(cin.peek()) == '\n')
			cin.ignore();
		getline(std::cin, tmp);
		admin->Set_Option_name(new_quest, tmp);
		
		std::cout << "Желаете ввести следующий вариант ответа? 1 - ДА, 2 - НЕТ" << std::endl;
		std::cin >> choice;
		if (choice == 2) exit = true;

		++count_options;
	}
again:
	std::cout << "Введите номер правильного варианта ответа: " << std::endl;
	cin >> num;
	admin->Set_Question_correct_answer(new_quest, num);
	if ((num - 1) < 0 || (num - 1) > new_quest->Get_Options().size())
	{
		std::cout << "Выбор не верный. Введите снова!";
		goto again;
	}
	admin->Add_Question(new_test, new_quest);
	system("cls");
}
void set_fake_answers(Admin* admin, Rezult_of_Test* fake_rezult, Test* selected_test)
{
	pair<size_t, size_t> correct_and_stud_answers;
	for (size_t i = 0; i < selected_test->Get_Questions().size(); ++i)
	{
		correct_and_stud_answers.first = selected_test->Get_Questions()[i]->Get_Correct_of_Question();
		correct_and_stud_answers.second = selected_test->Get_Questions()[i]->Get_Correct_of_Question();
		admin->Set_Rezults_correct_and_stud_answers(fake_rezult, selected_test->Get_Questions()[i], correct_and_stud_answers);
	
	}
}

////////////////

void User(Admin* admin, Student* student)
{
	Student* current_stud = nullptr;
	int choice;
	int count = 3;
	string login;
	string password;
	do
	{
		cout << "1. Регистрация в системе\n"
			 << "2. Пройти аутентификацию\n"
			 << "3. В главное меню\n";
		cin >> choice;
		system("cls");
		switch (choice)
		{
		case 1:
			current_stud = admin->Registration_Student();
			system("cls");
			User_info(admin, current_stud);
			break;
		case 2:
			
			do
			{
				
				cout << "У вас есть " <<count<<" попытки!!!\n\n";
				cout << "Введите логин: \n";
				cin >> login;
				cout << "Введите пароль: \n";
				cin >> password;
				if (admin->Enter_Student(login, password))
				{
					current_stud = admin->Get_Pointer_Student(login);
					User_info(admin, current_stud);
				}
				count--;
			} while (count > 0 && count <= 3);
			system("cls");
			break;
		case 3:
			system("cls");
			Welcome(admin, student);
			break;
		default:
			break;
		}
	} while (choice < 1 || choice > 3);
}
void User_info(Admin* admin, Student* current_stud)
{
	Test* waiting_test = nullptr;
	system("cls");
	int choice;
	do
	{
		cout << "1. Посмотреть предыдущие результаты\n"
			 << "2. Пройти тестирование\n"
			 << "3. Назад\n";
		cin >> choice;
		switch (choice)
		{
		case 1:
			show_current_student_stat(admin, current_stud);
			system("pause");
			system("cls");
			User_info(admin, current_stud);
			break;
		case 2:
			take_the_test(admin, current_stud, waiting_test);
			User_info(admin, current_stud);
			break;
		case 3:
			system("cls");
			User(admin, current_stud);
			break;
		default:
			break;
		}
	} while (choice < 1 || choice > 3);

}
void show_current_student_stat(Admin* admin, Student* current_stud)
{
	system("cls");
	list <Student*>::const_iterator it = All_Students.begin();
	Test* waiting_test = nullptr;
	bool mark = false;
	int choice = 0;
	for (; it != All_Students.end(); ++it)
	{
		if ((*it) == current_stud)
		{
			if (!(*it)->Get_Stud_Rez().empty())
			{
				cout << "Результаты студента: \n";
					for (size_t i = 0; i < (*it)->Get_Stud_Rez().size(); ++i)
					{
						if ((*it)->Get_Stud_Rez()[i]->Get_Current_Test() == NULL)
						{
							cout << "\t\tСтудент еще ничего не сдавал!\n";
							continue;
						}
						if ((*it)->Get_Stud_Rez()[i]->Get_Current_Test()->Get_Mark_is_Finished() != false)
						{
							cout << "Тест № " << i + 1 << "  " << (*it)->Get_Stud_Rez()[i]->Get_Current_Test()->Get_Name_of_Test() << endl;
							cout << "Раздел: " << (*it)->Get_Stud_Rez()[i]->Get_Current_Test()->Get_Name_of_Section() << endl;
							cout << "Подраздел: " << (*it)->Get_Stud_Rez()[i]->Get_Current_Test()->Get_Name_of_Subsection() << endl;
							cout << "Количество правильных ответов: " << (*it)->Get_Stud_Rez()[i]->Get_Quant_of_Right_Answers() << endl;
							cout << "Оценка: " << (*it)->Get_Stud_Rez()[i]->Get_Score() << endl;
							cout << "Результат: " << (*it)->Get_Stud_Rez()[i]->Get_Rezult_Message() << "\n\n";
						}
						
					}
				cout << "\n\n\nТесты, ожидаюшие завершение : \n";
				size_t i = 0;
					for (; i < (*it)->Get_Stud_Rez().size(); ++i)
					{
						if ((*it)->Get_Stud_Rez()[i]->Get_Current_Test() == NULL)
							continue;
						if ((*it)->Get_Stud_Rez()[i]->Get_Current_Test()->Get_Mark_is_Finished() == false)
						{
							cout << "Тест № " << i + 1 << "  " << (*it)->Get_Stud_Rez()[i]->Get_Current_Test()->Get_Name_of_Test() << endl;
							cout << "Раздел: " << (*it)->Get_Stud_Rez()[i]->Get_Current_Test()->Get_Name_of_Section() << endl;
							cout << "Подраздел: " << (*it)->Get_Stud_Rez()[i]->Get_Current_Test()->Get_Name_of_Subsection() <<"\n\n\n" << endl;
							mark = true;
						}
					}
					if (mark == true)
					{
						cout << "Введите номер теста  (Нажмите 0 для выхода)\n";
						cin >> choice;
						if (choice == 0)
							User_info(admin, current_stud);
						if (choice != 0)
						{
							waiting_test = (*it)->Get_Stud_Rez()[i - choice]->Get_Current_Test();
							take_the_test(admin, current_stud, waiting_test);
						}
					}
			}
			else
			{
				cout << "\t\tСтудент еще ничего не сдавал!\n";
				
			}

		}
		
	}
}
void take_the_test(Admin* admin, Student* current_stud, Test*& waiting_test)
{
	system("cls");
	size_t choice;
	size_t quant = 0;
	Test* current_test = nullptr;
	pair<size_t, size_t> correct_and_stud_answers;
	Rezult_of_Test* new_rez = new Rezult_of_Test;
	list <Section*>::const_iterator it = All_Tests.begin();

	for (; it != All_Tests.end(); ++it)
	{
		for (size_t i = 0; i < (*it)->Get_Subsections().size(); ++i)
		{
			if (!(*it)->Get_Subsections()[i]->Get_Tests().empty())
				++quant;
		}
	}
	if (quant == 0)
	{
		cout << "В системе ни одного теста!!!  Попросите админа добавить тесты!\n\n\n\n";
		system("pause");
	}
	else
	{
		if (waiting_test == nullptr)
		{
			current_test = choose_test(admin, current_stud);
			system("cls");
		}
		else
		{
			current_test = waiting_test;
			system("cls");
		}
		size_t i = current_test->Get_Start_Position();
		for (; i < current_test->Get_Questions().size(); ++i)
		{
			cout << "Вопрос № " << i + 1 << " " << current_test->Get_Questions()[i]->Get_Name_of_Question() << endl;
			cout << "Варианты ответов:\n";
			for (size_t j = 0; j < current_test->Get_Questions()[i]->Get_Options().size(); ++j)
			{
				cout << j + 1 << ". " << current_test->Get_Questions()[i]->Get_Options()[j] << endl;
			}
			do
			{
				cout << "\n\n";
				cout << "Введите вариант ответа: (Закончить потом - нажмите 0)\n";
				cin >> choice;
				admin->Set_Test_start_position(current_test, 1);

				if (choice == 0)
					goto miss;
			} while (choice < 1 || choice > current_test->Get_Questions()[i]->Get_Options().size());
			system("cls");
			admin->Set_Rezults_current_test(new_rez, current_test);

			correct_and_stud_answers.first = current_test->Get_Questions()[i]->Get_Correct_of_Question();
			correct_and_stud_answers.second = choice;
			admin->Set_Rezults_correct_and_stud_answers(new_rez, current_test->Get_Questions()[i], correct_and_stud_answers);
		}
	miss:
		if (choice == 0)
		{
			admin->Set_Rezults_current_test(new_rez, current_test);

			correct_and_stud_answers.first = current_test->Get_Questions()[i]->Get_Correct_of_Question();
			correct_and_stud_answers.second = choice;
			admin->Set_Rezults_correct_and_stud_answers(new_rez, current_test->Get_Questions()[i], correct_and_stud_answers);
		}
		if (current_test->Get_Questions().size() != current_test->Get_Start_Position())
		{
			admin->Set_Rezult_general_right_answers(new_rez);
			new_rez->Calculate_Score(current_test, new_rez);
			admin->Set_Rezults_messg_rezult(new_rez, "Тест не завершен!!!");
			admin->Set_Test_is_finished(current_test, false);
			admin->Set_Rezults_add_rezult(new_rez, current_stud);
		}
		else
		{
			admin->Set_Rezult_general_right_answers(new_rez);
			new_rez->Calculate_Score(current_test, new_rez);
			admin->Set_Test_is_finished(current_test, true);
			admin->Set_Test_start_0(current_test);
			admin->Set_Rezults_add_rezult(new_rez, current_stud);
			waiting_test = nullptr;
		}
		
	}
}
