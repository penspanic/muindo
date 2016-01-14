#pragma once

// ���α׷� �� �ϳ����� ��ü�� ����ϰԲ� ��
template<typename T> class Singleton
{
private:
	static T* m_Instance;

public:
	static T* InstancePtr()
	{
		if (m_Instance == nullptr)		// ��ü�� �������� ���� ��� 
			m_Instance = new T;		// ��ü ����
		return m_Instance;			// ��ü������ ��ȯ
	}
	static void DestroyInstance()
	{
		if (m_Instance != nullptr)
		{
			delete m_Instance;		// ��ü �Ҹ�
			m_Instance = nullptr;		// ��ü �Ҹ��� �������ͷ� ����
		}
	}
};

template<class T> T* Singleton<T>::m_Instance = nullptr;	// �ʱ�ȭ

