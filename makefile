# Diretórios
SRC_DIR = src
TEST_DIR = test
BIN_DIR = bin
UNIT_TEST_DIR = $(TEST_DIR)/unit
FUNCIONAL_TEST_DIR = $(TEST_DIR)/funcional

# Compilador e flags
CXX = g++
CXXFLAGS = -Wall -Wextra -std=c++11

# Arquivos fontes
SRC_FILES = $(wildcard $(SRC_DIR)/*.cpp)
UNIT_TEST_FILES = $(wildcard $(UNIT_TEST_DIR)/*.cpp)
FUNCIONAL_TEST_FILES = $(wildcard $(FUNCIONAL_TEST_DIR)/*.cpp)

# Arquivos objetos
SRC_OBJS = $(patsubst $(SRC_DIR)/%.cpp, $(BIN_DIR)/%.o, $(SRC_FILES))
UNIT_TEST_OBJS = $(patsubst $(UNIT_TEST_DIR)/%.cpp, $(BIN_DIR)/%.o, $(UNIT_TEST_FILES))
FUNCIONAL_TEST_OBJS = $(patsubst $(FUNCIONAL_TEST_DIR)/%.cpp, $(BIN_DIR)/%.o, $(FUNCIONAL_TEST_FILES))

# Executáveis
UNIT_TEST_EXEC = $(BIN_DIR)/unit_tests
FUNCIONAL_TEST_EXEC = $(BIN_DIR)/funcional_tests

# Regras
all: $(FUNCIONAL_TEST_EXEC)

$(BIN_DIR)/%.o: $(SRC_DIR)/%.cpp
	@mkdir -p $(BIN_DIR)
	$(CXX) $(CXXFLAGS) -c $< -o $@

$(BIN_DIR)/%.o: $(FUNCIONAL_TEST_DIR)/%.cpp
	@mkdir -p $(BIN_DIR)
	$(CXX) $(CXXFLAGS) -c $< -o $@

$(FUNCIONAL_TEST_EXEC): $(SRC_OBJS) $(FUNCIONAL_TEST_OBJS)
	$(CXX) $(CXXFLAGS) $^ -o $@

clean:
	rm -rf $(BIN_DIR)/*.o $(UNIT_TEST_EXEC) $(FUNCIONAL_TEST_EXEC)

.PHONY: all clean
