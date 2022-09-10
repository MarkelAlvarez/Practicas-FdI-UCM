################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../src/main.cpp 

CU_SRCS += \
../src/matrix_mul.cu 

CU_DEPS += \
./src/matrix_mul.d 

OBJS += \
./src/main.o \
./src/matrix_mul.o 

CPP_DEPS += \
./src/main.d 


# Each subdirectory must supply rules for building sources it contributes
src/%.o: ../src/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: NVCC Compiler'
	/opt/cuda-6.5/bin/nvcc -I"/opt/cuda-6.5/samples/0_Simple" -I"/opt/cuda-6.5/samples/common/inc" -I"/home/carlos/cuda-workspace/matrix_mul_shared" -G -g -O0 -gencode arch=compute_11,code=sm_11  -odir "src" -M -o "$(@:%.o=%.d)" "$<"
	/opt/cuda-6.5/bin/nvcc -I"/opt/cuda-6.5/samples/0_Simple" -I"/opt/cuda-6.5/samples/common/inc" -I"/home/carlos/cuda-workspace/matrix_mul_shared" -G -g -O0 --compile  -x c++ -o  "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

src/%.o: ../src/%.cu
	@echo 'Building file: $<'
	@echo 'Invoking: NVCC Compiler'
	/opt/cuda-6.5/bin/nvcc -I"/opt/cuda-6.5/samples/0_Simple" -I"/opt/cuda-6.5/samples/common/inc" -I"/home/carlos/cuda-workspace/matrix_mul_shared" -G -g -O0 -gencode arch=compute_11,code=sm_11  -odir "src" -M -o "$(@:%.o=%.d)" "$<"
	/opt/cuda-6.5/bin/nvcc -I"/opt/cuda-6.5/samples/0_Simple" -I"/opt/cuda-6.5/samples/common/inc" -I"/home/carlos/cuda-workspace/matrix_mul_shared" -G -g -O0 --compile --relocatable-device-code=false -gencode arch=compute_11,code=compute_11 -gencode arch=compute_11,code=sm_11  -x cu -o  "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


