#include <mutex>
#include <atomic>
#include <iostream>


// template <typename T>
// class Singleton
// {
//     friend T;
// public:
//     static T& instance();

// private:
//     Singleton() = default;
//     ~Singleton() = default;
//     Singleton( const Singleton& ) = delete;
//     Singleton& operator=( const Singleton& ) = delete;
// };

// template <typename T>
// T& Singleton<T>::instance()
// {
//     static T inst;
//     return inst;
// }

//https://stackoverflow.com/questions/41328038/singleton-template-as-base-class-in-c

template <typename T>
class Singleton {
	friend T;
public:
	static T& GetInstance(){
		std::call_once(initInstanceFlag, &Singleton::initSingleton);
		// volatile int dummy{};
		return *instance;
	}
private:
	Singleton()= default;
	~Singleton()= default;
public:
	Singleton(const Singleton&)= delete;
	Singleton& operator=(const Singleton&)= delete;

private:
	static T* instance;
	static std::once_flag initInstanceFlag;

	static void initSingleton(){
		instance = new T;
	}
};
template <typename T>
T* Singleton<T>::instance= nullptr;

template <typename T>
std::once_flag Singleton<T>::initInstanceFlag;


