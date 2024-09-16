// test_training_pipeline.cpp
#include "neural_network.h"
#include "data_loader.h"
#include <cassert>
#include <iostream>

void test_training_pipeline() {
    DataLoader loader;
    auto training_data = loader.loadData("tests/mock_data/sample_training_data.csv");

    int input_size = training_data[0].size() - 1; // Все кроме метки
    int hidden_size = 64;
    int output_size = 1;

    NeuralNetwork net(input_size, hidden_size, output_size);

    std::vector<Matrix> inputs;
    std::vector<Matrix> targets;

    for (const auto& row : training_data) {
        Matrix input(row.begin(), row.end() - 1); // Все, кроме метки
        Matrix target({row.back()});
        inputs.push_back(input);
        targets.push_back(target);
    }

    net.train(inputs, targets, 10, 0.01f);

    std::cout << "test_training_pipeline passed!" << std::endl;
}

int main() {
    test_training_pipeline();
    return 0;
}
