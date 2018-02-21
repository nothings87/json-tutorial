
V=@
# V=

APP = hello

SRCS = hello.c

OBJS = $(patsubst %.c,%.o,$(SRCS))

link: $(OBJS)
	@echo "Linking..."
	$(V)gcc $^ -o $(APP)

$(APP): $(OBJS)
	@echo "Linking..."
	$(V)gcc $^ -o $@

all: link

deploy: $(APP)
	@echo "Deploy $<..."
	@cp $< $(CGI_DIR)/$<.cgi


clean:
	@rm $(OBJS) $(APP)


WWW = /home/eddie/var/www

CGI_DIR = $(WWW)/servers/cgi-test/cgi-bin


%.o: %.c
	@echo "Compiling $<..."
	$(V)gcc -c $< -o $@

