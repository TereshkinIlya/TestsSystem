#pragma once
#include <iostream>
#include <string>
#include<algorithm>
#include <map>
#include <vector>
#include"TestStruct.h"


class Rezult_of_Test
{
	friend class Admin;
private:
	Test* current_test;
	std::pair<size_t, size_t> correct_and_stud_answers;
	bool is_passed;
	std::string rez_msg;
	size_t quant_of_right_answers;
	size_t score;
	std::map <Question*, std::pair<size_t, size_t>> quest_and_answers;
public:
	Rezult_of_Test() :current_test{ nullptr }, is_passed{ false },
		rez_msg{ "" }, quant_of_right_answers{ 0 }, score{ 0 } 
	{correct_and_stud_answers.first = 0; correct_and_stud_answers.second = 0;}
	Rezult_of_Test(Test* current_test, std::pair<size_t, size_t> correct_and_stud_answers, bool is_passed, std::string rez_msg,
		std::map <Question*, std::pair<size_t, size_t>> quest_and_answers, size_t quant_of_right_answers, size_t score);
	Rezult_of_Test(const Rezult_of_Test& other);

	Rezult_of_Test& operator = (const Rezult_of_Test& other);
	friend std::ostream& operator << (std::ostream& output, const std::pair<size_t, size_t>& correct_and_stud_answers);
	friend std::ostream& operator << (std::ostream& output, const std::map <Question*, std::pair<size_t, size_t>>& quest_and_answers);

	Test* Get_Current_Test() const { return current_test; }
	std::pair<size_t, size_t> Get_List_of_Answers() const { return correct_and_stud_answers; }
	bool Get_Rezult() const { return is_passed; }
	std::string Get_Rezult_Message() const { return rez_msg; }
	size_t Get_Quant_of_Right_Answers() const { return quant_of_right_answers; }
	size_t Get_Score() const { return score; }
	std::map <Question*, std::pair<size_t, size_t>> Get_Question_and_Answers() const { return quest_and_answers; }
	
	void Calculate_Score(Test* selected_test, Rezult_of_Test* rezult);

};

class Student
{
	friend class Admin;
private:
	std::string fio;
	std::string home_adress;
	std::string phone_number;
	std::vector<Rezult_of_Test*> rezults;
public:
	Student() :fio{ "" }, home_adress{ "" }, phone_number{ 0 } {}
	Student(std::string fio, std::string home_adress, std::string phone_number);
	Student(std::string fio, std::string home_adress, std::string phone_number, std::vector<Rezult_of_Test*> rezults);
	Student(const Student& other);

	Student& operator = (const Student& other);
	std::string Get_Stud_FIO() const { return fio; }
	std::string Get_Stud_HomAddr() const { return home_adress; }
	std::string Get_Stud_Pnumber() const { return phone_number; }
	std::vector<Rezult_of_Test*> Get_Stud_Rez() const { return rezults; }
};

