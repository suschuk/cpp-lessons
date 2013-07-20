#include <iostream>
#include <algorithm>
#include <vector>
#include <ctime>

class Foo
{
    friend std::ostream& operator<<(std::ostream&, const Foo&);
    friend bool greater(const Foo&, const Foo&);
    friend class FooComparator;
public:
    Foo(int = 0);
    bool operator<(const Foo&) const;


    static void init();
private:
    int i_;
};

class FooComparator
{
public:
    bool operator()(const Foo&, const Foo&) const;
};

int main()
{

    std::vector<Foo> vFoo;

    for(int i = 0; i < 100; ++i)
        vFoo.push_back(Foo());

    for(auto it = vFoo.begin(); it != vFoo.end(); ++it)
        std::cout << *it << " ";   
    std::cout << std::endl;

    std::sort(vFoo.begin(), vFoo.end(), greater);

    for(auto it = vFoo.begin(); it != vFoo.end(); ++it)
        std::cout << *it << " ";   
    std::cout << std::endl;

    std::sort(vFoo.begin(), vFoo.end());

    for(auto it = vFoo.begin(); it != vFoo.end(); ++it)
        std::cout << *it << " ";   
    std::cout << std::endl;

    std::sort(vFoo.begin(), vFoo.end(), FooComparator());

    for(auto it = vFoo.begin(); it != vFoo.end(); ++it)
        std::cout << *it << " ";   
    std::cout << std::endl;
    std::cout << std::endl;


    return 0;
}

Foo::Foo(int i) {
    if(0 != i)
        i_ = i;
    else
        i_ = rand()%90 + 109;
}

void Foo::init()
{
    static bool initialized = false;
    if(!initialized)
    {
        srand(static_cast<unsigned int>(time(0)));
        initialized = true;
    }
}
bool Foo::operator<(const Foo& right) const
{
    return (i_ < right.i_);
}
bool greater(const Foo& left, const Foo& right)
{
    return (left.i_ > right.i_);
}
std::ostream& operator<<(std::ostream& out, const Foo& foo)
{
    return out << foo.i_;
}

bool FooComparator::operator()(const Foo& left, const Foo& right) const
{
    return (left.i_ > right.i_);
}