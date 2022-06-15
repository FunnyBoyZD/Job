#pragma once
#include "stdio.h"
#include "vector.h"
#include <array>
//#define DEBUG

template <typename T>
class matrix
{
public:
	matrix() //����������� �� �������������
	{
#ifdef DEBUG //���� �� �������������� DEBUG, �� ���������� ��� �� #endif �� ���� ����� 
		cout << "���������� ����������� ��� ��������� ����� matrix - " << this << endl << endl;
#endif 
		_matrix = NULL;
		_matrixRowSize = _matrixColumnSize = 0;
	}
	matrix(int matrixRowSize, int matrixColumnSize) //����������� � �����������
	{
#ifdef DEBUG //���� �� �������������� DEBUG, �� ���������� ��� �� #endif �� ���� ����� 
		cout << "���������� ����������� � ����������� ����� matrix - " << this << endl << endl;
#endif 
		_matrixRowSize = matrixRowSize;
		_matrixColumnSize = matrixColumnSize;
		_matrix = (T**) new T*[_matrixRowSize];
		if (!_matrix)
		{
			std::cout << "�� ������� ������� ���'��� �� �������!" << std::endl;
			exit(0);
		}
		for (int i = 0; i < _matrixRowSize; i++)
		{
			if (!(_matrix[i] = (T*) new T[_matrixColumnSize]))
			{
				std::cout << "�� ������� ������� ���'��� �� �������!" << std::endl;
				exit(0);
			}
		}	
		for (int i = 0; i < _matrixRowSize; i++)
		{
			for (int j = 0; j < _matrixColumnSize; j++)
			{
				_matrix[i][j] = 0;
			}
		}
	}
	matrix(const matrix& other) //����������� ���������
	{
#ifdef DEBUG //���� �� �������������� DEBUG, �� ���������� ��� �� #endif �� ���� ����� 
		cout << "���������� ����������� ��������� ����� matrix - " << this << endl << endl;
#endif 
		_matrixRowSize = other._matrixRowSize;
		_matrixColumnSize = other._matrixColumnSize;

		_matrix = (T**) new T*[_matrixRowSize];
		if (!_matrix)
		{
			std::cout << "�� ������� ������� ���'��� �� �������!" << std::endl;
			exit(0);
		}
		for (int i = 0; i < _matrixRowSize; i++)
		{
			if (!(_matrix[i] = (T*) new T[_matrixColumnSize]))
			{
				std::cout << "�� ������� ������� ���'��� �� �������!" << std::endl;
				exit(0);
			}
		}
		for (int i = 0; i < _matrixRowSize; i++)
		{
			for (int j = 0; j < _matrixColumnSize; j++)
			{
				_matrix[i][j] = other._matrix[i][j];
			}
		}
	}
	~matrix() //����������
	{
#ifdef DEBUG //���� �� �������������� DEBUG, �� ���������� ��� �� �� ���� #endif 
		cout << "���������� ���������� ����� matrix - " << this << endl << endl;
#endif 
		if (_matrixRowSize > 0)
		{
			for (int i = 0; i < _matrixRowSize;i++)
			{
				delete[] _matrix[i];
			}
		}
		if (_matrixColumnSize > 0)
		{
			delete[] _matrix;
		}
	}
	matrix operator=(const matrix& other) //�������� ������������
	{
		if (this == &other)
		{
#ifdef DEBUG
			cout << "��������� ����������������!" << endl;
#endif
			return *this;
		}
		if (_matrixRowSize > 0)
		{
			for (int i = 0; i < _matrixRowSize;i++)
			{
				delete[] _matrix[i];
			}
		}
		if (_matrixColumnSize > 0)
		{
			delete[] _matrix;
		}

		_matrixRowSize = other._matrixRowSize;
		_matrixColumnSize = other._matrixColumnSize;

		_matrix = (T**) new T * [_matrixRowSize];
		if (!_matrix)
		{
			std::cout << "�� ������� ������� ���'��� �� �������!" << std::endl;
			exit(0);
		}
		for (int i = 0; i < _matrixRowSize; i++)
		{
			if (!(_matrix[i] = (T*) new T[_matrixColumnSize]))
			{
				std::cout << "�� ������� ������� ���'��� �� �������!" << std::endl;
				exit(0);
			}
		}

		for (int i = 0; i < _matrixRowSize; i++)
		{
			for (int j = 0; j < _matrixColumnSize; j++)
			{
				_matrix[i][j] = other._matrix[i][j];
			}
		}
		return *this;
	}
	matrix operator=(std::array<int, 2> sizes) //���������� ������ �� ������� ������ � ��������� ��������
	{
		if (sizes[0] != _matrixRowSize || _matrixColumnSize != sizes[1])
		{
			for (int i = 0; i < _matrixRowSize;i++)
			{
				delete[] _matrix[i];
			}
			delete[] _matrix;

			_matrixRowSize = sizes[0];
			_matrixColumnSize = sizes[1];

			_matrix = (T**) new T * [_matrixRowSize];
			if (!_matrix)
			{
				std::cout << "�� ������� ������� ���'��� �� �������!" << std::endl;
				exit(0);
			}
			for (int i = 0; i < _matrixRowSize; i++)
			{
				if (!(_matrix[i] = new T[_matrixColumnSize]))
				{
					std::cout << "�� ������� ������� ���'��� �� �������!" << std::endl;
					exit(0);
				}
			}
		}
		for (int i = 0; i < sizes[0]; i++)
		{
			for (int j = 0; j < sizes[1]; j++)
			{
				_matrix[i][j] = 0;
			}
		}
		return *this;
	}
	matrix operator=(std::array<T, 3> sizesAndNumber)
	{
		if (sizesAndNumber[0] != _matrixRowSize || _matrixColumnSize != sizesAndNumber[1])
		{
			for (int i = 0; i < _matrixRowSize;i++)
			{
				delete[] _matrix[i];
			}
			delete[] _matrix;

			_matrixRowSize = sizesAndNumber[0];
			_matrixColumnSize = sizesAndNumber[1];

			_matrix = (T**) new T*[_matrixRowSize];
			if (!_matrix)
			{
				std::cout << "�� ������� ������� ���'��� �� �������!" << std::endl;
				exit(0);
			}
			for (int i = 0; i < _matrixRowSize; i++)
			{
				if (!(_matrix[i] = new T[_matrixColumnSize]))
				{
					std::cout << "�� ������� ������� ���'��� �� �������!" << std::endl;
					exit(0);
				}
			}
		}
		for (int i = 0; i < _matrixRowSize; i++)
		{
			for (int j = 0; j < _matrixColumnSize; j++)
			{
				_matrix[i][j] = sizesAndNumber[2];
			}
		}
		return *this;
	}
	friend matrix operator~(const matrix& other) //�������������� �������
	{
		if (other._matrixRowSize != other._matrixColumnSize)
		{
			std::cout << "��������� ������������� �������� �������!" << std::endl;
			return other;
		}
		for (int i = 0; i < other._matrixRowSize; i++)
		{
			for (int j = 0; j < other._matrixColumnSize; j++)
			{
				other._matrix[j][i] = other._matrix[i][j];
			}	
		}	
		return other;
	}
	matrix operator*(const matrix& other) //�������� �������
	{
		if (_matrixColumnSize != other._matrixRowSize)
		{
			std::cout << "��������� ����������� ����� �������!" << std::endl;
			return *this;
		}
		T** temp = (T**) new T * [_matrixRowSize];
		if (!temp)
		{
			std::cout << "�� ������� ������� ���'��� �� ��������� �������!" << std::endl;
			exit(0);
		}
		for (int i = 0; i < _matrixRowSize; i++)
		{
			temp[i] = new T[other._matrixColumnSize];
			if (!temp[i])
			{
				std::cout << "�� ������� ������� ���'��� ����������� �����!" << std::endl;
				exit(0);
			}
			for (int j = 0; j < other._matrixColumnSize; j++)
			{
				temp[i][j] = 0;
				for (int k = 0; k < _matrixColumnSize; k++)
				{
					temp[i][k] += _matrix[i][k] * other._matrix[k][j];
				}
			}
		}

		_matrixColumnSize = other._matrixColumnSize;
		for (int i = 0; i < _matrixRowSize; i++)
		{
			for (int j = 0; j < _matrixColumnSize; j++)
			{
				_matrix[i][j] = temp[i][j];
			}
		}

		for (int i = 0; i < _matrixRowSize;i++)
		{
			delete[] temp[i];
		}
		delete[] temp;
		return *this;
	}
	vector<T> operator*(vector<T>& other)
	{
		if (other.GetVectorSize() != _matrixColumnSize)
		{
			std::cout << "��������� ����������� ������� ������ � �������!" << std::endl;
			return other;
		}
		for (int i = 0;i < _matrixRowSize;i++)
		{
			T temp = 0;
			for (int j = 0;j < _matrixColumnSize;j++)
			{
				temp += _matrix[i * _matrixColumnSize][j] * other.GetVectorElement(j);
			}
			other.SetVectorElement(i, temp);
		}
		return other;
	}
	matrix operator+(const matrix& other) //����������� ��������� �������
	{
		if (_matrixColumnSize != other._matrixColumnSize || _matrixRowSize != other._matrixRowSize)
		{
			std::cout << "��������� ������ ����� �������!" << std::endl;
			return *this;
		}
		for (int i = 0; i < _matrixRowSize; i++)
		{
			for (int j = 0; j < _matrixColumnSize; j++)
			{
				_matrix[i][j] += other._matrix[i][j];
			}
		}
		return *this;
	}
	matrix operator-(const matrix& other) //����������� �������� �������
	{
		if (_matrixColumnSize != other._matrixColumnSize || _matrixRowSize != other._matrixRowSize)
		{
			std::cout << "��������� ������ ����� �������!" << std::endl;
			return *this;
		}
		for (int i = 0; i < _matrixRowSize; i++)
		{
			for (int j = 0; j < _matrixColumnSize; j++)
			{
				_matrix[i][j] -= other._matrix[i][j];
			}
		}
		return *this;
	}
	matrix operator>>(FILE* fd) //���� � ����
	{
		if (fd = fopen("matrix.txt", "w") == NULL)
		{
			std::cout << "�� ������� ������� ����!" << std::endl;
			exit(0);
		}
		for (int i = 0; i < _matrixRowSize; i++)
		{
			for (int j = 0; j < _matrixColumnSize; j++)
			{
				if (j + 1 == _matrixColumnSize)
				{
					if (!fprintf(fd, "%lf", (double)_matrix[i][j]))
					{
						std::cout << "�� ������ ���������� ������� �� �����!" << std::endl;
						exit(0);
					}
				}
				else
				{
					if (!fprintf(fd, "%lf ", (double)_matrix[i][j]))
					{
						std::cout << "�� ������ ���������� ������� �� �����!" << std::endl;
						exit(0);
					}
				}
			}
			if (!fprintf(fd, "\n"))
			{
				std::cout << "�� ������ ���������� ������� �� �����!" << std::endl;
				exit(0);
			}
		}
		fclose(fd);
	}
	matrix operator<<(FILE* fd) //���� � �����
	{
		if (fd = fopen("matrix.txt", "r") == NULL)
		{
			std::cout << "�� ������� ������� ����!" << std::endl;
			exit(0);
		}
		for (int i = 0; i < _matrixRowSize; i++)
		{
			for (int j = 0; j < _matrixColumnSize; j++)
			{
				fscanf(fd, "%lf", (double)_matrix[i][j]);
			}
		}
		fclose(fd);
	}
	int SetMatrixElement(int i, int j, T elementToSet)
	{
		if (i<0 || j<0 || i>_matrixRowSize || j>_matrixColumnSize)
		{
			std::cout << "�� �������� ���������� �������� ����� ��� ������� �������!" << std::endl;
			return -1;
		}
		else
		{
			_matrix[i][j] = elementToSet;
		}
		return 0;
	}
	T GetMaximumAbs() //������ ��� ������������� �� ��������� ������� ��������
	{
		T maximum = abs(_matrix[0][0]);
		for (int i = 0; i < _matrixRowSize; i++)
		{
			for (int j = 0; j < _matrixColumnSize; j++)
			{
				if (abs(_matrix[i][j]) > maximum)
				{
					maximum = abs(_matrix[i][j]);
				}
			}
		}
		return maximum;
	}
	void Print() //���� ������� �� ������
	{
		for (int i = 0; i < _matrixRowSize; i++)
		{
			for (int j = 0; j < _matrixColumnSize; j++)
			{
				std::cout << _matrix[i][j] << " ";
			}
			std::cout << std::endl;
		}
	}
protected:
	T** _matrix; //�������
	int _matrixRowSize; // ������� �����
	int _matrixColumnSize; // ������� ��������
};