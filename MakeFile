# Makefile for LightIoT OMNeT++ Simulation

PROJECT_NAME=LightIoTSimulation

all:
	opp_makemake -f --deep -o $(PROJECT_NAME)
	make

clean:
	rm -f $(PROJECT_NAME)
	rm -rf out
	rm -f *.o *.vec *.sca *.log