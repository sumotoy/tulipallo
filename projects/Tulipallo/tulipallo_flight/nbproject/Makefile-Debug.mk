#
# Generated Makefile - do not edit!
#
# Edit the Makefile in the project folder instead (../Makefile). Each target
# has a -pre and a -post target defined where you can add customized code.
#
# This makefile implements configuration specific macros and targets.


# Environment
MKDIR=mkdir
CP=cp
GREP=grep
NM=nm
CCADMIN=CCadmin
RANLIB=ranlib
CC=gcc
CCC=g++
CXX=g++
FC=gfortran
AS=as

# Macros
CND_PLATFORM=GNU-Linux-x86
CND_DLIB_EXT=so
CND_CONF=Debug
CND_DISTDIR=dist
CND_BUILDDIR=build

# Include project Makefile
include Makefile

# Object Directory
OBJECTDIR=${CND_BUILDDIR}/${CND_CONF}/${CND_PLATFORM}

# Object Files
OBJECTFILES= \
	${OBJECTDIR}/AttitudeToControlSurfaceRule.o \
	${OBJECTDIR}/FlightController.o \
	${OBJECTDIR}/FlightControllerActivator.o \
	${OBJECTDIR}/FlightControllerOff.o \
	${OBJECTDIR}/LevelFlightGuidanceRule.o \
	${OBJECTDIR}/PIDControlRule.o \
	${OBJECTDIR}/PIDControllerZero.o \
	${OBJECTDIR}/Rule.o \
	${OBJECTDIR}/main.o


# C Compiler Flags
CFLAGS=

# CC Compiler Flags
CCFLAGS=-pthread -lrt -lwiringPi -lwiringPiDev -ldl
CXXFLAGS=-pthread -lrt -lwiringPi -lwiringPiDev -ldl

# Fortran Compiler Flags
FFLAGS=

# Assembler Flags
ASFLAGS=

# Link Libraries and Options
LDLIBSOPTIONS=/usr/local/lib/libwiringPi.so /usr/local/lib/libwiringPiDev.so -Wl,-rpath,../tulipallo_core/dist/Debug/GNU-Linux-x86 -L../tulipallo_core/dist/Debug/GNU-Linux-x86 -ltulipallo_core -Wl,-rpath,../tulipallo_control/dist/Debug/GNU-Linux-x86 -L../tulipallo_control/dist/Debug/GNU-Linux-x86 -ltulipallo_control -Wl,-rpath,../tulipallo_xplane/dist/Debug/GNU-Linux-x86 -L../tulipallo_xplane/dist/Debug/GNU-Linux-x86 -ltulipallo_xplane -Wl,-rpath,../tulipallo_gertboard/dist/Debug/GNU-Linux-x86 -L../tulipallo_gertboard/dist/Debug/GNU-Linux-x86 -ltulipallo_gertboard -Wl,-rpath,../tulipallo_xplane_gyro/dist/Debug/GNU-Linux-x86 -L../tulipallo_xplane_gyro/dist/Debug/GNU-Linux-x86 -ltulipallo_xplane_gyro

# Build Targets
.build-conf: ${BUILD_SUBPROJECTS}
	"${MAKE}"  -f nbproject/Makefile-${CND_CONF}.mk ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/tulipallo_flight

${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/tulipallo_flight: /usr/local/lib/libwiringPi.so

${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/tulipallo_flight: /usr/local/lib/libwiringPiDev.so

${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/tulipallo_flight: ../tulipallo_core/dist/Debug/GNU-Linux-x86/libtulipallo_core.so

${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/tulipallo_flight: ../tulipallo_control/dist/Debug/GNU-Linux-x86/libtulipallo_control.so

${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/tulipallo_flight: ../tulipallo_xplane/dist/Debug/GNU-Linux-x86/libtulipallo_xplane.so

${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/tulipallo_flight: ../tulipallo_gertboard/dist/Debug/GNU-Linux-x86/libtulipallo_gertboard.so

${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/tulipallo_flight: ../tulipallo_xplane_gyro/dist/Debug/GNU-Linux-x86/libtulipallo_xplane_gyro.so

${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/tulipallo_flight: ${OBJECTFILES}
	${MKDIR} -p ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}
	${LINK.cc} -o ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/tulipallo_flight ${OBJECTFILES} ${LDLIBSOPTIONS} -pthread -lrt -lwiringPi -lwiringPiDev -ldl

${OBJECTDIR}/AttitudeToControlSurfaceRule.o: AttitudeToControlSurfaceRule.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} $@.d
	$(COMPILE.cc) -g -pthread -lrt -lwiringPi -lwiringPiDev -ldl -MMD -MP -MF $@.d -o ${OBJECTDIR}/AttitudeToControlSurfaceRule.o AttitudeToControlSurfaceRule.cpp

${OBJECTDIR}/FlightController.o: FlightController.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} $@.d
	$(COMPILE.cc) -g -pthread -lrt -lwiringPi -lwiringPiDev -ldl -MMD -MP -MF $@.d -o ${OBJECTDIR}/FlightController.o FlightController.cpp

${OBJECTDIR}/FlightControllerActivator.o: FlightControllerActivator.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} $@.d
	$(COMPILE.cc) -g -pthread -lrt -lwiringPi -lwiringPiDev -ldl -MMD -MP -MF $@.d -o ${OBJECTDIR}/FlightControllerActivator.o FlightControllerActivator.cpp

${OBJECTDIR}/FlightControllerOff.o: FlightControllerOff.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} $@.d
	$(COMPILE.cc) -g -pthread -lrt -lwiringPi -lwiringPiDev -ldl -MMD -MP -MF $@.d -o ${OBJECTDIR}/FlightControllerOff.o FlightControllerOff.cpp

${OBJECTDIR}/LevelFlightGuidanceRule.o: LevelFlightGuidanceRule.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} $@.d
	$(COMPILE.cc) -g -pthread -lrt -lwiringPi -lwiringPiDev -ldl -MMD -MP -MF $@.d -o ${OBJECTDIR}/LevelFlightGuidanceRule.o LevelFlightGuidanceRule.cpp

${OBJECTDIR}/PIDControlRule.o: PIDControlRule.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} $@.d
	$(COMPILE.cc) -g -pthread -lrt -lwiringPi -lwiringPiDev -ldl -MMD -MP -MF $@.d -o ${OBJECTDIR}/PIDControlRule.o PIDControlRule.cpp

${OBJECTDIR}/PIDControllerZero.o: PIDControllerZero.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} $@.d
	$(COMPILE.cc) -g -pthread -lrt -lwiringPi -lwiringPiDev -ldl -MMD -MP -MF $@.d -o ${OBJECTDIR}/PIDControllerZero.o PIDControllerZero.cpp

${OBJECTDIR}/Rule.o: Rule.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} $@.d
	$(COMPILE.cc) -g -pthread -lrt -lwiringPi -lwiringPiDev -ldl -MMD -MP -MF $@.d -o ${OBJECTDIR}/Rule.o Rule.cpp

${OBJECTDIR}/main.o: main.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} $@.d
	$(COMPILE.cc) -g -pthread -lrt -lwiringPi -lwiringPiDev -ldl -MMD -MP -MF $@.d -o ${OBJECTDIR}/main.o main.cpp

# Subprojects
.build-subprojects:
	cd ../tulipallo_core && ${MAKE}  -f Makefile CONF=Debug
	cd ../tulipallo_control && ${MAKE}  -f Makefile CONF=Debug
	cd ../tulipallo_xplane && ${MAKE}  -f Makefile CONF=Debug
	cd ../tulipallo_gertboard && ${MAKE}  -f Makefile CONF=Debug
	cd ../tulipallo_xplane_gyro && ${MAKE}  -f Makefile CONF=Debug

# Clean Targets
.clean-conf: ${CLEAN_SUBPROJECTS}
	${RM} -r ${CND_BUILDDIR}/${CND_CONF}
	${RM} ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/tulipallo_flight

# Subprojects
.clean-subprojects:
	cd ../tulipallo_core && ${MAKE}  -f Makefile CONF=Debug clean
	cd ../tulipallo_control && ${MAKE}  -f Makefile CONF=Debug clean
	cd ../tulipallo_xplane && ${MAKE}  -f Makefile CONF=Debug clean
	cd ../tulipallo_gertboard && ${MAKE}  -f Makefile CONF=Debug clean
	cd ../tulipallo_xplane_gyro && ${MAKE}  -f Makefile CONF=Debug clean

# Enable dependency checking
.dep.inc: .depcheck-impl

include .dep.inc
