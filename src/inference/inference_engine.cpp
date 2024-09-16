// inference_engine.cpp
#include "neural_network.h"
#include "data_loader.h"
#include <iostream>

int main(int argc, char** argv) {
    // Загружаем предобученную модель
    NeuralNetwork net(10, 64, 1); // Пример размеров сети (должен соответствовать обученной модели)
    net.loadModel("models/inference/inference_v1.pth");

    // Загружаем тестовые данные
    DataLoader loader;
    auto test_data = loader.loadData("data/processed/test_data.csv");

    // Предсказания на тестовых данных
    for (const auto& row : test_data) {
        Matrix input(row.begin(), row.end() - 1); // Входные данные
        auto prediction = net.forward(input);
        std::cout << "Prediction: " << prediction << std::endl;
    }

    return 0;
}
