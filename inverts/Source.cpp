#include <iostream>
#include <bitset>

void invertBitsInRange(unsigned char* ptr, size_t length) {
    for (size_t i = 0; i < length; ++i) {
        for (int j = 0; j < 8; ++j) {   // ������������ ������ ��� � ������� �����
            if (j % 8 == 0) {           // ����������� ������ ������ ������� ���
                *ptr ^= (1 << j);       // ����������� ��� � ������� ��������� �������� XOR
            }
        }
        ++ptr;                           // ��������� � ���������� �����
    }
}

int main() {
    setlocale(LC_ALL, "ru");
    unsigned char memory[] = { 0b10011100, 0b11000111, 0b11101100, 0b10000110 }; // ������ ������ � ������
    size_t length = sizeof(memory);                                              // �������� ����� ������� ������ � ������

    std::cout << "�������� ������: " << std::endl;
    for (size_t i = 0; i < length; ++i) {
        std::cout << std::bitset<8>(memory[i]) << " ";
    }
    std::cout << std::endl;

    invertBitsInRange(memory, length);

    std::cout << "��������������� ������: " << std::endl;
    for (size_t i = 0; i < length; ++i) {
        std::cout << std::bitset<8>(memory[i]) << " ";
    }
    std::cout << std::endl;

    return 0;
}