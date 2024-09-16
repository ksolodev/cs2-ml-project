// trainer.cpp
#include "neural_network.h"
#include "data_loader.h"
#include <iostream>

int main(int argc, char** argv) {
    // Загружаем конфигурацию из файла
    std::string configPath = "config/training_config.yaml";
    // Можно использовать библиотеку для работы с YAML, чтобы прочитать конфигурацию
    float learning_rate = 0.01f;
    int epochs = 100;
    int batch_size = 32;

    // Загружаем данные
    DataLoader loader;
    auto training_data = loader.loadData("data/processed/training_data.csv");
    auto validation_data = loader.loadData("data/processed/validation_data.csv");

    // Инициализируем нейронную сеть
    int input_size = training_data[0].size() - 1; // Все кроме метки
    int hidden_size = 64;  // Произвольное количество нейронов на скрытом слое
    int output_size = 1;   // Один выходной нейрон для классификации

    NeuralNetwork net(input_size, hidden_size, output_size);

    // Обучаем модель
    std::vector<Matrix> inputs;  // Данные входных признаков
    std::vector<Matrix> targets; // Метки

    // Заполняем inputs и targets из training_data
    for (const auto& row : training_data) {
        Matrix input(row.begin(), row.end() - 1);  // Все элементы, кроме последнего (метка)
        Matrix target({row.back()});               // Последний элемент — метка
        inputs.push_back(input);
        targets.push_back(target);
    }

    net.train(inputs, targets, epochs, learning_rate);

    std::cout << "Training complete." << std::endl;
    return 0;
}
