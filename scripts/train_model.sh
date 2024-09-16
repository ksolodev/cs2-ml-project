#!/bin/bash

# Скрипт для запуска обучения модели

echo "Starting model training..."
./build/train_model --config=config/training_config.yaml
echo "Training complete!"
