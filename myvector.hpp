#pragma once
#include<iostream>
#include<algorithm>
#include<string>
using std::string;

template<class T>
class MyVector {
public:
	MyVector();
	MyVector(int n);
	MyVector(const MyVector& other);
	MyVector(int n, const T& elem);
	MyVector(int begin, int end);
	~MyVector();
	T& at(int idx)  const {
		return m_array[idx];
	}
	T* begin() const  {return m_array;}
	T* end() const {return m_array + m_size;}
	void clear() {m_size = 0;}
	bool empty() const  {return m_size == 0;}
	T* insert(int pos, const  T& elem);
	//T* insert(int pos, int n, T& elem);
	void erase(int pos);
	void erase(int begin, int end);
	void resize(int n);
	void multi_by_two();
	int size() const { return this->m_size; }
	int max_size()const { return this->m_max_size; }
	int capaticy()const { return this->m_used_size; }
	void pop_back();
	void push_back(const T& elem);
	T& front()const  { return this->m_array[0]; }
	T& back()const  { return this->m_array[m_size - 1];}
	T& operator[](int idx);
	MyVector& operator=(const MyVector& other);
	
private:
	T* m_array;
	int m_used_size; // record  real size
	int m_size;
	int m_max_size;

};







const int index_size = 50;

template<class T>
MyVector<T>::MyVector() {
	m_max_size = index_size;
	m_used_size = 0;
	m_size = 0;
	m_array = new T[m_max_size];

}

template<class T>
MyVector<T>::MyVector(int n) {
	m_max_size = n;
	m_used_size = m_size = 0;
	m_array = new T[n];
}

template<class T>
T& MyVector<T>::operator[](int idx) {
	return m_array[idx];
}

template<class T>
MyVector<T>::MyVector(const MyVector<T>& other) {
	m_used_size = m_size = other.size();
	m_max_size = other.max_size();
	m_array = new T[m_max_size];
	for (int i = 0; i < m_size; i++) {
		m_array[i] = other.at(i);
	}
}

template<class T>
MyVector<T>::MyVector(int n, const T& elem) {
	m_max_size = std::max(n, index_size) + 1;
	m_size = m_used_size = n;
	m_array = new T[m_max_size];
	for (int i = 0; i < n; i++) {
		m_array[i] = elem;
	}
}

template<class T>
MyVector<T>::MyVector( int begin, int end) {
	m_max_size = std::max(end - begin + 1, index_size) + 1;
	m_used_size = m_size = end - begin + 1;
	m_array = new int[m_size];
	for (int i = begin; i <= end; i++) {
		m_array[i - begin] = i;
	}
}

template<class T>
MyVector<T>::~MyVector() {
	if (m_array != nullptr) {
		delete[] m_array;
		m_array = nullptr;
	}
}

template<class T>
void MyVector<T>::multi_by_two() {
	m_max_size *= 2;
	T* temp_array = new T[m_max_size];
	for (int i = 0; i < m_size; i++) {
		temp_array[i] = m_array[i];
	}
	delete[] m_array;
	m_array = temp_array;

}

template<class T>
T* MyVector<T>::insert(int pos, const T& elem) {
	if (m_size + 1 == m_max_size) {
		multi_by_two();
	}
	for (int i = m_size; i >= pos; i++) {
		m_array[i] = m_array[i - 1];
	}
	m_array[pos - 1] = elem;
	m_size++;
	m_used_size++;
	return &m_array[pos - 1];
}

template<class T>
void MyVector<T>::erase(int pos) {
	for (int i = pos - 1; i < m_size - 1; i++) {
		m_array[i] = m_array[i + 1];
	}
	m_size--;
}

template<class T>
void MyVector<T>::erase(int begin, int end) {
	int dis = end - begin + 1;                           // 1 2 3 4 5
	for (int i = end; i < m_size; i++) {             // 2 3 4
		m_array[i - dis] = m_array[i];
	}
	m_size -= dis;
}

template<class T>
void MyVector<T>::resize(int n) {
	m_size = m_used_size = 0;
	if (m_array != nullptr) {
		delete[] m_array;
	}
	m_array = new T[n];
	m_max_size = n;

}

template<class T>
void MyVector<T>::push_back(const T& elem) {
	if (m_size + 1 == m_max_size) {
		multi_by_two();
	}
	m_array[m_size++] = elem;
}

template<class T>
void MyVector<T>::pop_back() {
	m_size--;
}

template<class T>
MyVector<T>& MyVector<T>::operator=(const MyVector<T>& other) {
	if (&other == this) return *this;

	m_used_size = m_size = other.size();
	if (m_array != nullptr) {
		delete[] m_array;
	}
	m_max_size = other.max_size();
	m_array = new T[m_max_size];
	for (int i = 0; i < m_size; i++) {
		m_array[i] = other.at(i);
	}

	return *this;

}


