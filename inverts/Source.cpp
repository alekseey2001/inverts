#include <iostream>
#include <bitset>

void invertBitsInRange(unsigned char* ptr, size_t length) {
    for (size_t i = 0; i < length; ++i) {
        for (int j = 0; j < 8; ++j) {   // обрабатываем каждый бит в текущем байте
            if (j % 8 == 0) {           // инвертируем только каждый восьмой бит
                *ptr ^= (1 << j);       // инвертируем бит с помощью побитовой операции XOR
            }
        }
        ++ptr;                           // переходим к следующему байту
    }
}

int main() {
    setlocale(LC_ALL, "ru");
    unsigned char memory[] = { 0b10011100, 0b11000111, 0b11101100, 0b10000110 }; // Пример данных в памяти
    size_t length = sizeof(memory);                                              // Получаем длину участка памяти в байтах

    std::cout << "Исходные данные: " << std::endl;
    for (size_t i = 0; i < length; ++i) {
        std::cout << std::bitset<8>(memory[i]) << " ";
    }
    std::cout << std::endl;

    invertBitsInRange(memory, length);

    std::cout << "Инвертированные данные: " << std::endl;
    for (size_t i = 0; i < length; ++i) {
        std::cout << std::bitset<8>(memory[i]) << " ";
    }
    std::cout << std::endl;

    return 0;
}