output: simulation.o Vehicle.o Helicopter.o Plane.o InAir.o terminalGate.o taxiway.o hanger.o runway.o
	clang++ simulation.o Vehicle.o Helicopter.o Plane.o InAir.o terminalGate.o taxiway.o hanger.o runway.o -o output

simulation.o: simulation.cpp simulation.h
	clang++ -c simulation.cpp

Vehicle.o: Vehicle.cpp Vehicle.h
	clang++ -c Vehicle.cpp

Helicopter.o: Helicopter.cpp Helicopter.h
	clang++ -c Helicopter.cpp

Plane.o: Plane.cpp Plane.h
	clang++ -c Plane.cpp

InAir.o: InAir.cpp InAir.h
	clang++ -c InAir.cpp

terminalGate.o: terminalGate.cpp terminalGate.h
	clang++ -c terminalGate.cpp

taxiway.o: taxiway.cpp taxiway.h
	clang++ -c taxiway.cpp

hanger.o: hanger.cpp hanger.h
	clang++ -c hanger.cpp

runway.o: runway.cpp runway.h
	clang++ -c runway.cpp

locations.o: locations.cpp locations.h
	clang++ -c locations.cpp

clean:
	rm *.o output