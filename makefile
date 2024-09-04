all: libimpl.so funcional_tests unit_tests

libimpl.so: bin/ModelBody.o bin/SystemBody.o bin/FlowBody.o
	g++ -shared -o bin/libimpl.so bin/ModelBody.o bin/SystemBody.o bin/FlowBody.o

bin/ModelBody.o: src/ModelBody.cpp
	g++ -c -fPIC src/ModelBody.cpp -o bin/ModelBody.o

bin/SystemBody.o: src/SystemBody.cpp
	g++ -c -fPIC src/SystemBody.cpp -o bin/SystemBody.o

bin/FlowBody.o: src/FlowBody.cpp
	g++ -c -fPIC src/FlowBody.cpp -o bin/FlowBody.o

funcional_tests: libimpl.so
	g++ test/funcional/*.cpp -Lbin -limpl -o bin/funcional.o

unit_tests: libimpl.so
	g++ test/unit/*.cpp -Lbin -limpl -o bin/unit.o

run: all
	LD_LIBRARY_PATH=bin ./bin/funcional.o
	LD_LIBRARY_PATH=bin ./bin/unit.o

clean:
	rm -f bin/*.o bin/libimpl.so
