#include <iostream>
#include <functional>



class Functor {
public:
    Functor(double val) : num (val) { }

        double operator ()(int ark) {
            std::cout.precision(ark); 
            std::cout.setf(std::ios::fixed); 
            return num;
        }
private:
    double num;
};

int main()
{
    setlocale(LC_ALL, "Russian");

    double a, b;
    char c;
    label:
    std::cout << ' ';
    std::cin >> a;
    std::cout << ' ';
    std::cin >> c;
    std::cout << ' ';
    std::cin >> b;
    if (c != '+' && c != '-' && c != '/' && c != '*' && c != '^') {
        std::cout << "Введите следующие математические действия: +,-,*,/,^ (степень)" << std::endl;
        goto label;
    }
    auto resalt = [&a, &b, &c]() -> double {
        switch (c) {
        case '+': return (a + b);
        case '-': return (a - b);
        case '*': return (a * b);
        case '/': return (a / b);
        case '^': return pow(a, b);
        }
    };
    int ark;
    std::cout << "Введите количество знаков после запятой ->";
    std::cin >> ark;
    Functor functor(resalt ());
   
    std::cout << functor (ark) << std::endl;

return 0;
}