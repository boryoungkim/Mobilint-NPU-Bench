# Mobilint-NPU-Bench
This repository contains benchmarking and analysis for **Mobilint NPU (Aries)**, focusing on performance optimization across various neural network architectures, from CNNs to LLMs.

## 📂 Project Structure
* `src/resnet50/`: Image classification benchmark using ResNet50.
* `src/llama/`: (Work in Progress) LLM architecture analysis and quantization benchmarks.
* `models/`: (Ignored) Model files (.mxq) used for inference.
* `mblt_sdk/`: (Ignored) Symbolic link to the Mobilint SDK.

## ✨ Added Features from plain MBLT_SDK
### 1. Unified Status Logging (`mblt_print_status.h`)
Print NPU status whenever I want.

```cpp
#include "mblt_print_status.h"
// MBLT-defined class - StatusClass sc;
MBLT_PRINT_STATUS( sc );
```

### 2. Flexible Build System (Makefile)
Each source directory (src/) contains a versatile Makefile that accepts a source argument. This allows you to compile and test different code variants instantly without modifying the build script.

```bash
# 1. Navigate to the target directory
cd src/llama
# 2. Build a specific source file (source=filename.cc)
make source=llama.cc
# 3. Execute the generated benchmark
./llama
```

## 🛠️ Environment Setup
### 1. Requirements
* Mobilint SDK (Aries v1.1.0+)
* C++ Compiler (g++)
* Python 3.x
### 2. Symbolic Link to SDK
To build the project, create a symbolic link to your local Mobilint SDK:

```bash
ln -s /path/to/your/mobilint_sdk mblt_sdk
```

## Benchmarking Goals
- [x] **ResNet50:** Basic NPU inference check execution information.
- [ ] **Llama:** Quantization (8-bit vs 4-bit) performance comparison.
- [ ] **Utilization:** Real-time NPU core trace and memory bandwidth analysis.

## Working Docs
* MBLT NPU 아키텍쳐 분석 보고서: https://docs.google.com/document/d/1BwT-naDXaWztWFPwHC7gbHPZcozb236hEvuZXxecjcs/edit?tab=t.0
* MBLT qbRuntime Basics: https://docs.google.com/document/d/1J5bnF1nCofTNZLQcuE07gODyuAcE_5T-ZChYrSLbMcM/edit?tab=t.0
* MBLT ARIES SDK 환경설정: https://docs.google.com/document/d/1Xc6yHAVuKjlXiIOdFizZfIxF30SAjBZqUrSbdrXHhRQ/edit?tab=t.0
