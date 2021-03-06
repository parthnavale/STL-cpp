#include<iostream>
using namespace std;

//add search function

template<typename T>
class vector
{
	T* arr;
	int syz,capa;
	public :
		typedef T* Iterator;
		vector<T>();
		~vector<T>(){
		}
		Iterator begin();
		Iterator end();
		int size();
		int capacity();
		void resize(int);
		bool empty();
		void shrink_to_fit();
		void reserve(int);
		T* back();
		T* front();
		void assign(int,T);
		void push_back(T);
		T pop_back();
		T* insert(int,T);
		T* insert(int,int,T);
		void erase(int);
		void swap(vector<T>&);
		void clear();
		//T* emplace();
		T* operator ++();
		void display();
		T& operator[](int);
		int search(T);
		void count_sort();
};
template<typename T>
vector<T>::vector()
{
	syz=0;
	capa=0;	
}


template<typename T>
typename vector<T>::Iterator vector<T>::begin()
{
	return arr;
}

template<typename T>
typename vector<T>::Iterator vector<T>::end()
{
	return arr+syz;
}

template <typename T>
int vector<T>::size()
{
	return syz;
}

template<typename T>
int vector<T>::capacity()
{
	return capa;
}

template<typename T>
bool vector<T>::empty()
{
	return (syz==0);
}

template<typename T>
void vector<T>::shrink_to_fit()
{
	T*  arr2=new T[syz];
	T* ar;
	for(int i=0;i<syz;i++)
	{
		arr2[i]=arr[i];
	}
	ar=arr;
	arr=arr2;
	delete ar;
	capa=syz;
}

template<typename T>
void vector<T>::resize(int n)
{
	static T* arr2,*ar;
	arr2=new T[n];
	for(int i=0;i<syz;i++)
	{
		arr2[i]=arr[i];
	}
	ar=arr;
	arr=arr2;
	capa=syz;
	delete ar;
}

template<typename T>
void vector<T>::reserve(int n)
{
	if(n>syz)
	{
		capa=n;
		T* arr2=new T[n],*ar;
		for(int i=0;i<syz;i++)
		{
			arr2[i]=arr[i];
		}
		ar=arr;
		arr=arr2;
		delete ar;
	}
}

template<typename T>
T* vector<T>::back()
{
	return &arr[syz-1];
}

template<typename T>
T* vector<T>::front()
{
	return arr;
}

template<typename T>
void vector<T>::assign(int sz,T vl)
{
	if(syz<sz)
	{
		T* arr2=new T[sz],*ar;
		for(int i=0;i<syz;i++)
		{
			arr2[i]=vl;
		}
		ar=arr;
		arr=arr2;
		delete ar;
		syz=sz;
		capa=syz;
	}
	else
	{
		for(int i=0;i<sz;i++)
			arr[i]=vl;
	}
}




template<typename T>
void vector<T>::push_back(T val)
{
	if(syz==capa)
	{
		T* arr2;
		int i=0;
		if(capa==0)
		{
			arr=new T[1];
			capa=1;
		}
		else
		{
			capa=capa*2;
			arr2=new T[capa];
			while(i<syz)
			{
				arr2[i]=arr[i];
				i++;
			}
			delete arr;
			arr=arr2;
		}
	}
	arr[syz]=val;
	syz++;
}

template<typename T>
T vector<T>::pop_back()
{
	syz--;
	return arr[syz];
}

template<typename T>
T* vector<T>::insert(int pos,T val)
{
	syz+=1;
	T* arr2=new T[syz],*ar;
	for(int i=0,j=0;i<syz;i++,j++)
	{
		if(i==pos)
		{
			arr2[i]=val;
			i++;
		}
		arr2[i]=arr[j];
	}		
	ar=arr;
	arr=arr2;
	delete ar;
	capa=syz;
}

template<typename T>
T* vector<T>::insert(int pos,int size,T val)
{
	syz+=size;
	T* arr2=new T[syz],*ar;
	for(int i=0,j=0;i<syz;i++,j++)
	{
		if(i==pos)
		{
			int k=0;
			while(k<size)
			{
				arr2[i]=val;
				k++;
				i++;
			}
		}
		arr2[i]=arr[j];
	}		
	ar=arr;
	arr=arr2;
	delete ar;
	capa=syz;	
}

template<typename T>
void vector<T>::erase(int pos)
{
	if(pos<syz)
	{
		syz-=1;
		T* arr2=new T[syz],*ar;
		for(int i=0,j=0;i<syz;i++,j++)
		{
			if(i==pos)
			{
				j++;
			}
			arr2[i]=arr[j];
		}		
		ar=arr;
		arr=arr2;
		delete ar;
		capa=syz;
	}
}

template<typename T>
void vector<T>::swap(vector<T> &arr2)
{
	if(arr2.size()==syz)
	{	
		T tmp;
		for(int i=0;i<syz;i++)
		{
			tmp=arr2[i];
			arr2[i]=arr[i];
			arr[i]=tmp;
		}
	}
}

template<typename T>
void vector<T>::clear()
{
	delete arr;
	syz=0;
	capa=0;
}

template<typename T>
void vector<T>::display()
{
	cout<<"\n";
	for(int i=0;i<syz;i++)
	{
		cout<<arr[i]<<" "<<endl;
	}
	cout<<"\n";
}
template<typename T>
void vector<T>::count_sort()
{
	 int max =arr[0];
	int min =arr[0];
	 for (int i = 0; i < syz; i++) 
        {
			 if(max<arr[i])
			 {
			 	max=arr[i];
			 }
			 if(min>arr[i])
			 {
			 	min=arr[i];
			 }
  		
		  }
   int n=syz;
    int range = max - min + 1; 
	
    int count[range],output[n];	
    	for(int i=0;i<range;i++)
  		{
  			count[i]=0;
		}
			for(int i=0;i<n;i++)
  		{
  			output[i]=0;
		}   
    
    for (int i = 0; i < syz; i++) 
        count[arr[i] - min]++; 
  
    for (int i = 1; i < range; i++) 
        count[i] += count[i - 1]; 
  
    for (int i = syz - 1; i >= 0; i--) { 
        output[count[arr[i] - min] - 1] = arr[i]; 
        count[arr[i] - min]--; 
    } 
  
    for (int i = 0; i < syz; i++) 
        arr[i] = output[i]; 
}



template<typename T>
T& vector<T>::operator [](int i)
{
	return arr[i];
}
template<typename T>
int vector<T>::search(T val)
{
	int i;
	for(i=0;i<syz;i++)
	{
		if(arr[i]==val)
			break;
	}
	if(i==syz)
		return -1;
	else
		return i;	
}

