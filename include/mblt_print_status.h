#ifndef MBLT_PRINT_STATUS_H
#define MBLT_PRINT_STATUS_H

#include <iostream>
#include <string>
#include <unordered_map>
#include <cstdlib>

#include "qbruntime/qbruntime.h"

/**
 * @brief Mobilint StatusCode 해독
 */
inline std::string get_mblt_status_string(mobilint::StatusCode sc) {
    static const std::unordered_map<int, std::string> status_names = {
        {0, "OK (Success)"},
        {1, "Driver_NotInitialized"},
        {2, "Model_NoTargetCores"},
        {3, "Model_FailedToLoadMXQ"},
        {4, "Model_FailedToOpenScaleFile (Deprecated)"},
        {5, "Model_InvalidScaleValue"},
        {6, "Model_FailedToOpenOutputScale (Deprecated)"},
        {7, "Model_InvalidOutputScaleValue (Deprecated)"},
        {8, "Model_FailedToOpenSectionBinary"},
        {9, "Model_NotLaunched"},
        {10, "Model_NotAlive"},
        {11, "Acc_CoreAlreadyInUse"},
        {12, "Acc_NoSuchModel"},
        {13, "Driver_FailedToAllocateHostMemory"},
        {14, "Driver_FailedToWriteMemoryBuffer"},
        {15, "Driver_FailedToReadMemoryBuffer"},
        {16, "Model_MXQAndModelConfigNotMatch"},
        {17, "Model_NoGlobalCoreWithGlobalMultiMode"},
        {18, "NotImplemented"},
        {19, "Model_FailedToOpenModelDescFile"},
        {20, "Model_BrokenMXQ"},
        {21, "Model_ShapeMismatched"},
        {22, "Model_DtypeMismatched"},
        {23, "InternalError"},
        {24, "Driver_FailedToClaimCores"},
        {25, "Driver_FailedToUnclaimCores"},
        {26, "Model_IsPacked (Deprecated)"},
        {27, "Model_IsNotPacked (Deprecated)"},
        {28, "Acc_TaskQueueNotFound"},
        {29, "MemoryPool_BufNotFound"},
        {30, "MemoryPool_AllocatorNotSet"},
        {32, "Model_FailedToAllocMemory"},
        {33, "Driver_FailedToPostInfer"},
        {34, "Driver_FailedToWaitDone"},
        {35, "Driver_WaitDoneTimeout"},
        {36, "Model_PredictError"},
        {37, "Model_FailedToSaveTensor"},
        {38, "Model_UnexpectedMemoryFormat (Deprecated)"},
        {39, "BadAlloc"},
        {40, "Model_TaskQueueClosed"},
        {41, "Model_TaskQueueTimeout"},
        {42, "Acc_NPUTimeout"},
        {43, "Acc_NoIMemInitFound"},
        {44, "Driver_FailedToAllocateModelMemory"},
        {45, "Driver_FailedToBuildCmaIoReq"},
        {46, "Driver_FailedToFreeModelMemory"},
        {47, "Driver_WrongBaseAddress"},
        {48, "Model_IsNotSupportedHardware"},
        {49, "Driver_FailedToLockCore"},
        {50, "Driver_FailedToUnlockCore"},
        {51, "Model_InvalidNPUDtype"},
        {52, "Model_InvalidRmemType"},
        {53, "Model_CacheOverflow (KV-cache)"},
        {54, "Model_NoCache"},
        {55, "Model_AsyncPipelineCheckFailed"},
        {56, "Model_AsyncPipelineNotAlive"},
        {57, "Model_AsyncPipelineTimeout"},
        {58, "Future_NotValid"},
        {59, "Model_InvalidSupplementary"},
        {60, "Model_NumCacheMismatched"},
        {61, "Model_FailedToFindDirectory"},
        {62, "Model_FailedToOpenCacheFile"},
        {63, "Model_BufferSizeMismatched"},
        {64, "Model_InvalidVariantIdx"},
        {65, "Model_AlreadyLaunched"}
    };

    auto it = status_names.find(static_cast<int>(sc));
    if (it != status_names.end()) return it->second;
    return "Unknown_Status_Code_" + std::to_string(static_cast<int>(sc));
}

/**
 * @brief 실행 결과를 무조건 출력. 
 * OK(0)이면 통과 메시지를, 아니면 상세 정보 출력 후 프로그램 종료.
 */
#define MBLT_PRINT_STATUS(cmd) \
    do { \
        mobilint::StatusCode _sc = (cmd); \
        if (_sc == mobilint::StatusCode::OK) { \
            std::cout << "[MBLT SUCCESS] " << #cmd << " -> " \
                      << get_mblt_status_string(_sc) << std::endl; \
        } else { \
            std::cerr << "\n[MBLT FATAL ERROR] --------------------------" << std::endl; \
            std::cerr << "File    : " << __FILE__ << ":" << __LINE__ << std::endl; \
            std::cerr << "Function: " << #cmd << std::endl; \
            std::cerr << "⚠️ Status : " << get_mblt_status_string(_sc) << " (" << (int)_sc << ")" << std::endl; \
            std::cerr << "----------------------------------------------\n" << std::endl; \
            std::exit(static_cast<int>(_sc)); \
        } \
    } while (0)

#endif