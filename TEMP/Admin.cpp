using namespace std;
#include "Admin.h"
#include <string>
std::list <Section*> All_Tests;
std::vector  <AccountsInfo*> Users;
std::list <Student*> All_Students;
Admin::Admin(std::string fio, std::string home_adress, std::string phone_number, std::string adm_login, std::string adm_password, bool is_admin)
{
	this->fio = fio;
	this->home_adress = home_adress;
	this->phone_number = phone_number;
	this->adm_login = adm_login;
	this->adm_password = adm_password;
	this->is_admin = is_admin;
}
void Admin::Set_Admin_name(std::string fio)
{
	this->fio = fio;
}
void Admin::Set_Admin_adress(std::string adress)
{
	this->home_adress = adress;
}
void Admin::Set_Admin_phonenumber(std::string phone_number)
{
	this->phone_number = phone_number;
}
void Admin::Set_Admin_login(std::string login)
{
	this->adm_login = Encode_login(login);
}
void Admin::Set_Admin_password(std::string password)
{
	this->adm_password = Encode_password(password);
}
void Admin::Set_Option_name(Question* question, std::string value)
{
	if (question == nullptr) return;
	question->options.push_back(value);
}
void Admin::Set_Question_name(Question* question, std::string value)
{
	if (question == nullptr) return;
	question->name_of_question = value;
}
void Admin::Set_Question_correct_answer(Question* question, size_t value)
{
	if (question == nullptr) return;
	question->correct_answer = value;
}
void Admin::Set_Question_option(Question* question, size_t index, std::string value)
{
	if (question == nullptr) return;
	if ((index - 1) < 0 || (index - 1) > question->Get_Options().size())
	{
		throw value;
	}
	else
	{
		question->options[index-1] = value;
	}
}
void Admin::Add_Question_option(Question* question, std::string value)
{
	if (question == nullptr) return;
	question->options.push_back(value);
}
void Admin::Add_Question(Test* test, Question* question)
{
	if (test == nullptr || question == nullptr) return;
	test->questions.push_back(question);
}
void Admin::Del_Question(Test* test, size_t index)
{
	if (test == nullptr) return;
	if ((index - 1) < 0 || (index - 1) > test->Get_Questions().size())
	{
		throw index;
	}
	else
	{
		std::vector<Question*>::iterator it = test->questions.begin() + (index - 1);
		test->questions.erase(it);
	}
}
void Admin::Del_Question_option(Question* question, size_t index)
{
	if (question == nullptr) return;
	if ((index - 1) < 0 || (index - 1) > question->Get_Options().size())
	{
		throw index;
	}
	else
	{
		std::vector<std::string>::iterator it = question->options.begin() + (index - 1);
		question->options.erase(it);
	}
}
void Admin::Set_Test_name(Test* test, std::string value)
{
	if (test == nullptr) return;
	test->name_of_test = value;
}
void Admin::Set_Test_quant_of_questions(Test* test, size_t value)
{
	if (test == nullptr) return;
	test->quant_of_questions = value;
}
void Admin::Set_Test_name_subsection(Test* test, std::string value)
{
	if (test == nullptr) return;
	test->name_of_subsection = value;
}
void Admin::Set_Test_name_section(Test* test, std::string value)
{
	if (test == nullptr) return;
	test->name_of_section = value;
}
void Admin::Set_Test_start_position(Test* test, size_t value)
{
	if (test == nullptr) return;
	test->start_position += value;
}
void Admin::Set_Test_start_0(Test* test)
{
	if (test == nullptr) return;
	test->start_position = 0;
}
void Admin::Set_Test_is_finished(Test* test, bool value)
{
	if (test == nullptr) return;
	test->is_finished = value;
}
void Admin::Add_Test(Test* test, Subsection* subsection)
{
	if (test == nullptr || subsection == nullptr) return;
	list <Section*>::iterator it = All_Tests.begin();
	Subsection* ten;
	ten = (*it)->subsections.back();
	ten->tests.push_back(test);

}
void Admin::Del_Test(Test* test, size_t index)
{
	
	if (test == nullptr) return;
	if ((index - 1) < 0 || (index - 1) > test->tests.size())
	{
		throw index;
	}
	else
	{
		list <Section*>::iterator it = All_Tests.begin();
		
		for (size_t i = 0; i < (*it)->subsections.size(); ++i)
		{
			for (size_t j = 0; j < (*it)->subsections[i]->tests.size(); j++)
			{
				if ((*it)->subsections[i]->tests[j] == test)
				{
					vector<Test*>::iterator it_test = (*it)->subsections[i]->tests.begin();
					advance(it_test, (index - 1));
					(*it)->subsections[i]->tests.erase(it_test);
				}
			}
		}
	}
}
void Admin::Set_Subsection_name(Subsection* subsection, std::string value)
{
	if (subsection == nullptr) return;
	subsection->name_of_subsection = value;
}
void Admin::Del_Subsection(Section* section, size_t index)
{
	if (section == nullptr)
		return;
	if ((index - 1) < 0 || (index - 1) > section->Get_Subsections().size())
	{
		throw index;
	}
	else
	{
		std::vector<Subsection*> ::iterator it = section->subsections.begin() + (index - 1);
		section->subsections.erase(it);
	}
}
void Admin::Add_Subsection_empty(Section* section, std::string value)
{
	if (section == nullptr) return;
	Subsection* new_sub = new Subsection(value);
	section->subsections.push_back(new_sub);
}
void Admin::Set_Section_name(Section* section, std::string value)
{
	if (section == nullptr) return;
	section->name_of_section = value;
}
void Admin::Del_Section(size_t index)
{
	if ((index - 1) < 0 || (index - 1) > All_Tests.size())
	{
		throw index;
	}
	else
	{
		std::list <Section*>::const_iterator it = All_Tests.begin();
		advance(it, (index - 1));
		All_Tests.erase(it);
	}
}
void Admin::Add_Section_empty(std::string value)
{
	Section* new_sec = new Section(value);
	All_Tests.push_back(new_sec);
}
void Admin::Set_Student_fio(Student* student, std::string value)
{
	if (student == nullptr) return;
	student->fio = value;
}
void Admin::Set_Student_adress(Student* student, std::string value)
{
	if (student == nullptr) return;
	student->home_adress = value;
}
void Admin::Set_Student_phone_number(Student* student, std::string value)
{
	if (student == nullptr) return;
	student->phone_number = value;
}
void Admin::Add_Student()
{
	cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	Student* student = new Student;

	std::cout << "Введите имя студента: " << std::endl;
	getline(cin, student->fio);

	std::cout << "Введите домашний адрес студента: " << std::endl;
	getline(cin, student->home_adress);

	std::cout << "Введите телефонный номер студента: " << std::endl;
	getline(cin, student->phone_number);

	Rezult_of_Test* new_rez = new Rezult_of_Test;
	AccountsInfo* new_acc = new AccountsInfo;
	new_acc->current_student = student;

	student->rezults.push_back(new_rez);
	All_Students.push_back(student);
	Users.push_back(new_acc);
}
void Admin::Del_Student(size_t index)
{
	if ((index - 1) < 0 || (index - 1) > All_Students.size())
	{
		throw index;
	}
	else
	{
		std::list <Student*>::const_iterator it = All_Students.begin();
		advance(it, (index - 1));
		All_Students.erase(it);
	}
}
void Admin::Set_Rezults_add_rezult(Rezult_of_Test* rezult, Student* student)
{
	if (student->rezults.size() == 1)
	{
		student->rezults[0] = rezult;
	}
	else
	{
		student->rezults.push_back(rezult);
	}
}
void Admin::Set_Rezults_current_test(Rezult_of_Test* rezults, Test* test)
{
	if (rezults == nullptr) return;
	rezults->current_test = test;
}
void Admin::Set_Rezults_correct_answ(Rezult_of_Test* rezults, Question* question, size_t value)
{
	if (rezults == nullptr) return;
	rezults->correct_and_stud_answers.first = value;
	rezults->quest_and_answers.at(question) = rezults->correct_and_stud_answers;
}
void Admin::Set_Rezults_stud_answ(Rezult_of_Test* rezults, Question* question, size_t value)
{
	if (rezults == nullptr) return;
	rezults->correct_and_stud_answers.second = value;
	rezults->quest_and_answers.at(question) = rezults->correct_and_stud_answers;
}
void Admin::Set_Rezults_flag_rezult(Rezult_of_Test* rezults, bool value)
{
	if (rezults == nullptr) return;
	rezults->is_passed = value;
}
void Admin::Set_Rezults_messg_rezult(Rezult_of_Test* rezults, std::string value)
{
	if (rezults == nullptr) return;
	rezults->rez_msg = value;
}
void Admin::Set_Rezults_quant_of_Rig_Answ(Rezult_of_Test* rezults, size_t value)
{
	if (rezults == nullptr) return;
	rezults->quant_of_right_answers = value;
}
void Admin::Set_Rezults_score(Rezult_of_Test* rezults, size_t value)
{
	if (rezults == nullptr) return;
	rezults->score = value;
}
void Admin::Set_Rezults_correct_and_stud_answers(Rezult_of_Test* rezult, Question* question, std::pair<size_t, size_t> correct_and_stud_answers)
{
	rezult->quest_and_answers.emplace(question, correct_and_stud_answers);
}
void Admin::Set_Rezult_general_right_answers(Rezult_of_Test* new_rez)
{
	size_t quant = 0;
	if (new_rez == nullptr) return;
	std::map <Question*, std::pair<size_t, size_t>>::iterator it = new_rez->quest_and_answers.begin();

	for (size_t i = 0; it != new_rez->quest_and_answers.end(); ++it)
	{
		if ((*it).second.first == (*it).second.second)
			++quant;
	}
	new_rez->quant_of_right_answers = quant;
	
}
int Admin::Get_All_Passed_Tests(Student* current_student)
{
	list <Student*>::const_iterator it = All_Students.begin();
	int count = 0;
	for (size_t i = 0; i < current_student->Get_Stud_Rez().size(); ++i)
	{
		if (current_student->Get_Stud_Rez()[i]->Get_Rezult() == true)
			++count;
	}
	return count;
}
int Admin::Get_All_Failed_Tests(Student* current_student)
{
	list <Student*>::const_iterator it = All_Students.begin();
	int count = 0;
	for (size_t i = 0; i < current_student->Get_Stud_Rez().size(); ++i)
	{
		if (current_student->Get_Stud_Rez()[i]->Get_Rezult() == false &&current_student->Get_Stud_Rez()[i]->Get_Current_Test() != nullptr)
			++count;
	}
	return count;
}
int Admin::Get_All_Waiting_Tests(Student* current_student)
{
	list <Section*>::const_iterator it = All_Tests.begin();
	int count = 0;
	if (current_student->rezults[0]->current_test == nullptr)
	{
		return 0;
	}
	for (; it != All_Tests.end(); ++it)
	{
		for (size_t j = 0; j < (*it)->Get_Subsections().size(); ++j)
		{
			for (size_t k = 0; k < (*it)->Get_Subsections()[j]->Get_Tests().size(); ++k)
			{
				if (current_student->Get_Stud_Rez()[k]->Get_Current_Test()->Get_Mark_is_Finished() == false)
				{
					++count;
				}
			}
		}
	}
	return count;
}
std::string Admin::Encode_login(std::string login)
{
	std::string crypted;
	for (size_t i = 0; i < strlen(login.c_str()); i++)
		crypted += login[i] ^ 2;
	return crypted;
}
std::string Admin::Encode_password(std::string password)
{
	std::string crypted;
	for (size_t i = 0; i < strlen(password.c_str()); i++)
		crypted += password[i] ^ 2;
	return crypted;
}
std::string Admin::Decode_login(std::string login)
{
	std::string uncrypted;
	for (size_t i = 0; i < strlen(login.c_str()); i++)
		uncrypted += login[i] ^ 2;
	return uncrypted;
}
std::string Admin::Decode_password(std::string password)
{
	std::string uncrypted;
	for (size_t i = 0; i < strlen(password.c_str()); i++)
		uncrypted += password[i] ^ 2;
	return uncrypted;
}
bool Admin::Check_login(std::string login)
{
	std::string tmp_login = Encode_login(login);
	for (size_t i = 0; i < Users.size(); ++i)
	{
		if (Users[i]->logs_and_pass.first == tmp_login)
			return true;
	}
	return false;
}
bool Admin::Check_password(std::string password)
{
	std::string tmp_password = Encode_password(password);
	for (size_t i = 0; i < Users.size(); ++i)
	{
		if (Users[i]->logs_and_pass.second == tmp_password)
			return true;
	}
	return false;
}
bool Admin::Registration()
{
	std::string tmp_login;
	std::string tmp_password;
	cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	std::cout << "Введите ваше ФИО: " << std::endl;
	getline(cin, this->fio);


	std::cout << "Введите ваш адрес: " << std::endl;
	getline(cin, this->home_adress);


	std::cout << "Введите ваш телефон: " << std::endl;
	getline(cin, this->phone_number);


	std::cout << "Введите ваш логин: " << std::endl;
	getline(cin, tmp_login);
	this->adm_login = Encode_login(tmp_login);

	std::cout << "Введите ваш пароль: " << std::endl;
	getline(cin, tmp_password);
	this->adm_password = Encode_password(tmp_password);
	this->is_admin = true;
	return true;
}
size_t Admin::Set_Account_find_student(list <Student*>::iterator it)
{
	size_t id_student = 0;
	for (size_t i = 0; i < Users.size(); ++i)
	{
		if (Users[i]->current_student == (*it))
		{
			id_student = i;
		}
	}
	return id_student;
}
void Admin::Set_Account_login(vector <AccountsInfo*>::iterator itu, std::string value)
{
	for (size_t i = 0; i < Users.size(); ++i)
	{
		if (Users[i]->Get_AccInfo_logs_and_pass().first == Encode_login(value))
		{
			(*itu)->logs_and_pass.first = "";
			throw "\tЛогин занят! Придумайте другой";
		}
	}
	(*itu)->logs_and_pass.first = Encode_login(value);
}
void Admin::Set_Account_password(vector <AccountsInfo*>::iterator itu, std::string value)
{
	(*itu)->logs_and_pass.second = Encode_password(value);
}
bool Admin::Enter(std::string login, std::string password)
{
	if (adm_login == Decode_login(login) && adm_password == Decode_password(password))
	{
		return true;
	}
	else
	{
		std::cout << "Access Denied!!\n";
		return false;
	}
}

void Admin::Exp_to_file_All_Students_Stat()
{
	ofstream f;
	f.open("students.txt");
	if (!f.is_open()) throw !f.is_open();
	if (All_Students.empty()) throw "List Is EMPTY!!!";

	std::list <Student*>::iterator its = All_Students.begin();
	size_t quant_rezults = (*its)->Get_Stud_Rez().size();
	for (; its != All_Students.end(); ++its)
	{
		f <<"ФИО: " << (*its)->Get_Stud_FIO() << std::endl;
		f <<"Домашний адрес: " << (*its)->Get_Stud_HomAddr() << std::endl;
		f <<"Номер телефона: " << (*its)->Get_Stud_Pnumber() << std::endl;
		for (size_t i = 0; i < quant_rezults; ++i)
		{
			if (!(*its)->Get_Stud_Rez()[i]->Get_Question_and_Answers().empty())
			{
				f << "\t" << "Раздел: " << (*its)->Get_Stud_Rez()[i]->Get_Current_Test()->Get_Name_of_Section() << std::endl;
				f << "\t" << "Подраздел: " << (*its)->Get_Stud_Rez()[i]->Get_Current_Test()->Get_Name_of_Subsection() << std::endl;
				f << "\t" << "Название теста: " << (*its)->Get_Stud_Rez()[i]->Get_Current_Test()->Get_Name_of_Test() << std::endl;
				f << "\t" << "Результат: " << (*its)->Get_Stud_Rez()[i]->Get_Rezult_Message() << std::endl;
				f << "\t" << "Количество правильных ответов" << (*its)->Get_Stud_Rez()[i]->Get_Quant_of_Right_Answers() << std::endl;
				f << "\t" << "Оценка: " << (*its)->Get_Stud_Rez()[i]->Get_Score() << std::endl;
			}
			else
				f << "\t" << "Student doesn`t have rezults!!!"<< std::endl;
		}

	}
	cout <<"\t\t" << "Данные выгружены в файл!";
	f.close();
}
void Admin::Exp_to_file_Current_student_Stat(size_t index)
{
	ofstream f;
	f.open("current_student.txt");
	if (!f.is_open()) throw !f.is_open();
	std::list <Student*>::const_iterator its = All_Students.begin();
	size_t quant_rezults = (*its)->Get_Stud_Rez().size();
	advance(its, (index - 1));

	f << (*its)->Get_Stud_FIO() << std::endl;
	f << (*its)->Get_Stud_HomAddr() << std::endl;
	f << (*its)->Get_Stud_Pnumber() << std::endl;
	for (size_t i = 0; i < quant_rezults; ++i)
	{
		f << "\t" << (*its)->Get_Stud_Rez()[i]->Get_Current_Test()->Get_Name_of_Section() << std::endl;
		f << "\t" << (*its)->Get_Stud_Rez()[i]->Get_Current_Test()->Get_Name_of_Subsection() << std::endl;
		f << "\t" << (*its)->Get_Stud_Rez()[i]->Get_Current_Test()->Get_Name_of_Test() << std::endl;
		f << "\t" << (*its)->Get_Stud_Rez()[i]->Get_Rezult_Message() << std::endl;
		f << "\t" << (*its)->Get_Stud_Rez()[i]->Get_Quant_of_Right_Answers() << std::endl;
		f << "\t" << (*its)->Get_Stud_Rez()[i]->Get_Score() << std::endl;
	}
	f.close();
}
void Admin::Exp_to_file_Current_test_Stat(Test* current_test)
{
	ofstream f;
	f.open("current_test.txt");
	if (!f.is_open()) throw !f.is_open();
	std::list <Section*>::const_iterator itt = All_Tests.begin();
	std::list <Student*>::const_iterator its = All_Students.begin();
	size_t quant_subsections = (*itt)->Get_Subsections().size();


	for (; itt != All_Tests.end(); ++itt)
	{
		for (size_t i = 0; i < quant_subsections; ++i)
		{
			for (size_t j = 0; j < (*itt)->Get_Subsections()[i]->Get_Tests().size(); ++j)
			{
				if ((*itt)->Get_Subsections()[i]->Get_Tests()[j] == current_test)
				{
					for (; its != All_Students.end(); ++its)
					{
						for (size_t k = 0; k < (*its)->Get_Stud_Rez().size(); ++k)
						{
							if ((*its)->Get_Stud_Rez()[k]->Get_Current_Test() == current_test)
							{
								f << "\t" << (*its)->Get_Stud_FIO() << std::endl;
								f << "\t" << (*its)->Get_Stud_HomAddr() << std::endl;
								f << "\t" << (*its)->Get_Stud_Pnumber() << std::endl;
								f << "\t" << (*its)->Get_Stud_Rez()[k]->Get_Rezult_Message() << std::endl;
								f << "\t" << (*its)->Get_Stud_Rez()[k]->Get_Score() << std::endl;
							}
						}
					}
				}
			}
		}
	}
	f.close();
}
void Admin::Exp_to_file_All_Sections()
{
	ofstream f;
	f.open("all_sections.txt");
	if (!f.is_open()) throw !f.is_open();
	if (All_Tests.empty()) throw "List Is EMPTY!!!";

	std::list <Section*>::const_iterator itt = All_Tests.begin();
	
	for (int i = 0; itt != All_Tests.end(); ++itt, ++i)
	{
		f <<i+1<<". " << (*itt)->Get_Name_of_Section() << std::endl;
	}
	cout << "\t\t" << "Данные выгружены в файл!";
	f.close();
}
void Admin::Exp_to_file_All_Subsections()
{
	std::list <Section*>::const_iterator it = All_Tests.begin();
	ofstream f;
	f.open("all_subsections.txt");

	if (!f.is_open()) throw !f.is_open();
	if ((*it)->Get_Subsections().empty()) throw "List Is EMPTY!!!\n";

	std::list <Section*>::const_iterator itt = All_Tests.begin();
	for (; itt != All_Tests.end(); ++itt)
	{
		for (size_t i = 0; i < (*itt)->Get_Subsections().size(); ++i)
		{
			f <<i+1<<". " << (*itt)->Get_Subsections()[i]->Get_Name_of_Subsection() << std::endl;
		}
	}
	cout << "\t\t" << "Данные выгружены в файл!";
	f.close();
}
void Admin::Exp_to_file_All_Tests()
{
	ofstream f;
	f.open("all_tests_in_subsections.txt");
	if (!f.is_open()) throw !f.is_open();
	std::list <Section*>::const_iterator itt = All_Tests.begin();

	for (; itt != All_Tests.end(); ++itt)
	{
		for (size_t j = 0; j < (*itt)->Get_Subsections().size(); ++j)
		{
			for (size_t k = 0; k < (*itt)->Get_Subsections()[j]->Get_Tests().size(); ++k)
			{
				f << (*itt)->Get_Subsections()[j]->Get_Tests()[k]->Get_Name_of_Test() << std::endl;
				for (size_t l = 0; l < (*itt)->Get_Subsections()[j]->Get_Tests()[k]->Get_Options().size(); ++l)
				{
					f << (*itt)->Get_Subsections()[j]->Get_Tests()[k]->Get_Options()[l] << std::endl;
				}
			}
		}
	}
	cout << "\t\t" << "Данные выгружены в файл!";
	f.close();
}
void Admin::Exp_to_file_Selected_Test(Test* test)
{
	ofstream f;
	f.open("selected_test.txt");
	if (!f.is_open()) throw !f.is_open();
	
	f << test->Get_Name_of_Test() << std::endl;

	for (size_t i = 0; i < test->Get_Questions().size(); ++i)
	{
		f << i+1 << ". " << test->Get_Questions()[i]->Get_Name_of_Question() << std::endl;

		for (size_t j = 0; j < test->Get_Questions()[i]->Get_Options().size(); ++j)
		{
			f << j + 1 << ". " << test->Get_Questions()[i]->Get_Options()[j] << std::endl;
		}
	}
	cout << "\t\t" << "Данные выгружены в файл!";
	f.close();
}
AccountsInfo::AccountsInfo(Student* current_student, std::string login, std::string password)
{
	this->current_student = current_student;
	this->logs_and_pass.first = login;
	this->logs_and_pass.second = password;
}




Student* Admin::Registration_Student()
{
	std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	Student* new_stud = new Student;

	std::cout << "Введите имя студента: " << std::endl;
	std::getline(std::cin, new_stud->fio);

	std::cout << "Введите домашний адрес студента: " << std::endl;
	getline(std::cin, new_stud->home_adress);

	std::cout << "Введите телефонный номер студента: " << std::endl;
	std::getline(std::cin, new_stud->phone_number);


	std::string tmp_login;
	std::string tmp_password;

again:
	std::cout << "Введите логин: " << std::endl;
	std::cin >> tmp_login;
	tmp_login = Encode_login(tmp_login);
	if (Check_login(tmp_login) == true)
	{
		std::cout << "Такой логин существует. Придумайте другой!" << std::endl;
		goto again;
	}
	else
	{
		std::cout << "Введите пароль: " << std::endl;
		std::cin >> tmp_password;
		tmp_password = Encode_password(tmp_password);
	}
	AccountsInfo* new_acc = new AccountsInfo(new_stud, tmp_login, tmp_password);
	Users.push_back(new_acc);
	All_Students.push_back(new_stud);
	return new_stud;
}
bool Admin::Enter_Student(std::string login, std::string password)
{
	for (size_t i = 0; i < Users.size(); ++i)
	{
		if (Check_login(login) == true && Check_password(password) == true)
		{
			return true;
		}
	}

	return false;
}
Student* Admin::Get_Pointer_Student(std::string login)
{
	std:: string temp_log;
	temp_log = Decode_login(login);
	
	for (size_t i = 0; i < Users.size(); ++i)
	{
		Users[i]->logs_and_pass.first == temp_log;
		return Users[i]->current_student;
	}
}