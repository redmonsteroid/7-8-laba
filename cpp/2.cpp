#include <iostream>
#include <string>

using namespace std;

// Функция для декодирования строки
string decodeStringRecursive(const string& s, int& index) {
    string result;
    int repeatCount = 0;

    while (index < s.length()) {
        char currentChar = s[index];

        if (isdigit(currentChar)) {
            // Собираем число repeatCount
            repeatCount = repeatCount * 10 + (currentChar - '0');
        } else if (currentChar == '[') {
            // Рекурсивно обрабатываем внутреннюю строку
            string nestedString = decodeStringRecursive(s, ++index);

            // Повторяем внутреннюю строку repeatCount раз
            for (int i = 0; i < repeatCount; ++i) {
                result += nestedString;
            }
            repeatCount = 0;// Сбрасываем repeatCount после использования
        } else if (currentChar == ']') {
            return result;// Возвращаем результат до закрывающей скобки
        } else {
            result += currentChar;// Обычные символы добавляем в результат
        }

        // Увеличиваем индекс для следующего символа
        ++index;
    }

    return result;
}

int main() {
    string encodedString;
    getline(cin, encodedString);
    int index = 0;
    string decodedString = decodeStringRecursive(encodedString, index);
    cout << "Decoded String: " << decodedString << endl;

    return 0;
}
