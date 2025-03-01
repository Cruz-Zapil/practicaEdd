# Nombre del ejecutable
TARGET = juego

# Compilador
CXX = g++

# Flags de compilación
CXXFLAGS = -Wall -std=c++17 -Iinclude -Isrc/include

# Directorios
SRCDIR = src/lib
OBJDIR = build
BINDIR = build

# Archivos fuente y objetos
SOURCES = $(wildcard $(SRCDIR)/*.cpp) src/main.cpp
OBJECTS = $(patsubst $(SRCDIR)/%.cpp, $(OBJDIR)/%.o, $(SOURCES:.cpp=.o))

# Regla principal
$(BINDIR)/$(TARGET): $(OBJECTS)
	$(CXX) $(CXXFLAGS) -o $@ $^

# Compilación de .cpp a .o
$(OBJDIR)/%.o: $(SRCDIR)/%.cpp | $(OBJDIR)
	$(CXX) $(CXXFLAGS) -c $< -o $@

$(OBJDIR)/main.o: src/main.cpp | $(OBJDIR)
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Crear el directorio de build si no existe
$(OBJDIR):
	mkdir -p $(OBJDIR)

# Limpiar archivos generados
clean:
	rm -rf $(OBJDIR) $(BINDIR)/$(TARGET)

# Regla por defecto
.PHONY: clean
