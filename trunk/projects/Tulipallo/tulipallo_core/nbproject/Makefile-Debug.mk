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
	${OBJECTDIR}/Button.o \
	${OBJECTDIR}/ButtonDownEvent.o \
	${OBJECTDIR}/ButtonPressEvent.o \
	${OBJECTDIR}/ButtonToggledEvent.o \
	${OBJECTDIR}/ButtonUpEvent.o \
	${OBJECTDIR}/Clock.o \
	${OBJECTDIR}/ClockException.o \
	${OBJECTDIR}/ClockStartEvent.o \
	${OBJECTDIR}/ClockStopEvent.o \
	${OBJECTDIR}/ClockTickEvent.o \
	${OBJECTDIR}/Context.o \
	${OBJECTDIR}/DataStream.o \
	${OBJECTDIR}/DatagramPacket.o \
	${OBJECTDIR}/DatagramSocket.o \
	${OBJECTDIR}/DatagramSocketClient.o \
	${OBJECTDIR}/DatagramSocketServer.o \
	${OBJECTDIR}/Epsilon.o \
	${OBJECTDIR}/Event.o \
	${OBJECTDIR}/Exception.o \
	${OBJECTDIR}/ExceptionEvent.o \
	${OBJECTDIR}/GPIO.o \
	${OBJECTDIR}/GPIOException.o \
	${OBJECTDIR}/GPIOFactorySingleton.o \
	${OBJECTDIR}/IButtonCommand.o \
	${OBJECTDIR}/IButtonListener.o \
	${OBJECTDIR}/IClockListener.o \
	${OBJECTDIR}/IExceptionListener.o \
	${OBJECTDIR}/IGPIOFactory.o \
	${OBJECTDIR}/IGPIOFactoryProvider.o \
	${OBJECTDIR}/INetworkAddress.o \
	${OBJECTDIR}/IStateChangedListener.o \
	${OBJECTDIR}/IllegalArgumentException.o \
	${OBJECTDIR}/IllegalStateException.o \
	${OBJECTDIR}/InternetAddress.o \
	${OBJECTDIR}/KeyNotFoundException.o \
	${OBJECTDIR}/ObjectFactory.o \
	${OBJECTDIR}/ObjectFactoryException.o \
	${OBJECTDIR}/ObjectFactoryMethod.o \
	${OBJECTDIR}/Pin.o \
	${OBJECTDIR}/Properties.o \
	${OBJECTDIR}/PropertiesException.o \
	${OBJECTDIR}/SocketException.o \
	${OBJECTDIR}/StateChangedEvent.o \
	${OBJECTDIR}/Thread.o \
	${OBJECTDIR}/ThreadException.o


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
LDLIBSOPTIONS=/usr/local/lib/libwiringPi.so /usr/local/lib/libwiringPiDev.so

# Build Targets
.build-conf: ${BUILD_SUBPROJECTS}
	"${MAKE}"  -f nbproject/Makefile-${CND_CONF}.mk ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/libtulipallo_core.${CND_DLIB_EXT}

${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/libtulipallo_core.${CND_DLIB_EXT}: /usr/local/lib/libwiringPi.so

${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/libtulipallo_core.${CND_DLIB_EXT}: /usr/local/lib/libwiringPiDev.so

${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/libtulipallo_core.${CND_DLIB_EXT}: ${OBJECTFILES}
	${MKDIR} -p ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}
	${LINK.cc} -o ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/libtulipallo_core.${CND_DLIB_EXT} ${OBJECTFILES} ${LDLIBSOPTIONS} -pthread -lrt -lwiringPi -lwiringPiDev -ldl -shared -fPIC

${OBJECTDIR}/Button.o: Button.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} $@.d
	$(COMPILE.cc) -g -pthread -lrt -lwiringPi -lwiringPiDev -ldl -fPIC  -MMD -MP -MF $@.d -o ${OBJECTDIR}/Button.o Button.cpp

${OBJECTDIR}/ButtonDownEvent.o: ButtonDownEvent.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} $@.d
	$(COMPILE.cc) -g -pthread -lrt -lwiringPi -lwiringPiDev -ldl -fPIC  -MMD -MP -MF $@.d -o ${OBJECTDIR}/ButtonDownEvent.o ButtonDownEvent.cpp

${OBJECTDIR}/ButtonPressEvent.o: ButtonPressEvent.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} $@.d
	$(COMPILE.cc) -g -pthread -lrt -lwiringPi -lwiringPiDev -ldl -fPIC  -MMD -MP -MF $@.d -o ${OBJECTDIR}/ButtonPressEvent.o ButtonPressEvent.cpp

${OBJECTDIR}/ButtonToggledEvent.o: ButtonToggledEvent.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} $@.d
	$(COMPILE.cc) -g -pthread -lrt -lwiringPi -lwiringPiDev -ldl -fPIC  -MMD -MP -MF $@.d -o ${OBJECTDIR}/ButtonToggledEvent.o ButtonToggledEvent.cpp

${OBJECTDIR}/ButtonUpEvent.o: ButtonUpEvent.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} $@.d
	$(COMPILE.cc) -g -pthread -lrt -lwiringPi -lwiringPiDev -ldl -fPIC  -MMD -MP -MF $@.d -o ${OBJECTDIR}/ButtonUpEvent.o ButtonUpEvent.cpp

${OBJECTDIR}/Clock.o: Clock.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} $@.d
	$(COMPILE.cc) -g -pthread -lrt -lwiringPi -lwiringPiDev -ldl -fPIC  -MMD -MP -MF $@.d -o ${OBJECTDIR}/Clock.o Clock.cpp

${OBJECTDIR}/ClockException.o: ClockException.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} $@.d
	$(COMPILE.cc) -g -pthread -lrt -lwiringPi -lwiringPiDev -ldl -fPIC  -MMD -MP -MF $@.d -o ${OBJECTDIR}/ClockException.o ClockException.cpp

${OBJECTDIR}/ClockStartEvent.o: ClockStartEvent.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} $@.d
	$(COMPILE.cc) -g -pthread -lrt -lwiringPi -lwiringPiDev -ldl -fPIC  -MMD -MP -MF $@.d -o ${OBJECTDIR}/ClockStartEvent.o ClockStartEvent.cpp

${OBJECTDIR}/ClockStopEvent.o: ClockStopEvent.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} $@.d
	$(COMPILE.cc) -g -pthread -lrt -lwiringPi -lwiringPiDev -ldl -fPIC  -MMD -MP -MF $@.d -o ${OBJECTDIR}/ClockStopEvent.o ClockStopEvent.cpp

${OBJECTDIR}/ClockTickEvent.o: ClockTickEvent.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} $@.d
	$(COMPILE.cc) -g -pthread -lrt -lwiringPi -lwiringPiDev -ldl -fPIC  -MMD -MP -MF $@.d -o ${OBJECTDIR}/ClockTickEvent.o ClockTickEvent.cpp

${OBJECTDIR}/Context.o: Context.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} $@.d
	$(COMPILE.cc) -g -pthread -lrt -lwiringPi -lwiringPiDev -ldl -fPIC  -MMD -MP -MF $@.d -o ${OBJECTDIR}/Context.o Context.cpp

${OBJECTDIR}/DataStream.o: DataStream.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} $@.d
	$(COMPILE.cc) -g -pthread -lrt -lwiringPi -lwiringPiDev -ldl -fPIC  -MMD -MP -MF $@.d -o ${OBJECTDIR}/DataStream.o DataStream.cpp

${OBJECTDIR}/DatagramPacket.o: DatagramPacket.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} $@.d
	$(COMPILE.cc) -g -pthread -lrt -lwiringPi -lwiringPiDev -ldl -fPIC  -MMD -MP -MF $@.d -o ${OBJECTDIR}/DatagramPacket.o DatagramPacket.cpp

${OBJECTDIR}/DatagramSocket.o: DatagramSocket.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} $@.d
	$(COMPILE.cc) -g -pthread -lrt -lwiringPi -lwiringPiDev -ldl -fPIC  -MMD -MP -MF $@.d -o ${OBJECTDIR}/DatagramSocket.o DatagramSocket.cpp

${OBJECTDIR}/DatagramSocketClient.o: DatagramSocketClient.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} $@.d
	$(COMPILE.cc) -g -pthread -lrt -lwiringPi -lwiringPiDev -ldl -fPIC  -MMD -MP -MF $@.d -o ${OBJECTDIR}/DatagramSocketClient.o DatagramSocketClient.cpp

${OBJECTDIR}/DatagramSocketServer.o: DatagramSocketServer.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} $@.d
	$(COMPILE.cc) -g -pthread -lrt -lwiringPi -lwiringPiDev -ldl -fPIC  -MMD -MP -MF $@.d -o ${OBJECTDIR}/DatagramSocketServer.o DatagramSocketServer.cpp

${OBJECTDIR}/Epsilon.o: Epsilon.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} $@.d
	$(COMPILE.cc) -g -pthread -lrt -lwiringPi -lwiringPiDev -ldl -fPIC  -MMD -MP -MF $@.d -o ${OBJECTDIR}/Epsilon.o Epsilon.cpp

${OBJECTDIR}/Event.o: Event.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} $@.d
	$(COMPILE.cc) -g -pthread -lrt -lwiringPi -lwiringPiDev -ldl -fPIC  -MMD -MP -MF $@.d -o ${OBJECTDIR}/Event.o Event.cpp

${OBJECTDIR}/Exception.o: Exception.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} $@.d
	$(COMPILE.cc) -g -pthread -lrt -lwiringPi -lwiringPiDev -ldl -fPIC  -MMD -MP -MF $@.d -o ${OBJECTDIR}/Exception.o Exception.cpp

${OBJECTDIR}/ExceptionEvent.o: ExceptionEvent.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} $@.d
	$(COMPILE.cc) -g -pthread -lrt -lwiringPi -lwiringPiDev -ldl -fPIC  -MMD -MP -MF $@.d -o ${OBJECTDIR}/ExceptionEvent.o ExceptionEvent.cpp

${OBJECTDIR}/GPIO.o: GPIO.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} $@.d
	$(COMPILE.cc) -g -pthread -lrt -lwiringPi -lwiringPiDev -ldl -fPIC  -MMD -MP -MF $@.d -o ${OBJECTDIR}/GPIO.o GPIO.cpp

${OBJECTDIR}/GPIOException.o: GPIOException.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} $@.d
	$(COMPILE.cc) -g -pthread -lrt -lwiringPi -lwiringPiDev -ldl -fPIC  -MMD -MP -MF $@.d -o ${OBJECTDIR}/GPIOException.o GPIOException.cpp

${OBJECTDIR}/GPIOFactorySingleton.o: GPIOFactorySingleton.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} $@.d
	$(COMPILE.cc) -g -pthread -lrt -lwiringPi -lwiringPiDev -ldl -fPIC  -MMD -MP -MF $@.d -o ${OBJECTDIR}/GPIOFactorySingleton.o GPIOFactorySingleton.cpp

${OBJECTDIR}/IButtonCommand.o: IButtonCommand.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} $@.d
	$(COMPILE.cc) -g -pthread -lrt -lwiringPi -lwiringPiDev -ldl -fPIC  -MMD -MP -MF $@.d -o ${OBJECTDIR}/IButtonCommand.o IButtonCommand.cpp

${OBJECTDIR}/IButtonListener.o: IButtonListener.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} $@.d
	$(COMPILE.cc) -g -pthread -lrt -lwiringPi -lwiringPiDev -ldl -fPIC  -MMD -MP -MF $@.d -o ${OBJECTDIR}/IButtonListener.o IButtonListener.cpp

${OBJECTDIR}/IClockListener.o: IClockListener.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} $@.d
	$(COMPILE.cc) -g -pthread -lrt -lwiringPi -lwiringPiDev -ldl -fPIC  -MMD -MP -MF $@.d -o ${OBJECTDIR}/IClockListener.o IClockListener.cpp

${OBJECTDIR}/IExceptionListener.o: IExceptionListener.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} $@.d
	$(COMPILE.cc) -g -pthread -lrt -lwiringPi -lwiringPiDev -ldl -fPIC  -MMD -MP -MF $@.d -o ${OBJECTDIR}/IExceptionListener.o IExceptionListener.cpp

${OBJECTDIR}/IGPIOFactory.o: IGPIOFactory.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} $@.d
	$(COMPILE.cc) -g -pthread -lrt -lwiringPi -lwiringPiDev -ldl -fPIC  -MMD -MP -MF $@.d -o ${OBJECTDIR}/IGPIOFactory.o IGPIOFactory.cpp

${OBJECTDIR}/IGPIOFactoryProvider.o: IGPIOFactoryProvider.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} $@.d
	$(COMPILE.cc) -g -pthread -lrt -lwiringPi -lwiringPiDev -ldl -fPIC  -MMD -MP -MF $@.d -o ${OBJECTDIR}/IGPIOFactoryProvider.o IGPIOFactoryProvider.cpp

${OBJECTDIR}/INetworkAddress.o: INetworkAddress.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} $@.d
	$(COMPILE.cc) -g -pthread -lrt -lwiringPi -lwiringPiDev -ldl -fPIC  -MMD -MP -MF $@.d -o ${OBJECTDIR}/INetworkAddress.o INetworkAddress.cpp

${OBJECTDIR}/IStateChangedListener.o: IStateChangedListener.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} $@.d
	$(COMPILE.cc) -g -pthread -lrt -lwiringPi -lwiringPiDev -ldl -fPIC  -MMD -MP -MF $@.d -o ${OBJECTDIR}/IStateChangedListener.o IStateChangedListener.cpp

${OBJECTDIR}/IllegalArgumentException.o: IllegalArgumentException.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} $@.d
	$(COMPILE.cc) -g -pthread -lrt -lwiringPi -lwiringPiDev -ldl -fPIC  -MMD -MP -MF $@.d -o ${OBJECTDIR}/IllegalArgumentException.o IllegalArgumentException.cpp

${OBJECTDIR}/IllegalStateException.o: IllegalStateException.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} $@.d
	$(COMPILE.cc) -g -pthread -lrt -lwiringPi -lwiringPiDev -ldl -fPIC  -MMD -MP -MF $@.d -o ${OBJECTDIR}/IllegalStateException.o IllegalStateException.cpp

${OBJECTDIR}/InternetAddress.o: InternetAddress.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} $@.d
	$(COMPILE.cc) -g -pthread -lrt -lwiringPi -lwiringPiDev -ldl -fPIC  -MMD -MP -MF $@.d -o ${OBJECTDIR}/InternetAddress.o InternetAddress.cpp

${OBJECTDIR}/KeyNotFoundException.o: KeyNotFoundException.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} $@.d
	$(COMPILE.cc) -g -pthread -lrt -lwiringPi -lwiringPiDev -ldl -fPIC  -MMD -MP -MF $@.d -o ${OBJECTDIR}/KeyNotFoundException.o KeyNotFoundException.cpp

${OBJECTDIR}/ObjectFactory.o: ObjectFactory.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} $@.d
	$(COMPILE.cc) -g -pthread -lrt -lwiringPi -lwiringPiDev -ldl -fPIC  -MMD -MP -MF $@.d -o ${OBJECTDIR}/ObjectFactory.o ObjectFactory.cpp

${OBJECTDIR}/ObjectFactoryException.o: ObjectFactoryException.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} $@.d
	$(COMPILE.cc) -g -pthread -lrt -lwiringPi -lwiringPiDev -ldl -fPIC  -MMD -MP -MF $@.d -o ${OBJECTDIR}/ObjectFactoryException.o ObjectFactoryException.cpp

${OBJECTDIR}/ObjectFactoryMethod.o: ObjectFactoryMethod.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} $@.d
	$(COMPILE.cc) -g -pthread -lrt -lwiringPi -lwiringPiDev -ldl -fPIC  -MMD -MP -MF $@.d -o ${OBJECTDIR}/ObjectFactoryMethod.o ObjectFactoryMethod.cpp

${OBJECTDIR}/Pin.o: Pin.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} $@.d
	$(COMPILE.cc) -g -pthread -lrt -lwiringPi -lwiringPiDev -ldl -fPIC  -MMD -MP -MF $@.d -o ${OBJECTDIR}/Pin.o Pin.cpp

${OBJECTDIR}/Properties.o: Properties.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} $@.d
	$(COMPILE.cc) -g -pthread -lrt -lwiringPi -lwiringPiDev -ldl -fPIC  -MMD -MP -MF $@.d -o ${OBJECTDIR}/Properties.o Properties.cpp

${OBJECTDIR}/PropertiesException.o: PropertiesException.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} $@.d
	$(COMPILE.cc) -g -pthread -lrt -lwiringPi -lwiringPiDev -ldl -fPIC  -MMD -MP -MF $@.d -o ${OBJECTDIR}/PropertiesException.o PropertiesException.cpp

${OBJECTDIR}/SocketException.o: SocketException.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} $@.d
	$(COMPILE.cc) -g -pthread -lrt -lwiringPi -lwiringPiDev -ldl -fPIC  -MMD -MP -MF $@.d -o ${OBJECTDIR}/SocketException.o SocketException.cpp

${OBJECTDIR}/StateChangedEvent.o: StateChangedEvent.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} $@.d
	$(COMPILE.cc) -g -pthread -lrt -lwiringPi -lwiringPiDev -ldl -fPIC  -MMD -MP -MF $@.d -o ${OBJECTDIR}/StateChangedEvent.o StateChangedEvent.cpp

${OBJECTDIR}/Thread.o: Thread.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} $@.d
	$(COMPILE.cc) -g -pthread -lrt -lwiringPi -lwiringPiDev -ldl -fPIC  -MMD -MP -MF $@.d -o ${OBJECTDIR}/Thread.o Thread.cpp

${OBJECTDIR}/ThreadException.o: ThreadException.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} $@.d
	$(COMPILE.cc) -g -pthread -lrt -lwiringPi -lwiringPiDev -ldl -fPIC  -MMD -MP -MF $@.d -o ${OBJECTDIR}/ThreadException.o ThreadException.cpp

# Subprojects
.build-subprojects:

# Clean Targets
.clean-conf: ${CLEAN_SUBPROJECTS}
	${RM} -r ${CND_BUILDDIR}/${CND_CONF}
	${RM} ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/libtulipallo_core.${CND_DLIB_EXT}

# Subprojects
.clean-subprojects:

# Enable dependency checking
.dep.inc: .depcheck-impl

include .dep.inc
