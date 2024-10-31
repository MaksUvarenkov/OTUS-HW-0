#include <mutex>
#include <atomic>


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

template <typename T>
class Singleton{
public:
  static Singleton* getInstance(){
    Singleton* sin= instance.load();
    if ( !sin ){
      std::lock_guard<std::mutex> myLock(myMutex);
      sin= instance.load();
      if( !sin ){
        sin= new Singleton();
        instance.store(sin);
      }
    }   
    // volatile int dummy{};
    return sin;
  }
private:
  Singleton()= default;
  ~Singleton()= default;
  Singleton(const Singleton&)= delete;
  Singleton& operator=(const Singleton&)= delete;

  static std::atomic<Singleton*> instance;
  static std::mutex myMutex;
};

template <typename T>
std::atomic<Singleton<T>*> Singleton<T>::instance;

template <typename T>
std::mutex Singleton<T>::myMutex;


