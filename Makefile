# Definindo o compilador
CXX = g++

# Definindo os arquivos fonte, excluindo oldmain.cpp
SRCS = $(filter-out oldmain.cpp, $(wildcard *.cpp))

# Definindo os arquivos objeto
OBJS = $(SRCS:.cpp=.o)

# Nome do executável
EXEC = main

# Regra padrão
all: $(EXEC)

# Regra para criar o executável
$(EXEC): $(OBJS)
	$(CXX) -o $@ $^

# Regra para criar os arquivos objeto
%.o: %.cpp
	$(CXX) -c $< -o $@

# Limpeza dos arquivos objeto e executável
clean:
	rm -f $(OBJS) $(EXEC)

.PHONY: all clean
