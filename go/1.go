package main

import (
	"fmt"
)

// Рекурсивная функция для проверки возможности раскраски домов
func canPaintHouses(currentHouse int, colors []int, N int, K int) bool {
	// Базовый случай: если все дома раскрашены успешно
	if currentHouse == N {
		return true
	}

	// Перебираем все доступные цвета для текущего дома
	for color := 1; color <= K; color++ {
		// Проверяем условие, что цвет не должен повторяться ранее, чем через 2 дома
		if (currentHouse < 2 || (colors[currentHouse-2] != color)) && (currentHouse == 0 || colors[currentHouse-1] != color) {
			// Пробуем раскрасить текущий дом в данный цвет
			colors[currentHouse] = color

			// Рекурсивно вызываем функцию для следующего дома
			if canPaintHouses(currentHouse+1, colors, N, K) {
				return true // Если удалось успешно раскрасить остальные дома
			}

			// Откатываем изменения (backtrack), если не удалось раскрасить дома дальше
			colors[currentHouse] = 0
		}
	}

	// Если не удалось найти подходящую раскраску
	return false
}

func main() {
	var N, K int
	fmt.Println("Введите количество домов (N): ")
	fmt.Scan(&N)
	fmt.Println("Введите количество цветов (K): ")
	fmt.Scan(&K)

	colors := make([]int, N) // Создаем срез для хранения цветов домов

	// Проверяем возможность раскраски домов
	if canPaintHouses(0, colors, N, K) {
		fmt.Println("Можно раскрасить дома с заданными условиями.")
		fmt.Println("Раскраска домов:")
		for i := 0; i < N; i++ {
			fmt.Printf("Дом %d: Цвет %d\n", i+1, colors[i])
		}
	} else {
		fmt.Println("Невозможно раскрасить дома с заданными условиями.")
	}
}
