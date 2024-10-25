#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

Base*	generate(void){
	int	value = rand() % 3;
	if (value == 0) {
        std::cout << "A created" << std::endl;
        return new A();
    } else if (value == 1) {
        std::cout << "B created" << std::endl;
        return new B();
    } else {
        std::cout << "C created" << std::endl;
        return new C();
    }
}

void	identify(Base* p)
{
	if (dynamic_cast<A*>(p))
		std::cout << "This is A: " << p << std::endl;
	else if (dynamic_cast<B*>(p))
		std::cout << "This is B: " << p << std::endl;
	else if (dynamic_cast<C*>(p))
		std::cout << "This is C: " << p << std::endl;
	else
		std::cout << "Unknown type" << p << std::endl;
}

void	identify(Base& p)
{
	try {
        A& a = dynamic_cast<A&>(p);
        std::cout << "This is A: " << &a << std::endl;
    } catch (const std::bad_cast&) {
        try {
            B& b = dynamic_cast<B&>(p);
            std::cout << "This is B: " << &b << std::endl;
        } catch (const std::bad_cast&) {
            try {
                C& c = dynamic_cast<C&>(p);
                std::cout << "This is C: " << &c << std::endl;
            } catch (const std::bad_cast&) {
                std::cout << "Unknown type: " << std::endl;
            }
        }
    }
}

int main(){
	srand(time(NULL));

	Base* base = generate();
	std::cout << "Base: " << base << std::endl;
	identify(*base);
	delete (base);
	return 0;
}
