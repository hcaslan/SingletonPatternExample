#include <iostream>

/* Thread synchronization muteksi için yer tutucu */
class Mutex
{   /* Bir muteks oluþturmak, kullanmak ve serbest býrakmak için için yer tutucu */
};

/* Thread synchronization lock için yer tutucu */
class Lock
{
public:
    Lock(Mutex& m) : mutex(m) { /* Muteks elde etmek için yer tutucu kodu */ }
    ~Lock() { /* Mutex'i serbest býrakmak için yer tutucu kod */ }
private:
    Mutex& mutex;
};

class Singleton
{
public:
    static Singleton* GetInstance();
    int a;
    ~Singleton() { std::cout << "In Destructor" << std::endl; }

private:
    Singleton(int _a) : a(_a) { std::cout << "In Constructor" << std::endl; }

    static Mutex mutex;
};

Mutex Singleton::mutex;

Singleton* Singleton::GetInstance()
{
    Lock lock(mutex);

    std::cout << "Get Instance" << std::endl;

    // Ýlk eriþim sýrasýnda baþlatýldý
    static Singleton inst(1);

    return &inst;
}

int main()
{
    Singleton* singleton = Singleton::GetInstance();
    std::cout << "The value of the singleton: " << singleton->a << std::endl;
    return 0;
}