package main

import (
	"fmt"
)

// Функция для декодирования строки
func decodeStringRecursive(s string, index *int) string {
	result := ""
	repeatCount := 0

	for *index < len(s) {
		currentChar := s[*index]

		if currentChar >= '0' && currentChar <= '9' {
			// Собираем число repeatCount
			repeatCount = repeatCount*10 + int(currentChar-'0')
		} else if currentChar == '[' {
			// Рекурсивно обрабатываем внутреннюю строку
			*index++
			nestedString := decodeStringRecursive(s, index)

			// Повторяем внутреннюю строку repeatCount раз
			for i := 0; i < repeatCount; i++ {
				result += nestedString
			}
			repeatCount = 0 // Сбрасываем repeatCount после использования
		} else if currentChar == ']' {
			// Встретили закрывающую скобку, возвращаем результат до этого момента
			return result
		} else {
			// Обычные символы добавляем в результат
			result += string(currentChar)
		}

		// Увеличиваем индекс для следующего символа
		*index++
	}

	return result
}

func main() {
	var encodedString string
	fmt.Println("Введите закодированную строку:")
	fmt.Scanln(&encodedString)

	index := 0
	decodedString := decodeStringRecursive(encodedString, &index)
	fmt.Println("Decoded String:", decodedString)
}
