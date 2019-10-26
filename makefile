LDFLAGS += -static
CFLAGS  += -g

TOOLS = echo ls

all : ${TOOLS}


clean:
	rm -f ${TOOLS}
