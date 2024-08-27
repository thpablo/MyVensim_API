all: libimpl.so funcional_tests unit_tests

libimpl.so: bin/ModelImplementation.o bin/SystemImplementation.o bin/FlowImplementation.o
	g++ -shared -o bin/libimpl.so bin/ModelImplementation.o bin/SystemImplementation.o bin/FlowImplementation.o

bin/ModelImplementation.o: src/ModelImplementation.cpp
	g++ -c -fPIC src/ModelImplementation.cpp -o bin/ModelImplementation.o

bin/SystemImplementation.o: src/SystemImplementation.cpp
	g++ -c -fPIC src/SystemImplementation.cpp -o bin/SystemImplementation.o

bin/FlowImplementation.o: src/FlowImplementation.cpp
	g++ -c -fPIC src/FlowImplementation.cpp -o bin/FlowImplementation.o

funcional_tests: libimpl.so
	g++ test/funcional/*.cpp -Lbin -limpl -o bin/funcional.o

unit_tests: libimpl.so
	g++ test/unit/*.cpp -Lbin -limpl -o bin/unit.o

run: all
	LD_LIBRARY_PATH=bin ./bin/funcional.o
	LD_LIBRARY_PATH=bin ./bin/unit.o

clean:
	rm -f bin/*.o bin/libimpl.so
