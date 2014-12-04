CC = gcc
CFLAGS = -Werror
LDFLAGS = -lm
SOURCE = cJSON.c
TARGET = libcJSON.so
TARGET += test


all:$(TARGET)

libcJSON.so:
	$(CC) -fPIC -shared $(CFLAGS) $(LDFLAGS) $(SOURCE) -o $@

test:libcJSON.so
	$(CC) test.c $(CFLAGS)  -L. -lcJSON -lm -o $@

install:
	sudo cp $(TARGET) /lib
	sudo cp cJSON.h /usr/include/

clean:
	rm $(TARGET)
