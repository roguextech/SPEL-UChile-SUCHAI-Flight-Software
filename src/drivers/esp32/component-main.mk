#
# Main component makefile.
#
# This Makefile can be left empty. By default, it will take the sources in the
# src/ directory, compile them and link them into lib(subdirectory_name).a
# in the build directory. This behaviour is entirely configurable,
# please read the ESP-IDF documents if you need to do this.
#
COMPONENT_OBJS := main.o globals.o utils.o taskHousekeeping.o taskExecuter.o taskDispatcher.o taskConsole.o taskFlightPlan.o cmdFP.o cmdConsole.o cmdDRP.o cmdOBC.o repoCommand.o repoData.o init.o

