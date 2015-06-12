#ifndef VECTOR_H
#define VECTOR_H

template<typename T>
class Vector{
private:
	int m_capacity;
	int m_size;
	T *m_pData;
public:
	Vector(){
		m_capacity = 1;
		m_size = 0;
		m_pData = new T[m_capacity];
	}
	Vector(int c)
	{
		if (c <= 0)
		{
			throw std::invalid_argument("The size must be a positive integer!");
		}
		else
		{
			m_size = 0;
			m_capacity = c;
			m_pData = new T[m_capacity];
		}
	}
	Vector(const Vector& p)  // copy constr
	{
		m_size = p.m_size;
		m_capacity = p.m_capacity;
		m_pData = p.m_pData;
	}
	Vector (int c, const T& val)  // fill constr
    {
		if (c <= 0)
		{
			throw std::invalid_argument("The size must be a positive integer!");
		}
		else
		{
			m_size = c;
			m_capacity = c;
			m_pData = new T[m_capacity];
			for(int i = 0; i < m_size; i++)
			{
				m_pData[i] = val;
			}
		}
    }
	Vector& operator=(const Vector& p)
	{
		if (this != &p)
		{
			m_size = p.m_size;
			m_capacity = p.m_capacity;
			m_pData = p.m_pData;
		}
		return *this;
	}
	~Vector()
	{
		delete[] m_pData;
	}
	void push_back(T value){
		if (m_size >= m_capacity)
		{
			reserve();
		}
		m_pData[m_size] = value;
		m_size++;
	}
	void pop_back(){
		m_size--;
	}
	void resize(int newSize)
	{
		if (newSize < m_size)
		{
			for (int i = newSize; i < m_size; i++)
			{
				m_pData[i].~T();
			}
		}
		else if (newSize > m_capacity)
		{
			reserve(newSize);
		}
		m_size = newSize;
	}
	void reserve(int newcapacity = -1)
	{
		if (newcapacity > m_capacity)
		{
			T* temp = new T[newcapacity];
			for (int i = 0; i < m_size; i++){
				temp[i] = m_pData[i];
			}
			delete[] m_pData;
			m_pData = temp;
			m_capacity = newcapacity;
		}
		else if(newcapacity == -1)
		{
			int newCapacity = m_capacity * 2;
			T *temp = new T[newCapacity];
			for (int i = 0; i < m_size; i++){
				temp[i] = m_pData[i];
			}
			delete[] m_pData;
			m_pData = temp;
			m_capacity = newCapacity;
		}
	}
	T& front(){
		return m_pData[0];
	}
	T& back(){
		return m_pData[m_size - 1];
	}
	void insert(int i, T value)
	{
		if (i >= m_capacity)
		{
			throw std::invalid_argument("The position must less than: " + m_capacity);
		}
		if (m_size >= m_capacity)
		{
			reserve();
		}
		m_size++;
		for (int j = m_size - 1; j > i; j--)
		{
			m_pData[j] = m_pData[j - 1];
		}
		m_pData[i] = value;
	}
	void erase(int i)
	{
		for (int j = i; j < m_size - 1; j++)
		{
			m_pData[j] = m_pData[j + 1];
		}
		m_size--;
	}
	T& operator[](int index){
		return m_pData[index];
	}
	int size(){
		return m_size;
	}
	int capacity(){
		return m_capacity;
	}
	bool empty(){
		if (m_size == 0) return 1;
		return 0;
	}
	void clear()
	{
		for (int i = 0; i < m_size; i++)
			{
				m_pData[i].~T();
			}
		T* temp = new T[1];
		delete[] m_pData;
		m_pData = temp;
		m_size = 0;
		m_capacity = 0;
	}
	void shrink_to_fit()
	{
		T* temp = new T[m_size];
		for (int i = 0; i < m_size; i++){
			temp[i] = m_pData[i];
		}
		delete[] m_pData;
		m_pData = temp;
		m_capacity = m_size;
	}
	void swap(int n1, int n2)
	{
		T swap = m_pData[n1];
		m_pData[n1] = m_pData[n2];
		m_pData[n2] = swap;
	}
	T* begin() 
	{
		return m_pData;
	}
	T* end() 
	{
		return m_pData + size();
	}
};

#endif 