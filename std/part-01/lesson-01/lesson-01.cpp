#include <iostream>
// #include <cstddef>
#include <vector>
#include <complex>
#include <list>

class CMovable {
    friend   std::ostream& operator<<(std::ostream&, const CMovable&);
    public:
        CMovable(char* p = nullptr) : pch(p) {}
        // CMovable(const CMovable& r) : pch(_strdup(r.pch)) {}
        CMovable(CMovable&& r) {
            std::cout << " Move ctor";
            pch = r.pch;
            r.pch = nullptr;

        }
      
    private:

        char* pch;
};
CMovable bar() {

    CMovable m("InBarCreated");
    return m;

}




int main() {

    std::cout << "Part I. Lesson # 1." << std::endl;

    // 1.1 compiler 

    if( __cplusplus == 201103L)

        std::cout << "this compiler declares C++0x or C++11 compatibility" << std::endl;

    else if( __cplusplus == 199711L)

        std::cout << "this compiler declares C++98 and C++03 compatibility" << std::endl;

    else

        std::cout << "this compiler makes no difference in C++11 and C++03 / C++98" << std::endl;

    // 2.2 nullptr

    void foo(void*);

    foo(nullptr);

    nullptr_t my_nullptr;
    my_nullptr;
    foo(my_nullptr);

    // 1.3. Initializers
/*  Doesn't work: 

    std::vector<int> v  { 2, 3, 5, 7, 11, 13, 17 };
    std::vector<std::string> cities { "Berlin", "New York", "London", "Braunschweig", "Cairo", "Cologne" };
    std::complex<double> c{4.0,3.0}; // equivalent to c(4.0,3.0)

    std::ostream_iterator<std::string> out_it(std::cout, ", ");
    std::copy(cities.begin(), cities.end(), out_it);
*/

    char* cities[] = { "Berlin", "New York", "London", "Braunschweig", "Cairo", "Cologne" };

    std::ostream_iterator<std::string> out_it(std::cout, ", ");
    std::copy(cities, cities + sizeof(cities)/sizeof(cities[0]), out_it);
    std::cout << std::endl;

    std::list<std::string> lst;
    lst.resize(sizeof(cities)/sizeof(cities[0]));

    std::copy(cities, cities + sizeof(cities)/sizeof(cities[0]), lst.begin());


    for ( auto x : lst ) {
        std::cout << x << std::endl;
    }

    // 1.4. Movable semantics

    CMovable first("first"), second("second");

    std::cout << first << second;

    CMovable third ( std::move(first) );

    std::cout << first << second << third;

    std::cout << bar() << std::endl;

    // 1.5. Raw literals

/*  error C2065: 'R' : undeclared identifier

    char* pRaw = R"nc(a\
                   b\nc()"
                   )nc";
*/
    // 1.6. Alias template
/*
    template <typename T>  using Vec = std::vector<T,MyAlloc<T>>; // standard vector using own allocator
    Vec<int> coll;
*/
    // 1.6. lambdas

    [] { std::cout << "hello lambda" << std::endl; } (); // prints ‘‘hello lambda’’

    auto l = [] (const std::string& s) { std::cout << s << std::endl; };
    l("hello lambda"); // prints ‘‘hello lambda’’

}

void foo(void* arg) {

    if(0 == arg) {

        std::cout << "NULL pointer passed to foo()" << std::endl;
    }
}

std::ostream& operator<<(std::ostream& out, const CMovable& x) {

    return out << (x.pch == nullptr ? "Empty object" : x.pch) << std::endl;
}