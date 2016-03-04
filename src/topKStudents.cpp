/*
OVERVIEW:  You are given scores for students of a class in alphabetical order. Write a function that returns the names and scores of top K students.
Input is array of structures of type student (each student has name and score).
E.g.: If input is [ { "stud1", 20 }, { "stud2", 30 }, { "stud3", 40 } ] (three students with marks 20, 30 , 40) and K value is 2.
return top 2 students [ { "stud2", 30 }, { "stud3", 40 } ]

INPUTS: array of structures of type student, length of the array, integer K.

OUTPUT: Return top K students from array. Output need not be in decreasing order of scores.

ERROR CASES: Return NULL for invalid inputs.

NOTES:
*/

#include <iostream>
#include <malloc.h>
void q_Sort(struct student *students, int start, int end);
struct student {
	char *name;
	int score;
};

struct student ** topKStudents(struct student *students, int len, int K) {
	struct student **new_array;
	new_array = (struct student**)malloc(2 * sizeof(struct student));
	if (students == NULL || len <= 0 || K <= 0)
		return NULL;

	q_Sort(students, 0, len - 1);
	for (int i = 0; i < K; i++)
	{
		new_array[i] = &students[i];
	}
	return new_array;

	return NULL;
}

void q_Sort(struct student *students, int start, int end)
{
	int pivot, left, right;
	struct student temp;

	if (start < end)
	{
		pivot = start;
		left = start;
		right = end;

		//Sorting in descending order 
		while (left < right)
		{
			while (students[left].score >= students[pivot].score && left < end)
			{
				left++;
			}
			while (students[right].score<students[pivot].score)
			{
				right--;
			}

			if (left<right)
			{
				temp = students[left];
				students[left] = students[right];
				students[right] = temp;
			}
		}

		//swapping pivot element with right element
		temp = students[pivot];
		students[pivot] = students[right];
		students[right] = temp;

		//partioning
		q_Sort(students, start, right - 1);
		q_Sort(students, right + 1, end);
	}
}