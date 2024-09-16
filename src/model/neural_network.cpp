// neural_network.cpp
#include "neural_network.h"
#include <iostream>

NeuralNetwork::NeuralNetwork(int input_size, int hidden_size, int output_size) {
    // Инициализация слоев сети
    this->input_size = input_size;
    this->hidden_size = hidden_size;
    this->output_size = output_size;

    // Инициализация весов (случайно или с нормальным распределением)
    initializeWeights();
}

void NeuralNetwork::initializeWeights() {
    // Инициализация весов случайными значениями
    std::cout << "Initializing weights..." << std::endl;
    weights_input_hidden = Matrix(input_size, hidden_size);
    weights_hidden_output = Matrix(hidden_size, output_size);
}

Matrix NeuralNetwork::forward(const Matrix& input) {
    // Прямое распространение
    Matrix hidden = input.dot(weights_input_hidden).applyActivation(sigmoid);
    Matrix output = hidden.dot(weights_hidden_output).applyActivation(sigmoid);
    return output;
}

void NeuralNetwork::train(const std::vector<Matrix>& inputs, const std::vector<Matrix>& targets, int epochs, float learning_rate) {
    // Обучение нейросети методом обратного распространения
    std::cout << "Training the neural network..." << std::endl;
    for (int epoch = 0; epoch < epochs; ++epoch) {
        for (size_t i = 0; i < inputs.size(); ++i) {
            // Шаг прямого распространения
            Matrix output = forward(inputs[i]);
            // Подсчет ошибки и обратное распространение
            backpropagation(output, targets[i], learning_rate);
        }
    }
}

void NeuralNetwork::backpropagation(const Matrix& output, const Matrix& target, float learning_rate) {
    // Реализация обратного распространения ошибки
    Matrix output_error = target - output;
    // Другие шаги обратного распространения
}
