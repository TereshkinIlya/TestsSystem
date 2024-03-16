#include "TestStruct.h"
#include <string.h>
#include <iostream>
Question::Question(std::string name_of_question, size_t correct_answer, std::vector<std::string> options)
{
	this->name_of_question = name_of_question;
	this->correct_answer = correct_answer;
	this->options = options;
}
Question::Question(const Question& other)
{
	this->name_of_question = other.name_of_question;
	this->correct_answer = other.correct_answer;
	this->options = other.options;
}
Question& Question::operator=(const Question& other)
{
	if (this == &other)
		return *this;
	this->name_of_question = other.name_of_question;
	this->correct_answer = other.correct_answer;
	this->options = other.options;
	return *this;
}
std::ostream& operator << (std::ostream& output, const std::vector<std::string>& options)
{
	for (int i = 0; i < (int)options.size(); ++i)
	{
		output << i + 1 << ". " << options[i] << "\n";
	}
	return output;
}
std::ostream& operator << (std::ostream& output, const Question& question)
{
	output << question.Get_Name_of_Question() << "\n";
	return output;
}
std::ostream& operator << (std::ostream& output, const std::vector<Question*>& questions)
{
	for (int i = 0; i < (int)questions.size(); ++i)
	{
		output << i + 1 << ". " << questions;
	}
	return output;
}


Subsection::Subsection(std::string name_of_subsection, std::vector<Test*> tests) : Subsection(name_of_subsection)
{
	this->tests = tests;
}
Subsection::Subsection(const Subsection& other)
{
	this->name_of_subsection = other.name_of_subsection;
	this->tests = other.tests;
}
Subsection& Subsection::operator=(const Subsection& other)
{
	if (this == &other)
		return *this;
	this->name_of_subsection = other.name_of_subsection;
	this->tests = other.tests;
	return *this;
}
std::ostream& operator << (std::ostream& output, const Subsection& subsection)
{
	output << subsection.Get_Name_of_Subsection() << "\n";
	return output;
}
std::ostream& operator << (std::ostream& output, const std::vector<Subsection*>& subsection)
{
	for (int i = 0; i < (int)subsection.size(); ++i)
	{
		output << i + 1 << ". " << subsection[i] << "\n";
	}
	return output;
}



Section::Section(std::string name_of_section, std::vector<Subsection*> subsections) : Section(name_of_section)
{
	this->subsections = subsections;
}
Section::Section(const Section& other)
{
	this->name_of_section = other.name_of_section;
	this->subsections = other.subsections;
}

Section& Section::operator=(const Section& other)
{
	if (this == &other)
		return *this;
	this->name_of_section = other.name_of_section;
	this->subsections = other.subsections;
	return *this;
}
std::ostream& operator << (std::ostream& output, const Section& section)
{
	output << section.Get_Name_of_Section() << "\n";
	return output;
}



Test::Test(std::string name_of_test, size_t quant_of_questions, std::string name_of_section, std::string name_of_subsection,
	size_t start_position, bool is_finished)
{
	this->name_of_test = name_of_test;
	this->quant_of_questions = quant_of_questions;
	this->name_of_section = name_of_section;
	this->name_of_subsection = name_of_subsection;
	this->is_finished = is_finished;
	this->start_position = start_position;
}
Test::Test(std::string name_of_test, size_t quant_of_questions, std::string name_of_section, bool is_finished,
	std::string name_of_subsection, std::vector<Question*> questions)
	: Test(name_of_test, quant_of_questions, name_of_section, name_of_subsection, is_finished, start_position)
{
	this->questions = questions;
}
Test::Test(const Test& other)
{
	this->name_of_test = other.name_of_test;
	this->quant_of_questions = other.quant_of_questions;
	this->name_of_section = other.name_of_section;
	this->name_of_subsection = other.name_of_subsection;
	this->questions = other.questions;
	this->is_finished = other.is_finished;
	this->start_position = other.start_position;
}
Test& Test::operator=(const Test& other)
{
	if (this == &other)
		return *this;
	this->quant_of_questions = other.quant_of_questions;
	this->name_of_section = other.name_of_section;
	this->name_of_subsection = other.name_of_subsection;
	this->questions = other.questions;
	this->is_finished = is_finished;
	this->start_position = other.start_position;
	return *this;
}
std::ostream& operator << (std::ostream& output, const Test& test)
{
	output << test.Get_Name_of_Test() << "\n";
	return output;
}
std::ostream& operator << (std::ostream& output, const std::vector<Test*>& tests)
{
	for (int i = 0; i < (int)tests.size(); ++i)
	{
		output << i + 1 << ". " << tests[i] << "\n";
	}
	return output;
}