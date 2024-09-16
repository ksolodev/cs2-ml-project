// test_neural_network.cpp
#include "neural_network.h"
#include <cassert>
#include <iostream>

void test_forward_pass() {
    NeuralNetwork net(10, 64, 1);
    
    Matrix input({0.5, 0.2, 0.1, 0.4, 0.6, 0.3, 0.7, 0.8, 0.9, 0.1});
    Matrix output = net.forward(input);

    assert(output.size() == 1 && "Output size should be 1.");
    std::cout << "test_forward_pass passed!" << std::endl;
}

int main() {
    test_forward_pass();
    return 0;
}
