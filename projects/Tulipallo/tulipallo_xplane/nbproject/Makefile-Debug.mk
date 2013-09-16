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
	${OBJECTDIR}/ControlSurfaceFactory.o \
	${OBJECTDIR}/ControlSurfaceSentence.o \
	${OBJECTDIR}/ISentenceListener.o \
	${OBJECTDIR}/InvalidMessageException.o \
	${OBJECTDIR}/LocationFactory.o \
	${OBJECTDIR}/LocationSentence.o \
	${OBJECTDIR}/MarshallingException.o \
	${OBJECTDIR}/MessageHandler.o \
	${OBJECTDIR}/MessageReciever.o \
	${OBJECTDIR}/MessageTransmitter.o \
	${OBJECTDIR}/SentenceFactory.o \
	${OBJECTDIR}/SentenceReceivedEvent.o \
	${OBJECTDIR}/SituationFactory.o \
	${OBJECTDIR}/SituationSentence.o \
	${OBJECTDIR}/SlipFactory.o \
	${OBJECTDIR}/SlipSentence.o \
	${OBJECTDIR}/SpeedFactory.o \
	${OBJECTDIR}/SpeedSentence.o \
	${OBJECTDIR}/XPlaneSentence.o


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
LDLIBSOPTIONS=-Wl,-rpath,../tulipallo_core/dist/Debug/GNU-Linux-x86 -L../tulipallo_core/dist/Debug/GNU-Linux-x86 -ltulipallo_core

# Build Targets
.build-conf: ${BUILD_SUBPROJECTS}
	"${MAKE}"  -f nbproject/Makefile-${CND_CONF}.mk ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/libtulipallo_xplane.${CND_DLIB_EXT}

${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/libtulipallo_xplane.${CND_DLIB_EXT}: ../tulipallo_core/dist/Debug/GNU-Linux-x86/libtulipallo_core.so

${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/libtulipallo_xplane.${CND_DLIB_EXT}: ${OBJECTFILES}
	${MKDIR} -p ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}
	${LINK.cc} -o ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/libtulipallo_xplane.${CND_DLIB_EXT} ${OBJECTFILES} ${LDLIBSOPTIONS} -pthread -lrt -ldl -shared -fPIC

${OBJECTDIR}/ControlSurfaceFactory.o: ControlSurfaceFactory.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} $@.d
	$(COMPILE.cc) -g -pthread -lrt -ldl -fPIC  -MMD -MP -MF $@.d -o ${OBJECTDIR}/ControlSurfaceFactory.o ControlSurfaceFactory.cpp

${OBJECTDIR}/ControlSurfaceSentence.o: ControlSurfaceSentence.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} $@.d
	$(COMPILE.cc) -g -pthread -lrt -ldl -fPIC  -MMD -MP -MF $@.d -o ${OBJECTDIR}/ControlSurfaceSentence.o ControlSurfaceSentence.cpp

${OBJECTDIR}/ISentenceListener.o: ISentenceListener.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} $@.d
	$(COMPILE.cc) -g -pthread -lrt -ldl -fPIC  -MMD -MP -MF $@.d -o ${OBJECTDIR}/ISentenceListener.o ISentenceListener.cpp

${OBJECTDIR}/InvalidMessageException.o: InvalidMessageException.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} $@.d
	$(COMPILE.cc) -g -pthread -lrt -ldl -fPIC  -MMD -MP -MF $@.d -o ${OBJECTDIR}/InvalidMessageException.o InvalidMessageException.cpp

${OBJECTDIR}/LocationFactory.o: LocationFactory.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} $@.d
	$(COMPILE.cc) -g -pthread -lrt -ldl -fPIC  -MMD -MP -MF $@.d -o ${OBJECTDIR}/LocationFactory.o LocationFactory.cpp

${OBJECTDIR}/LocationSentence.o: LocationSentence.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} $@.d
	$(COMPILE.cc) -g -pthread -lrt -ldl -fPIC  -MMD -MP -MF $@.d -o ${OBJECTDIR}/LocationSentence.o LocationSentence.cpp

${OBJECTDIR}/MarshallingException.o: MarshallingException.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} $@.d
	$(COMPILE.cc) -g -pthread -lrt -ldl -fPIC  -MMD -MP -MF $@.d -o ${OBJECTDIR}/MarshallingException.o MarshallingException.cpp

${OBJECTDIR}/MessageHandler.o: MessageHandler.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} $@.d
	$(COMPILE.cc) -g -pthread -lrt -ldl -fPIC  -MMD -MP -MF $@.d -o ${OBJECTDIR}/MessageHandler.o MessageHandler.cpp

${OBJECTDIR}/MessageReciever.o: MessageReciever.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} $@.d
	$(COMPILE.cc) -g -pthread -lrt -ldl -fPIC  -MMD -MP -MF $@.d -o ${OBJECTDIR}/MessageReciever.o MessageReciever.cpp

${OBJECTDIR}/MessageTransmitter.o: MessageTransmitter.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} $@.d
	$(COMPILE.cc) -g -pthread -lrt -ldl -fPIC  -MMD -MP -MF $@.d -o ${OBJECTDIR}/MessageTransmitter.o MessageTransmitter.cpp

${OBJECTDIR}/SentenceFactory.o: SentenceFactory.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} $@.d
	$(COMPILE.cc) -g -pthread -lrt -ldl -fPIC  -MMD -MP -MF $@.d -o ${OBJECTDIR}/SentenceFactory.o SentenceFactory.cpp

${OBJECTDIR}/SentenceReceivedEvent.o: SentenceReceivedEvent.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} $@.d
	$(COMPILE.cc) -g -pthread -lrt -ldl -fPIC  -MMD -MP -MF $@.d -o ${OBJECTDIR}/SentenceReceivedEvent.o SentenceReceivedEvent.cpp

${OBJECTDIR}/SituationFactory.o: SituationFactory.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} $@.d
	$(COMPILE.cc) -g -pthread -lrt -ldl -fPIC  -MMD -MP -MF $@.d -o ${OBJECTDIR}/SituationFactory.o SituationFactory.cpp

${OBJECTDIR}/SituationSentence.o: SituationSentence.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} $@.d
	$(COMPILE.cc) -g -pthread -lrt -ldl -fPIC  -MMD -MP -MF $@.d -o ${OBJECTDIR}/SituationSentence.o SituationSentence.cpp

${OBJECTDIR}/SlipFactory.o: SlipFactory.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} $@.d
	$(COMPILE.cc) -g -pthread -lrt -ldl -fPIC  -MMD -MP -MF $@.d -o ${OBJECTDIR}/SlipFactory.o SlipFactory.cpp

${OBJECTDIR}/SlipSentence.o: SlipSentence.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} $@.d
	$(COMPILE.cc) -g -pthread -lrt -ldl -fPIC  -MMD -MP -MF $@.d -o ${OBJECTDIR}/SlipSentence.o SlipSentence.cpp

${OBJECTDIR}/SpeedFactory.o: SpeedFactory.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} $@.d
	$(COMPILE.cc) -g -pthread -lrt -ldl -fPIC  -MMD -MP -MF $@.d -o ${OBJECTDIR}/SpeedFactory.o SpeedFactory.cpp

${OBJECTDIR}/SpeedSentence.o: SpeedSentence.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} $@.d
	$(COMPILE.cc) -g -pthread -lrt -ldl -fPIC  -MMD -MP -MF $@.d -o ${OBJECTDIR}/SpeedSentence.o SpeedSentence.cpp

${OBJECTDIR}/XPlaneSentence.o: XPlaneSentence.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} $@.d
	$(COMPILE.cc) -g -pthread -lrt -ldl -fPIC  -MMD -MP -MF $@.d -o ${OBJECTDIR}/XPlaneSentence.o XPlaneSentence.cpp

# Subprojects
.build-subprojects:
	cd ../tulipallo_core && ${MAKE}  -f Makefile CONF=Debug

# Clean Targets
.clean-conf: ${CLEAN_SUBPROJECTS}
	${RM} -r ${CND_BUILDDIR}/${CND_CONF}
	${RM} ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/libtulipallo_xplane.${CND_DLIB_EXT}

# Subprojects
.clean-subprojects:
	cd ../tulipallo_core && ${MAKE}  -f Makefile CONF=Debug clean

# Enable dependency checking
.dep.inc: .depcheck-impl

include .dep.inc
