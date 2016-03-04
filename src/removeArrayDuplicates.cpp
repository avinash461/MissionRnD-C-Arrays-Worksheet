/*
OVERVIEW:  given an array that has duplicate values remove all duplicate values.
E.g.: input: [1, 1, 2, 2, 3, 3], output [1, 2, 3]

Ex 2: [4,4,2,2,1,5] output : [4,2,1,5]

INPUTS: Integer array and length of the array .

OUTPUT: Update input array by removing duplicate values and return the final array length

ERROR CASES: Return -1 for invalid inputs.

NOTES: Don't create new array, try to change the input array.
*/

#include <stdio.h>
#include <stdlib.h>

int removeArrayDuplicates(int *Arr, int len)
{
	int new_index = 0, dup_count = 0;
	if ((Arr) && (len>0))
	{

		for (int i = 0; i<len; i++)
		{
			for (int j = i + 1; j<len; j++)
			{
				if (Arr[i] == Arr[j])
				{
					Arr[j] = 'd';   //d-duplicate value replaced with d
				}
			}
		}
		for (int k = 0; k<len; k++)
		{
			if (Arr[k] == 'd')
			{
				dup_count++;
			}
			else
			{
				Arr[new_index] = Arr[k];
				new_index++;
			}
		}
		for (int i = 0; i<new_index; i++)
		{
			printf("%d \n", Arr[i]);
		}
		return new_index;
	}
	else return -1;
}