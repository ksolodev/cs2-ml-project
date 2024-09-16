## Project Structure:
- **/data**: Contains raw and processed data.
- **/models**: Trained models and checkpoints.
- **/src**: Source code for data processing, model training, and inference.
- **/scripts**: Automation scripts for training and inference.
- **/config**: Configuration files for training and model setup.

## Configuration:
- **training_config.yaml**: Specifies parameters for training, including learning rate, batch size, etc.
- **model_config.yaml**: Defines the architecture of the neural network, such as the number of layers and activation functions.

## Testing:
Unit and integration tests are available to ensure the correctness of the components:
1. **Unit Tests**:
   - Run unit tests for individual modules like data loading and forward pass using:
     ```bash
     ./build/tests/unit_tests/test_data_loader
     ./build/tests/unit_tests/test_neural_network
     ```

2. **Integration Tests**:
   - Run integration tests to check the training pipeline:
     ```bash
     ./build/tests/integration_tests/test_training_pipeline
     ```
