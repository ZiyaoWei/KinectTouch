################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../src/JackByTheNotes.cpp \
../src/KinectTouch.cpp \
../src/Note.cpp \
../src/PlayedNote.cpp \
../src/PreProcess.cpp 

OBJS += \
./src/JackByTheNotes.o \
./src/KinectTouch.o \
./src/Note.o \
./src/PlayedNote.o \
./src/PreProcess.o 

CPP_DEPS += \
./src/JackByTheNotes.d \
./src/KinectTouch.d \
./src/Note.d \
./src/PlayedNote.d \
./src/PreProcess.d 


# Each subdirectory must supply rules for building sources it contributes
src/%.o: ../src/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -I/usr/include/ni -I"/home/wzy/Research/KinectTouch/src/oscpack" -I"/home/wzy/Research/KinectTouch/src/TUIO" -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


