/* Name : Anshul Bahukhandi
   Date : 1/29/2016

This code implements the famous heapsort algorithm to 
sort an array. It inputs the data from a text file and 
write the data back to another output text file . 
Time complexity of heapsort is O(nlogn)  

*/


#include<iostream>
#include<string>
#include<fstream>

using namespace std; 

/*function to take input from a text file */

int input( int * array  , const string filename)
{
	int i =0 ;
	ifstream fin;
	fin.open(filename.c_str());
	if(!fin.is_open()) 
		cout<<"File failed to open !\n";
	else
	{
		while(!fin.eof())
		{
			fin>>array[i];
			i++;
		}
	}

	fin.close();
	return i;
}

/*Function to write the array to output file*/

void output( int * array , int count  , std::string filename)
{
	ofstream fout;
	fout.open(filename.c_str());
	for ( int i = 0 ; i<count ; i++)
		fout<<array[i]<<"\n";

	fout.close();

}

/* Function to make the Maximum-Heap of the input array */
void createHeap(int *array , int count )
{
	count = count-1; //changing count to index
	int i = count /2;
	while(i>=0)
	{
		int parent = i;
		int child = 2*parent +1 ; 
		while(child<=count)   //loop to go deeper at every value of i 
		{
			if(child+1 <= count && array[child+1] > array[child])
				child++;
			if(array[parent]<array[child])
			{		
				int temp = array[parent];
				array[parent]=array[child];
				array[child]=temp;
			}

			parent=child; 
			child=2*parent + 1;
		}
		i--;
	}
}

/*Function to sort the input array using the heap procedure*/
void sort(int * array , int count)
{

	createHeap(array , count);

	int temp = array[count-1];
	array[count-1]= array[0];
	array[0]=temp;
	count = count-1;

	if(count>1)
	sort(array , count);
}


int main()
{
	/*Taking input from the text file and storing into an array*/
	int count; 
	int * array=new int[20];
	count = input(array , "test.in");

	/*Making the Max-Heap of the input array */
	sort(array , count);

/*Writing the output to the text file*/

	output(array ,count , "test.out");
	
	cout<<"Heap Sorting complete!\n";
	return 0 ; 

}

