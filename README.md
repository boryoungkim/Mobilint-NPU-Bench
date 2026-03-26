# Mobilint-NPU-Bench 

This repository contains benchmarking and analysis for **Mobilint NPU (Aries)**, focusing on performance optimization across various neural network architectures, from CNNs to LLMs.

---

## 📂 Project Structure
* \`src/resnet50/\`: Image classification benchmark using ResNet50.
* \`src/llama/\`: (Work in Progress) LLM architecture analysis and quantization benchmarks.
* \`models/\`: (Ignored) Model files (\`.mxq\`) used for inference.
* \`mblt_sdk/\`: (Ignored) Symbolic link to the Mobilint SDK.

---

## 🛠️ Environment Setup
### 1. Requirements
* Mobilint SDK (Aries v1.1.0+)
* C++ Compiler (g++)
* Python 3.x
### 2. Symbolic Link to SDK
To build the project, create a symbolic link to your local Mobilint SDK:
\`\`\`bash
ln -s /path/to/your/mobilint_sdk mblt_sdk
\`\`\`
### 3. Model Files
Place your compiled \`.mxq\` models in the \`models/\` directory.

---

## 🚀 How to Run (Example: ResNet50)
### Build
\`\`\`bash
cd src/resnet50
make
\`\`\`
### Execute
\`\`\`bash
./resnet50
\`\`\`

---

## 📊 Benchmarking Goals
- [x] **ResNet50:** Basic NPU inference and check runtime information
- [ ] **Llama (LLM):** Quantization (8-bit vs 4-bit) performance comparison.
- [ ] **Utilization:** Real-time NPU core trace and memory bandwidth analysis.

