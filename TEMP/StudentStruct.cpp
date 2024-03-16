
#include "StudentStruct.h"
#include <vector>

Rezult_of_Test::Rezult_of_Test(Test* current_test, std::pair<size_t, size_t> correct_and_stud_answers, bool is_passed,
	std::string rez_msg, std::map <Question*, std::pair<size_t, size_t>> quest_and_answers, size_t quant_of_right_answers, size_t score)
{
	this->current_test = current_test;
	this->correct_and_stud_answers = correct_and_stud_answers;
	this->is_passed = is_passed;
	this->rez_msg = rez_msg;
	this->quest_and_answers = quest_and_answers;
	this->quant_of_right_answers = quant_of_right_answers;
	this->score = score;
}
Rezult_of_Test::Rezult_of_Test(const Rezult_of_Test& other)
{
	this->current_test = other.current_test;
	this->correct_and_stud_answers = other.correct_and_stud_answers;
	this->is_passed = other.is_passed;
	this->rez_msg = other.rez_msg;
	this->quest_and_answers = other.quest_and_answers;
	this->quant_of_right_answers = other.quant_of_right_answers;
	this->score = other.score;
}
Rezult_of_Test& Rezult_of_Test::operator= (const Rezult_of_Test& other)
{
	if (this == &other)
		return *this;
	this->current_test = other.current_test;
	this->correct_and_stud_answers = other.correct_and_stud_answers;
	this->is_passed = other.is_passed;
	this->rez_msg = other.rez_msg;
	this->quest_and_answers = other.quest_and_answers;
	this->quant_of_right_answers = other.quant_of_right_answers;
	this->score = other.score;
	return *this;
}
std::ostream& operator << (std::ostream& output, const std::pair<size_t, size_t>& correct_and_stud_answers)
{
	output << "Correct answer: " << correct_and_stud_answers.first << "\n" <<
		"Student answer: " << correct_and_stud_answers.second << "\n";
	return output;
}
std::ostream& operator << (std::ostream& output, const std::map <Question*, std::pair<size_t, size_t>>& quest_and_answers)
{
	std::map<Question*, std::pair<size_t, size_t>>::const_iterator it = quest_and_answers.begin();
	for (; it != quest_and_answers.end(); ++it)
	{
		output << (*it).first->Get_Name_of_Question() << "\n" << "Correct answer: " << (*it).second.first << "\n" <<
			"Student answer: " << (*it).second.second;
	}
	return output;
}
void Rezult_of_Test::Calculate_Score(Test* selected_test, Rezult_of_Test* rezult)
{
	size_t quant_of_questions = selected_test->Get_Quant_of_Questions();
	double tmp = rezult->Get_Quant_of_Right_Answers() / quant_of_questions;
	tmp = int(tmp * 10 + 0.5) / 10.0;
	rezult->score = size_t(tmp * 10);
	if (rezult->score >= 10.0 || rezult->score <= 12.0)
	{
		rezult->is_passed = true;
		rezult->rez_msg = "Great !!! Your rating is 5";
	}
	else if (rezult->score >= 7.0 || rezult->score < 10.0)
	{
		rezult->is_passed = true;
		rezult->rez_msg = "Good !!! Your rating is 4";
	}
	else if (rezult->score >= 4.0 || rezult->score < 7.0)
	{
		rezult->is_passed = true;;
		rezult->rez_msg = "Bad !!! Your rating is 3";
	}
	else if (rezult->score < 4.0)
	{
		rezult->is_passed = true;;
		rezult->rez_msg = "You`r Looser !!! Your rating is 2";
	}
}


Student::Student(std::string fio, std::string home_adress, std::string phone_number)
{
	this->fio = fio;
	this->home_adress = home_adress;
	this->phone_number = phone_number;
}
Student::Student(std::string fio, std::string home_adress, std::string phone_number, std::vector<Rezult_of_Test*> rezults)
{
	this->fio = fio;
	this->home_adress = home_adress;
	this->phone_number = phone_number;
	this->rezults = rezults;
}
Student::Student(const Student& other)
{
	this->fio = other.fio;
	this->home_adress = other.home_adress;
	this->phone_number = other.phone_number;
	this->rezults = other.rezults;
}
Student& Student::operator= (const Student& other)
{
	if (this == &other)
		return *this;
	this->fio = other.fio;
	this->home_adress = other.home_adress;
	this->phone_number = other.phone_number;
	this->rezults = other.rezults;
	return *this;
}