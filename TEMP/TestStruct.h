#pragma once
#include <iostream>
#include <string>
#include <vector>


class Test;

class Question
{
	friend class Admin;
protected:
	std::string name_of_question;
	size_t correct_answer;
	std::vector<std::string> options;
public:
	Question() :name_of_question{ "" }, correct_answer{ 0 } {}
	Question(std::string name_of_question, size_t correct_answer, std::vector<std::string> options);
	Question(const Question& other);

	Question& operator = (const Question& other);
	friend std::ostream& operator << (std::ostream& output, const Question& question);
	friend std::ostream& operator << (std::ostream& output, const std::vector<std::string>& options);
	friend std::ostream& operator << (std::ostream& output, const std::vector<Question*>& questions);

	std::string Get_Name_of_Question() const { return name_of_question; }
	std::vector<std::string> Get_Options() const { return options; }
	size_t Get_Correct_of_Question() const { return correct_answer; }
};

class Subsection
{
	friend class Admin;
protected:
	std::string name_of_subsection;
	std::vector<Test*> tests;
public:
	Subsection() :name_of_subsection{ "" } {}
	Subsection(std::string name_of_subsection) { this->name_of_subsection = name_of_subsection; }
	Subsection(std::string name_of_subsection, std::vector<Test*> tests);
	Subsection(const Subsection& other);

	Subsection& operator = (const Subsection& other);
	friend std::ostream& operator << (std::ostream& output, const Subsection& subsection);
	friend std::ostream& operator << (std::ostream& output, const std::vector<Subsection*>& subsection);

	std::string Get_Name_of_Subsection() const { return name_of_subsection; }
	std::vector<Test*> Get_Tests() const { return tests; }
};

class Section
{
	friend class Admin;
protected:
	std::string name_of_section;
	std::vector<Subsection*> subsections;
public:
	Section() :name_of_section{ "" } {}
	Section(std::string name_of_section) { this->name_of_section = name_of_section; }
	Section(std::string name_of_section, std::vector<Subsection*> subsections);
	Section(const Section& other);

	Section& operator = (const Section& other);
	friend std::ostream& operator << (std::ostream& output, const Section& section);
	friend std::ostream& operator << (std::ostream& output, const Subsection& subsection);

	std::string Get_Name_of_Section() const { return name_of_section; }
	std::vector<Subsection*> Get_Subsections() const { return subsections; }
};

class Test : public Subsection, public Section, public Question
{
	friend class Admin;
private:
	std::string name_of_test;
	size_t start_position;
	size_t quant_of_questions;
	bool is_finished;
	std::vector<Question*> questions;
public:
	Test() :quant_of_questions{ 0 }, name_of_test{ "" }, is_finished{ false }, start_position{ 0 }
	{ this->name_of_subsection = ""; this->name_of_section = ""; }
	Test(std::string name_of_test, size_t quant_of_questions, std::string name_of_section, std::string name_of_subsection,
		size_t start_position, bool is_finished);
	Test(std::string name_of_test, size_t quant_of_questions, std::string name_of_section, bool is_finished,
		std::string name_of_subsection, std::vector<Question*> questions);
	Test(const Test& other);

	Test& operator = (const Test& other);
	friend std::ostream& operator << (std::ostream& output, const Test& test);
	friend std::ostream& operator << (std::ostream& output, const std::vector<Test*>& tests);

	std::string Get_Name_of_Test() const { return name_of_test; }
	std::string Get_Name_of_Subsection() const { return this->name_of_subsection; }
	std::string Get_Name_of_Section() const { return this->name_of_section; }
	size_t Get_Quant_of_Questions() const { return quant_of_questions; }
	size_t Get_Start_Position() const { return start_position; }
	bool Get_Mark_is_Finished() const { return is_finished; }
	std::vector<Question*> Get_Questions() const { return questions; }

};
