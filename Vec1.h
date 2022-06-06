#pragma once

template<typename T>
Vector<T>::Vector(size_t num)
{
	m_cap = num;
	m_size = num;
	m_arr = new T[m_cap];
}

template<typename T>
Vector<T>::Vector(size_t num, T init)
{
	m_cap = num;
	m_size = num;
	m_arr = new T[m_cap];
	for (int i = 0; i < m_size; i++)
	{
		m_arr[i] = init;
	}
}

template<typename T>
Vector<T>::Vector(std::initializer_list<T>& lst) 
{
	m_cap = lst.size();
	m_size = m_cap;
	m_arr = new T[m_cap];
	int num = 0;
	for (auto i = lst.begin(); i != lst.end; i++)
	{
		m_arr[num++] = i;
	}
}

template<typename T>
Vector<T>::Vector(const Vector& oth)
{
	m_cap = oth.m_cap;
	m_size = oth.m_size;
	if (!oth.empty())
	{
		T* tmp = new T[m_cap];
		for (int i = 0; i < m_size; i++)
		{
			tmp[i] = oth.m_arr[i];
		}
		if (m_arr)
		{
			delete[]m_arr;
		}
		m_arr = tmp;
		tmp = nullptr;
	}
}

template<typename T>
Vector<T>::Vector(Vector&& tmp)
{
	m_cap = tmp.m_cap;
	m_size = tmp.m_size;
	m_arr = tmp.m_arr;

	tmp.m_cap = 0;
	tmp.m_size = 0;
	tmp.m_arr = nullptr;
}

template<typename T>
Vector<T>& Vector<T>::operator=(const Vector& oth)
{
	if (this == oth)
	{
		return *this;
	}
	m_cap = oth.m_cap;
	m_size = oth.m_size;
	if (!oth.empty())
	{
		T* tmp = new T[m_cap];
		for (int i = 0; i < m_size; i++)
		{
			tmp[i] = oth.m_arr[i];
		}
		if (m_arr)
		{
			delete[]m_arr;
		}
		m_arr = tmp;
		tmp = nullptr;
	}

	return *this;
}

template<typename T>
Vector<T>& Vector<T>::operator=(Vector&& tmp)
{
	m_cap = tmp.m_cap;
	m_size = tmp.m_size;
	m_arr = tmp.m_arr;

	tmp.m_cap = 0;
	tmp.m_size = 0;
	tmp.m_arr = nullptr;

	return *this;
}

template<typename T>
T& Vector<T>::at(size_t index)
{
	if (index >= m_size)
	{
		throw std::out_of_range("");
	}
	return m_arr[index];
}

template<typename T>
T& Vector<T>::at(size_t index) const
{
	if (index >= m_size)
	{
		throw std::out_of_range("");
	}
	return m_arr[index];
}


template<typename T>
T& Vector<T>::operator[](size_t index)
{
	return m_arr[index];
}

template<typename T>
T& Vector<T>::operator[](size_t index) const
{
	return m_arr[index];
