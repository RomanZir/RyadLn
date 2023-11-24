#include <iostream>
#include <cmath>
#include <chrono>
#include <locale>

double calculateLnSeries(double x, int N) {
    if (std::abs(x) >= 1.0) {
        std::cerr << "Ошибка: x должен находиться в диапазоне (-1, 1)." << std::endl;
        return 0.0;
    }

    double result = 0.0;
    for (int n = 1; n <= N; ++n) {
        result += std::pow(-1, n + 1) * std::pow(x, n) / n;
    }

    return result;
}

int main() {
    // Установка русской локали
    std::locale::global(std::locale(""));

    double x;
    int N;

    std::wcout << L"Введите значение x (-1 < x < 1): ";
    std::wcin >> x;

    std::wcout << L"Введите количество членов (N): ";
    std::wcin >> N;

    auto start = std::chrono::high_resolution_clock::now();

    double lnResult = calculateLnSeries(x, N);

    auto end = std::chrono::high_resolution_clock::now();
    auto duration = std::chrono::duration_cast<std::chrono::duration<double>>(end - start);

    std::wcout << L"ln(1 + " << x << L") с использованием " << N << L" членов приближенно равен: " << lnResult << std::endl;
    std::wcout << L"Время выполнения: " << duration.count() << L" секунд" << std::endl;

    return 0;
}

