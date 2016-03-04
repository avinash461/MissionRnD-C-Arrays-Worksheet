/*
OVERVIEW:  You are given scores for students of a class in alphabetical order. Write a function that sorts these scores in descending order.
Input is array of structures of type student (each student has name and score).
E.g.: If input is [ { "stud1", 20 }, { "stud2", 30 }, { "stud3", 40 } ] (three students with marks 20, 30 , 40).
Output for this will be [ { "stud3", 40 }, { "stud2", 30 }, { "stud1", 20 } ]

INPUTS: Array of structures of type student, length of array.

OUTPUT: Sort the array in descending order of scores.

ERROR CASES: Return NULL for invalid Inputs.

NOTES:
*/

#include <stdio.h>
void quickSort(struct student *students, int start, int end);
struct student {
	char name[10];
	int score;
};

void * scoresDescendingSort(struct student *students, int len) {
	if (students == NULL || len <= 0)
		return NULL;

	quickSort(students, 0, len - 1);

	return NULL;

}
void quickSort(struct student *students, int start, int end)
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
		quickSort(students, start, right - 1);
		quickSort(students, right + 1, end);
	}
}