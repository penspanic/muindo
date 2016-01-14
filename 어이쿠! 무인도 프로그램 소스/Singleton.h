#pragma once

// 프로그램 상에 하나만의 객체를 사용하게끔 함
template<typename T> class Singleton
{
private:
	static T* m_Instance;

public:
	static T* InstancePtr()
	{
		if (m_Instance == nullptr)		// 객체가 존재하지 않을 경우 
			m_Instance = new T;		// 객체 생성
		return m_Instance;			// 객체포인터 반환
	}
	static void DestroyInstance()
	{
		if (m_Instance != nullptr)
		{
			delete m_Instance;		// 객체 소멸
			m_Instance = nullptr;		// 객체 소멸후 널포인터로 만듬
		}
	}
};

template<class T> T* Singleton<T>::m_Instance = nullptr;	// 초기화

