#include <iostream>

/* Thread synchronization muteksi i�in yer tutucu */
class Mutex
{   /* Bir muteks olu�turmak, kullanmak ve serbest b�rakmak i�in i�in yer tutucu */
};

/* Thread synchronization lock i�in yer tutucu */
class Lock
{
public:
    Lock(Mutex& m) : mutex(m) { /* Muteks elde etmek i�in yer tutucu kodu */ }
    ~Lock() { /* Mutex'i serbest b�rakmak i�in yer tutucu kod */ }
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

    // �lk eri�im s�ras�nda ba�lat�ld�
    static Singleton inst(1);

    return &inst;
}

int main()
{
    Singleton* singleton = Singleton::GetInstance();
    std::cout << "The value of the singleton: " << singleton->a << std::endl;
    return 0;
}