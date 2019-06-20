#include <string>
#include "csci152_student.h"
	/*
	 * Standard argument constructor -- you must copy the arrays!
	 *
	 * Do not worry about illegal inputs for this assignment - you do not need
	 * to throw an exception, or even try to handle them
	 */

csci152_student::csci152_student(
	std::string nm,
	unsigned int *asmts,
	unsigned int num_qs,
	unsigned int *quizzes,
	unsigned int final_exam
) {
		num_of_quizzes = num_qs;
	quiz_scores = new unsigned int[num_of_quizzes];
	assignment_scores = new unsigned int[4];
	name = nm;

	final_exam_score = final_exam;
	for (int i = 0; i < num_of_quizzes; i++) {
		quiz_scores[i] = quizzes[i];
	}
	for (int i = 0; i < 4; i++) {
		assignment_scores[i] = asmts[i];
	}
}

	/*
	 * Copy constructor
	 */
csci152_student::csci152_student(const csci152_student& other) {
	quiz_scores = new unsigned int[num_of_quizzes];
	assignment_scores = new unsigned int[4];
	name = other.name;
	num_of_quizzes = other.num_of_quizzes;
	final_exam_score = other.final_exam_score;
	for (int i = 0; i < num_of_quizzes; i++) {
		quiz_scores[i] = other.quiz_scores[i];
	}
	for (int i = 0; i < 4; i++) {
		assignment_scores[i] = other.assignment_scores[i];
	}
	
}

/*
 * Copy assignment - be careful to properly dispose of allocated memory for this
 * before overwriting with values from other
 */
csci152_student& csci152_student::operator=(const csci152_student& other) {
	if (this == &other) {
		return *this;
	}
	delete[] quiz_scores;
	delete[] assignment_scores;
	num_of_quizzes = other.num_of_quizzes;
	quiz_scores = new unsigned int[num_of_quizzes];
	assignment_scores = new unsigned int[4];
	name = other.name;
	final_exam_score = other.final_exam_score;
	for (int i = 0; i < num_of_quizzes; i++) {
		quiz_scores[i] = other.quiz_scores[i];
	}
	for (int i = 0; i < 4; i++) {
		assignment_scores[i] = other.assignment_scores[i];
	}
	
	return *this;
}


/*
 * Name getter
 */
std::string csci152_student::get_name() const {
	return name;
}

/*
 * Calculates the average assignment score, between 0.0 and 100.0
 */
double csci152_student::calculate_assignment_perc() const {
	double sum = 0;
	int i;
	for (i = 0; i < 4; i++) {
		sum = sum + assignment_scores[i];
	}
	sum = sum / 4;
	return sum;
}

/*
 * Calculates the total quiz percentage, where the lowest score is dropped from
 * from the calculation.  Between 0.0 and 100.0
 */
double csci152_student::calculate_quiz_perc() const {
	double sum = 0;
	double avr;
	int n = 15;
	
	for ( int i = 0; i < num_of_quizzes; i++) {
		if(quiz_scores[i]<n){
			n=quiz_scores[i];
		}
		sum = sum + quiz_scores[i];
	}
	avr = (((sum - n) / (num_of_quizzes - 1))/15)*100;

	return avr;
}

/*
 * Returns the value stored in final_exam_score
 */
unsigned int csci152_student::get_final_exam_perc() const {
	return final_exam_score;
}

/*
 * Calculates the total course grade as a percent, using the weighting from
 * the syllabus
 */
double csci152_student::calculate_course_perc() const {
	double sum;
	sum = ((calculate_assignment_perc() * 20) +(calculate_quiz_perc()* 40) + (get_final_exam_perc() * 40))/100;
	return sum;
}

/*
 * Destructor - don't forget you need to delete anything you explicitly allocated
 */
csci152_student::~csci152_student() {
	delete[] assignment_scores;
	delete[] quiz_scores;
}
