CC = g++

CFLAGS = -Wall -std=c++17

TARGET = Practica2Oficial

SRCS = main.cpp \
	.src/estructuras/Arbol.cpp \
	.src/estructuras/Arbol.h \
	.src/estructuras/ListaDoblemente.cpp \
	.src/estructuras/ListaDoblemente.h \
	.src/estructuras/Nodo.cpp \
	.src/estructuras/Nodo.h \
	.src/estructuras/ArbolAVL.cpp \
	.src/estructuras/ArbolAVL.h \
	.src/estructuras/NodoArbol.cpp \
	.src/estructuras/NodoArbol.h \
	.src/estructuras/TablaHash.h \
	.src/clases/Contactos.cpp \
	.src/clases/Contactos.h \
	.src/clases/Grupos.cpp \
	.src/clases/Grupos.h \
	.src


OBJS = $(SRCS:.cpp=.o)

$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) -o $(TARGET) $(OBJS)

.cpp.o:
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS) $(TARGET)