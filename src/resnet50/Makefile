# 1. 모빌린트 SDK 연결(심볼릭 링크로 걸어둠)
SDK_ROOT = ../../mblt_sdk/qbruntime/qbruntime
INC_DIR  = $(SDK_ROOT)/include
LIB_DIR  = $(SDK_ROOT)/lib

# 2. 컴파일러 및 옵션
CXX      = g++
CXXFLAGS = -O3 -std=c++17 -Wall -I$(INC_DIR) -I.
LDFLAGS  = -L$(LIB_DIR) -Wl,-rpath,$(LIB_DIR)
LDLIBS   = -lqbruntime

# 3. argument 체크 (source=파일명.cc)
ifeq ($(source),)
$(error [ERROR] 'source' argument is missing! Usage: make source=your_code.cc)
endif

TARGET = $(basename $(source))

# 4. 빌드 규칙
all: $(TARGET)

$(TARGET): $(source)
	$(CXX) $(CXXFLAGS) $(source) -o $(TARGET) $(LDFLAGS) $(LDLIBS)

clean:
	rm -f $(TARGET)

.PHONY: all clean