#pragma once

template<typename T>
void Vector<T>::push_back(const T& el)
{
	if (m_size == m_cap)
	{
		m_cap *= 2;
		T* tmp = new T[m_cap];
		for (int i = 0; i < m_size; i++)
		{
			tmp[i] = m_arr[i];
		}
		delete[] m_arr;
		m_arr = tmp;
		tmp = nullptr;
	}
	m_arr[m_size++] = el;
}

template<typename T>
void Vector<T>::push_back(T&& el)
{
	if (m_size == m_cap)
	{
		m_cap *= 2;
		T* tmp = new T[m_cap];
		for (int i = 0; i < m_size; i++)
		{
			tmp[i] = m_arr[i];
		}
		delete[] m_arr;
		m_arr = tmp;
		tmp = nullptr;
	}
	m_arr[m_size++] = el;
}

template<typename T>
void Vector<T>::pop_back()
{
	if (m_size == 0)
	{
		throw std::out_of_range("");
	}
	m_size--;
	T* tmp = new T[m_cap];
	for (int i = 0; i < m_size; i++)
	{
		tmp[i] = m_arr[i];
	}
	delete[]m_arr;
	m_arr = tmp;
	tmp = nullptr;
}

template<typename T>
void Vector<T>::insert(size_t index, const T& val)
{
	if (index > m_size)
	{
		throw std::out_of_range("");
	}
	if (m_size == m_cap)
	{
		m_cap *= 2;
	}
	T* tmp = new T[m_cap];
	for (int i = 0; i < index; i++)
	{
		tmp[i] = m_arr[i];
	}
	tmp[index] = val;
	for (int i = index + 1; i < m_size + 1; i++)
	{
		tmp[i] = m_arr[i - 1];
	}
	delete[] m_arr;
	m_arr = tmp;
	tmp = nullptr;
}

template<typename T>
void Vector<T>::insert(size_t index, T&& val)
{
	if (index > m_size)
	{
		throw std::out_of_range("");
	}
	if (m_size == m_cap)
	{
		m_cap *= 2;
	}
	T* tmp = new T[m_cap];
	for (int i = 0; i < index; i++)
	{
		tmp[i] = m_arr[i];
	}
	tmp[index] = val;
	for (int i = index + 1; i < m_size + 1; i++)
	{
		tmp[i] = m_arr[i - 1];
	}
	delete[] m_arr;
	m_arr = tmp;
	tmp = nullptr;
}

template<typename T>
size_t Vector<T>::size() const
{
	return m_size;
}

template<typename T>
size_t Vector<T>::capacity() const
{
	return m_cap;
}

template<typename T>
void Vector<T>::clear()
{
	if (!(this->empty()))
	{
		delete[]m_arr;
		m_cap = 1;
		m_size = 0;
		m_arr = new T[m_cap];
	}
}

template<typename T>
void Vector<T>::resize(size_t size)
{
	if (m_cap < size)
	{
		m_cap = size;
		if (!(this->empty()))
		{
			T* tmp = new T[m_cap];
			for (int i = 0; i < m_size; i++)
			{
				tmp[i] = m_arr[i];
			}
			delete[]m_arr;
			m_arr = tmp;
			tmp = nullptr;
		}
	}
}

template<typename T>
void Vector<T>::erase(size_t index)
{
	if (!(this->empty()))
	{	
		T* tmp = new T[m_cap];
		for (int i = 0; i < index; i++)
		{
			tmp[i] = m_arr[i];
		}
		m_size--;
		for (int i = index; i < m_size; i++)
		{
			tmp[i] = m_arr[i + 1];
		}
		delete[]m_arr;
		m_arr = tmp;
		tmp = nullptr;
	}
}

template<typename T>
bool Vector<T>::empty() const
{
	if (m_size == 0)
	{
		return true;
	}
	else
	{
		return false;
	}
}
