#include <iostream>

using namespace std;

void insertionSort(int myArray[], int length)
{
	int j, temp;

	for (int i = 1; i < length; i++)
	{
		j = i;

		while (j > 0 && myArray[j] < myArray[j - 1])
		{
			temp = myArray[j];
			myArray[j] = myArray[j - 1];
			myArray[j - 1] = temp;
			j--;
		}
	}
}

void selectionSort(int myArray[], int length)
{
	int i, j, first, temp;
	for (i = length - 1; i > 0; i--)
	{
		first = 0;                 // initialize to subscript of first element
		for (j = 1; j <= i; j++)   // locate smallest between positions 1 and i.
		{
			if (myArray[j] > myArray[first])
				first = j;
		}
		temp = myArray[first];		// Swap smallest found with element in position i.
		myArray[first] = myArray[i];
		myArray[i] = temp;
	}
	return;
}

void bubbleSort(int myArray[], int length)
{
	int i, j, flag = 1;				// set flag to 1 to start first pass
	int temp;						// holding variable
	for (i = 1; (i <= length) && flag; i++)
	{
		flag = 0;
		for (j = 0; j < (length - 1); j++)
		{
			if (myArray[j + 1] < myArray[j])	// ascending order simply changes to <
			{
				temp = myArray[j];				// swap elements
				myArray[j] = myArray[j + 1];
				myArray[j + 1] = temp;
				flag = 1;		               // indicates that a swap occurred.
			}
		}
	}
	return;
}

void merge(int *, int, int, int);
void mergeSort(int myArray[], int low, int high)
{
	int mid;

	if (low < high)
	{
		mid = (low + high) / 2;

		mergeSort(myArray, low, mid);
		mergeSort(myArray, mid + 1, high);
		merge(myArray, low, high, mid);
	}
	return;
}
void merge(int myArray[], int low, int high, int mid)
{
	int i, j, k, c[50];
	i = low;
	k = low;
	j = mid + 1;

	while (i <= mid && j <= high)
	{
		if (myArray[i] < myArray[j])
		{
			c[k] = myArray[i];
			k++;
			i++;
		}
		else
		{
			c[k] = myArray[j];
			k++;
			j++;
		}
	}
	while (i <= mid)
	{
		c[k] = myArray[i];
		k++;
		i++;
	}
	while (j <= high)
	{
		c[k] = myArray[j];
		k++;
		j++;
	}

	for (i = low; i < k; i++)
	{
		myArray[i] = c[i];
	}
}

int partition(int myArray[], int top, int bottom);
void quickSort(int myArray[], int top, int bottom)
{
	// top = subscript of beginning of array
	// bottom = subscript of end of array

	int middle;
	if (top < bottom)
	{
		middle = partition(myArray, top, bottom);
		quickSort(myArray, top, middle);   		// sort first section
		quickSort(myArray, middle + 1, bottom); // sort second section
	}
	return;
}
//Function to determine the partitions
// partitions the array and returns the middle subscript
int partition(int myArray[], int top, int bottom)
{
	int x = myArray[top];
	int i = top - 1;
	int j = bottom + 1;
	int temp;
	do
	{
		do
		{
			j--;
		} while (x < myArray[j]);

		do
		{
			i++;
		} while (x > myArray[i]);

		if (i < j)
		{
			temp = myArray[i];
			myArray[i] = myArray[j];
			myArray[j] = temp;
		}
	} while (i < j);
	return j;           // returns middle subscript 
}

int main(void) 
{ 
	cout << "Insertion Sort" << endl;
	{
		int myArray[10] = { 3, 6, 1, 0, 8, 9, 5, 4, 2, 7 };

		for (int i : myArray)
			cout << i << " ";
		cout << endl;
		insertionSort(myArray, 10);
		for (int i : myArray)
			cout << i << " ";
		cout << endl;
	}

	cout << "Selection Sort" << endl;
	{
		int myArray[10] = { 3, 6, 1, 0, 8, 9, 5, 4, 2, 7 };
		for (int i : myArray)
			cout << i << " ";
		cout << endl;
		selectionSort(myArray, 10);
		for (int i : myArray)
			cout << i << " ";
		cout << endl;
	}

	cout << "Bubble Sort" << endl;
	{
		int myArray[10] = { 3, 6, 1, 0, 8, 9, 5, 4, 2, 7 };
		for (int i : myArray)
			cout << i << " ";
		cout << endl;
		bubbleSort(myArray, 10);
		for (int i : myArray)
			cout << i << " ";
		cout << endl;
	}

	cout << "Merge Sort" << endl;
	{
		int myArray[10] = { 3, 6, 1, 0, 8, 9, 5, 4, 2, 7 };
		for (int i : myArray)
			cout << i << " ";
		cout << endl;
		mergeSort(myArray, 0, 9);
		for (int i : myArray)
			cout << i << " ";
		cout << endl;
	}

	cout << "Quick Sort" << endl;
	{
		int myArray[10] = { 3, 6, 1, 0, 8, 9, 5, 4, 2, 7 };
		for (int i : myArray)
			cout << i << " ";
		cout << endl;
		quickSort(myArray, 0, 9);
		for (int i : myArray)
			cout << i << " ";
		cout << endl;
	}

	return 0; 
}