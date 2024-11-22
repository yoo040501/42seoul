#include "Array.hpp"

int main()
{
 try {
        Array<int> arr1;
        std::cout << "arr1 size: " << arr1.size() << std::endl;

        Array<int> arr2(5);
        std::cout << "arr2 size: " << arr2.size() << std::endl;

        for (size_t i = 0; i < arr2.size(); ++i) {
            arr2[i] = i + 1;
        }

        std::cout << "arr2 elements: ";
        for (size_t i = 0; i < arr2.size(); ++i) {
            std::cout << arr2[i] << " ";
        }
        std::cout << std::endl;

        Array<int> arr3(arr2);
        std::cout << "arr3 (copied from arr2) elements: ";
        for (size_t i = 0; i < arr3.size(); ++i) {
            std::cout << arr3[i] << " ";
        }
        std::cout << std::endl;

        Array<int> arr4(arr3);
        arr4 = arr2;
        std::cout << "arr4 (assigned from arr2) elements: ";
        for (size_t i = 0; i < arr4.size(); ++i) {
            std::cout << arr4[i] << " ";
        }
        std::cout << std::endl;

        // 범위를 벗어난 접근 테스트
        try {
            std::cout << arr2[10] << std::endl;
        } catch (const std::out_of_range& e) {
            std::cout << "Caught exception: " << e.what() << std::endl;
        }

        // 다른 타입으로 테스트
        Array<std::string> strArr(3);
        strArr[0] = "Hello";
        strArr[1] = "World";
        strArr[2] = "!";
        std::cout << "String array elements: ";
        for (size_t i = 0; i < strArr.size(); ++i) {
            std::cout << strArr[i] << " ";
        }
        std::cout << std::endl;

    } catch (const std::exception& e) {
        std::cerr << "Unexpected exception: " << e.what() << std::endl;
    }

    return 0;
}
