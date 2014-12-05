CC = gcc
CFLAGS = -Werror
LDFLAGS = -lm
SOURCE = cJSON.c
TARGET = libcJSON.so
TARGET += test1
TARGET += test2


all:$(TARGET)

libcJSON.so:
	$(CC) -fPIC -shared $(CFLAGS) $(LDFLAGS) $(SOURCE) -o $@

test1:libcJSON.so
	$(CC) test.c $(CFLAGS)  -L. -lcJSON -lm -o $@

test2:libcJSON.so
	$(CC) test2.c $(CFLAGS) -L. -lcJSON -lm -o $@

install:$(TARGET)
	sudo cp $(TARGET) /lib
	sudo cp cJSON.h /usr/include/

clean:
	rm $(TARGET)
