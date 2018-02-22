
V?=@

APP=post-json

SRCS=http-post-json.c

OBJS=$(patsubst %.c,%.o,$(SRCS))

CURDIR:=$(shell pwd)

CFLAGS=

INCLUDES=
INCLUDES+=$(CURDIR)/jsmn

CFLAGS+=$(addprefix -I,$(INCLUDES))

LIBJSMN=$(CURDIR)/jsmn/libjsmn.a

LDFLAGS=
LDFLAGS+=-L$(CURDIR)/jsmn -ljsmn

link: $(OBJS)
	@echo "Linking..."
	$(V)gcc $(LDFLAGS) $^ -o $(APP)

$(APP): $(OBJS)
	@echo "Linking..."
	$(V)gcc $^ -o $@ $(LDFLAGS)

all: $(APP)

deploy: $(APP)
	@echo "Deploy $<..."
	@cp $< $(CGI_DIR)/$<.cgi


clean:
	@rm $(OBJS) $(APP)


WWW = /home/eddie/var/www

CGI_DIR = $(WWW)/servers/cgi-test/cgi-bin


%.o: %.c
	@echo "Compiling $<..."
	$(V)gcc $(CFLAGS) -c $< -o $@

