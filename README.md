# Tarjan and Jen-Schmidt Algorithms for Biconnectivity

## Introduction to Algorithm Engineering Project

- Sumit Kumar 2022111012
- Priet Ukani 2022111039

---

## Table of Contents
- [Description](##Description)
- [Steps to Run](##Steps-to-Run)
- [File Structure](##File-Structure)

## Description

## Steps to Run
- For getting the results of all 3 algorithms(using randomly generated tests for all different values of edges and vertices), run the following command
    ```bash
        cd testing
        chmod +x script.sh
        bash script.sh
    ```
- For plotting the results of the generated data points(after running the above step), run the following command
    ```bash
        python plot.py
    ```


## File Structure
The directory structure of the repository is as follows:
- `testing/`: This directory contains the testing scripts and the generated data points.
    - `testing/script.sh`: This file contains the script to randomly generate and run the tests for all 3 algorithms.
    - `testing/outputs/`: This directory contains the results of the algorithms(times).
    - `testing/correctness_generator.cpp`: This file contains the code to generate the correctness tests for the algorithms.
    - `testing/generator.cpp`: This file contains the code to generate the random tests for the algorithms which is used by `script.sh`.
    - `testing/helper.sh`: This script is used by `script.sh` to run the tests.
- `img/`: This directory contains the images of the generated plots and related images.
- `plot.py`: This file contains the code for plotting the generated data points.    
- `README.md`: This file contains the project's README documentation.
