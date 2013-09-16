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
	${OBJECTDIR}/XPlaneGyro.o


# C Compiler Flags
CFLAGS=

# CC Compiler Flags
CCFLAGS=-pthread -lrt -ldl
CXXFLAGS=-pthread -lrt -ldl

# Fortran Compiler Flags
FFLAGS=

# Assembler Flags
ASFLAGS=

# Link Libraries and Options
LDLIBSOPTIONS=-Wl,-rpath,../tulipallo_core/dist/Debug/GNU-Linux-x86 -L../tulipallo_core/dist/Debug/GNU-Linux-x86 -ltulipallo_core -Wl,-rpath,../tulipallo_xplane/dist/Debug/GNU-Linux-x86 -L../tulipallo_xplane/dist/Debug/GNU-Linux-x86 -ltulipallo_xplane

# Build Targets
.build-conf: ${BUILD_SUBPROJECTS}
	"${MAKE}"  -f nbproject/Makefile-${CND_CONF}.mk ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/libtulipallo_xplane_gyro.${CND_DLIB_EXT}

${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/libtulipallo_xplane_gyro.${CND_DLIB_EXT}: ../tulipallo_core/dist/Debug/GNU-Linux-x86/libtulipallo_core.so

${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/libtulipallo_xplane_gyro.${CND_DLIB_EXT}: ../tulipallo_xplane/dist/Debug/GNU-Linux-x86/libtulipallo_xplane.so

${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/libtulipallo_xplane_gyro.${CND_DLIB_EXT}: ${OBJECTFILES}
	${MKDIR} -p ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}
	${LINK.cc} -o ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/libtulipallo_xplane_gyro.${CND_DLIB_EXT} ${OBJECTFILES} ${LDLIBSOPTIONS} -pthread -lrt -ldl -shared -fPIC

${OBJECTDIR}/XPlaneGyro.o: XPlaneGyro.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} $@.d
	$(COMPILE.cc) -g -pthread -lrt -ldl -fPIC  -MMD -MP -MF $@.d -o ${OBJECTDIR}/XPlaneGyro.o XPlaneGyro.cpp

# Subprojects
.build-subprojects:
	cd ../tulipallo_core && ${MAKE}  -f Makefile CONF=Debug
	cd ../tulipallo_xplane && ${MAKE}  -f Makefile CONF=Debug

# Clean Targets
.clean-conf: ${CLEAN_SUBPROJECTS}
	${RM} -r ${CND_BUILDDIR}/${CND_CONF}
	${RM} ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/libtulipallo_xplane_gyro.${CND_DLIB_EXT}

# Subprojects
.clean-subprojects:
	cd ../tulipallo_core && ${MAKE}  -f Makefile CONF=Debug clean
	cd ../tulipallo_xplane && ${MAKE}  -f Makefile CONF=Debug clean

# Enable dependency checking
.dep.inc: .depcheck-impl

include .dep.inc
