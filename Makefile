CXX		 := g++
CXXFLAGS := -std=c++11

BIN     := bin
SRC     := src
BUILD	:= build
INCLUDE := include
LIB     := lib
LIBRARIES   := 
EXECUTABLE  := main
PARAMS	:= -size 10 10 -border open 1
PARAMSDIM1	:=  -dim 1 -size 25 -cell Ace30 -border nonborders -init 1D_25.txt
PARAMSDIM2	:=  -dim 2 -size 50 50 -cell Life51_346 -border nonborders -init file2.txt
SOURCES := $(wildcard $(SRC)/*.cc)
OBJS	:= $(patsubst $(SRC)/%.cc,$(BUILD)/%.o,$(SOURCES))

.PHONY: all project run clean dim1 dim2

all: $(BIN)/$(EXECUTABLE)

$(BIN)/$(EXECUTABLE): $(OBJS)
	@echo "🚧 Building..."
	$(CXX) -o $@ $(CXXFLAGS) -L$(LIB) $(OBJS)

$(BUILD)/%.o: $(SRC)/%.cc
	@echo "🚧 Building..."
	$(CXX) -c -o $@ $(CXXFLAGS) $<

project:
	clear
	@echo "📁 Creating Project Structure..."
	mkdir -p bin build include src

run:
	@echo "🚀 Executing..."
	./$(BIN)/$(EXECUTABLE) $(PARAMS)

dim1:
	@echo "🚀 Executing..."
	./$(BIN)/$(EXECUTABLE) $(PARAMSDIM1)

dim2:
	@echo "🚀 Executing..."
	./$(BIN)/$(EXECUTABLE) $(PARAMSDIM2)

clean:
	@echo "🧹 Clearing..."
	rm -f $(BIN)/* $(BUILD)/*