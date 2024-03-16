#pragma once
#include <iostream>
#include <fstream>
#include <list>
#include <string>
#include"TestStruct.h"
#include"StudentStruct.h"

class AccountsInfo;
extern std::list <Section*> All_Tests;
extern std::vector  <AccountsInfo*> Users;
extern std::list <Student*> All_Students;

class Admin
{
private:
	std::string fio;
	std::string home_adress;
	std::string phone_number;
	std::string adm_login;
	std::string adm_password;
	bool is_admin;
public:
	Admin() :fio{ "" }, home_adress{ "" }, phone_number{ 0 }, adm_login{ "" }, adm_password{ "" }, is_admin{ false } {}
	Admin(std::string fio, std::string home_adress, std::string phone_number, std::string adm_login, std::string adm_password, bool is_admin);

	std::string Get_Admin_fio() const { return fio; }
	std::string Get_Admin_adress() const { return home_adress; }
	std::string Get_Admin_phone_number() const { return phone_number; }
	std::string Get_Admin_login() const { return adm_login; }
	std::string Get_Admin_password() const { return adm_password; }

	void Set_Admin_name(std::string fio);
	void Set_Admin_adress(std::string adress);
	void Set_Admin_phonenumber(std::string phone_number);
	void Set_Admin_login(std::string login);
	void Set_Admin_password(std::string password);
	bool Get_Admin_is_admin() const { return is_admin; }
	std::string Get_Admin_Decode_login() { return Decode_login(this->adm_login); }
	std::string Get_Admin_Decode_password() { return Decode_password(this->adm_password); }
	
	void Set_Option_name(Question* question, std::string value);
	void Set_Question_name(Question* question, std::string value);
	void Set_Question_correct_answer(Question* question, size_t value);
	void Set_Question_option(Question* question, size_t index, std::string value);
	void Add_Question_option(Question* question, std::string value);
	void Add_Question(Test* test, Question* question);
	void Del_Question(Test* test, size_t index);
	void Del_Question_option(Question* question, size_t index);

	void Set_Test_name(Test* test, std::string value);
	void Set_Test_quant_of_questions(Test* test, size_t value);
	void Set_Test_name_subsection(Test* test, std::string value);
	void Set_Test_name_section(Test* test, std::string value);
	void Set_Test_start_position(Test* test, size_t value);
	void Set_Test_start_0(Test* test);
	void Set_Test_is_finished(Test* test, bool value);
	void Add_Test(Test* test, Subsection* subsection);
	void Del_Test(Test* test, size_t index);

	void Set_Subsection_name(Subsection* subsection, std::string value);
	void Del_Subsection(Section* section, size_t index);
	void Add_Subsection_empty(Section* section, std::string value);

	void Set_Section_name(Section* section, std::string value);
	void Add_Section_empty(std::string value);
	void Del_Section(size_t index);

	void Set_Student_fio(Student* student, std::string value);
	void Set_Student_adress(Student* student, std::string value);
	void Set_Student_phone_number(Student* student, std::string value);
	void Add_Student();
	void Del_Student(size_t index);
	Student* Registration_Student();
	bool Enter_Student(std::string login, std::string password);
	Student* Get_Pointer_Student(std::string login);

	void Set_Rezults_add_rezult(Rezult_of_Test* rezult, Student* student);
	void Set_Rezults_current_test(Rezult_of_Test* rezults, Test* test);
	void Set_Rezults_correct_answ(Rezult_of_Test* rezults, Question* question, size_t value);
	void Set_Rezults_stud_answ(Rezult_of_Test* rezults, Question* question, size_t value);
	void Set_Rezults_flag_rezult(Rezult_of_Test* rezults, bool value);
	void Set_Rezults_messg_rezult(Rezult_of_Test* rezults, std::string value);
	void Set_Rezults_quant_of_Rig_Answ(Rezult_of_Test* rezults, size_t value);
	void Set_Rezults_score(Rezult_of_Test* rezults, size_t value);
	void Set_Rezults_correct_and_stud_answers(Rezult_of_Test* rezult, Question* question, std::pair<size_t, size_t> correct_and_stud_answers);
	void Set_Rezult_general_right_answers(Rezult_of_Test* new_rez);
	int Get_All_Passed_Tests(Student* current_student);
	int Get_All_Failed_Tests(Student* current_student);
	int Get_All_Waiting_Tests(Student* current_student);
	
	std::string Encode_login(std::string login);
	std::string Encode_password(std::string password);
	std::string Decode_login(std::string login);
	std::string Decode_password(std::string password);
	bool Registration();
	bool Check_login(std::string login);
	bool Check_password(std::string password);
	bool Enter(std::string login, std::string password);
	

	size_t Set_Account_find_student(std::list <Student*>::iterator it);
	void Set_Account_login(std::vector <AccountsInfo*>::iterator itu, std::string value);
	void Set_Account_password(std::vector <AccountsInfo*>::iterator itu, std::string value);

	void Exp_to_file_All_Students_Stat();
	void Exp_to_file_All_Sections();
	void Exp_to_file_All_Subsections();
	void Exp_to_file_All_Tests();
	void Exp_to_file_Selected_Test(Test* test);
	void Exp_to_file_Current_student_Stat(size_t index);
	void Exp_to_file_Current_test_Stat(Test* current_test);

	

	
};

class AccountsInfo
{
	friend class Admin;
private:
	Student* current_student;
	std::pair <std::string, std::string> logs_and_pass;
public:
	AccountsInfo() : current_student{ nullptr } { logs_and_pass.first = ""; logs_and_pass.second = ""; }
	AccountsInfo(Student* current_student, std::string login, std::string password);

	Student* Get_AccInfo_current_student() const { return current_student; }
	std::pair <std::string, std::string> Get_AccInfo_logs_and_pass() const { return logs_and_pass; }
};



