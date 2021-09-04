#include <iostream>
#include <string>
#include <tuple>
#include <initializer_list>
#include <type_traits>
#include <vector>
#include <typeinfo>
#include <typeindex>
#include <cstdlib>
#include <string>
#include <algorithm>
#ifndef _MSC_VER
#include <cxxabi.h>
#endif
#include <stdexcept>
#include <memory>

#define _L(...) "[" #__VA_ARGS__ "]"
#define L(...) _L(__VA_ARGS__)

template <class T>
std::string type_name()
{
    typedef typename std::remove_reference<T>::type TR;
    std::unique_ptr<char, void (*)(void *)> own(
#ifndef _MSC_VER
            abi::__cxa_demangle(typeid(TR).name(), nullptr, nullptr, nullptr),
#else
            nullptr,
#endif
            std::free);
    std::string r = own != nullptr ? own.get() : typeid(TR).name();
    if (std::is_const<TR>::value)
        r += " const";
    if (std::is_volatile<TR>::value)
        r += " volatile";
    if (std::is_lvalue_reference<T>::value)
        r += "&";
    else if (std::is_rvalue_reference<T>::value)
        r += "&&";
    return r;
}

class __print
{
private:
    template <typename T>
    void __print_elem(const T &elem, std::size_t depth)
    {
        *file << elem;
    }

    template <typename T>
    void __print_elem(const std::vector<T> &vec, std::size_t depth)
    {
        if (show_type)
            *file << "std::vector<" << type_name<decltype(vec[0])>() << ">";

        *file << "[";

        __print_elem(vec[0], depth + 1);
        for (std::size_t i = 1; i < vec.size(); i++)
        {
            *file << ", ";
            __print_elem(vec[i], depth + 1);
        }

        *file << "]";
    }

    template <std::size_t I = 0, typename... Tp>
    inline typename std::enable_if<I == 0, void>::type
    __print_tuple(std::tuple<Tp...> &t)
    {
        __print_elem(std::get<I>(t), 0);
        __print_tuple<I + 1, Tp...>(t);
    }

    template <std::size_t I = 0, typename... Tp>
    inline typename std::enable_if<(I < sizeof...(Tp)) && (I != 0), void>::type
    __print_tuple(std::tuple<Tp...> &t)
    {
        *file << sep;
        __print_elem(std::get<I>(t), 0);
        __print_tuple<I + 1, Tp...>(t);
    }

    template <std::size_t I = 0, typename... Tp>
    inline typename std::enable_if<I == sizeof...(Tp), void>::type
    __print_tuple(std::tuple<Tp...> &t)
    {
        *file << end;
        if (flush)
            file->flush();
    }

public:
    bool flush;
    bool show_type;
    std::string end;
    std::string sep;
    std::ostream *file;
    bool reset = false;

    __print()
    {
        end = "\n";
        sep = " ";
        flush = false;
        show_type = false;
        file = new std::ostream(std::cout.rdbuf());
    }

    ~__print()
    {
        free(file);
    }

    void clear()
    {
        delete file;
        end = "\n";
        sep = " ";
        flush = false;
        show_type = false;
        file = new std::ostream(std::cout.rdbuf());
    }

    template <class... Args>
    inline void operator()(Args &&...args)
    {
        auto _args = std::make_tuple(std::forward<Args>(args)...);
        __print_tuple(_args);
        if (reset)
        {
            clear();
        }
    }
};

thread_local __print print{};
using namespace std;

struct item {
    short high;
    short mid;
};

ostream& operator<<(ostream& os, const item& foo) {
    os << "<" << foo.high << ", " << foo.mid << ">";
    return os;
}

inline short second_highest(int a, int b, int c, int d) {
    vector<int> foo({a,b,c,d});
    sort(foo.begin(), foo.end());
    if (foo[1] == foo[2] == foo[3])
        return foo[0];
    if (foo[2] == foo[3])
        return foo[1];
    return foo[2];
}

void solve() {
    int n;
    cin >> n;

    vector<item> nums(n);
    for (int i=0; i<n; i++) {
        int temp;
        cin >> temp;
        nums[i].high = temp;
    }

    vector<vector<item>> DP(n, vector<item>(1));

    for (int i=0; i<n; i++) {
        DP[i][0] = nums[i];
    }

    for (int l=1; l<n; l++) {
        for (int i=0; i<n-l; i++) {
            DP[i].push_back({
                max({DP[i][l-1].high, DP[i][l-1].mid, DP[i+1][l-1].high, DP[i+1][l-1].mid}),
                second_highest(DP[i][l-1].high, DP[i][l-1].mid, DP[i+1][l-1].high, DP[i+1][l-1].mid)
            });
        }
    }

    int sum = 0;

    for (int i=0; i<n; i++) {
        for (int j=0; j<DP[i].size(); j++) {
            sum += DP[i][j].mid;
        }
    }

    for (auto& row:DP)
         print(row);

    //print(sum);
    printf("%d", sum);
}


int main() {
    solve();
}