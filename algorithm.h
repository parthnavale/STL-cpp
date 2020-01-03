#include<iostream>
//sort(first_itr,last_itr)   //checked
//reverse(first_itr,last_itr)
//*max_element(first_itr,last_itr)
//*max_element(first_itr,last_itr)
//accumulate(*max_element(first_itr,last_itr)
template<typename T>
void swap(T *i,T *j)
{
	T tmp=*i;
	*i=*j;
	*j=tmp;
}
template<typename T>
T* partition(T* i,T* j)
{
	T* start=i;
		do{
			do{
				++i;;
			}while(*i<*start);
			do{
				--j;
			}while(*j>*start);
			if(i<j)
				swap(i,j);
		}while(i<j);
		swap(j,start);
		return j;		
}
template<typename T>
void qsort(T* i,T* j)
{
	T* k=NULL;
	if(i<j)
	{
		if(*i>*j)
			swap(i,j);
		k=partition(i,j);
		qsort(i,k-1);
		qsort(k+1,j);
	}
}
template<typename T>
void sort(T* first_itr,T* last_itr)
{
	T* i=first_itr,*j=last_itr-1;
	qsort(i,j);
}

//binary_search()            correct for char data type
//lower_bound upper_bound    correct for char data types
//void erase(pos)			 already in vector.h
//next_permutation(C)	swap function not working
//prev_permutation(first_itr,last_itr)	swap function not working
//distance(first_itr,last_itr)			correct for char data types 			

//Checked Correct
template <typename T>
bool binary_search(T* first_itr,T* last_itr,T val)
{
	T* arr=first_itr;
	int r=(last_itr-first_itr)/sizeof(T)-1,l=0;
	int mid=(r/2);
	cout<<l<<mid<<r<<endl;
	while(l<r)
	{
		int mid=(l+r/2);
		cout<<l<<mid<<r<<endl;
		if(arr[mid]==val)
		{
			cout<<"Found";
			return 1;
		}
		if(arr[mid]>val)
		{
			cout<<"First half";
			r=mid-1;
		}
		if(arr[mid]<val)
		{
			cout<<"Second half";
			l=mid;
		}
	}
	return 0;
}

//checked correct
template <typename T>
T* lower_bound(T* first_itr,T* last_itr,T val)
{
	T* a=first_itr;
	while(a!=last_itr)
	{
		if(*a>=val)
		{
			break;
		}
		a++;
	}
	return a;
}

//checked correct
template <typename T>
T* upper_bound(T* first_itr,T* last_itr,T val)
{
	T* a=first_itr;
	while(a!=last_itr)
	{
		if(*a>val)
		{
			break;
		}
		a++;
	}
	return a;
}


// checked swap function not working
template<typename T>
void swap(T &a, T &b)
{
    T t = a;
    a = b;
    b = t;
}

template <typename T>
bool next_permutation(T* first_itr,T* last_itr)
{
	T* arr=first_itr;
	int size=(last_itr-first_itr)/sizeof(T);
	int r=size-1,l;
	l=r-1;
	cout<<size<<endl;
	while(arr[r]<arr[l])
	{
		r-=1;
		l-=1;
	}
	if(arr[r]>arr[l])
	{
		cout<<"Before :"<<arr[l]<<arr[r]<<endl;
//		swap(arr[r],arr[l]);
		T temp=arr[l];
		arr[l]=arr[r];
		arr[r]=temp;
		cout<<"After :"<<arr[l]<<arr[r]<<endl;
		return true;		
	}		
return false;
}
//prev_permutation(first_itr,last_itr)

template <typename T>
void distance(T* first_itr,T* last_itr)
{
	int size=(last_itr-first_itr)/sizeof(T);
	cout<<size;
//	return size;
}

