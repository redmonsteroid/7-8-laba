#include <iostream>
#include <vector>

using namespace std;

// Рекурсивная функция для проверки возможности раскраски домов
bool canPaintHouses(int currentHouse, vector<int>& colors, int N, int K) {
    // Базовый случай: если все дома раскрашены успешно
    if (currentHouse == N) {
        return true;
    }

    // Перебираем все доступные цвета для текущего дома
    for (int color = 1; color <= K; ++color) {
        // Проверяем условие, что цвет не должен повторяться ранее, чем через 2 дома
        if ((currentHouse < 2 || (colors[currentHouse - 2] != color)) && colors[currentHouse - 1] != color) {
            // Пробуем раскрасить текущий дом в данный цвет
            colors[currentHouse] = color;
            
            // Рекурсивно вызываем функцию для следующего дома
            if (canPaintHouses(currentHouse + 1, colors, N, K)) {
                return true; // Если удалось успешно раскрасить остальные дома
            }
            
            // Откатываем изменения (backtrack), если не удалось раскрасить дома дальше
            colors[currentHouse] = 0;
        }
    }

    // Если не удалось найти подходящую раскраску
    return false;
}

int main() {
    system("chcp 65001");
    int N, K;
    cout << "Введите количество домов (N): ";
    cin >> N;
    cout << "Введите количество цветов (K): ";
    cin >> K;

    vector<int> colors(N, 0); // Вектор для хранения цветов домов

    // Проверяем возможность раскраски домов
    if (canPaintHouses(0, colors, N, K)) {
        cout << "Можно раскрасить дома с заданными условиями." << endl;
        cout << "Раскраска домов:" << endl;
        for (int i = 0; i < N; ++i) {
            cout << "Дом " << i + 1 << ": Цвет " << colors[i] << endl;
        }
    } else {
        cout << "Невозможно раскрасить дома с заданными условиями." << endl;
    }

    return 0;
}
