
V=@
# V=

APP = get 

SRCS = http-get.c

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
	@cp $< $(DVRS_DIR)/$<


clean:
	@rm $(OBJS) $(APP)


WWW = /home/eddie/var/www

CGI_DIR = $(WWW)/servers/cgi-test/cgi-bin
DVRS_DIR = $(WWW)/servers/cgi-test/DVRS


%.o: %.c
	@echo "Compiling $<..."
	$(V)gcc -c $< -o $@

