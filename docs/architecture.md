# Project Architecture

## Overview
This project is designed to build a neural network for Counter-Strike 2 (CS2) using C++ and machine learning techniques. The project is divided into several modules, including data processing, model training, inference, and utility functions.

## Key Modules:
1. **Data Processing (`src/data/`)**
   - Data loading and preprocessing.
   - Feature extraction from CS2 demo files and logs.

2. **Model (`src/model/`)**
   - Neural network architecture implemented with fully connected layers.
   - Layer-wise computations and backpropagation.

3. **Training (`src/training/`)**
   - Core training loop and weight updates.
   - Model evaluation and metrics tracking.

4. **Inference (`src/inference/`)**
   - Loading pretrained models and running inference on unseen data.

## Data Flow:
1. **Data Loading:** Raw data is loaded from `data/raw/` and processed into a usable format.
2. **Model Training:** The processed data is used to train the neural network.
3. **Inference:** The trained model is used to make predictions on new data.

## Directory Structure:
- `/data`: Contains raw and processed data.
- `/models`: Stores trained models and checkpoints.
- `/src`: Contains source code for training, model definition, and utilities.
- `/config`: Configuration files for training and model setup.
